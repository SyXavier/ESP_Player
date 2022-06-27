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
#include "Pin_Detected.h"

static std::vector <Pin_Info *> detectedPool;
static const char *TAG = "Pin Detected"; //检测引脚库标签

Pin_Info *pin_init(uint8_t pin, void (*_callback)(void *), void *args)
{
	Pin_Info *p = NULL;

	//在PSRAM中分配内存
	p = (Pin_Info *)ps_calloc(1, sizeof(Pin_Info));
	if (p == NULL) {
		ESP_LOGE(TAG, "pin_init() p == NULL");
		return NULL;  
	}

	p->pin            = pin;
	p->buf            = 0xFF;
	p->state          = false;
	p->_callback      = _callback;
	p->args           = args;

	return p;
}

bool pin_add_in_detected(Pin_Info *obj)
{
	if (obj == NULL)
		return false;

	detectedPool.push_back(obj);
	return true;
}

void pin_detected_timer_init()
{
	static esp_timer_create_args_t pin_timer;
	static esp_timer_handle_t pin_timer_handle;

	pin_timer.callback = _irq_pin_detected;
	pin_timer.arg      = NULL;
	pin_timer.name     = "pin_detected_timer";

	esp_err_t err = esp_timer_create(&pin_timer, &pin_timer_handle);
	if (err != ESP_OK) {
		ESP_LOGE(TAG, "pin_detected_timer_init() timer create error!");
		return;
	}

	err = esp_timer_start_periodic(pin_timer_handle, MS_DELAY(TIMER));
	if (err != ESP_OK)
		ESP_LOGE(TAG, "pin_detected_timer_init() timer start error!");
}

static void _irq_pin_detected(void *param)
{
	for (auto item : detectedPool) {
		//检测引脚
		item->buf = (item->buf << 1) | digitalRead(item->pin);
		if (item->buf == 0x00)
			item->state = true;
		else if (item->buf == 0xFF)
			item->state = false;
		//执行回调函数
		if (item->_callback != NULL)
			item->_callback(item->args);
	}
}

void free_pin_detected()
{
	//释放内存
	for (auto item : detectedPool)
		free(item);
	detectedPool.clear();
}

