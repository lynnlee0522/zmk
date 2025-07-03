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

int zmk_widget_logo_init(struct zmk_widget_logo *widget, lv_obj_t *parent) {
    // 创建一个容器，将图片和文本放在同一行
    lv_obj_t *container = lv_obj_create(parent);
    lv_obj_set_layout(container, LV_LAYOUT_FLEX);
    lv_obj_set_flex_flow(container, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_pad_gap(container, 5, 0); // 图片和文本间距5像素

    // 设置容器的高度
    lv_obj_set_height(container, 30); // 设置容器高度为30像素

    // 取消容器的边框
    lv_obj_set_style_border_width(container, 0, 0);

    // 取消容器的上下左右间距
    lv_obj_set_style_pad_all(container, 0, 0);

    // 设置主轴和交叉轴居中对齐
    lv_obj_set_flex_align(container, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_CENTER);

    // widget->obj 指向 container
    widget->obj = container;

    // 创建图片对象并添加到容器
    lv_obj_t *img = lv_img_create(container);
    LV_IMG_DECLARE(logo_img);
    lv_img_set_src(img, &logo_img);

    // 创建文本标签，显示 "NXT kb"
    lv_obj_t *label = lv_label_create(container);
    lv_label_set_text(label, "NXT kb");
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_LEFT, 0);
    // 设置字体大小为 20px
    lv_obj_set_style_text_font(label, &lv_font_montserrat_20, LV_PART_MAIN);

    sys_slist_append(&widgets, &widget->node);
    return 0;
}

lv_obj_t *zmk_widget_logo_obj(struct zmk_widget_logo *widget) { return widget->obj; }
