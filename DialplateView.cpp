﻿#include "DialplateView.h"
#include <stdarg.h>
#include <stdio.h>
#include "lv_anim_timeline_wrapper.h"
#include "lv_obj_ext_func.h"
#include "ResourcePool.h"

using namespace Page;

void DialplateView::Create(lv_obj_t* root)
{
    lv_obj_remove_style_all(root);
    lv_obj_set_size(root, LV_HOR_RES, LV_VER_RES);
    BottomInfo_Create(root);
    TopInfo_Create(root);
    BtnCont_Create(root);
    ui.anim_timeline = lv_anim_timeline_create();

#define ANIM_DEF(start_time, obj, attr, start, end) \
     {start_time, obj, LV_ANIM_EXEC(attr), start, end, 500, lv_anim_path_ease_out, true}

#define ANIM_OPA_DEF(start_time, obj) \
     ANIM_DEF(start_time, obj, opa_scale, LV_OPA_TRANSP, LV_OPA_COVER)

    lv_coord_t y_tar_top = lv_obj_get_y(ui.topInfo.cont);
    lv_coord_t y_tar_bottom = lv_obj_get_y(ui.bottomInfo.cont);
    lv_coord_t h_tar_btn = lv_obj_get_height(ui.btnCont.btnPlay);

    lv_anim_timeline_wrapper_t wrapper[] =
    {
        ANIM_DEF(0, ui.topInfo.cont, y, -lv_obj_get_height(ui.topInfo.cont), y_tar_top),
        ANIM_DEF(200, ui.bottomInfo.cont, y, -lv_obj_get_height(ui.bottomInfo.cont), y_tar_bottom),
        ANIM_OPA_DEF(200, ui.bottomInfo.cont),
        ANIM_DEF(500, ui.btnCont.btnSet,  height, 0, h_tar_btn),
        ANIM_DEF(600, ui.btnCont.btnPrev, height, 0, h_tar_btn),
        ANIM_DEF(700, ui.btnCont.btnPlay, height, 0, h_tar_btn),
        ANIM_DEF(800, ui.btnCont.btnNext, height, 0, h_tar_btn),
        ANIM_DEF(900, ui.btnCont.btnList, height, 0, h_tar_btn),
        LV_ANIM_TIMELINE_WRAPPER_END
    };
    lv_anim_timeline_add_wrapper(ui.anim_timeline, wrapper);
}

void DialplateView::Delete()
{
    if (ui.anim_timeline)
    {
        lv_anim_timeline_del(ui.anim_timeline);
        ui.anim_timeline = nullptr;
    }
}

