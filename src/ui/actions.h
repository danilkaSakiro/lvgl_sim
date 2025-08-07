#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_button1_action(lv_event_t * e);
extern void action_button2_action(lv_event_t * e);
extern void action_button4_action(lv_event_t * e);
extern void action_button5_action(lv_event_t * e);
extern void action_screen(lv_event_t * e);
extern void action_tools_action(lv_event_t * e);
extern void action_fan_tool_action(lv_event_t * e);
extern void action_wi_fi_action(lv_event_t * e);
extern void action_brightness_action(lv_event_t * e);
extern void action_sound_action(lv_event_t * e);
extern void action_lang_action(lv_event_t * e);
extern void action_window_action(lv_event_t * e);
extern void action_aboba_action(lv_event_t * e);
extern void action_button6_action(lv_event_t * e);
extern void action_power_on(lv_event_t * e);
extern void action_power_off(lv_event_t * e);
extern void action_go_back(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/