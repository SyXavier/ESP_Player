#include "PlayList.h"
#include "lv_obj_ext_func.h"
#include "StatusBar.h"
#include "PageManager.h"

using namespace Page;

PlayList::PlayList()
{
}

PlayList::~PlayList()
{
}

void PlayList::onCustomAttrConfig()
{
    SetCustomLoadAnimType(PageManager::LOAD_ANIM_OVER_LEFT);
}

void PlayList::onViewLoad()
{
    View.Create(root);
    AttachEvent(root);
    for (auto item : View.ui.objList)
        AttachEvent(item);
}

void PlayList::onViewDidLoad()
{

}

void PlayList::onViewWillAppear()
{
    lv_indev_set_group(lv_get_indev(LV_INDEV_TYPE_ENCODER), View.ui.group);
    StatusBar::SetStyle(StatusBar::STYLE_BLACK);
    lv_obj_fade_in(root, 300, 0);
}

void PlayList::onViewDidAppear()
{
}

void PlayList::onViewWillDisappear()
{
    lv_obj_fade_out(root, 300, 0);
}

void PlayList::onViewDidDisappear()
{
}

void PlayList::onViewDidUnload()
{
    lv_group_del(View.ui.group);
    View.ui.objList.clear();
}

void PlayList::AttachEvent(lv_obj_t* obj)
{
    lv_obj_set_user_data(obj, this);
    lv_obj_add_event_cb(obj, onEvent, LV_EVENT_ALL, this);
}

void PlayList::onEvent(lv_event_t* event)
{
    lv_obj_t* obj = lv_event_get_target(event);
    lv_event_code_t code = lv_event_get_code(event);
    PlayList* instance = (PlayList*)lv_obj_get_user_data(obj);

    //播放指定歌曲
    if (code == LV_EVENT_SHORT_CLICKED)
    {
        if (obj != instance->root) {
            const char* str = lv_list_get_btn_text(instance->View.ui.playList, obj);
			instance->audioprocess.play(str);
        }
    }
	//返回
	else if (code == LV_EVENT_LONG_PRESSED) {
        if (lv_obj_has_state(obj, LV_STATE_FOCUSED))
        {
            instance->Manager->Pop();
        }
	}
    if (obj == instance->root)
    {
        if (code == LV_EVENT_LEAVE)
        {
            instance->Manager->Pop();
        }
    }
}
