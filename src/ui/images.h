#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_tree;
extern const lv_img_dsc_t img_humadity;
extern const lv_img_dsc_t img_visual;
extern const lv_img_dsc_t img_power;
extern const lv_img_dsc_t img_temp;
extern const lv_img_dsc_t img_tool;
extern const lv_img_dsc_t img_fan;
extern const lv_img_dsc_t img_co2;
extern const lv_img_dsc_t img_timer;
extern const lv_img_dsc_t img_backtemp;
extern const lv_img_dsc_t img_dec;
extern const lv_img_dsc_t img_inc;
extern const lv_img_dsc_t img_backfan;
extern const lv_img_dsc_t img_visual_settings;
extern const lv_img_dsc_t img_clock;
extern const lv_img_dsc_t img_timer_menu;
extern const lv_img_dsc_t img_configuration;
extern const lv_img_dsc_t img_tems;
extern const lv_img_dsc_t img_dispetcher;
extern const lv_img_dsc_t img_grafik;
extern const lv_img_dsc_t img_menu_out;
extern const lv_img_dsc_t img_tool_menu;
extern const lv_img_dsc_t img_calendar;
extern const lv_img_dsc_t img_clock_out;
extern const lv_img_dsc_t img_change_time;
extern const lv_img_dsc_t img_temp_timer;
extern const lv_img_dsc_t img_fan_timer;
extern const lv_img_dsc_t img_start_timer;
extern const lv_img_dsc_t img_fann_timer;
extern const lv_img_dsc_t img_backspace;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[30];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/