#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *blank;
    lv_obj_t *off_state;
    lv_obj_t *on_state_mainscreen;
    lv_obj_t *on_state_change_temp;
    lv_obj_t *on_state_change_rpm;
    lv_obj_t *tools;
    lv_obj_t *clock_settings;
    lv_obj_t *timer_settings;
    lv_obj_t *sound_menu;
    lv_obj_t *language_menu;
    lv_obj_t *window_menu;
    lv_obj_t *aboba_menu;
    lv_obj_t *real_temperature_value;
    lv_obj_t *button_tool;
    lv_obj_t *button_power;
    lv_obj_t *main_temp;
    lv_obj_t *time_main;
    lv_obj_t *button_temp;
    lv_obj_t *button_fan;
    lv_obj_t *button_timer;
    lv_obj_t *humadity;
    lv_obj_t *get_humadity;
    lv_obj_t *get_co2;
    lv_obj_t *co2;
    lv_obj_t *pm2_5;
    lv_obj_t *get_pm25;
    lv_obj_t *back_temp;
    lv_obj_t *set_temperature_value;
    lv_obj_t *time_main_1;
    lv_obj_t *inc_temp;
    lv_obj_t *dec_temp;
    lv_obj_t *real_temp_value;
    lv_obj_t *button_conf_temp;
    lv_obj_t *obj0;
    lv_obj_t *back_rpm;
    lv_obj_t *set_rpm_value;
    lv_obj_t *time_main_2;
    lv_obj_t *inc_rpm;
    lv_obj_t *dec_rpm;
    lv_obj_t *real_rpm_value;
    lv_obj_t *button_conf_rpm;
    lv_obj_t *obj1;
    lv_obj_t *wi_fi_settings;
    lv_obj_t *wi_fi;
    lv_obj_t *brightness_settings;
    lv_obj_t *obj2;
    lv_obj_t *sound_settings;
    lv_obj_t *obj3;
    lv_obj_t *language_settings;
    lv_obj_t *language;
    lv_obj_t *window_settings;
    lv_obj_t *window;
    lv_obj_t *aboba_settings;
    lv_obj_t *aboba;
    lv_obj_t *button_back;
    lv_obj_t *obj4;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_BLANK = 1,
    SCREEN_ID_OFF_STATE = 2,
    SCREEN_ID_ON_STATE_MAINSCREEN = 3,
    SCREEN_ID_ON_STATE_CHANGE_TEMP = 4,
    SCREEN_ID_ON_STATE_CHANGE_RPM = 5,
    SCREEN_ID_TOOLS = 6,
    SCREEN_ID_CLOCK_SETTINGS = 7,
    SCREEN_ID_TIMER_SETTINGS = 8,
    SCREEN_ID_SOUND_MENU = 9,
    SCREEN_ID_LANGUAGE_MENU = 10,
    SCREEN_ID_WINDOW_MENU = 11,
    SCREEN_ID_ABOBA_MENU = 12,
};

void create_screen_blank();
void delete_screen_blank();
void tick_screen_blank();

void create_screen_off_state();
void delete_screen_off_state();
void tick_screen_off_state();

void create_screen_on_state_mainscreen();
void delete_screen_on_state_mainscreen();
void tick_screen_on_state_mainscreen();

void create_screen_on_state_change_temp();
void delete_screen_on_state_change_temp();
void tick_screen_on_state_change_temp();

void create_screen_on_state_change_rpm();
void delete_screen_on_state_change_rpm();
void tick_screen_on_state_change_rpm();

void create_screen_tools();
void delete_screen_tools();
void tick_screen_tools();

void create_screen_clock_settings();
void delete_screen_clock_settings();
void tick_screen_clock_settings();

void create_screen_timer_settings();
void delete_screen_timer_settings();
void tick_screen_timer_settings();

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