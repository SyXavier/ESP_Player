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

static Pin_Info *encoder_btn;
static int32_t   encoder_cnt;

void encoder_init()
{
	pinMode(ENC_CLK, INPUT);
	pinMode(ENC_DT,  INPUT);
	pinMode(ENC_BTN, INPUT);

	attachInterrupt(digitalPinToInterrupt(ENC_CLK), _irq_encoder, CHANGE);
	encoder_btn = pin_init(ENC_BTN, NULL, NULL);
	pin_add_in_detected(encoder_btn);

	static lv_indev_drv_t encoder_driver;
	
	lv_indev_drv_init(&encoder_driver);
	encoder_driver.type = LV_INDEV_TYPE_ENCODER;
	encoder_driver.read_cb = encoder_read_callback;
	lv_indev_drv_register(&encoder_driver);
}

int32_t encoder_get_diff()
{
	int32_t step = encoder_cnt;
	encoder_cnt = 0;
	return step;
}

bool encoder_get_is_push()
{
	return encoder_btn->state;
}

static void _irq_encoder()
{
	static bool	encoder_is_first_flag = true;
	static bool	encoder_flag;

	if (encoder_is_first_flag == true && digitalRead(ENC_CLK) == LOW) {
		encoder_flag = false;
		if (digitalRead(ENC_DT) == HIGH)
			encoder_flag = true;
		encoder_is_first_flag = false;
	}
	if (encoder_is_first_flag == false && digitalRead(ENC_CLK) == HIGH) {
		if (digitalRead(ENC_DT) == LOW && encoder_flag == true)
			//顺时针
			++encoder_cnt;
		if (digitalRead(ENC_DT) == HIGH && encoder_flag == false)
			//逆时针
			--encoder_cnt;
		encoder_is_first_flag = true;
	}
}

static void encoder_read_callback(
	lv_indev_drv_t *indev_driver, 
	lv_indev_data_t *data)
{
	data->enc_diff = encoder_get_diff();
	data->state    = encoder_get_is_push() 
				   ? LV_INDEV_STATE_PR
				   : LV_INDEV_STATE_REL;
}


