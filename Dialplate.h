#pragma once
#ifndef __DIALPLATE_PRESENTER_H
#define __DIALPLATE_PRESENTER_H

#include "DialplateView.h"
#include "PageBase.h"
#include "PageManager.h"
#include "AudioProcess.h"

namespace Page
{
    class Dialplate : public PageBase
    {
    public:
        Dialplate();
        virtual ~Dialplate();

        virtual void onCustomAttrConfig();
        virtual void onViewLoad();
        virtual void onViewDidLoad();
        virtual void onViewWillAppear();
        virtual void onViewDidAppear();
        virtual void onViewWillDisappear();
        virtual void onViewDidDisappear();
        virtual void onViewDidUnload();

    private:
        void Update();
        void AttachEvent(lv_obj_t* obj);
        static void onTimerUpdate(lv_timer_t* timer);
        static void onEvent(lv_event_t* event);
        void onBtnClicked(lv_obj_t* btn);

    private:
        DialplateView View;
        lv_group_t* group;
        lv_timer_t* timer;
		AudioProcess& audioprocess = AudioProcess::getInstance();
    };
}

#endif
