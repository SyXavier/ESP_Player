#include "Dialplate.h"
#include "lv_obj_ext_func.h"
#include "StatusBar.h"

using namespace Page;

Dialplate::Dialplate()
{
}

Dialplate::~Dialplate()
{
}

void Dialplate::onCustomAttrConfig()
{
    SetCustomLoadAnimType(PageManager::LOAD_ANIM_NONE);
}

void Dialplate::onViewLoad()
{
    View.Create(root);
    group = lv_group_create();
    lv_group_set_wrap(group, false);

	lv_group_add_obj(group, View.ui.btnCont.btnSet);
	lv_group_add_obj(group, View.ui.btnCont.btnPrev);
	lv_group_add_obj(group, View.ui.btnCont.btnPlay);
	lv_group_add_obj(group, View.ui.btnCont.btnNext);
	lv_group_add_obj(group, View.ui.btnCont.btnList);
	lv_group_focus_obj(View.ui.btnCont.btnPlay);

	AttachEvent(View.ui.btnCont.btnSet);
	AttachEvent(View.ui.btnCont.btnPrev);
	AttachEvent(View.ui.btnCont.btnPlay);
	AttachEvent(View.ui.btnCont.btnNext);
	AttachEvent(View.ui.btnCont.btnList);
}

void Dialplate::onViewDidLoad()
{
}

void Dialplate::onViewWillAppear()
{
    lv_indev_set_group(lv_get_indev(LV_INDEV_TYPE_ENCODER), group);
	StatusBar::SetStyle(StatusBar::STYLE_TRANSP);
    Update();
    View.AppearAnimStart();
}

void Dialplate::onViewDidAppear()
{
    timer = lv_timer_create(onTimerUpdate, 1000, this);
}

void Dialplate::onViewWillDisappear()
{
    lv_timer_del(timer);
}

void Dialplate::onViewDidDisappear()
{
}

void Dialplate::onViewDidUnload()
{
    View.Delete();
    lv_group_del(group);
}

void Dialplate::AttachEvent(lv_obj_t* obj)
{
    lv_obj_add_event_cb(obj, onEvent, LV_EVENT_ALL, this);
}

void Dialplate::Update()
{
	if (audioprocess.getIsNewPlay()) {
		lv_bar_set_range(
			View.ui.topInfo.barProgress, 
			0, 
			audioprocess.getAudioFileDuration()
		);
	}
	
	lv_obj_set_style_bg_img_src(
		View.ui.btnCont.btnPlay,
		audioprocess.getPlayState() 
		? LV_SYMBOL_PAUSE 
		: LV_SYMBOL_PLAY
		, 0
	);
	
	lv_label_set_text_fmt(
		View.ui.topInfo.labelTotalTime, 
		"%d:%02d", 
		audioprocess.getAudioFileDuration() / 60,
		audioprocess.getAudioFileDuration() % 60
	);
	
	lv_label_set_text(
		View.ui.topInfo.labelName, 
		audioprocess.getCurrName().c_str()
	);
	
	lv_bar_set_value(
		View.ui.topInfo.barProgress, 
		audioprocess.getAudioCurrentTime(), 
		LV_ANIM_ON
	);
	
	lv_label_set_text_fmt(
		View.ui.topInfo.labelCurrentTime, 
		"%d:%02d", 
		audioprocess.getAudioCurrentTime() / 60,
		audioprocess.getAudioCurrentTime() % 60
	);
	
    lv_label_set_text_fmt(
		View.ui.bottomInfo.labelInfoGrp[0].labelValue, 
		"%2d", 
		audioprocess.getAudioVolume()
	);
	
    lv_label_set_text_fmt(
        View.ui.bottomInfo.labelInfoGrp[1].labelValue,
        "%+2d",
        audioprocess.getGainLowPass()
    );

    lv_label_set_text_fmt(
        View.ui.bottomInfo.labelInfoGrp[2].labelValue,
        "%+2d",
        audioprocess.getGainBandPass()
    );

    lv_label_set_text_fmt(
        View.ui.bottomInfo.labelInfoGrp[3].labelValue,
        "%+2d",
        audioprocess.getGainHighPass()
    );
}

void Dialplate::onTimerUpdate(lv_timer_t* timer)
{
    Dialplate* instance = (Dialplate*)timer->user_data;
    instance->Update();
}

void Dialplate::onBtnClicked(lv_obj_t* btn)
{
	//设置
	if (btn == View.ui.btnCont.btnSet)
		Manager->Push("Setting");
	//播放/暂停
	else if (btn == View.ui.btnCont.btnPlay)
		audioprocess.play();
	//上一首
  	else if (btn == View.ui.btnCont.btnPrev)
		audioprocess.prev();
	//下一首
	else if (btn == View.ui.btnCont.btnNext)
		audioprocess.next();
	//歌曲列表
	else
		Manager->Push("PlayList");

	lv_label_set_text(
		View.ui.topInfo.labelName, 
		audioprocess.getCurrName().c_str()
	);

	lv_obj_set_style_bg_img_src(
		View.ui.btnCont.btnPlay,
		audioprocess.getPlayState() 
		? LV_SYMBOL_PAUSE 
		: LV_SYMBOL_PLAY
		, 0
	);
}

void Dialplate::onEvent(lv_event_t* event)
{
    Dialplate* instance = (Dialplate*)lv_event_get_user_data(event);
    lv_obj_t* obj = lv_event_get_target(event);
    lv_event_code_t code = lv_event_get_code(event);

    if (code == LV_EVENT_SHORT_CLICKED)
    {
        instance->onBtnClicked(obj);
    }
}
