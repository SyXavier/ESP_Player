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
#include <SdFat.h>

//FAT32
static File32 dir;
static File32 file;
static const char *TAG = "SD Card";

void sdcard_init()
{
	pinMode(SD_CS, OUTPUT);
	digitalWrite(SD_CS, HIGH);

	SPI.begin(SD_SCK, SD_MISO, SD_MOSI);
	SPI.setFrequency(1000000);

	if (!SD.begin(SD_CS, SD_SCK_MHZ(16)))
		ESP_LOGE(TAG, "SD Initialize failed");
}

uint64_t sdcard_size()
{
	return SD.cardSize();
}

uint64_t sdcard_used_bytes()
{
	return SD.usedBytes();
}

uint64_t sdcard_file_read(
	char *root, 
	std::vector<String> &filePool)
{
	if (!dir.open(root)) {
		ESP_LOGE(TAG, "Can't open %s\n", root);
		return 0;
	}

	char fn[256];
	while (file.openNext(&dir, O_RDONLY)) {
		if (file.isDir()) {
			file.close();
			continue;  
		}

		file.getName(fn, sizeof(fn));
		String str = fn;
		str.toLowerCase();
		if (
			!(str.endsWith(".mp3") ||
			str.endsWith(".m4a") ||
			str.endsWith(".aac") ||
			str.endsWith(".wav") ||
	  		str.endsWith(".flac"))) {
			file.close();
			continue;
		}

		filePool.push_back(fn);
		file.close();
	}
	dir.close();
	
	return filePool.size();
}

char *sdcard_type()
{
	csd_t m_csd;
	
	switch (SD.card()->type()) {
		
		case SD_CARD_TYPE_SD1:
			return "SD1";
		
		case SD_CARD_TYPE_SD2:
			return "SD2";
			
		case SD_CARD_TYPE_SDHC:
			if (sdCardCapacity(&m_csd) < 70000000)
				return "SDHC";
			else
				return "SDXC";

		default:
			return "UNKNOWN";
	}
}


