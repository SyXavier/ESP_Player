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

void hal_init()
{
	Serial.begin(115200);

	//打印调试信息
	Serial.println(VERSION_FIRMWARE_NAME);
	Serial.println(VERSION_SOFTWARE);
	Serial.println(VERSION_HARDWARE);
	Serial.println(VERSION_AUTHOR_NAME);
	Serial.println(VERSION_LVGL);
	Serial.println(VERSION_FILESYSTEM);
	Serial.println(VERSION_COMPILER);
	Serial.println(VERSION_BUILD_TIME);
	
	Serial.print("\nCPU Freq:	");
	Serial.print(cpu_freq_mhz());
	Serial.println("MHz");
	Serial.print("CPU ID:	");
	Serial.print((uint32_t)(cpu_chip_id() >> 32), HEX);
	Serial.println((uint32_t)cpu_chip_id(), HEX);
	Serial.print("CPU Revision:	");
	Serial.println(cpu_revision());

	Serial.print("\nRAM Heap Size:	");
	Serial.print(ram_heap_size() / 1024.0 / 1024.0);
	Serial.println("MB");
	Serial.print("RAM Free Heap Size:	");
	Serial.print(ram_free_heap_size() / 1024.0 / 1024.0);
	Serial.println("MB");
	Serial.print("RAM Min Free Heap Size:	");
	Serial.print(ram_min_free_heap_size() / 1024.0 / 1024.0);
	Serial.println("MB");
	Serial.print("RAM Max Alloc Heap Size:	");
	Serial.print(ram_max_alloc_heap_size() / 1024.0 / 1024.0);
	Serial.println("MB");

	Serial.print("\nPSRAM Size:	");
	Serial.print(psram_size() / 1024.0 / 1024.0);
	Serial.println("MB");
	Serial.print("PSRAM Free Size:	");
	Serial.print(psram_free_size() / 1024.0 / 1024.0);
	Serial.println("MB");
	Serial.print("PSRAM Min Free Size:	");
	Serial.print(psram_min_free_size() / 1024.0 / 1024.0);
	Serial.println("MB");
	Serial.print("PSRAM Max Alloc Size:	");
	Serial.print(psram_max_alloc_size() / 1024.0 / 1024.0);
	Serial.println("MB");

	Serial.print("\nROM Size:	");
	Serial.print(rom_size() / 1024.0 / 1024.0);
	Serial.println("MB");
	Serial.print("ROM Speed:	");
	Serial.print(rom_speed());
	Serial.println("MHz");

	//初始化相关设备
	pin_detected_timer_init();
	display_init();
	encoder_init();
	sdcard_init();
	audio_init();
}


