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
#ifndef _HAL_H_
#define _HAL_H_

#include <Arduino.h>
#include "Audio.h"
#include <lvgl.h>
#include "Pin_Detected.h"
#include "MP3_Version.h"
#include <vector>

#define TFT_BLK           	32
#define BLK_BTN  			33

#define I2S_DOUT  			25
#define I2S_BCLK  			27
#define I2S_LRC   			26

#define SD_CS         		 5
#define SD_MOSI      		23
#define SD_MISO      		19
#define SD_SCK       		18

#define ENC_CLK 			39
#define ENC_DT  			34
#define ENC_BTN 			35

#define HAL_DELAY(x) vTaskDelay(pdMS_TO_TICKS(x))

extern Audio audio;

/* Hardware Abstraction Layer */
void hal_init();
void hal_restart();

/* CPU */
uint32_t cpu_freq_mhz();
uint8_t cpu_revision();
uint64_t cpu_chip_id();

/* RAM */
uint32_t ram_heap_size();
uint32_t ram_free_heap_size();
uint32_t ram_min_free_heap_size();
uint32_t ram_max_alloc_heap_size();
uint32_t psram_size();
uint32_t psram_free_size();
uint32_t psram_min_free_size();
uint32_t psram_max_alloc_size();

/* ROM */
uint32_t rom_size();
uint32_t rom_speed();

/* Display */
void display_init();
static void display_flush_callback(
	lv_disp_drv_t *disp, 
	const lv_area_t *area, 
	lv_color_t *color_p);
void display_task(void *args);

/* Backlight */
void backlight_init();
void backlight_open();
void backlight_close();
void backlight_callback(void *args);

/* Encoder */
void encoder_init();
int32_t encoder_get_diff();
bool encoder_get_is_push();
static void _irq_encoder();
static void encoder_read_callback(
	lv_indev_drv_t *indev_driver, 
	lv_indev_data_t *data);

/* SD */
void sdcard_init();
uint64_t sdcard_size();
uint64_t sdcard_used_bytes();
uint64_t sdcard_file_read(
	char *root, 
	std::vector<String> &filePool);
char *sdcard_type();

/* Audio */
void audio_init();
void audio_set_default();
bool audio_is_end();

#endif //_HAL_H_
