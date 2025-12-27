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

    char text[256] = {0};
    char line[96];

    lv_label_set_recolor(label, true);

    for (int i = 0; i < ZMK_SPLIT_CENTRAL_PERIPHERAL_COUNT + ZMK_SPLIT_CENTRAL_COUNT; i++) {

        state = battery_objects[i];

        /* 外设断联直接跳过 */
        if (state.is_peripheral && state.level == 0) {
            continue;
        }

        uint8_t level = state.level;

        const char *color;
        const char *battery_icon;

        if (level > 95) {
            color = "00ff00";
            battery_icon = LV_SYMBOL_BATTERY_FULL;
        } else if (level > 65) {
            color = "aaff00";
            battery_icon = LV_SYMBOL_BATTERY_3;
        } else if (level > 35) {
            color = "ffff00";
            battery_icon = LV_SYMBOL_BATTERY_2;
        } else if (level > 5) {
            color = "ff8000";
            battery_icon = LV_SYMBOL_BATTERY_1;
        } else {
            color = "ff0000";
            battery_icon = LV_SYMBOL_BATTERY_EMPTY;
        }

        /* 只有在 usb_present 时才显示充电符号 */
        if (state.usb_present) {
            snprintf(line, sizeof(line), "#%s %s %d%% %s#", color, battery_icon, level,
                     LV_SYMBOL_CHARGE);
        } else {
            /* 用同一个符号，但颜色设为背景色 / 全透明 */
            snprintf(line, sizeof(line), "#%s %s %d%%# #000080 %s#", color, battery_icon, level,
                     LV_SYMBOL_CHARGE);
        }

        strcat(text, line);

        /* 换行（必须在 recolor 块外） */
        if (i < ZMK_SPLIT_CENTRAL_PERIPHERAL_COUNT + ZMK_SPLIT_CENTRAL_COUNT - 1) {
            strcat(text, "\n");
        }
    }

    lv_label_set_text(label, text);

    LOG_DBG("Battery label text:\n%s", text);
}

void battery_status_update_cb(struct battery_status_state state) {
    int idx = state.is_peripheral ? 1 : 0;
    battery_objects[idx] = state; // 存储最新状态

    struct zmk_widget_battery_status *widget;
    SYS_SLIST_FOR_EACH_CONTAINER(&widgets, widget, node) { set_battery_symbol(widget->obj, state); }
}

static struct battery_status_state peripheral_battery_status_get_state(const zmk_event_t *eh) {
    const struct zmk_peripheral_battery_state_changed *ev =
        as_zmk_peripheral_battery_state_changed(eh);

    return (struct battery_status_state){
        .is_peripheral = true,
        .source = ev->source + ZMK_SPLIT_CENTRAL_COUNT,
        .level = ev->state_of_charge,
#if IS_ENABLED(CONFIG_USB_DEVICE_STACK)
        .usb_present = false,
#endif
    };
}

static struct battery_status_state central_battery_status_get_state(const zmk_event_t *eh) {
    const struct zmk_battery_state_changed *ev = as_zmk_battery_state_changed(eh);

    return (struct battery_status_state){
        .is_peripheral = false,
        .source = 0,
        .level = (ev != NULL) ? ev->state_of_charge : zmk_battery_state_of_charge(),
#if IS_ENABLED(CONFIG_USB_DEVICE_STACK)
        .usb_present = zmk_usb_is_powered(),
#endif /* IS_ENABLED(CONFIG_USB_DEVICE_STACK) */
    };
}

static struct battery_status_state battery_status_get_state(const zmk_event_t *eh) {
    if (as_zmk_peripheral_battery_state_changed(eh) != NULL) {
        return peripheral_battery_status_get_state(eh);
    } else {
        return central_battery_status_get_state(eh);
    }
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
    // 设置text的字体
    lv_obj_set_style_text_font(widget->obj, &lv_font_montserrat_20, LV_PART_MAIN);
    sys_slist_append(&widgets, &widget->node);
    widget_battery_status_init();
    return 0;
}

lv_obj_t *zmk_widget_battery_status_obj(struct zmk_widget_battery_status *widget) {
    return widget->obj;
}