void DialplateView::TopInfo_Create(lv_obj_t* par)
{
    lv_obj_t* cont = lv_obj_create(par);
    lv_obj_remove_style_all(cont);
    lv_obj_set_size(cont, LV_HOR_RES, 142);
    lv_obj_set_style_bg_opa(cont, LV_OPA_COVER, 0); //LV_PART_MAIN
    lv_obj_set_style_bg_color(cont, lv_color_hex(0x333333), 0); //LV_PART_MAIN
    lv_obj_set_style_radius(cont, 27, 0);
    lv_obj_set_y(cont, -36);
    ui.topInfo.cont = cont;

	//歌曲名
    lv_obj_t* label = lv_label_create(cont);
    lv_obj_set_style_text_color(label, lv_color_white(), 0);
    lv_obj_set_width(label, 140);
    lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_style_text_font(label, Resource.GetFont("simhei_20"), 0);
    lv_label_set_text(label, " ");
	lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 80);
	ui.topInfo.labelName = label;

	//进度条
	lv_obj_t *bar = lv_bar_create(cont);
    lv_obj_set_style_bg_opa(bar, LV_OPA_COVER, 0);
    lv_obj_set_style_bg_color(bar, lv_color_white(), 0);
    lv_obj_set_style_bg_color(bar, lv_color_hex(0xff931e), LV_PART_INDICATOR);
	lv_bar_set_range(bar, 0, 10 * 60);
	lv_bar_set_value(bar, 0, LV_ANIM_ON); 
	lv_obj_set_width(bar, 140);
	lv_obj_set_height(bar, 5);
	lv_obj_align_to(bar, ui.topInfo.labelName, LV_ALIGN_BOTTOM_MID, 0, 25);
	ui.topInfo.barProgress = bar;

	//当前时长
	label = lv_label_create(cont);
	lv_obj_set_style_text_color(label, lv_color_white(), 0);
	lv_obj_set_width(label, 30);
	lv_obj_clear_flag(label, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(label, ui.topInfo.barProgress, LV_ALIGN_BOTTOM_LEFT, -35, 6);
	lv_obj_set_style_text_font(label, &lv_font_montserrat_12, 0);
	lv_label_set_text(label, "0:00");
	ui.topInfo.labelCurrentTime = label;

	//总时长
	label = lv_label_create(cont);
	lv_obj_set_style_text_color(label, lv_color_white(), 0);
	lv_obj_set_width(label, 30);
	lv_obj_clear_flag(label, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_align_to(label, ui.topInfo.barProgress, LV_ALIGN_BOTTOM_RIGHT, 38, 6);
	lv_obj_set_style_text_font(label, &lv_font_montserrat_12, 0);
	lv_label_set_text(label, "0:00");
	ui.topInfo.labelTotalTime = label;
}

void DialplateView::BottomInfo_Create(lv_obj_t* par)
{
    lv_obj_t* cont = lv_obj_create(par);
    lv_obj_remove_style_all(cont);
    lv_obj_set_style_bg_color(cont, lv_color_black(), 0);
	lv_obj_set_size(cont, LV_HOR_RES, 90);
    lv_obj_align(cont, LV_ALIGN_TOP_MID, 0, 106);

    lv_obj_set_flex_flow(cont, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(
        cont,
        LV_FLEX_ALIGN_SPACE_EVENLY,
        LV_FLEX_ALIGN_CENTER,
        LV_FLEX_ALIGN_CENTER
    );
    ui.bottomInfo.cont = cont;

    const char* unitText[4] =
    {
        "音量",
        "低音",
        "中音",
        "高音"
    };
    for (int i = 0; i < ARRAY_SIZE(ui.bottomInfo.labelInfoGrp); i++)
    {
        SubInfoGrp_Create(
            cont,
            &(ui.bottomInfo.labelInfoGrp[i]),
            unitText[i]
        );
    }
}

void DialplateView::SubInfoGrp_Create(lv_obj_t* par, SubInfo_t* info, const char* unitText)
{
    lv_obj_t* cont = lv_obj_create(par);
    lv_obj_remove_style_all(cont);
    lv_obj_set_size(cont, 93, 39);

    lv_obj_set_flex_flow(cont, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(
        cont,
        LV_FLEX_ALIGN_SPACE_AROUND,
        LV_FLEX_ALIGN_CENTER,
        LV_FLEX_ALIGN_CENTER
    );

    lv_obj_t* label = lv_label_create(cont);
    lv_obj_set_style_text_color(label, lv_color_white(), 0);
    info->labelValue = label;

    label = lv_label_create(cont);
    lv_obj_set_style_text_font(label, Resource.GetFont("simhei_14"), 0);
	lv_obj_set_style_text_color(label, lv_color_hex(0xb3b3b3), 0);
    lv_label_set_text(label, unitText);
    info->labelUnit = label;
    info->cont = cont;
}

void DialplateView::BtnCont_Create(lv_obj_t* par)
{
    lv_obj_t* cont = lv_obj_create(par);
    lv_obj_remove_style_all(cont);
    lv_obj_set_size(cont, LV_HOR_RES, 40);
    lv_obj_align_to(cont, ui.bottomInfo.cont, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    ui.btnCont.cont = cont;

	ui.btnCont.btnSet  = Btn_Create(cont, LV_SYMBOL_SETTINGS, -92);
	ui.btnCont.btnPrev = Btn_Create(cont, LV_SYMBOL_PREV, -46);
	ui.btnCont.btnPlay = Btn_Create(cont, LV_SYMBOL_PLAY, 0);
	ui.btnCont.btnNext = Btn_Create(cont, LV_SYMBOL_NEXT, 46);
	ui.btnCont.btnList = Btn_Create(cont, LV_SYMBOL_LIST, 92);
}

lv_obj_t* DialplateView::Btn_Create(lv_obj_t* par, const void* img_src, lv_coord_t x_ofs)
{
    lv_obj_t* obj = lv_obj_create(par);
    lv_obj_remove_style_all(obj);
    lv_obj_set_size(obj, 40, 31);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_align(obj, LV_ALIGN_CENTER, x_ofs, 0);
    lv_obj_set_style_bg_img_src(obj, img_src, 0);

    lv_obj_set_style_bg_opa(obj, LV_OPA_COVER, 0);
    lv_obj_set_style_width(obj, 45, LV_STATE_PRESSED);
    lv_obj_set_style_height(obj, 25, LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0x666666), 0);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xbbbbbb), LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff931e), LV_STATE_FOCUSED);
    lv_obj_set_style_radius(obj, 9, 0); //LV_PART_MAIN

    static lv_style_transition_dsc_t tran;
    static const lv_style_prop_t prop[] = { LV_STYLE_WIDTH, LV_STYLE_HEIGHT, LV_STYLE_PROP_INV };

    lv_style_transition_dsc_init(
        &tran,
        prop,
        lv_anim_path_ease_out,
        200,
        0,
        nullptr
    );
    lv_obj_set_style_transition(obj, &tran, LV_STATE_PRESSED);
    lv_obj_set_style_transition(obj, &tran, LV_STATE_FOCUSED);
    lv_obj_update_layout(obj);
    return obj;
}

void DialplateView::AppearAnimStart(bool reverse)
{
    lv_anim_timeline_set_reverse(ui.anim_timeline, reverse);
    lv_anim_timeline_start(ui.anim_timeline);
}
