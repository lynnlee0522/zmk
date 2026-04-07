/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zmk/split/central.h>
#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/battery.h>
#include <zmk/display.h>
#include <zmk/display/widgets/battery_status.h>
#include <zmk/usb.h>
#include <zmk/events/usb_conn_state_changed.h>
#include <zmk/event_manager.h>
#include <zmk/events/battery_state_changed.h>

static sys_slist_t widgets = SYS_SLIST_STATIC_INIT(&widgets);

// 根据电量百分比获取对应的电池符号
static inline const char *get_battery_symbol(uint8_t level) {
    if (level > 95) {
        return LV_SYMBOL_BATTERY_FULL;
    } else if (level > 65) {
        return LV_SYMBOL_BATTERY_3;
    } else if (level > 35) {
        return LV_SYMBOL_BATTERY_2;
    } else if (level > 5) {
        return LV_SYMBOL_BATTERY_1;
    } else {
        return LV_SYMBOL_BATTERY_EMPTY;
    }
}

struct battery_status_state {
    bool is_peripheral; // 是否是外设电池状态
    uint8_t source;
    uint8_t level;
#if IS_ENABLED(CONFIG_USB_DEVICE_STACK)
    bool usb_present;
#endif
};

#define ZMK_SPLIT_CENTRAL_COUNT 1

struct battery_status_state
    battery_objects[ZMK_SPLIT_CENTRAL_PERIPHERAL_COUNT + ZMK_SPLIT_CENTRAL_COUNT] = {
        [0] = {.is_peripheral = false, .source = 0, .level = 0},
        [1] = {.is_peripheral = true, .source = 0, .level = 0}};

static void set_battery_symbol(lv_obj_t *label, struct battery_status_state state) {
    char text[64] = {};
    int len = 0;
    const int battery_count = ZMK_SPLIT_CENTRAL_PERIPHERAL_COUNT + ZMK_SPLIT_CENTRAL_COUNT;

    for (int i = 0; i < battery_count; i++) {
        state = battery_objects[i];

        // 跳过断联的外设（电量为0）
        if (state.is_peripheral && state.level == 0) {
            continue;
        }

        const char *symbol = get_battery_symbol(state.level);
        len += snprintf(text + len, sizeof(text) - len, "%s %u%%", symbol, state.level);

#if IS_ENABLED(CONFIG_USB_DEVICE_STACK)
        if (state.usb_present) {
            len += snprintf(text + len, sizeof(text) - len, " %s", LV_SYMBOL_CHARGE);
        }
#endif

        // 分隔中央和外设的显示
        if (i < ZMK_SPLIT_CENTRAL_PERIPHERAL_COUNT) {
            len += snprintf(text + len, sizeof(text) - len, "\n");
        }
    }

    lv_label_set_text(label, text);
}

void battery_status_update_cb(struct battery_status_state state) {
    int idx = state.is_peripheral ? 1 : 0;
    battery_objects[idx] = state;

    struct zmk_widget_battery_status *widget;
    SYS_SLIST_FOR_EACH_CONTAINER(&widgets, widget, node) { set_battery_symbol(widget->obj, state); }
}

static struct battery_status_state peripheral_battery_status_get_state(const zmk_event_t *eh) {
    const struct zmk_peripheral_battery_state_changed *ev =
        as_zmk_peripheral_battery_state_changed(eh);

    if (ev == NULL) {
        LOG_WRN("Invalid peripheral battery event");
        return (struct battery_status_state){.is_peripheral = true, .source = 0, .level = 0};
    }

    return (struct battery_status_state){
        .is_peripheral = true,
        .source = ev->source + ZMK_SPLIT_CENTRAL_COUNT,
        .level = ev->state_of_charge,
    };
}

static struct battery_status_state central_battery_status_get_state(const zmk_event_t *eh) {
    const struct zmk_battery_state_changed *ev = as_zmk_battery_state_changed(eh);
    uint8_t level = (ev != NULL) ? ev->state_of_charge : zmk_battery_state_of_charge();

#if IS_ENABLED(CONFIG_USB_DEVICE_STACK)
    bool usb_powered = zmk_usb_is_powered();
#endif

    return (struct battery_status_state){
        .is_peripheral = false,
        .source = 0,
        .level = level,
#if IS_ENABLED(CONFIG_USB_DEVICE_STACK)
        .usb_present = usb_powered,
#endif
    };
}

static struct battery_status_state battery_status_get_state(const zmk_event_t *eh) {
    return (as_zmk_peripheral_battery_state_changed(eh) != NULL)
               ? peripheral_battery_status_get_state(eh)
               : central_battery_status_get_state(eh);
}

ZMK_DISPLAY_WIDGET_LISTENER(widget_battery_status, struct battery_status_state,
                            battery_status_update_cb, battery_status_get_state)

ZMK_SUBSCRIPTION(widget_battery_status, zmk_battery_state_changed);

ZMK_SUBSCRIPTION(widget_battery_status, zmk_peripheral_battery_state_changed);

#if IS_ENABLED(CONFIG_USB_DEVICE_STACK)
ZMK_SUBSCRIPTION(widget_battery_status, zmk_usb_conn_state_changed);
#endif /* IS_ENABLED(CONFIG_USB_DEVICE_STACK) */

int zmk_widget_battery_status_init(struct zmk_widget_battery_status *widget, lv_obj_t *parent) {
    widget->obj = lv_label_create(parent);
    lv_obj_set_style_text_font(widget->obj, &lv_font_montserrat_14, LV_PART_MAIN);
    sys_slist_append(&widgets, &widget->node);
    widget_battery_status_init();
    return 0;
}

lv_obj_t *zmk_widget_battery_status_obj(struct zmk_widget_battery_status *widget) {
    return widget->obj;
}
