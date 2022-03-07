#include "StartupView.h"
#include "lv_anim_timeline_wrapper.h"
#include "lv_obj_ext_func.h"
#include "ResourcePool.h"

using namespace Page;

void StartupView::Create(lv_obj_t* root)
{
    lv_obj_remove_style_all(root);
    lv_obj_set_size(root, LV_HOR_RES, LV_VER_RES);
    lv_obj_t* cont = lv_obj_create(root);
    lv_obj_remove_style_all(cont);
    lv_obj_set_size(cont, 110, 110);
    lv_obj_center(cont);
    ui.cont = cont;

    lv_obj_t *img = lv_img_create(cont);
	lv_img_set_src(img, Resource.GetImage("logo"));
	lv_obj_center(img);
    lv_coord_t y = lv_obj_get_y(img);
    lv_obj_set_y(img, y - 10);
	ui.imgLogo = img;

	lv_obj_t *bar = lv_bar_create(cont);
    lv_obj_set_style_bg_opa(bar, LV_OPA_COVER, 0);
    lv_obj_set_style_bg_color(bar, lv_color_hex(0x2E2E2E), 0);
    lv_obj_set_style_bg_color(bar, lv_color_white(), LV_PART_INDICATOR);
    lv_bar_set_range(bar, 0, 100);
	lv_obj_set_width(bar, 110);
	lv_obj_set_height(bar, 4);
	lv_obj_center(bar);
	y = lv_obj_get_y(bar);
	lv_obj_set_y(bar, y + 60);
	ui.barProgress = bar;

    ui.anim_timeline = lv_anim_timeline_create();

#define ANIM_DEF(start_time, obj, attr, start, end, time) \
     {start_time, obj, LV_ANIM_EXEC(attr), start, end, time, lv_anim_path_ease_out, true}

    lv_anim_timeline_wrapper_t wrapper[] =
    {
        ANIM_DEF(2000, ui.barProgress, y, y + 60, y + 50, 0),
		ANIM_DEF(2500, ui.barProgress, bar_value, 0, 100, 3000),
		LV_ANIM_TIMELINE_WRAPPER_END
    };

    lv_anim_timeline_add_wrapper(ui.anim_timeline, wrapper);
}

void StartupView::Delete()
{
    if(ui.anim_timeline)
    {
        lv_anim_timeline_del(ui.anim_timeline);
        ui.anim_timeline = nullptr;
    }
}
