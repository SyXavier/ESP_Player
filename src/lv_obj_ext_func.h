﻿#pragma once
#ifndef __LV_OBJ_EXT_FUNC_H
#define __LV_OBJ_EXT_FUNC_H

#include <lvgl.h>

#define LV_ANIM_TIME_DEFAULT    400
#define LV_ANIM_EXEC(attr)      (lv_anim_exec_xcb_t)lv_obj_set_##attr

void lv_obj_set_opa_scale(lv_obj_t* obj, int16_t opa);
int16_t lv_obj_get_opa_scale(lv_obj_t* obj);
void lv_label_set_text_add(lv_obj_t* label, const char* text);
void lv_obj_set_bar_value(lv_obj_t *bar, uint32_t value);
void lv_obj_add_anim(
    lv_obj_t* obj, lv_anim_t* a,
    lv_anim_exec_xcb_t exec_cb,
    int32_t start, int32_t end,
    uint16_t time = LV_ANIM_TIME_DEFAULT,
    uint32_t delay = 0,
    lv_anim_ready_cb_t ready_cb = NULL,
    lv_anim_path_cb_t path_cb = lv_anim_path_ease_out
);
#define LV_OBJ_ADD_ANIM(obj,attr,target,time)\
do{\
    lv_obj_add_anim(\
        (obj), NULL,\
        (lv_anim_exec_xcb_t)lv_obj_set_##attr,\
        lv_obj_get_##attr(obj),\
        (target),\
        (time)\
    );\
}while(0)
#define LV_OBJ_ADD_DELAY_ANIM(obj,attr,target,delay,time)\
do{\
    lv_obj_add_anim(\
        (obj), NULL,\
        (lv_anim_exec_xcb_t)lv_obj_set_##attr,\
        lv_obj_get_##attr(obj),\
        (target),\
        (time),\
        (delay)\
    );\
}while(0)
lv_indev_t* lv_get_indev(lv_indev_type_t type);

#endif
