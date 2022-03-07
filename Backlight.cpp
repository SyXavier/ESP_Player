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

static Pin_Info *backlight_btn;
static bool backlight_state;
static bool backlight_btn_state_bak;

void backlight_init()
{
	pinMode(BLK_BTN, INPUT);
  	pinMode(TFT_BLK, OUTPUT);

	backlight_state 		= false;
	backlight_btn_state_bak = false;
	
  	backlight_close();

  	backlight_btn = pin_init(BLK_BTN, backlight_callback, NULL);
  	pin_add_in_detected(backlight_btn);
}

void backlight_open()
{
	digitalWrite(TFT_BLK, HIGH);
	backlight_state = true;
}

void backlight_close()
{
	digitalWrite(TFT_BLK, LOW);
	backlight_state = false;
}

void backlight_callback(void *args)
{
	if (backlight_btn->state != backlight_btn_state_bak) {
		if (backlight_btn_state_bak)
			backlight_state ? backlight_close() 
					 		: backlight_open();
		backlight_btn_state_bak = backlight_btn->state;
	}
}

