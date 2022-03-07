#include "Setting.h"
#include "PageManager.h"
#include "lv_obj_ext_func.h"
#include "StatusBar.h"

using namespace Page;

Setting::Setting()
{
}

Setting::~Setting()
{
}

void Setting::onCustomAttrConfig()
{
    SetCustomLoadAnimType(PageManager::LOAD_ANIM_OVER_RIGHT);
}

void Setting::onViewLoad()
{
    View.Create(root);
    AttachEvent(root);
	AttachEvent(View.ui.volume.slider);
	AttachEvent(View.ui.bass.slider);
	AttachEvent(View.ui.alto.slider);
	AttachEvent(View.ui.treble.slider);
}

void Setting::onViewDidLoad()
{
}

void Setting::onViewWillAppear()
{
	lv_indev_set_group(lv_get_indev(LV_INDEV_TYPE_ENCODER), View.ui.group);
	StatusBar::SetStyle(StatusBar::STYLE_BLACK);
	lv_obj_fade_in(root, 300, 0);
}

void Setting::onViewDidAppear()
{
}

void Setting::onViewWillDisappear()
{
	lv_obj_fade_out(root, 300, 0);
}

void Setting::onViewDidDisappear()
{
}

void Setting::onViewDidUnload()
{
}

void Setting::AttachEvent(lv_obj_t* obj)
{
    lv_obj_set_user_data(obj, this);
    lv_obj_add_event_cb(obj, onEvent, LV_EVENT_ALL, this);
}

void Setting::onEvent(lv_event_t* event)
{	
    lv_obj_t* obj = lv_event_get_target(event);
    lv_event_code_t code = lv_event_get_code(event);
    Setting* instance = (Setting*)lv_obj_get_user_data(obj);

 	if (code == LV_EVENT_LONG_PRESSED_REPEAT) {
		instance->Manager->Pop();
	} 
	else if (code == LV_EVENT_VALUE_CHANGED) {
		//调节音量、EQ
		if (obj == instance->View.ui.volume.slider) {
			instance->audioprocess.setAudioVolume(lv_slider_get_value(obj));
		}
		else if (obj == instance->View.ui.bass.slider) {
			instance->audioprocess.setGainLowPass(lv_slider_get_value(obj));
		}
		else if (obj == instance->View.ui.alto.slider) {
			instance->audioprocess.setGainBandPass(lv_slider_get_value(obj));
		}
		else if (obj == instance->View.ui.treble.slider) {
			instance->audioprocess.setGainHighPass(lv_slider_get_value(obj));
		}
	}

    if (obj == instance->root)
    {
        if (code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LEAVE)
        {
            instance->Manager->Pop();
        }
    }
}
