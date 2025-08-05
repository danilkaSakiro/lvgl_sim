#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *blank;
    lv_obj_t *main;
    lv_obj_t *second;
    lv_obj_t *tools;
    lv_obj_t *temperature;
    lv_obj_t *button1;
    lv_obj_t *button2;
    lv_obj_t *button3;
    lv_obj_t *button4;
    lv_obj_t *tool;
    lv_obj_t *fan_tools;
    lv_obj_t *arc;
    lv_obj_t *button5;
    lv_obj_t *arc_val;
    lv_obj_t *odd_even;
    lv_obj_t *wi_fi_settings;
    lv_obj_t *wi_fi;
    lv_obj_t *brightness_settings;
    lv_obj_t *sound_settings;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_BLANK = 1,
    SCREEN_ID_MAIN = 2,
    SCREEN_ID_SECOND = 3,
    SCREEN_ID_TOOLS = 4,
};

void create_screen_blank();
void delete_screen_blank();
void tick_screen_blank();

void create_screen_main();
void delete_screen_main();
void tick_screen_main();

void create_screen_second();
void delete_screen_second();
void tick_screen_second();

void create_screen_tools();
void delete_screen_tools();
void tick_screen_tools();

void create_screen_by_id(enum ScreensEnum screenId);
void delete_screen_by_id(enum ScreensEnum screenId);
void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/