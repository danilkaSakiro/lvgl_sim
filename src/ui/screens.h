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
    lv_obj_t *wi_fi_setting;
    lv_obj_t *set_temp;
    lv_obj_t *real_temperature;
    lv_obj_t *button1;
    lv_obj_t *obj0;
    lv_obj_t *button2;
    lv_obj_t *obj1;
    lv_obj_t *tool;
    lv_obj_t *fan_tools;
    lv_obj_t *obj2;
    lv_obj_t *set_temperature;
    lv_obj_t *obj3;
    lv_obj_t *tim;
    lv_obj_t *start_timer;
    lv_obj_t *mod;
    lv_obj_t *real_temp;
    lv_obj_t *conf;
    lv_obj_t *obj4;
    lv_obj_t *set_temp_from_timer;
    lv_obj_t *fan_mode_from_timer;
    lv_obj_t *time;
    lv_obj_t *set_temp_1;
    lv_obj_t *temperature_1;
    lv_obj_t *button1_1;
    lv_obj_t *obj5;
    lv_obj_t *button2_1;
    lv_obj_t *obj6;
    lv_obj_t *tool_1;
    lv_obj_t *fan_tools_1;
    lv_obj_t *obj7;
    lv_obj_t *obj8;
    lv_obj_t *tim_1;
    lv_obj_t *time_1;
    lv_obj_t *mod_1;
    lv_obj_t *real_temp_1;
    lv_obj_t *conf_1;
    lv_obj_t *obj9;
    lv_obj_t *set_temp_from_timer_1;
    lv_obj_t *fan_mode_from_timer_1;
    lv_obj_t *wi_fi_settings;
    lv_obj_t *wi_fi;
    lv_obj_t *brightness_settings;
    lv_obj_t *obj10;
    lv_obj_t *sound_settings;
    lv_obj_t *obj11;
    lv_obj_t *language_settings;
    lv_obj_t *language;
    lv_obj_t *window_settings;
    lv_obj_t *window;
    lv_obj_t *aboba_settings;
    lv_obj_t *aboba;
    lv_obj_t *button5_1;
    lv_obj_t *obj12;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_BLANK = 1,
    SCREEN_ID_MAIN = 2,
    SCREEN_ID_SECOND = 3,
    SCREEN_ID_TOOLS = 4,
    SCREEN_ID_WI_FI_SETTING = 5,
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

void create_screen_wi_fi_setting();
void delete_screen_wi_fi_setting();
void tick_screen_wi_fi_setting();

void create_screen_by_id(enum ScreensEnum screenId);
void delete_screen_by_id(enum ScreensEnum screenId);
void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/