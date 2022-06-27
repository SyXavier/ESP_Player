#pragma once
#ifndef __PLAY_LIST_VIEW_H
#define __PLAY_LIST_VIEW_H

#include "Page.h"
#include <vector>

namespace Page
{
    class PlayListView
    {
	    public:
		    void Create(lv_obj_t* root);
			static void Group_Focus(lv_group_t *group);

		public:
		    struct
		    {
		        lv_obj_t *playList;
				std::vector<lv_obj_t *> objList;
				lv_group_t *group;
		    } ui;

		private:
		    struct
		    {
				lv_style_t button;
		    } style;

		private:
			void Group_Init();
		    void Style_Init();
		    void Style_Reset();
			void List_Add_Data();
    };
}

#endif // !__VIEW_H

