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
#include "HAL.h"
#include <TFT_eSPI.h>

#define DISPLAY_WIDTH 		240	
#define DISPLAY_HEIGHT 		240

static TFT_eSPI tft = TFT_eSPI();
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[DISPLAY_WIDTH * DISPLAY_HEIGHT / 10];

void display_init()
{
	backlight_init();
	lv_init();
	tft.begin();
	tft.setRotation(0);

	lv_disp_draw_buf_init(
		&draw_buf, 
		buf, 
		NULL, 
		DISPLAY_WIDTH * DISPLAY_HEIGHT / 10
	);

	static lv_disp_drv_t disp_drv;
	
	lv_disp_drv_init(&disp_drv);
	disp_drv.hor_res = DISPLAY_WIDTH;
	disp_drv.ver_res = DISPLAY_HEIGHT;
	disp_drv.flush_cb = display_flush_callback;
	disp_drv.draw_buf = &draw_buf;
	lv_disp_drv_register(&disp_drv);
}

static void display_flush_callback(
	lv_disp_drv_t *disp, 
	const lv_area_t *area, 
 	lv_color_t *color_p)
{
	uint32_t w = (area->x2 - area->x1 + 1);
	uint32_t h = (area->y2 - area->y1 + 1);

	tft.startWrite();
	tft.setAddrWindow(area->x1, area->y1, w, h);
	tft.pushColors((uint16_t *)&color_p->full, w * h, true);
	tft.endWrite();
	lv_disp_flush_ready(disp);
}

void display_task(void *args)
{
	while (true) {
		lv_task_handler();
		HAL_DELAY(5);
	}
	vTaskDelete(NULL);
}


