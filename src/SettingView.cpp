#include "SettingView.h"
#include <stdarg.h>
#include <stdio.h>
#include "StatusBar.h"
#include "ResourcePool.h"
#include "lv_obj_ext_func.h"
#include "AudioProcess.h"

using namespace Page;

#define COLOR_ORANGE	lv_color_hex(0xff931e)
#define ITEM_HEIGHT		35
#define GET_ITEM_HEIGHT(x) (ITEM_HEIGHT * x + 10)

void SettingView::Create(lv_obj_t* root)
{
	lv_obj_remove_style_all(root);
	lv_obj_set_size(root, LV_HOR_RES, LV_VER_RES);
	lv_obj_set_style_bg_opa(root, LV_OPA_COVER, 0);
	lv_obj_set_style_bg_color(root, lv_color_black(), 0);

	Style_Init();
	TopInfo_Init(root);

	AudioProcess& audioprocess = AudioProcess::getInstance();
	Item_Create(
		&ui.volume, 
		root, 
		"音量:", 
		GET_ITEM_HEIGHT(1), 
		0, 
		16, 
		audioprocess.getAudioVolume()
	);
	
	Item_Create(
		&ui.bass, 
		root, 
		"低音:", 
		GET_ITEM_HEIGHT(2), 
		-40, 
		6,
		audioprocess.getGainLowPass()
	);
	
	Item_Create(
		&ui.alto, 
		root, 
		"中音:", 
		GET_ITEM_HEIGHT(3), 
		-40, 
		6,
		audioprocess.getGainBandPass()
	);

	Item_Create(
		&ui.treble, 
		root, 
		"高音:", 
		GET_ITEM_HEIGHT(4), 
		-40, 
		6,
		audioprocess.getGainHighPass()
	);
	
	Group_Init();
}

void SettingView::Group_Init()
{
	lv_group_t *group = lv_group_create();
	ui.group = group;
	
	lv_indev_set_group(lv_get_indev(LV_INDEV_TYPE_ENCODER), group);
    lv_group_set_wrap(group, false);
	
	lv_group_add_obj(group, ui.volume.slider);
	lv_group_add_obj(group, ui.bass.slider);
	lv_group_add_obj(group, ui.alto.slider);
	lv_group_add_obj(group, ui.treble.slider);
}

void SettingView::Style_Init()
{
	lv_style_init(&style.main);
    lv_style_set_bg_opa(&style.main, LV_OPA_COVER);
    lv_style_set_bg_color(&style.main, lv_color_white());
    lv_style_set_radius(&style.main, LV_RADIUS_CIRCLE);

    lv_style_init(&style.indicator);
    lv_style_set_bg_opa(&style.indicator, LV_OPA_COVER);
    lv_style_set_bg_color(&style.indicator, COLOR_ORANGE);
    lv_style_set_radius(&style.indicator, LV_RADIUS_CIRCLE);

    lv_style_init(&style.knob);
    lv_style_set_bg_opa(&style.knob, LV_OPA_COVER);
    lv_style_set_bg_color(&style.knob, lv_color_hex(0x444444));
    lv_style_set_radius(&style.knob, LV_RADIUS_CIRCLE);
    lv_style_set_pad_all(&style.knob, 6);

    lv_style_init(&style.focus);
    lv_style_set_bg_color(&style.focus, lv_color_hex(0x666666));

	lv_style_init(&style.edit);
	lv_style_set_bg_color(&style.edit, lv_color_hex(0x333333));
}

void SettingView::Item_Create(
	item_t *item,
	lv_obj_t *par,
	const char *info,
	lv_coord_t y_ofs,
	int start,
	int end,
	int value
)
{
	lv_obj_t *label = lv_label_create(par);
	lv_obj_align(label, LV_ALIGN_TOP_LEFT, 15, y_ofs + STATUS_BAR_HEIGHT);
	lv_obj_set_style_text_color(label, lv_color_white(), 0);
	lv_obj_set_style_text_font(label, Resource.GetFont("simhei_20"), 0);
	lv_label_set_text(label, info);
	lv_obj_clear_flag(label, LV_OBJ_FLAG_SCROLLABLE);
	item->label = label;

	lv_obj_t *slider = lv_slider_create(par);
	lv_obj_remove_style_all(slider);
	lv_obj_add_style(slider, &style.main, LV_PART_MAIN);
	lv_obj_add_style(slider, &style.indicator, LV_PART_INDICATOR);
	lv_obj_add_style(slider, &style.knob, LV_PART_KNOB);
	lv_obj_add_style(slider, &style.focus, LV_PART_KNOB | LV_STATE_FOCUSED);
	lv_obj_add_style(slider, &style.edit, LV_PART_KNOB | LV_STATE_EDITED);
	lv_obj_align(slider, LV_ALIGN_TOP_RIGHT, -15, y_ofs + STATUS_BAR_HEIGHT + 9);
	lv_slider_set_range(slider, start, end);
	lv_obj_set_width(slider, 140);
	lv_obj_set_height(slider, 5);
	lv_slider_set_value(slider, value, LV_ANIM_ON);
	item->slider = slider;
}

void SettingView::TopInfo_Init(lv_obj_t *par)
{
	lv_obj_t *label = lv_label_create(par);
	lv_obj_set_style_text_font(label, Resource.GetFont("simhei_20"), 0);
	lv_obj_set_style_text_color(label, lv_color_white(), 0);
	lv_label_set_text(label, "设置");
	lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 15 + STATUS_BAR_HEIGHT);
	ui.topInfo = label;
}
