#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *blank;
    lv_obj_t *power_off;
    lv_obj_t *main;
    lv_obj_t *second;
    lv_obj_t *tools;
    lv_obj_t *wi_fi_menu;
    lv_obj_t *brightness_menu;
    lv_obj_t *sound_menu;
    lv_obj_t *language_menu;
    lv_obj_t *window_menu;
    lv_obj_t *aboba_menu;
    lv_obj_t *set_temp;
    lv_obj_t *real_temperature_value;
    lv_obj_t *button1;
    lv_obj_t *button2;
    lv_obj_t *tool_main;
    lv_obj_t *fan_tools_main;
    lv_obj_t *button_power;
    lv_obj_t *set_temperature_value;
    lv_obj_t *obj0;
    lv_obj_t *tim;
    lv_obj_t *start_timer;
    lv_obj_t *mod;
    lv_obj_t *real_temp;
    lv_obj_t *set_temp_from_timer;
    lv_obj_t *fan_mode_from_timer;
    lv_obj_t *time_main;
    lv_obj_t *set_rpm;
    lv_obj_t *real_rpm_value;
    lv_obj_t *button4;
    lv_obj_t *obj1;
    lv_obj_t *button5;
    lv_obj_t *obj2;
    lv_obj_t *tool_sec;
    lv_obj_t *fan_tools_sec;
    lv_obj_t *button6;
    lv_obj_t *set_rpm_value;
    lv_obj_t *obj3;
    lv_obj_t *tim_1;
    lv_obj_t *time_1;
    lv_obj_t *mod_1;
    lv_obj_t *real_rpm;
    lv_obj_t *set_temp_from_timer_1;
    lv_obj_t *fan_mode_from_timer_1;
    lv_obj_t *time_sec;
    lv_obj_t *wi_fi_settings;
    lv_obj_t *wi_fi;
    lv_obj_t *brightness_settings;
    lv_obj_t *obj4;
    lv_obj_t *sound_settings;
    lv_obj_t *obj5;
    lv_obj_t *language_settings;
    lv_obj_t *language;
    lv_obj_t *window_settings;
    lv_obj_t *window;
    lv_obj_t *aboba_settings;
    lv_obj_t *aboba;
    lv_obj_t *button_back;
    lv_obj_t *obj6;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_BLANK = 1,
    SCREEN_ID_POWER_OFF = 2,
    SCREEN_ID_MAIN = 3,
    SCREEN_ID_SECOND = 4,
    SCREEN_ID_TOOLS = 5,
    SCREEN_ID_WI_FI_MENU = 6,
    SCREEN_ID_BRIGHTNESS_MENU = 7,
    SCREEN_ID_SOUND_MENU = 8,
    SCREEN_ID_LANGUAGE_MENU = 9,
    SCREEN_ID_WINDOW_MENU = 10,
    SCREEN_ID_ABOBA_MENU = 11,
};

void create_screen_blank();
void delete_screen_blank();
void tick_screen_blank();

void create_screen_power_off();
void delete_screen_power_off();
void tick_screen_power_off();

void create_screen_main();
void delete_screen_main();
void tick_screen_main();

void create_screen_second();
void delete_screen_second();
void tick_screen_second();

void create_screen_tools();
void delete_screen_tools();
void tick_screen_tools();

void create_screen_wi_fi_menu();
void delete_screen_wi_fi_menu();
void tick_screen_wi_fi_menu();

void create_screen_brightness_menu();
void delete_screen_brightness_menu();
void tick_screen_brightness_menu();

void create_screen_sound_menu();
void delete_screen_sound_menu();
void tick_screen_sound_menu();

void create_screen_language_menu();
void delete_screen_language_menu();
void tick_screen_language_menu();

void create_screen_window_menu();
void delete_screen_window_menu();
void tick_screen_window_menu();

void create_screen_aboba_menu();
void delete_screen_aboba_menu();
void tick_screen_aboba_menu();

void create_screen_by_id(enum ScreensEnum screenId);
void delete_screen_by_id(enum ScreensEnum screenId);
void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/