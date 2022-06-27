#pragma once
#ifndef __PLAY_LIST_PRESENTER_H
#define __PLAY_LIST_PRESENTER_H

#include "PlayListView.h"
#include "PageBase.h"
#include "PageManager.h"
#include "AudioProcess.h"

namespace Page
{
    class PlayList : public PageBase
    {
		public:
			PlayList();
			virtual ~PlayList();

			virtual void onCustomAttrConfig();
			virtual void onViewLoad();
			virtual void onViewDidLoad();
			virtual void onViewWillAppear();
			virtual void onViewDidAppear();
			virtual void onViewWillDisappear();
			virtual void onViewDidDisappear();
			virtual void onViewDidUnload();

		private:
			void AttachEvent(lv_obj_t* obj);
			static void onEvent(lv_event_t* event);

		private:
			PlayListView View;
			AudioProcess& audioprocess = AudioProcess::getInstance();
    };
}

#endif

