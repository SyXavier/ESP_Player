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

Audio audio;
static bool isEnd; //音频播放结束

void audio_init()
{
	audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
	isEnd = false;
}

void audio_set_default()
{
	isEnd = false;
}

bool audio_is_end()
{
	return isEnd;
}

//音频相关信息
void audio_eof_mp3(const char *info)
{
	isEnd = true;
	Serial.print("eof_mp3     ");
	Serial.println(info);
}

void audio_info(const char *info)
{
	Serial.print("info        ");
	Serial.println(info);
}

void audio_id3data(const char *info)
{
	Serial.print("id3data     ");
	Serial.println(info);
}

void audio_showstation(const char *info)
{
	Serial.print("station     ");
	Serial.println(info);
}

void audio_showstreaminfo(const char *info)
{
	Serial.print("streaminfo  ");
	Serial.println(info);
}

void audio_showstreamtitle(const char *info)
{
	Serial.print("streamtitle ");
	Serial.println(info);
}

void audio_bitrate(const char *info)
{
	Serial.print("bitrate     ");
	Serial.println(info);
}

void audio_commercial(const char *info)
{
	Serial.print("commercial  ");
	Serial.println(info);
}

void audio_icyurl(const char *info)
{
	Serial.print("icyurl      ");
	Serial.println(info);
}

void audio_lasthost(const char *info)
{
	Serial.print("lasthost    ");
	Serial.println(info);
}

void audio_eof_speech(const char *info)
{
	Serial.print("eof_speech  ");
	Serial.println(info);
}