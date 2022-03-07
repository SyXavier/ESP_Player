/*
 * MIT License
 * Copyright (c) 2021 _VIFEXTech, SyXavier
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
#include "StatusBar.h"
#include "lv_obj_ext_func.h"
#include "ResourcePool.h"

#define BATT_USAGE_HEIGHT (lv_obj_get_style_height(ui.battery.img, 0) - 6)
#define BATT_USAGE_WIDTH  (lv_obj_get_style_width(ui.battery.img, 0) - 4)

struct
{
    lv_obj_t* cont;
	lv_obj_t* imgLogo;
    lv_obj_t* imgSD;
    lv_obj_t* labelClock;

    struct
    {
        lv_obj_t* img;
        lv_obj_t* objUsage;
        lv_obj_t* label;
    } battery;
} ui;

static void StatusBar_Update(lv_timer_t* timer)
{
}

static lv_obj_t* StatusBar_Create(lv_obj_t* par)
{
    lv_obj_t* cont = lv_obj_create(par);
    lv_obj_remove_style_all(cont);

    lv_obj_set_size(cont, LV_HOR_RES, STATUS_BAR_HEIGHT);
    lv_obj_set_y(cont, -STATUS_BAR_HEIGHT);
	
    /* style1 */
    lv_obj_set_style_bg_opa(cont, LV_OPA_TRANSP, LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cont, lv_color_hex(0x333333), LV_STATE_DEFAULT);
	
    /* style2 */
    lv_obj_set_style_bg_opa(cont, LV_OPA_60, LV_STATE_USER_1);
	lv_obj_set_style_bg_color(cont, lv_color_black(), LV_STATE_USER_1);
    lv_obj_set_style_shadow_color(cont, lv_color_black(), LV_STATE_USER_1);
    lv_obj_set_style_shadow_width(cont, 10, LV_STATE_USER_1);

    static lv_style_transition_dsc_t tran;
    static const lv_style_prop_t prop[] =
    {
        LV_STYLE_BG_COLOR,
        LV_STYLE_OPA,
        LV_STYLE_PROP_INV
    };
    lv_style_transition_dsc_init(
        &tran,
        prop,
        lv_anim_path_ease_out,
        200,
        0,
        nullptr
    );

    lv_obj_set_style_transition(cont, &tran, LV_STATE_USER_1);
    ui.cont = cont;

    static lv_style_t style;
	
    lv_style_init(&style);
    lv_style_set_text_color(&style, lv_color_white());
    lv_style_set_text_font(&style, Resource.GetFont("simhei_14"));
	
	/* logo */
    lv_obj_t* img = lv_img_create(cont);
    lv_img_set_src(img, Resource.GetImage("mini_logo"));
    lv_obj_align(img, LV_ALIGN_LEFT_MID, 5, 0);
    ui.imgLogo = img;

    /* sd card */
    img = lv_img_create(cont);
    lv_img_set_src(img, Resource.GetImage("sd_card"));
    lv_obj_align(img, LV_ALIGN_LEFT_MID, 50, -1);
    lv_obj_add_flag(img, LV_OBJ_FLAG_HIDDEN);
    ui.imgSD = img;

    /* clock */
    lv_obj_t *label = lv_label_create(cont);
    lv_obj_add_style(label, &style, 0);
    lv_label_set_text(label, "00:00");
    lv_obj_center(label);
    ui.labelClock = label;

    /* battery */
    img = lv_img_create(cont);
    lv_img_set_src(img, Resource.GetImage("battery"));
    lv_obj_align(img, LV_ALIGN_RIGHT_MID, -35, 0);
    lv_img_t* img_ext = (lv_img_t*)img;
    lv_obj_set_size(img, img_ext->w, img_ext->h);
    ui.battery.img = img;

    lv_obj_t* obj = lv_obj_create(img);
    lv_obj_remove_style_all(obj);
    lv_obj_set_style_bg_color(obj, lv_color_white(), 0);
    lv_obj_set_style_bg_opa(obj, LV_OPA_COVER, 0);
    lv_obj_set_style_opa(obj, LV_OPA_COVER, 0);
    lv_obj_set_size(obj, BATT_USAGE_WIDTH, BATT_USAGE_HEIGHT);
    lv_obj_align(obj, LV_ALIGN_BOTTOM_MID, 0, -2);
    ui.battery.objUsage = obj;

    label = lv_label_create(cont);
    lv_obj_add_style(label, &style, 0);
    lv_obj_align_to(label, ui.battery.img, LV_ALIGN_OUT_RIGHT_MID, 3, 0);
    lv_label_set_text(label, "100%");
    ui.battery.label = label;

	StatusBar::SetStyle(StatusBar::STYLE_TRANSP);

    lv_timer_t* timer = lv_timer_create(StatusBar_Update, 1000, nullptr);
    lv_timer_ready(timer);

    return ui.cont;
}

void StatusBar::SetStyle(Style_t style)
{
    lv_obj_t* cont = ui.cont;
    if (style == STYLE_TRANSP)
    {
        lv_obj_add_state(cont, LV_STATE_DEFAULT);
        lv_obj_clear_state(cont, LV_STATE_USER_1);
    }
    else if (style == STYLE_BLACK)
    {
        lv_obj_add_state(cont, LV_STATE_USER_1);
    }
    else
    {
        return;
    }
}

void StatusBar::Init(lv_obj_t* par)
{
    StatusBar_Create(par);
}

void StatusBar::Appear(bool en)
{
    int32_t start = -STATUS_BAR_HEIGHT;
    int32_t end = 0;

    if (!en)
    {
        int32_t temp = start;
        start = end;
        end = temp;
    }

    lv_anim_t a;
	
    lv_anim_init(&a);
    lv_anim_set_var(&a, ui.cont);
    lv_anim_set_values(&a, start, end);
    lv_anim_set_time(&a, 500);
    lv_anim_set_delay(&a, 1000);
    lv_anim_set_exec_cb(&a, LV_ANIM_EXEC(y));
    lv_anim_set_path_cb(&a, lv_anim_path_ease_out);
    lv_anim_set_early_apply(&a, true);
    lv_anim_start(&a);
}

