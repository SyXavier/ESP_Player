#pragma once
#ifndef __DIALPLATE_VIEW_H
#define __DIALPLATE_VIEW_H

#include "Page.h"
#include <lvgl.h>

namespace Page
{
    class DialplateView
    {

    public:
        typedef struct
        {
            lv_obj_t* cont;
            lv_obj_t *labelValue;
			lv_obj_t *labelUnit;
        } SubInfo_t;

    public:
        struct
        {
            struct
            {
                lv_obj_t* cont;
				lv_obj_t *labelName;
				lv_obj_t *barProgress;
				lv_obj_t *labelCurrentTime;
				lv_obj_t *labelTotalTime;
            } topInfo;

            struct
            {
                lv_obj_t* cont;
                SubInfo_t labelInfoGrp[4];
            } bottomInfo;

            struct
            {
                lv_obj_t* cont;
				lv_obj_t *btnSet;
				lv_obj_t *btnPrev;
				lv_obj_t *btnPlay;
				lv_obj_t *btnNext;		
				lv_obj_t *btnList;
            } btnCont;

            lv_anim_timeline_t* anim_timeline;
        } ui;

        void Create(lv_obj_t* root);
        void Delete();
        void AppearAnimStart(bool reverse = false);

    private:
        void TopInfo_Create(lv_obj_t* par);
        void BottomInfo_Create(lv_obj_t* par);
        void SubInfoGrp_Create(lv_obj_t* par, SubInfo_t* info, const char* unitText);
        void BtnCont_Create(lv_obj_t* par);
        lv_obj_t* Btn_Create(lv_obj_t* par, const void* img_src, lv_coord_t x_ofs);
    };
}

#endif // !__VIEW_H
