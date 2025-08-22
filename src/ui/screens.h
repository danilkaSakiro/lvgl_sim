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
    lv_obj_t *on_state_confirm_temp;
    lv_obj_t *on_state_change_fan;
    lv_obj_t *on_state_confirm_fan;
    lv_obj_t *tools;
    lv_obj_t *clock_menu;
    lv_obj_t *timer_menu;
    lv_obj_t *timer_parametr_menu;
    lv_obj_t *on_state_mainscreen_with_timer;
    lv_obj_t *setting_menu;
    lv_obj_t *configuration_menu;
    lv_obj_t *grafik_menu;
    lv_obj_t *dispetcher_menu;
    lv_obj_t *themes_menu;
    lv_obj_t *visual_menu;
    lv_obj_t *pasword_menu;
    lv_obj_t *button_tool;
    lv_obj_t *button_power;
    lv_obj_t *main_temp;
    lv_obj_t *time_main;
    lv_obj_t *button_temp;
    lv_obj_t *button_fan;
    lv_obj_t *humadity;
    lv_obj_t *get_humadity;
    lv_obj_t *get_co2;
    lv_obj_t *pm2_5;
    lv_obj_t *get_pm25;
    lv_obj_t *get_visual;
    lv_obj_t *co2;
    lv_obj_t *main_real_temp;
    lv_obj_t *timer;
    lv_obj_t *back_temp;
    lv_obj_t *set_temperature_value;
    lv_obj_t *time_temp;
    lv_obj_t *inc_temp;
    lv_obj_t *dec_temp;
    lv_obj_t *real_temp_value;
    lv_obj_t *button_conf_temp;
    lv_obj_t *button_cancel_temp;
    lv_obj_t *nochange_temp;
    lv_obj_t *change_temp;
    lv_obj_t *back_fan;
    lv_obj_t *set_fan_mode;
    lv_obj_t *time_main_2;
    lv_obj_t *inc_fan;
    lv_obj_t *dec_fan;
    lv_obj_t *obj0;
    lv_obj_t *real_fan_mode;
    lv_obj_t *real_fan;
    lv_obj_t *set_fan;
    lv_obj_t *button_conf_rpm;
    lv_obj_t *button_cancel_fan;
    lv_obj_t *nochange_fan;
    lv_obj_t *change_fan;
    lv_obj_t *clock_settings;
    lv_obj_t *obj1;
    lv_obj_t *timer_settings;
    lv_obj_t *obj2;
    lv_obj_t *configuration_settings;
    lv_obj_t *obj3;
    lv_obj_t *tool_settings;
    lv_obj_t *obj4;
    lv_obj_t *grafik_settings;
    lv_obj_t *obj5;
    lv_obj_t *dispetcher_settings;
    lv_obj_t *obj6;
    lv_obj_t *theme_settings;
    lv_obj_t *obj7;
    lv_obj_t *visual_settings;
    lv_obj_t *obj8;
    lv_obj_t *button_back;
    lv_obj_t *date;
    lv_obj_t *obj9;
    lv_obj_t *out_clock;
    lv_obj_t *time;
    lv_obj_t *obj10;
    lv_obj_t *obj11;
    lv_obj_t *button_conf_time;
    lv_obj_t *obj12;
    lv_obj_t *obj13;
    lv_obj_t *obj14;
    lv_obj_t *obj15;
    lv_obj_t *obj16;
    lv_obj_t *obj17;
    lv_obj_t *obj18;
    lv_obj_t *obj19;
    lv_obj_t *obj20;
    lv_obj_t *obj21;
    lv_obj_t *out_timer;
    lv_obj_t *obj22;
    lv_obj_t *out_parametr_timer;
    lv_obj_t *up;
    lv_obj_t *down;
    lv_obj_t *confirm_timer_parametrs;
    lv_obj_t *time_start_timer;
    lv_obj_t *temp_start_timer;
    lv_obj_t *timer_mode1;
    lv_obj_t *timer_mode2;
    lv_obj_t *timer_mode3;
    lv_obj_t *timer_mode4;
    lv_obj_t *timer_mode2_time;
    lv_obj_t *timer_mode2_temp;
    lv_obj_t *timer_mode2_fan_mode;
    lv_obj_t *timer_mode3_time;
    lv_obj_t *timer_mode3_temp;
    lv_obj_t *timer_mode3_fan_mode;
    lv_obj_t *timer_mode4_time;
    lv_obj_t *timer_mode4_temp;
    lv_obj_t *timer_mode4_fan_mode;
    lv_obj_t *obj23;
    lv_obj_t *timer_mode1_time;
    lv_obj_t *timer_mode1_temp;
    lv_obj_t *timer_mode1_fan_mode;
    lv_obj_t *button_tool_with_timer;
    lv_obj_t *button_power_with_timer;
    lv_obj_t *main_temp_with_timer;
    lv_obj_t *time_main_with_timer;
    lv_obj_t *button_temp_with_timer;
    lv_obj_t *button_fan_with_timer;
    lv_obj_t *humadity_with_timer;
    lv_obj_t *get_humadity_with_timer;
    lv_obj_t *get_co2_with_timer;
    lv_obj_t *pm2_5_with_timer;
    lv_obj_t *get_pm25_with_timer;
    lv_obj_t *get_visual_with_timer;
    lv_obj_t *co2_with_timer;
    lv_obj_t *main_real_temp_with_timer;
    lv_obj_t *start_timer;
    lv_obj_t *temp_timer;
    lv_obj_t *fan_timer;
    lv_obj_t *timer_with_timer;
    lv_obj_t *obj24;
    lv_obj_t *out_configuration;
    lv_obj_t *configuration;
    lv_obj_t *settings;
    lv_obj_t *pid_regulator;
    lv_obj_t *temps_datchik;
    lv_obj_t *calibration;
    lv_obj_t *real_datchik_value;
    lv_obj_t *modbus;
    lv_obj_t *obj25;
    lv_obj_t *out_grafik;
    lv_obj_t *obj26;
    lv_obj_t *obj27;
    lv_obj_t *obj28;
    lv_obj_t *target_temp_grafik;
    lv_obj_t *onroom_temp_grafik;
    lv_obj_t *real_temp_grafik;
    lv_obj_t *out_dispetcher;
    lv_obj_t *change_theme;
    lv_obj_t *nochange_theme;
    lv_obj_t *backspace;
    lv_obj_t *get_password;
    lv_obj_t *n1;
    lv_obj_t *n2;
    lv_obj_t *n3;
    lv_obj_t *n4;
    lv_obj_t *n5;
    lv_obj_t *n6;
    lv_obj_t *n7;
    lv_obj_t *n8;
    lv_obj_t *n9;
    lv_obj_t *n0;
    lv_obj_t *_;
    lv_obj_t *confirm_pass;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_BLANK = 1,
    SCREEN_ID_OFF_STATE = 2,
    SCREEN_ID_ON_STATE_MAINSCREEN = 3,
    SCREEN_ID_ON_STATE_CHANGE_TEMP = 4,
    SCREEN_ID_ON_STATE_CONFIRM_TEMP = 5,
    SCREEN_ID_ON_STATE_CHANGE_FAN = 6,
    SCREEN_ID_ON_STATE_CONFIRM_FAN = 7,
    SCREEN_ID_TOOLS = 8,
    SCREEN_ID_CLOCK_MENU = 9,
    SCREEN_ID_TIMER_MENU = 10,
    SCREEN_ID_TIMER_PARAMETR_MENU = 11,
    SCREEN_ID_ON_STATE_MAINSCREEN_WITH_TIMER = 12,
    SCREEN_ID_SETTING_MENU = 13,
    SCREEN_ID_CONFIGURATION_MENU = 14,
    SCREEN_ID_GRAFIK_MENU = 15,
    SCREEN_ID_DISPETCHER_MENU = 16,
    SCREEN_ID_THEMES_MENU = 17,
    SCREEN_ID_VISUAL_MENU = 18,
    SCREEN_ID_PASWORD_MENU = 19,
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

