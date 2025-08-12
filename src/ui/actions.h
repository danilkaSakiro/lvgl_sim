#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_screen(lv_event_t * e);
extern void action_power_on(lv_event_t * e);
extern void action_power_off(lv_event_t * e);
extern void action_set_temp(lv_event_t * e);
extern void action_set_fan_mode(lv_event_t * e);
extern void action_go_to_menu(lv_event_t * e);
extern void action_back_to_mainscreen_from_temp(lv_event_t * e);
extern void action_inc_temp(lv_event_t * e);
extern void action_dec_temp(lv_event_t * e);
extern void action_confirm_temp(lv_event_t * e);
extern void action_back_to_mainscreen_from_fan(lv_event_t * e);
extern void action_inc_fan(lv_event_t * e);
extern void action_dec_fan(lv_event_t * e);
extern void action_confirm_fan(lv_event_t * e);
extern void action_menu_out(lv_event_t * e);
extern void action_time_tool(lv_event_t * e);
extern void action_timer_tool(lv_event_t * e);
extern void action_configuration_tool(lv_event_t * e);
extern void action_change_tool(lv_event_t * e);
extern void action_grafik_tool(lv_event_t * e);
extern void action_dispetcher_tool(lv_event_t * e);
extern void action_tems_tool(lv_event_t * e);
extern void action_visual_tool(lv_event_t * e);
extern void action_get_fan_mode(lv_event_t * e);
extern void action_change_temp(lv_event_t * e);
extern void action_nochange_temp(lv_event_t * e);
extern void action_save_temperature_change(lv_event_t * e);
extern void action_change_fan(lv_event_t * e);
extern void action_nochange_fan(lv_event_t * e);
extern void action_save_fan_change(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/