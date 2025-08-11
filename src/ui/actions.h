#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_inc_temp(lv_event_t * e);
extern void action_dec_temp(lv_event_t * e);
extern void action_inc_rpm(lv_event_t * e);
extern void action_dec_rpm(lv_event_t * e);
extern void action_screen(lv_event_t * e);
extern void action_menu(lv_event_t * e);
extern void action_set_temp(lv_event_t * e);
extern void action_set_fan_mode(lv_event_t * e);
extern void action_go_mainscreen(lv_event_t * e);
extern void action_wi_fi_action(lv_event_t * e);
extern void action_brightness_action(lv_event_t * e);
extern void action_sound_action(lv_event_t * e);
extern void action_lang_action(lv_event_t * e);
extern void action_window_action(lv_event_t * e);
extern void action_aboba_action(lv_event_t * e);
extern void action_power_on(lv_event_t * e);
extern void action_power_off(lv_event_t * e);
extern void action_confirm(lv_event_t * e);
extern void action_menu_out(lv_event_t * e);
extern void action_get_fan_mode(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/