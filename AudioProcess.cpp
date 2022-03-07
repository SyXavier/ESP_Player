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
#include "AudioProcess.h"
#include "esp_task_wdt.h"

AudioProcess::AudioProcess()
{
	sdcard_file_read("/", filePool);

	Player_Info.state 	 			= PLAY;
	Player_Info.mode  	 			= SEQUENCE;
	Player_Info.vol	  	 			= MID;
	Player_Info.volume 	 			= 8;
	Player_Info.isNewPlay			= false;
	
	Player_Info.gainLowPass 		= 0;
	Player_Info.gainBandPass 		= 0;
	Player_Info.gainHighPass 		= 0;
	
	Player_Info.audiofile.a_name	= filePool.empty()
									? ""
									: filePool.front();
	Player_Info.prevName 			= "";

	isChange = false;
	setDefaults();
	audio.setVolume(Player_Info.volume);
	esp_task_wdt_init(3, false);
  	esp_task_wdt_add(xTaskGetIdleTaskHandleForCPU(0));
  	xTaskCreatePinnedToCore(
  		audioTask, 
  		"audio task", 
  		4096, 
  		(void *)this, 
  		1, 
  		NULL, 
  		0
  	);
}

AudioProcess::~AudioProcess()
{
	filePool.clear();
}

void AudioProcess::setDefaults()
{
	Player_Info.audiofile.a_sample_rate 	= 44100;
	Player_Info.audiofile.a_duration 		= 0;
	Player_Info.audiofile.a_bits_per_sample = 0;
	Player_Info.audiofile.a_channels		= 2;
}

inline void AudioProcess::audioManager(AudioProcess *ap)
{
	if (ap->isChange) {
		ap->isChange = false;
		audio.stopSong();
		HAL_DELAY(100);
		ap->setDefaults();
		audio.connecttoSD(ap->Player_Info.audiofile.a_name.c_str());
	}
	if (audio_is_end()) {
		audio_set_default();
		ap->next();
	}
	if (audio.isRunning() && ap->Player_Info.audiofile.a_duration == 0) {
		ap->Player_Info.audiofile.a_channels  		= audio.getChannels();
		ap->Player_Info.audiofile.a_sample_rate     = audio.getSampleRate();
		ap->Player_Info.audiofile.a_bits_per_sample = audio.getBitsPerSample();
		ap->Player_Info.audiofile.a_duration        = audio.getAudioFileDuration();
		ap->Player_Info.isNewPlay = ap->Player_Info.audiofile.a_duration ? true : false;
	}
}

void AudioProcess::play(String name)
{
	Player_Info.audiofile.a_name = name;
	play();
}

void AudioProcess::play() 
{
	if (Player_Info.audiofile.a_name == "")
		return;
	if (Player_Info.audiofile.a_name != Player_Info.prevName) {
		Player_Info.prevName = Player_Info.audiofile.a_name;
		Player_Info.state = PAUSE;
		audio.setVolume(Player_Info.volume);
		isChange = true;
		return;
	}
	if (Player_Info.state == PLAY) {
		Player_Info.state = PAUSE;
		audio.setVolume(Player_Info.volume);
	} 
	else {
		Player_Info.state = PLAY;
		audio.setVolume(0);
	}
	audio.pauseResume();
}

void AudioProcess::next()
{
	int32_t index = getFilePoolIndex(Player_Info.audiofile.a_name);
	if (index == -1)
		return;
	play(filePool[++index >= filePool.size() ? 0 : index]);
}

void AudioProcess::prev()
{
	int32_t index = getFilePoolIndex(Player_Info.audiofile.a_name);
	if (index == -1)
		return;
	play(filePool[--index < 0 ? filePool.size() - 1 : index]);
}

void AudioProcess::audioTask(void *args)
{
	AudioProcess *ap = (AudioProcess *)args;
	
	while (true) {
		audioManager(ap);
	    audio.loop();
	    esp_task_wdt_reset();
	    HAL_DELAY(1);
  	}
	vTaskDelete(NULL);
}

void AudioProcess::printFilePool()
{
	for (auto item : filePool)
		Serial.println(item);
}

uint32_t AudioProcess::getAudioFileDuration()
{
	return Player_Info.audiofile.a_duration;
}

uint32_t AudioProcess::getAudioCurrentTime()
{
	return audio.getAudioCurrentTime();
}

uint8_t AudioProcess::getAudioVolume()
{
	return Player_Info.volume;
}

int8_t AudioProcess::getGainLowPass()
{
	return Player_Info.gainLowPass;
}

int8_t AudioProcess::getGainBandPass()
{
	return Player_Info.gainBandPass;
}

int8_t AudioProcess::getGainHighPass()
{
	return Player_Info.gainHighPass;
}

String AudioProcess::getCurrName()
{
	return Player_Info.audiofile.a_name.substring(
		0,
		Player_Info.audiofile.a_name.lastIndexOf('.')
	);
}

bool AudioProcess::getPlayState()
{
	return Player_Info.state == PAUSE;
}

int64_t AudioProcess::getFilePoolIndex(String filename)
{
	int64_t index = -1;
	
	auto item = std::find(filePool.begin(), filePool.end(), filename);
	if (item == filePool.end())
		goto End;
	index = item - filePool.begin();
End:
	return index;
}

bool AudioProcess::getIsNewPlay()
{
	if (Player_Info.isNewPlay) {
		Player_Info.isNewPlay = false;
		return true;
	}
	return false;
}

void AudioProcess::setAudioVolume(uint8_t vol)
{
	Player_Info.volume = vol;
	audio.setVolume(Player_Info.volume);
}

void AudioProcess::setGainLowPass(int8_t bass)
{
	Player_Info.gainLowPass = bass;
	audio.setTone(
		Player_Info.gainLowPass, 
		Player_Info.gainBandPass,
		Player_Info.gainHighPass
	);
}

void AudioProcess::setGainBandPass(int8_t alto)
{
	Player_Info.gainBandPass = alto;
	audio.setTone(
		Player_Info.gainLowPass, 
		Player_Info.gainBandPass,
		Player_Info.gainHighPass
	);
}

void AudioProcess::setGainHighPass(int8_t treble)
{
	Player_Info.gainHighPass = treble;
	audio.setTone(
		Player_Info.gainLowPass, 
		Player_Info.gainBandPass,
		Player_Info.gainHighPass
	);
}


