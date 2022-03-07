#include "ResourcePool.h"

/* Global resource manager */
ResourcePool Resource;

extern "C" {
#define IMPORT_FONT(name) \
do{\
    LV_FONT_DECLARE(font_##name)\
    Resource.Font_.AddResource(#name, (void*)&font_##name);\
}while(0)
	
#define IMPORT_IMG(name) \
do{\
    LV_IMG_DECLARE(img_src_##name)\
    Resource.Image_.AddResource(#name, (void*)&img_src_##name);\
}while (0)

    static void Resource_Init()
    {
        /* Import Fonts */
		IMPORT_FONT(simhei_14);
		IMPORT_FONT(simhei_20);

        /* Import Images */
		IMPORT_IMG(logo);
		IMPORT_IMG(mini_logo);
		IMPORT_IMG(battery);
		IMPORT_IMG(sd_card);
    }

} /* extern "C" */

void ResourcePool::Init()
{
    Font_.SetDefault((void*)&lv_font_montserrat_12);
    Resource_Init();
}
