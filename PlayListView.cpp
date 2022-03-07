#include "PlayListView.h"
#include "lv_obj_ext_func.h"
#include "ResourcePool.h"
#include "AudioProcess.h"
#include "StatusBar.h"

using namespace Page;

#define COLOR_ORANGE    lv_color_hex(0xff931e)

void PlayListView::Create(lv_obj_t* root)
{
    lv_obj_remove_style_all(root);
    lv_obj_set_size(root, LV_HOR_RES, LV_VER_RES);
    lv_obj_set_style_bg_color(root, lv_color_black(), 0);
    lv_obj_set_style_bg_opa(root, LV_OPA_COVER, 0);
	
	//创建列表
	lv_obj_t *list = lv_list_create(root);
	lv_obj_set_size(list, LV_HOR_RES, LV_VER_RES - STATUS_BAR_HEIGHT);
	lv_obj_set_pos(list, 0, STATUS_BAR_HEIGHT);
	lv_obj_set_style_bg_color(list, lv_color_black(), 0);
	lv_obj_set_style_border_color(list, lv_color_black(), 0);
	lv_obj_clear_flag(list, LV_OBJ_FLAG_SCROLLABLE);
	ui.playList = list;

	Style_Init();
    Group_Init();

	//向列表中添加歌曲
	List_Add_Data();
}

void PlayListView::Group_Init()
{
	ui.group = lv_group_create();
	Group_Focus(NULL);
	lv_group_set_focus_cb(ui.group, Group_Focus);
    lv_indev_set_group(lv_get_indev(LV_INDEV_TYPE_ENCODER), ui.group);
	lv_group_set_wrap(ui.group, false);
}

void PlayListView::Style_Init()
{
	lv_style_init(&style.button);
	lv_style_set_bg_color(&style.button, lv_color_black());
	lv_style_set_border_color(&style.button, lv_color_black());
	lv_style_set_border_width(&style.button, 0);
    lv_style_set_text_color(&style.button, lv_color_white());
	lv_style_set_radius(&style.button, 7);
}

void PlayListView::Style_Reset()
{
	lv_style_reset(&style.button);
}

void PlayListView::List_Add_Data()
{
	AudioProcess &audioprocess = AudioProcess::getInstance();
	lv_obj_t *btn = NULL;
	
	//向列表添加歌曲
	for (auto item : audioprocess.filePool) {
		btn = lv_list_add_btn(ui.playList, LV_SYMBOL_AUDIO, item.c_str());
		lv_obj_set_style_text_font(lv_obj_get_child(btn, 1), Resource.GetFont("simhei_20"), 0);
		lv_label_set_long_mode(lv_obj_get_child(btn, 1), LV_LABEL_LONG_DOT);
		lv_obj_add_style(btn, &style.button, 0);
		lv_obj_set_style_bg_color(btn, COLOR_ORANGE, LV_STATE_FOCUS_KEY);
		lv_obj_set_style_bg_color(btn, lv_color_hex(0xbbbbbb), LV_STATE_PRESSED);
		lv_group_add_obj(ui.group, btn);
		ui.objList.push_back(btn);
	}
}

void PlayListView::Group_Focus(lv_group_t* group) {
    static lv_obj_t* last = NULL;
    lv_obj_t* btn = NULL;

    if (group == NULL) {
        last = NULL;
        return;
    }
    if (last != NULL)
        lv_label_set_long_mode(lv_obj_get_child(last, 1), LV_LABEL_LONG_DOT);
    
    btn = lv_group_get_focused(group);
    last = btn;
    lv_label_set_long_mode(lv_obj_get_child(btn, 1), LV_LABEL_LONG_SCROLL_CIRCULAR);
}


