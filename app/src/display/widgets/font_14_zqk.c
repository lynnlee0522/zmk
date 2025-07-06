/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --no-compress --font ZQKfreefont-2.ttf --symbols
 *ABCDEFGHIGKLMNOPQRSTUVWXYZabcdefghigklmnopqrstuvwxyz1234567890:- --format lvgl -o font_14_zqk.c
 ******************************************************************************/

#ifdef __has_include
#if __has_include("lvgl.h")
#ifndef LV_LVGL_H_INCLUDE_SIMPLE
#define LV_LVGL_H_INCLUDE_SIMPLE
#endif
#endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef FONT_14_ZQK
#define FONT_14_ZQK 1
#endif

#if FONT_14_ZQK

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+002D "-" */
    0xff,

    /* U+0030 "0" */
    0x7d, 0xff, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xfe, 0xf8,

    /* U+0031 "1" */
    0xce, 0x66, 0x66, 0x66, 0xff,

    /* U+0032 "2" */
    0xfc, 0xfc, 0x18, 0x37, 0xff, 0xb0, 0x60, 0xff, 0xfc,

    /* U+0033 "3" */
    0xfd, 0xfc, 0x18, 0x37, 0xef, 0xc1, 0x83, 0xff, 0xf8,

    /* U+0034 "4" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x7f, 0xdf, 0x83, 0x6, 0xc,

    /* U+0035 "5" */
    0xff, 0xfb, 0x6, 0xf, 0xcf, 0xc1, 0x83, 0xff, 0xf8,

    /* U+0036 "6" */
    0x7f, 0xff, 0x6, 0xf, 0xdf, 0xf1, 0xe3, 0xfe, 0xf8,

    /* U+0037 "7" */
    0xff, 0xfc, 0x38, 0x60, 0xc3, 0x6, 0x1c, 0x30, 0xe0,

    /* U+0038 "8" */
    0x7d, 0xff, 0x1e, 0x37, 0xdf, 0xf1, 0xe3, 0xfe, 0xf8,

    /* U+0039 "9" */
    0x7d, 0xff, 0x1e, 0x3c, 0x7f, 0xdf, 0x83, 0xff, 0xf8,

    /* U+003A ":" */
    0xf0, 0xf0,

    /* U+0041 "A" */
    0x1c, 0xe, 0x7, 0x87, 0xc3, 0x61, 0xb1, 0xdc, 0xf6, 0x7b, 0x31, 0xc0,

    /* U+0042 "B" */
    0xfd, 0xff, 0x1e, 0x3f, 0xdf, 0xb1, 0xe3, 0xff, 0xf8,

    /* U+0043 "C" */
    0x7f, 0xff, 0x6, 0xc, 0x18, 0x30, 0x60, 0xfe, 0xfc,

    /* U+0044 "D" */
    0xfd, 0xff, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xff, 0xf8,

    /* U+0045 "E" */
    0xff, 0xff, 0x6, 0xf, 0xff, 0xb0, 0x60, 0xff, 0xfc,

    /* U+0046 "F" */
    0xff, 0xff, 0x6, 0xc, 0x1f, 0xff, 0x60, 0xc1, 0x80,

    /* U+0047 "G" */
    0x7f, 0xff, 0x6, 0xd, 0xfb, 0xf1, 0xe3, 0xfe, 0xf8,

    /* U+0048 "H" */
    0xc7, 0x8f, 0x1e, 0x3f, 0xff, 0xf1, 0xe3, 0xc7, 0x8c,

    /* U+0049 "I" */
    0xff, 0x66, 0x66, 0x66, 0xff,

    /* U+004B "K" */
    0xcf, 0x9b, 0x66, 0xcf, 0x1e, 0x36, 0x6c, 0xcd, 0x9c,

    /* U+004C "L" */
    0xc1, 0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xff, 0xfc,

    /* U+004D "M" */
    0xc1, 0xf1, 0xf8, 0xfe, 0xff, 0x7f, 0xff, 0x77, 0xbb, 0xc1, 0xe0, 0xc0,

    /* U+004E "N" */
    0xc7, 0xcf, 0x9f, 0xbf, 0x7b, 0xf7, 0xe7, 0xcf, 0x8c,

    /* U+004F "O" */
    0x7c, 0xfb, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0x7c, 0xf8,

    /* U+0050 "P" */
    0xfd, 0xff, 0x1e, 0x3c, 0x7f, 0xff, 0x60, 0xc1, 0x80,

    /* U+0051 "Q" */
    0x7c, 0xfb, 0x1e, 0x3c, 0x78, 0xf7, 0xef, 0x7e, 0xfc,

    /* U+0052 "R" */
    0xfd, 0xff, 0x1e, 0x3c, 0x7f, 0xf7, 0x6e, 0xcd, 0x8c,

    /* U+0053 "S" */
    0x7f, 0xff, 0x6, 0xf, 0xcf, 0xc1, 0x83, 0xff, 0xf8,

    /* U+0054 "T" */
    0xff, 0xfc, 0x60, 0xc1, 0x83, 0x6, 0xc, 0x18, 0x30,

    /* U+0055 "U" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0x7c, 0xf8,

    /* U+0056 "V" */
    0x63, 0x31, 0x98, 0xce, 0xe3, 0x61, 0xb0, 0xf8, 0x38, 0x1c, 0xe, 0x0,

    /* U+0057 "W" */
    0x60, 0x6c, 0xcd, 0x99, 0xb7, 0x67, 0xfc, 0x7f, 0x8f, 0xf1, 0xde, 0x39, 0x83, 0x30,

    /* U+0058 "X" */
    0x67, 0x76, 0x3e, 0x3c, 0x1c, 0x1c, 0x3c, 0x3e, 0x76, 0x67,

    /* U+0059 "Y" */
    0xc3, 0xc3, 0xe7, 0x7e, 0x3c, 0x18, 0x18, 0x18, 0x18, 0x18,

    /* U+005A "Z" */
    0xfe, 0xfc, 0x38, 0xe1, 0x86, 0x1c, 0x70, 0xff, 0xfc,

    /* U+0061 "a" */
    0x7f, 0xff, 0x1e, 0x3c, 0xff, 0xdd, 0x80,

    /* U+0062 "b" */
    0xc1, 0x83, 0x7, 0xef, 0xf8, 0xf1, 0xe3, 0xff, 0xf8,

    /* U+0063 "c" */
    0x7f, 0xff, 0x6, 0xc, 0x1f, 0xdf, 0x80,

    /* U+0064 "d" */
    0x6, 0xc, 0x1b, 0xff, 0xf8, 0xf1, 0xe3, 0xfe, 0xfc,

    /* U+0065 "e" */
    0x7d, 0xff, 0x1f, 0xff, 0xdf, 0xdf, 0x80,

    /* U+0066 "f" */
    0x3b, 0xd9, 0xff, 0xb1, 0x8c, 0x63, 0x0,

    /* U+0067 "g" */
    0x7f, 0xff, 0x1e, 0x3f, 0xef, 0xc1, 0xff, 0x7c,

    /* U+0068 "h" */
    0xc1, 0x83, 0x7, 0xef, 0xf8, 0xf1, 0xe3, 0xc7, 0x8c,

    /* U+0069 "i" */
    0xf3, 0xff, 0xf0,

    /* U+006B "k" */
    0xc1, 0x83, 0x6, 0x6d, 0xdb, 0x3c, 0x6c, 0xdd, 0x98,

    /* U+006C "l" */
    0xdb, 0x6d, 0xb6, 0xec,

    /* U+006D "m" */
    0x7f, 0xbf, 0xfc, 0xcf, 0x33, 0xcc, 0xf3, 0x3c, 0xcc,

    /* U+006E "n" */
    0x7d, 0xff, 0x1e, 0x3c, 0x78, 0xf1, 0x80,

    /* U+006F "o" */
    0x7d, 0xff, 0x1e, 0x3c, 0x7f, 0xdf, 0x0,

    /* U+0070 "p" */
    0xfd, 0xff, 0x1e, 0x3c, 0x7f, 0xff, 0x60, 0xc0,

    /* U+0071 "q" */
    0x7f, 0xff, 0x1e, 0x3c, 0x7f, 0xdf, 0x83, 0x6,

    /* U+0072 "r" */
    0xdf, 0xfd, 0x8c, 0x63, 0x0,

    /* U+0073 "s" */
    0x7f, 0xff, 0x7, 0xe7, 0xff, 0xff, 0x0,

    /* U+0074 "t" */
    0x67, 0xfe, 0xc6, 0x31, 0xe7,

    /* U+0075 "u" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x7f, 0xdf, 0x0,

    /* U+0076 "v" */
    0x66, 0x66, 0x76, 0x3c, 0x3c, 0x3c, 0x18,

    /* U+0077 "w" */
    0x60, 0xdb, 0xb6, 0xed, 0xff, 0x3b, 0x8e, 0xe3, 0xb8,

    /* U+0078 "x" */
    0x66, 0x7e, 0x3c, 0x18, 0x3c, 0x7e, 0x66,

    /* U+0079 "y" */
    0xc7, 0x8f, 0x1f, 0xf7, 0xe0, 0xc1, 0xff, 0x7c,

    /* U+007A "z" */
    0xfe, 0xfc, 0x71, 0xc7, 0x1f, 0xff, 0x80};

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
    {.bitmap_index = 0, .adv_w = 100, .box_w = 4, .box_h = 2, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 1, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 10, .adv_w = 84, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 15, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 24, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 33, .adv_w = 127, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 42, .adv_w = 127, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 51, .adv_w = 127, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 60, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 69, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 78, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 87, .adv_w = 60, .box_w = 2, .box_h = 6, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 89, .adv_w = 147, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 101, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 110, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 119, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 128, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 137, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 146, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 155, .adv_w = 127, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 164, .adv_w = 80, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 169, .adv_w = 127, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 178, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 187, .adv_w = 159, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 199, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 208, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 217, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 226, .adv_w = 135, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 235, .adv_w = 130, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 244, .adv_w = 127, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 253, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 262, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 271, .adv_w = 144, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 283, .adv_w = 187, .box_w = 11, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 297, .adv_w = 135, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 307, .adv_w = 130, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 317, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 326, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 333, .adv_w = 121, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 342, .adv_w = 122, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 349, .adv_w = 122, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 358, .adv_w = 123, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 365, .adv_w = 95, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 372, .adv_w = 121, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 380, .adv_w = 121, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 389, .adv_w = 49, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 392, .adv_w = 122, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 401, .adv_w = 73, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 405, .adv_w = 169, .box_w = 10, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 414, .adv_w = 121, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 421, .adv_w = 121, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 428, .adv_w = 121, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 436, .adv_w = 121, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 444, .adv_w = 85, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 449, .adv_w = 121, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 456, .adv_w = 93, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 461, .adv_w = 122, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 468, .adv_w = 129, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 475, .adv_w = 174, .box_w = 10, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 484, .adv_w = 127, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 491, .adv_w = 131, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 499, .adv_w = 122, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0}};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_0[] = {
    0,  0,  0,  1,  2,  3,  4,  5,  6, 7,  8,  9,  10, 11, 0,  0,  0,  0,  0,  0,  12,
    13, 14, 15, 16, 17, 18, 19, 20, 0, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
    33, 34, 35, 36, 0,  0,  0,  0,  0, 0,  37, 38, 39, 40, 41, 42, 43, 44, 45};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] = {{.range_start = 45,
                                                .range_length = 61,
                                                .glyph_id_start = 1,
                                                .unicode_list = NULL,
                                                .glyph_id_ofs_list = glyph_id_ofs_list_0,
                                                .list_length = 61,
                                                .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL},
                                               {.range_start = 107,
                                                .range_length = 16,
                                                .glyph_id_start = 47,
                                                .unicode_list = NULL,
                                                .glyph_id_ofs_list = NULL,
                                                .list_length = 0,
                                                .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY}};

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
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};

extern const lv_font_t lv_font_montserrat_14;

/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t font_14_zqk = {
#else
lv_font_t font_14_zqk = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt, /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt, /*Function pointer to get glyph's bitmap*/
    .line_height = 12,                              /*The maximum line height required by the font*/
    .base_line = 2, /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc, /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = &lv_font_montserrat_14,
#endif
    .user_data = NULL,
};

#endif /*#if FONT_14_ZQK*/
