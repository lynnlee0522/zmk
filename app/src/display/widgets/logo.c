/*
 * Copyright (c) 2022 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);
#include <zmk/display.h>
#include <zmk/display/widgets/logo.h>

static sys_slist_t widgets = SYS_SLIST_STATIC_INIT(&widgets);

LV_FONT_DECLARE(font_18_big_john);

int zmk_widget_logo_init(struct zmk_widget_logo *widget, lv_obj_t *parent) {
    // 创建主容器，水平排列图像和文本
    lv_obj_t *main_container = lv_obj_create(parent);
    lv_obj_set_layout(main_container, LV_LAYOUT_FLEX);
    lv_obj_set_flex_flow(main_container, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_pad_gap(main_container, 5, 0);
    lv_obj_set_height(main_container, 30);
    lv_obj_set_width(main_container, lv_obj_get_width(parent));
    lv_obj_set_style_border_width(main_container, 0, 0);
    lv_obj_set_style_pad_all(main_container, 0, 0);

    // 设置对齐方式
    lv_obj_set_flex_align(main_container, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_CENTER);

    // widget->obj 指向主容器
    widget->obj = main_container;

    // 创建图片对象
    lv_obj_t *img = lv_img_create(main_container);
    LV_IMG_DECLARE(logo_img);
    lv_img_set_src(img, &logo_img);

    // 创建文本标签，显示 "NXTKB"
    lv_obj_t *label = lv_label_create(main_container);
    lv_label_set_text(label, "NXTKB");
    lv_obj_set_style_text_font(label, &font_18_big_john, LV_PART_MAIN);
    // 设置标签颜色为橙色
    lv_obj_set_style_text_color(label, lv_color_hex(0xFFA500), LV_PART_MAIN);
    sys_slist_append(&widgets, &widget->node);
    return 0;
}

lv_obj_t *zmk_widget_logo_obj(struct zmk_widget_logo *widget) { return widget->obj; }
