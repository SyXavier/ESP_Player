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
#ifndef _AUDIO_PROCESS_H_
#define _AUDIO_PROCESS_H_

#include "HAL.h"

class AudioProcess {
public:	
	~AudioProcess();
	void play(String name);
	void play();
	void next();
	void prev();
	void printFilePool();
	
	static AudioProcess& getInstance() 
	{
		static AudioProcess instance;
		return instance;
	}
	
	uint32_t getAudioFileDuration();
	uint32_t getAudioCurrentTime();
	uint8_t getAudioVolume();
	int8_t getGainLowPass();
	int8_t getGainBandPass();
	int8_t getGainHighPass();
	void setAudioVolume(uint8_t vol);
	void setGainLowPass(int8_t bass);
	void setGainBandPass(int8_t alto);
	void setGainHighPass(int8_t treble);
	String getCurrName();
	bool getPlayState();
	bool getIsNewPlay();
	
private:
	AudioProcess();
	void setDefaults();
	static void audioTask(void *args);
	static inline void audioManager(AudioProcess *ap);
	int64_t getFilePoolIndex(String filename);

public:	
	//播放状态
	typedef enum {
		PAUSE,
		PLAY
	} Play_state_t;

	//播放模式
	typedef enum {
		SEQUENCE,
		LOOP,
		RANDOM
	} Play_mode_t;

	//播放音量
	typedef enum {
		MUTE,
		MID,
		MAX
	} Play_vol_t;

	//音频文件信息
	typedef struct {
		String    			a_name;				//歌曲名字
		uint32_t  			a_sample_rate;		//歌曲采样率
		uint32_t  			a_duration;			//歌曲时长
		uint8_t   			a_bits_per_sample;	//歌曲码率
		uint8_t   			a_channels;			//歌曲声道数
	} AudioFile_Info;

	//播放器信息
	struct {
		Play_state_t 		state;				//当前播放状态
		Play_mode_t 		mode;				//当前播放模式
		Play_vol_t 			vol;				//当前音量状态
		bool				isNewPlay;			//播放新歌曲标志

		AudioFile_Info 		audiofile;			//音频文件信息
		uint8_t				volume;				//当前播放音量大小
		String				prevName;			//上一首歌曲名

		int8_t				gainLowPass;		//低通
		int8_t				gainBandPass;		//带通
		int8_t				gainHighPass;		//高通
	} Player_Info;

	std::vector<String> filePool;				//SD卡根目录中所有的歌曲名
	
private:
	bool isChange; 								//播放新歌曲
};

#endif
