#ifndef __SETTING_PRESENTER_H
#define __SETTING_PRESENTER_H

#include "SettingView.h"
#include "PageManager.h"
#include "AudioProcess.h"

namespace Page
{
	class Setting : public PageBase
	{
		public:
			Setting();
			virtual ~Setting();

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
			SettingView View;
			AudioProcess& audioprocess = AudioProcess::getInstance();
	};
}

#endif
