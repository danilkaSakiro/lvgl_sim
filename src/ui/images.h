#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_wi_fi;
extern const lv_img_dsc_t img_brightness;
extern const lv_img_dsc_t img_up;
extern const lv_img_dsc_t img_down;
extern const lv_img_dsc_t img_left;
extern const lv_img_dsc_t img_right;
extern const lv_img_dsc_t img_power;
extern const lv_img_dsc_t img_tools;
extern const lv_img_dsc_t img_clock;
extern const lv_img_dsc_t img_sound;
extern const lv_img_dsc_t img_language;
extern const lv_img_dsc_t img_window;
extern const lv_img_dsc_t img_tree;
extern const lv_img_dsc_t img_temp;
extern const lv_img_dsc_t img_fan;
extern const lv_img_dsc_t img_timer;
extern const lv_img_dsc_t img_humadity;
extern const lv_img_dsc_t img_co2;
extern const lv_img_dsc_t img_back;
extern const lv_img_dsc_t img_configuration;
extern const lv_img_dsc_t img_menu_tool;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[21];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/