/*
 * MIT License
 * Copyright (c) 2021 SyXavier
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef _MP3_VERSION_H_
#define _MP3_VERSION_H_

/* Firmware Version */
#define VERSION_FIRMWARE_NAME   "MP3 Player"
#define VERSION_SOFTWARE        "v1.0"
#define VERSION_HARDWARE        "v1.0"
#define VERSION_AUTHOR_NAME     "SyXavier"

/* Number to string macro */
#define _VERSION_NUM_TO_STR_(n) #n
#define VERSION_NUM_TO_STR(n)   _VERSION_NUM_TO_STR_(n)

/* LVGL Version */
#include <lvgl.h>
#define VERSION_LVGL            "LVGL v"\
                                VERSION_NUM_TO_STR(LVGL_VERSION_MAJOR)\
                                "."\
                                VERSION_NUM_TO_STR(LVGL_VERSION_MINOR)\
                                "."\
                                VERSION_NUM_TO_STR(LVGL_VERSION_PATCH)\
                                " "\
                                LVGL_VERSION_INFO

/* File System Version */
#include <SdFat.h>
#define SD_FAT_VERSION          2.1.0-beta
#define VERSION_FILESYSTEM      "SDFAT v" VERSION_NUM_TO_STR(SD_FAT_VERSION)

/* Compiler Version */
#if defined(__GNUC__)
#define VERSION_COMPILER        "GCC v"\
                                VERSION_NUM_TO_STR(__GNUC__)\
                                "."\
                                VERSION_NUM_TO_STR(__GNUC_MINOR__)\
                                "."\
                                VERSION_NUM_TO_STR(__GNUC_PATCHLEVEL__)
#else
#define VERSION_COMPILER        "UNKNOW"
#endif

/* Build Time */
#define VERSION_BUILD_TIME      __DATE__ "\n" __TIME__

#endif //_MP3_VERSION_H_
