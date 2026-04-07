/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/init.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/bluetooth/services/bas.h>

#include <zephyr/logging/log.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/event_manager.h>
#include <zmk/battery.h>
#include <zmk/events/battery_state_changed.h>
#include <zmk/events/activity_state_changed.h>
#include <zmk/activity.h>
#include <zmk/workqueue.h>

static uint8_t last_state_of_charge = 0;

uint8_t zmk_battery_state_of_charge(void) { return last_state_of_charge; }

#if DT_HAS_CHOSEN(zmk_battery)
static const struct device *const battery = DEVICE_DT_GET(DT_CHOSEN(zmk_battery));
#else
#warning                                                                                           \
    "Using a node labeled BATTERY for the battery sensor is deprecated. Set a zmk,battery chosen node instead. (Ignore this if you don't have a battery sensor.)"
static const struct device *battery;
#endif

#if IS_ENABLED(CONFIG_ZMK_BATTERY_REPORTING_FETCH_MODE_LITHIUM_VOLTAGE)
static uint8_t lithium_ion_mv_to_pct(int16_t bat_mv) {
    // Simple linear approximation of a battery based off adafruit's discharge graph:
    // https://learn.adafruit.com/li-ion-and-lipoly-batteries/voltages

    if (bat_mv >= 4200) {
        return 100;
    } else if (bat_mv <= 3450) {
        return 0;
    }

    return bat_mv * 2 / 15 - 459;
}

#endif // IS_ENABLED(CONFIG_ZMK_BATTERY_REPORTING_FETCH_MODE_LITHIUM_VOLTAGE)

static int zmk_battery_update(const struct device *battery) {
    struct sensor_value state_of_charge;
    int rc;

    LOG_ERR("[BATTERY_UPDATE] START, battery=%p", battery);

#if IS_ENABLED(CONFIG_ZMK_BATTERY_REPORTING_FETCH_MODE_STATE_OF_CHARGE)

    rc = sensor_sample_fetch_chan(battery, SENSOR_CHAN_GAUGE_STATE_OF_CHARGE);
    if (rc != 0) {
        LOG_ERR("[BATTERY_UPDATE] Failed to fetch (STATE_OF_CHARGE): %d", rc);
        return rc;
    }

    rc = sensor_channel_get(battery, SENSOR_CHAN_GAUGE_STATE_OF_CHARGE, &state_of_charge);

    if (rc != 0) {
        LOG_ERR("[BATTERY_UPDATE] Failed to get state_of_charge: %d", rc);
        return rc;
    }

    LOG_ERR("[BATTERY_UPDATE] Fetched STATE_OF_CHARGE: val1=%u, val2=%d", state_of_charge.val1,
            state_of_charge.val2);
#elif IS_ENABLED(CONFIG_ZMK_BATTERY_REPORTING_FETCH_MODE_LITHIUM_VOLTAGE)
    rc = sensor_sample_fetch_chan(battery, SENSOR_CHAN_VOLTAGE);
    if (rc != 0) {
        LOG_ERR("[BATTERY_UPDATE] Failed to fetch (VOLTAGE): %d", rc);
        return rc;
    }

    struct sensor_value voltage;
    rc = sensor_channel_get(battery, SENSOR_CHAN_VOLTAGE, &voltage);

    if (rc != 0) {
        LOG_ERR("[BATTERY_UPDATE] Failed to get voltage: %d", rc);
        return rc;
    }

    uint16_t mv = voltage.val1 * 1000 + (voltage.val2 / 1000);
    state_of_charge.val1 = lithium_ion_mv_to_pct(mv);

    LOG_ERR("[BATTERY_UPDATE] Fetched VOLTAGE: %d mV → %u%%", mv, state_of_charge.val1);
#else
#error "Not a supported reporting fetch mode"
#endif

    LOG_ERR("[BATTERY_UPDATE] last_state=%u, new_state=%u, changed=%d", last_state_of_charge,
            state_of_charge.val1, (last_state_of_charge != state_of_charge.val1));

    if (last_state_of_charge != state_of_charge.val1) {
        last_state_of_charge = state_of_charge.val1;

        LOG_ERR("[BATTERY_UPDATE] Raising event with level=%u", last_state_of_charge);

        rc = raise_zmk_battery_state_changed(
            (struct zmk_battery_state_changed){.state_of_charge = last_state_of_charge});

        if (rc != 0) {
            LOG_ERR("[BATTERY_UPDATE] Failed to raise event: %d", rc);
            return rc;
        }
    } else {
        LOG_ERR("[BATTERY_UPDATE] Level unchanged, skipping event");
    }

#if IS_ENABLED(CONFIG_BT_BAS)
    if (bt_bas_get_battery_level() != last_state_of_charge) {
        LOG_DBG("Setting BAS GATT battery level to %d.", last_state_of_charge);

        rc = bt_bas_set_battery_level(last_state_of_charge);

        if (rc != 0) {
            LOG_WRN("Failed to set BAS GATT battery level (err %d)", rc);
            return rc;
        }
    }
#endif

    return rc;
}

static void zmk_battery_work(struct k_work *work) {
    int rc = zmk_battery_update(battery);

    if (rc != 0) {
        LOG_DBG("Failed to update battery value: %d.", rc);
    }
}

K_WORK_DEFINE(battery_work, zmk_battery_work);

static void zmk_battery_timer(struct k_timer *timer) {
    k_work_submit_to_queue(zmk_workqueue_lowprio_work_q(), &battery_work);
}

K_TIMER_DEFINE(battery_timer, zmk_battery_timer, NULL);

static void zmk_battery_start_reporting() {
    if (device_is_ready(battery)) {
        k_timer_start(&battery_timer, K_NO_WAIT, K_SECONDS(CONFIG_ZMK_BATTERY_REPORT_INTERVAL));
    }
}

static int zmk_battery_init(void) {
    LOG_ERR("[BATTERY_INIT] START");

#if !DT_HAS_CHOSEN(zmk_battery)
    battery = device_get_binding("BATTERY");

    LOG_ERR("[BATTERY_INIT] Using deprecated BATTERY label, device=%p", battery);

    if (battery == NULL) {
        LOG_ERR("[BATTERY_INIT] FAILED: battery device not found");
        return -ENODEV;
    }

    LOG_WRN("Finding battery device labeled BATTERY is deprecated. Use zmk,battery chosen node.");
#endif

    LOG_ERR("[BATTERY_INIT] Checking device ready: battery=%p", battery);
    if (!device_is_ready(battery)) {
        LOG_ERR("[BATTERY_INIT] FAILED: Battery device \"%s\" is not ready", battery->name);
        return -ENODEV;
    }

    LOG_ERR("[BATTERY_INIT] Device ready, starting reporting");
    zmk_battery_start_reporting();
    LOG_ERR("[BATTERY_INIT] SUCCESS");
    return 0;
}

static int battery_event_listener(const zmk_event_t *eh) {

    if (as_zmk_activity_state_changed(eh)) {
        switch (zmk_activity_get_state()) {
        case ZMK_ACTIVITY_ACTIVE:
            zmk_battery_start_reporting();
            return 0;
        case ZMK_ACTIVITY_IDLE:
        case ZMK_ACTIVITY_SLEEP:
            k_timer_stop(&battery_timer);
            return 0;
        default:
            break;
        }
    }
    return -ENOTSUP;
}

ZMK_LISTENER(battery, battery_event_listener);

ZMK_SUBSCRIPTION(battery, zmk_activity_state_changed);

SYS_INIT(zmk_battery_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
