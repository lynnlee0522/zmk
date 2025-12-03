/*******************************************************************************
 * Size: 24 px
 * Bpp: 1
 * Opts: --bpp 1 --size 24 --no-compress --stride 1 --align 1 --font big-john-woff2-2.ttf --symbols
 *N,X,T,K,B, --format lvgl -o font_24_big_john.c
 ******************************************************************************/

#ifdef __has_include
#if __has_include("lvgl.h")
#ifndef LV_LVGL_H_INCLUDE_SIMPLE
#define LV_LVGL_H_INCLUDE_SIMPLE
#endif
#endif
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef FONT_24_BIG_JOHN
#define FONT_24_BIG_JOHN 1
#endif

#if FONT_24_BIG_JOHN

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+002C "," */
    0x6f, 0xf7, 0x22,

    /* U+0042 "B" */
    0xff, 0xc3, 0xff, 0x8f, 0xff, 0x3f, 0xfe, 0xf8, 0xfb, 0xe3, 0xef, 0x8f, 0xbf, 0xfc, 0xff, 0xf3,
    0xff, 0xef, 0xff, 0xbe, 0x1f, 0xf8, 0x7f, 0xe1, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xf3, 0xff, 0x80,

    /* U+004B "K" */
    0xf8, 0x1f, 0x9f, 0x7, 0xe3, 0xe1, 0xf8, 0x7c, 0x7e, 0xf, 0x9f, 0x81, 0xf7, 0xe0, 0x3f, 0xf8,
    0x7, 0xfe, 0x0, 0xff, 0xc0, 0x1f, 0xfc, 0x3, 0xff, 0xc0, 0x7f, 0xfc, 0xf, 0x9f, 0xc1, 0xf1,
    0xfc, 0x3e, 0x1f, 0xc7, 0xc1, 0xfc, 0xf8, 0x1f, 0xdf, 0x1, 0xfc,

    /* U+004E "N" */
    0xc0, 0x3f, 0xc0, 0x7f, 0xc0, 0xff, 0xc1, 0xff, 0xc3, 0xff, 0xc7, 0xff, 0xcf, 0xff, 0xdf, 0xff,
    0xff, 0xff, 0xff, 0xef, 0xff, 0xcf, 0xff, 0x8f, 0xff, 0xf, 0xfe, 0xf, 0xfc, 0xf, 0xf8, 0xf,
    0xf0, 0x1c,

    /* U+0054 "T" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7, 0xc0, 0x1f, 0x0, 0x7c, 0x1, 0xf0, 0x7, 0xc0,
    0x1f, 0x0, 0x7c, 0x1, 0xf0, 0x7, 0xc0, 0x1f, 0x0, 0x7c, 0x1, 0xf0, 0x7, 0xc0, 0x1f, 0x0,

    /* U+0058 "X" */
    0x7e, 0xf, 0xc7, 0xe1, 0xf8, 0x7c, 0x7e, 0xf, 0xdf, 0x80, 0xff, 0xe0, 0xf, 0xfc, 0x1, 0xff, 0x0,
    0x1f, 0xc0, 0x1, 0xf8, 0x0, 0x7f, 0x0, 0x1f, 0xf0, 0x3, 0xff, 0x0, 0xff, 0xe0, 0x3f, 0x7e, 0x7,
    0xc7, 0xe1, 0xf8, 0x7c, 0x7e, 0xf, 0xcf, 0x80, 0xfc};

/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0,
     .adv_w = 0,
     .box_w = 0,
     .box_h = 0,
     .ofs_x = 0,
     .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 92, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 3, .adv_w = 272, .box_w = 14, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 35, .adv_w = 329, .box_w = 19, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 78, .adv_w = 301, .box_w = 15, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 112, .adv_w = 273, .box_w = 14, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 144, .adv_w = 311, .box_w = 19, .box_h = 18, .ofs_x = 0, .ofs_y = 0}};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {0x0, 0x16, 0x1f, 0x22, 0x28, 0x2c};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] = {{.range_start = 44,
                                                .range_length = 45,
                                                .glyph_id_start = 1,
                                                .unicode_list = unicode_list_0,
                                                .glyph_id_ofs_list = NULL,
                                                .list_length = 6,
                                                .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY}};

/*-----------------
 *    KERNING
 *----------------*/

/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] = {5, 1};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] = {-19};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs = {.glyph_ids = kern_pair_glyph_ids,
                                                       .values = kern_pair_values,
                                                       .pair_cnt = 1,
                                                       .glyph_ids_size = 0};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif

};

extern const lv_font_t lv_font_montserrat_24;

/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t font_24_big_john = {
#else
lv_font_t font_24_big_john = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt, /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt, /*Function pointer to get glyph's bitmap*/
    .line_height = 20,                              /*The maximum line height required by the font*/
    .base_line = 2, /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -5,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc, /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = &lv_font_montserrat_24,
#endif
    .user_data = NULL,
};

#endif /*#if FONT_24_BIG_JOHN*/