void create_screen_on_state_confirm_temp();
void delete_screen_on_state_confirm_temp();
void tick_screen_on_state_confirm_temp();

void create_screen_on_state_change_fan();
void delete_screen_on_state_change_fan();
void tick_screen_on_state_change_fan();

void create_screen_on_state_confirm_fan();
void delete_screen_on_state_confirm_fan();
void tick_screen_on_state_confirm_fan();

void create_screen_tools();
void delete_screen_tools();
void tick_screen_tools();

void create_screen_clock_menu();
void delete_screen_clock_menu();
void tick_screen_clock_menu();

void create_screen_timer_menu();
void delete_screen_timer_menu();
void tick_screen_timer_menu();

void create_screen_timer_parametr_menu();
void delete_screen_timer_parametr_menu();
void tick_screen_timer_parametr_menu();

void create_screen_on_state_mainscreen_with_timer();
void delete_screen_on_state_mainscreen_with_timer();
void tick_screen_on_state_mainscreen_with_timer();

void create_screen_setting_menu();
void delete_screen_setting_menu();
void tick_screen_setting_menu();

void create_screen_configuration_menu();
void delete_screen_configuration_menu();
void tick_screen_configuration_menu();

void create_screen_grafik_menu();
void delete_screen_grafik_menu();
void tick_screen_grafik_menu();

void create_screen_dispetcher_menu();
void delete_screen_dispetcher_menu();
void tick_screen_dispetcher_menu();

void create_screen_themes_menu();
void delete_screen_themes_menu();
void tick_screen_themes_menu();

void create_screen_visual_menu();
void delete_screen_visual_menu();
void tick_screen_visual_menu();

void create_screen_pasword_menu();
void delete_screen_pasword_menu();
void tick_screen_pasword_menu();

void create_screen_by_id(enum ScreensEnum screenId);
void delete_screen_by_id(enum ScreensEnum screenId);
void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/