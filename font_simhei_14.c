/*******************************************************************************
 * Size: 14 px
 * Bpp: 4
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include <lvgl.h>
#else
#include <lvgl.h>
#endif

#ifndef FONT_SIMHEI_14
#define FONT_SIMHEI_14 1
#endif

#if FONT_SIMHEI_14

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0025 "%" */
    0x0, 0x0, 0x1, 0x3, 0xd8, 0x0, 0x70, 0x94,
    0xd0, 0x61, 0xa, 0x3d, 0x8, 0x0, 0x94, 0xd4,
    0x30, 0x3, 0xd8, 0x80, 0x0, 0x0, 0x16, 0xac,
    0x10, 0x7, 0x3b, 0x76, 0x0, 0x73, 0xa5, 0x80,
    0x52, 0x2b, 0x67, 0x7, 0x0, 0xbd, 0x10, 0x0,
    0x0, 0x0,

    /* U+002B "+" */
    0x0, 0xa, 0x0, 0x0, 0x0, 0xe0, 0x0, 0x0,
    0xe, 0x0, 0xa, 0xff, 0xff, 0xf8, 0x0, 0xe,
    0x0, 0x0, 0x0, 0xe0, 0x0, 0x0, 0xe, 0x0,
    0x0,

    /* U+002D "-" */
    0xaf, 0xff, 0xff, 0x70,

    /* U+0030 "0" */
    0x1, 0xbf, 0xa0, 0x0, 0xca, 0x2b, 0x90, 0x3f,
    0x10, 0x2f, 0x6, 0xc0, 0x0, 0xe2, 0x8a, 0x0,
    0xd, 0x48, 0x90, 0x0, 0xc4, 0x7a, 0x0, 0xd,
    0x34, 0xe0, 0x0, 0xf1, 0xe, 0x60, 0x8c, 0x0,
    0x4f, 0xde, 0x30, 0x0, 0x14, 0x10, 0x0,

    /* U+0031 "1" */
    0x0, 0xd2, 0xb, 0xf2, 0xa7, 0xf2, 0x20, 0xf2,
    0x0, 0xf2, 0x0, 0xf2, 0x0, 0xf2, 0x0, 0xf2,
    0x0, 0xf2, 0x0, 0xf2,

    /* U+0032 "2" */
    0x0, 0x0, 0x0, 0x0, 0x4d, 0xfc, 0x30, 0x1f,
    0x61, 0x9d, 0x4, 0x70, 0x2, 0xf0, 0x0, 0x0,
    0x4e, 0x0, 0x0, 0xc, 0x70, 0x0, 0x6, 0xd0,
    0x0, 0x2, 0xe3, 0x0, 0x1, 0xd6, 0x0, 0x0,
    0xca, 0x0, 0x0, 0x4f, 0xff, 0xff, 0x30,

    /* U+0033 "3" */
    0x0, 0x14, 0x20, 0x0, 0x5e, 0xcf, 0x60, 0x1e,
    0x20, 0x5e, 0x1, 0x40, 0x1, 0xf0, 0x0, 0x0,
    0x9a, 0x0, 0x2, 0xfe, 0x10, 0x0, 0x2, 0xac,
    0x0, 0x0, 0x0, 0xf2, 0x49, 0x0, 0xf, 0x11,
    0xf7, 0x2a, 0xc0, 0x4, 0xdf, 0xb1, 0x0,

    /* U+0034 "4" */
    0x0, 0x0, 0xb6, 0x0, 0x0, 0x5f, 0x60, 0x0,
    0x1e, 0xd6, 0x0, 0x9, 0x9a, 0x60, 0x4, 0xe0,
    0xa6, 0x0, 0xd4, 0xa, 0x60, 0x8a, 0x0, 0xa6,
    0xd, 0xff, 0xff, 0xfb, 0x0, 0x0, 0xa6, 0x0,
    0x0, 0xa, 0x60,

    /* U+0035 "5" */
    0x9, 0xff, 0xfd, 0x0, 0xc4, 0x11, 0x0, 0xf,
    0x0, 0x0, 0x3, 0xfd, 0xfb, 0x20, 0x5c, 0x32,
    0xac, 0x0, 0x0, 0x1, 0xf1, 0x0, 0x0, 0xf,
    0x28, 0x50, 0x2, 0xf0, 0x5e, 0x44, 0xc9, 0x0,
    0x8f, 0xe8, 0x0,

    /* U+0036 "6" */
    0x0, 0x7, 0xc0, 0x0, 0x2, 0xf3, 0x0, 0x0,
    0xb8, 0x0, 0x0, 0x5f, 0x65, 0x0, 0xd, 0xd8,
    0xbd, 0x4, 0xf0, 0x0, 0xc7, 0x6b, 0x0, 0x9,
    0x95, 0xc0, 0x0, 0xb8, 0x1f, 0x71, 0x5f, 0x30,
    0x3c, 0xfe, 0x50,

    /* U+0037 "7" */
    0x6f, 0xff, 0xff, 0x70, 0x11, 0x11, 0xe3, 0x0,
    0x0, 0x6a, 0x0, 0x0, 0xe, 0x20, 0x0, 0x5,
    0xc0, 0x0, 0x0, 0xc5, 0x0, 0x0, 0x2f, 0x0,
    0x0, 0x7, 0xa0, 0x0, 0x0, 0xc6, 0x0, 0x0,
    0xf, 0x20, 0x0,

    /* U+0038 "8" */
    0x5, 0xef, 0xc2, 0x1, 0xe3, 0x18, 0xd0, 0x4b,
    0x0, 0x2f, 0x1, 0xf4, 0x19, 0xa0, 0x8, 0xff,
    0xe1, 0x3, 0xe3, 0x7, 0xd0, 0x89, 0x0, 0xd,
    0x38, 0xa0, 0x0, 0xe3, 0x5f, 0x75, 0xbe, 0x0,
    0x7d, 0xfd, 0x30,

    /* U+0039 "9" */
    0x5, 0xdf, 0xa1, 0x3, 0xf6, 0x3c, 0xd0, 0x9a,
    0x0, 0x2f, 0x2b, 0x70, 0x1, 0xf1, 0x8b, 0x0,
    0x6d, 0x1, 0xcb, 0x9f, 0x60, 0x0, 0x29, 0xe0,
    0x0, 0x0, 0xe5, 0x0, 0x0, 0x6c, 0x0, 0x0,
    0xe, 0x30, 0x0,

    /* U+003A ":" */
    0x4f, 0x14, 0x0, 0x0, 0x0, 0x14, 0x4f,

    /* U+4E2D "�? */
    0x0, 0x0, 0x5, 0xe0, 0x0, 0x0, 0x0, 0x0,
    0x5, 0xd0, 0x0, 0x0, 0x2b, 0xbb, 0xbc, 0xfb,
    0xbb, 0xb9, 0x3e, 0x22, 0x26, 0xd2, 0x22, 0x6d,
    0x3e, 0x0, 0x4, 0xd0, 0x0, 0x5d, 0x3e, 0x0,
    0x4, 0xd0, 0x0, 0x5d, 0x3e, 0x22, 0x26, 0xd2,
    0x22, 0x6d, 0x4f, 0xbb, 0xbc, 0xfb, 0xbb, 0xcd,
    0x1, 0x0, 0x4, 0xd0, 0x0, 0x1, 0x0, 0x0,
    0x4, 0xd0, 0x0, 0x0, 0x0, 0x0, 0x5, 0xd0,
    0x0, 0x0, 0x0, 0x0, 0x5, 0xe0, 0x0, 0x0,

    /* U+4F4E "�? */
    0x0, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2f, 0x10, 0x0, 0x3, 0x83, 0x0, 0x0, 0x7a,
    0x1b, 0xcd, 0xfc, 0x95, 0x0, 0x0, 0xd5, 0x1e,
    0x10, 0xe1, 0x0, 0x0, 0x4, 0xf4, 0x1e, 0x0,
    0xd1, 0x0, 0x0, 0xc, 0xf4, 0x1e, 0x0, 0xd2,
    0x0, 0x0, 0x6c, 0xc4, 0x1f, 0xdd, 0xfe, 0xde,
    0x50, 0x12, 0xc4, 0x1e, 0x0, 0x96, 0x0, 0x0,
    0x0, 0xc4, 0x1e, 0x0, 0x69, 0x0, 0x0, 0x0,
    0xc4, 0x1e, 0x6, 0x2d, 0x0, 0x0, 0x0, 0xc4,
    0x1f, 0xc7, 0xc, 0x50, 0x80, 0x0, 0xc4, 0x3f,
    0x6c, 0x24, 0xe6, 0xc0, 0x0, 0xc5, 0x3, 0x5,
    0x70, 0x7f, 0x50, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    /* U+91CF "�? */
    0x0, 0x5e, 0xaa, 0xaa, 0xaa, 0xe5, 0x0, 0x0,
    0x4e, 0xbb, 0xbb, 0xbb, 0xe5, 0x0, 0x0, 0x5b,
    0x33, 0x33, 0x33, 0xb5, 0x0, 0x0, 0x28, 0x88,
    0x88, 0x88, 0x82, 0x0, 0x3d, 0xcb, 0xbb, 0xbb,
    0xbb, 0xbc, 0xd1, 0x0, 0x37, 0x77, 0x77, 0x77,
    0x73, 0x0, 0x0, 0x6b, 0x55, 0xaa, 0x55, 0xb7,
    0x0, 0x0, 0x6e, 0xbb, 0xdd, 0xbb, 0xe7, 0x0,
    0x0, 0x5b, 0x99, 0xcc, 0x99, 0xb6, 0x0, 0x0,
    0x89, 0x99, 0xcc, 0x99, 0x97, 0x0, 0x0, 0x32,
    0x22, 0x89, 0x22, 0x22, 0x0, 0xc, 0xbb, 0xbb,
    0xdd, 0xbb, 0xbb, 0xc0,

    /* U+97F3 "�? */
    0x0, 0x0, 0x0, 0x61, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xc7, 0x0, 0x0, 0x0, 0x6, 0xed,
    0xdd, 0xee, 0xdd, 0xdd, 0x20, 0x0, 0x2, 0xa0,
    0x0, 0x1b, 0x10, 0x0, 0x0, 0x0, 0xd7, 0x0,
    0x6c, 0x0, 0x0, 0xa, 0xaa, 0xdb, 0xaa, 0xec,
    0xaa, 0xa1, 0x3, 0x22, 0x22, 0x22, 0x22, 0x22,
    0x30, 0x0, 0x1d, 0xdd, 0xdd, 0xdd, 0xd1, 0x0,
    0x0, 0x1f, 0x11, 0x11, 0x11, 0xf1, 0x0, 0x0,
    0x1f, 0xaa, 0xaa, 0xaa, 0xf1, 0x0, 0x0, 0x1f,
    0x33, 0x33, 0x33, 0xf1, 0x0, 0x0, 0x1f, 0x11,
    0x11, 0x11, 0xf1, 0x0, 0x0, 0x2f, 0xcc, 0xcc,
    0xcc, 0xf2, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0,
    0x0, 0x0,

    /* U+9AD8 "�? */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xd8, 0x0, 0x0, 0x0, 0xd, 0xcc,
    0xcc, 0xee, 0xcc, 0xcc, 0xd1, 0x1, 0x12, 0x22,
    0x22, 0x22, 0x21, 0x10, 0x0, 0xe, 0xcb, 0xbb,
    0xbc, 0xc0, 0x0, 0x0, 0xe, 0x76, 0x66, 0x68,
    0xc0, 0x0, 0x0, 0x5, 0x66, 0x66, 0x66, 0x40,
    0x0, 0x8, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xa0,
    0xa, 0x60, 0x0, 0x0, 0x0, 0x4, 0xc0, 0xa,
    0x60, 0xad, 0xcc, 0xcd, 0x4, 0xc0, 0xa, 0x60,
    0xa4, 0x0, 0x3c, 0x4, 0xc0, 0xa, 0x60, 0x8c,
    0xcc, 0xca, 0x4, 0xb0, 0xa, 0x60, 0x0, 0x0,
    0x0, 0x4d, 0x70, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 112, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 42, .adv_w = 112, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 67, .adv_w = 112, .box_w = 7, .box_h = 1, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 71, .adv_w = 112, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 110, .adv_w = 112, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 130, .adv_w = 112, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 169, .adv_w = 112, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 208, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 243, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 278, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 313, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 348, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 383, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 418, .adv_w = 112, .box_w = 2, .box_h = 7, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 425, .adv_w = 224, .box_w = 12, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 497, .adv_w = 224, .box_w = 14, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 595, .adv_w = 224, .box_w = 14, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 679, .adv_w = 224, .box_w = 14, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 777, .adv_w = 224, .box_w = 14, .box_h = 14, .ofs_x = 0, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x6, 0x8, 0xb, 0xc, 0xd, 0xe, 0xf,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x4e08, 0x4f29,
    0x91aa, 0x97ce, 0x9ab3
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 37, .range_length = 39604, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 19, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t font_simhei_14 = {
#else
lv_font_t font_simhei_14 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 14,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if FONT_SIMHEI_14*/

