#include "lv_obj_ext_func.h"

void lv_obj_set_opa_scale(lv_obj_t* obj, int16_t opa)
{
    lv_obj_set_style_bg_opa(obj, (lv_opa_t)opa, LV_PART_MAIN);
}

int16_t lv_obj_get_opa_scale(lv_obj_t* obj)
{
    return lv_obj_get_style_bg_opa(obj, LV_PART_MAIN);
}

/**
  * @brief  在label后追加字符串
  * @param  label:被追加的对象
  * @param  text:追加的字符串
  * @retval 无
  */
void lv_label_set_text_add(lv_obj_t* label, const char* text)
{
    if (!label)
        return;
    lv_label_ins_text(label, strlen(lv_label_get_text(label)), text);
}

/**
  * @brief  为对象添加动画
  * @param  obj:对象地址
  * @param  a:动画控制器地址
  * @param  exec_cb:控制对象属性的函数地址
  * @param  start:动画的开始值
  * @param  end:动画的结束值
  * @param  time:动画的执行时间
  * @param  delay:动画开始前的延时时间
  * @param  ready_cb:动画结束事件回调
  * @param  path_cb:动画曲线
  * @retval 无
  */
void lv_obj_add_anim(
    lv_obj_t* obj, lv_anim_t* a,
    lv_anim_exec_xcb_t exec_cb,
    int32_t start, int32_t end,
    uint16_t time,
    uint32_t delay,
    lv_anim_ready_cb_t ready_cb,
    lv_anim_path_cb_t path_cb
)
{
    lv_anim_t anim_temp;

    if (a == NULL)
    {
        a = &anim_temp;

        //初始化动画
        lv_anim_init(a);
    }

    lv_anim_set_exec_cb(a, exec_cb); //设置控制对象属性的函数
    lv_anim_set_var(a, obj); //设置动画变量
    lv_anim_set_time(a, time); //设置动画持续时间
    lv_anim_set_values(a, start, end); //设置动画开始和结束值
    lv_anim_set_delay(a, delay); //设置动画开始前的延迟
    lv_anim_set_path_cb(a, path_cb); //设置动画曲线
    lv_anim_set_ready_cb(a, ready_cb); //设置动画结束后的回调
    lv_anim_set_start_cb(a, ready_cb); //设置动画开始的回调

    //应用动画
    lv_anim_start(a);
}

//设置bar值
void lv_obj_set_bar_value(lv_obj_t *bar, uint32_t value)
{
	lv_bar_set_value(bar, value, LV_ANIM_ON);
}

//获取输入设备类型
lv_indev_t* lv_get_indev(lv_indev_type_t type)
{
    lv_indev_t* cur_indev = NULL;

    for (;;)
    {	
        cur_indev = lv_indev_get_next(cur_indev);
        if (!cur_indev)
        {
            break;
        }
        if (cur_indev->driver->type == type)
        {
            return cur_indev;
        }
    }
    return NULL;
}
