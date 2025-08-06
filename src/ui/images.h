#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_tools40;
extern const lv_img_dsc_t img_fan_tool;
extern const lv_img_dsc_t img_frosty_tool;
extern const lv_img_dsc_t img_wi_fi;
extern const lv_img_dsc_t img_brightness;
extern const lv_img_dsc_t img_language;
extern const lv_img_dsc_t img_window;
extern const lv_img_dsc_t img_sound;
extern const lv_img_dsc_t img_state;
extern const lv_img_dsc_t img_clock;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[10];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/