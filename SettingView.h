#ifndef __SETTING_VIEW_H
#define __SETTING_VIEW_H

#include "Page.h"

namespace Page
{
	class SettingView
	{
		public:
			void Create(lv_obj_t* root);

		public:
			typedef struct {
				lv_obj_t *label;
				lv_obj_t *slider;
			} item_t;

			struct
			{
				lv_obj_t *topInfo;

				item_t volume;
				item_t bass;
				item_t alto;
				item_t treble;

				lv_group_t *group;
			} ui;

			struct {
				lv_style_t main;
				lv_style_t indicator;
				lv_style_t knob;
				lv_style_t focus;
				lv_style_t edit;
			} style;

		private:
			void Group_Init();
			void Style_Init();
			void TopInfo_Init(lv_obj_t *par);
			void Item_Create(
				item_t *item,
				lv_obj_t *par,
				const char *info,
				lv_coord_t y_ofs,
				int start,
				int end,
				int value
			);
	};
}

#endif // !__VIEW_H
