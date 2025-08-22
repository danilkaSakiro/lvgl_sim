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
extern void action_thems_tool(lv_event_t * e);
extern void action_visual_tool(lv_event_t * e);
extern void action_get_fan_mode(lv_event_t * e);
extern void action_change_temp(lv_event_t * e);
extern void action_nochange_temp(lv_event_t * e);
extern void action_cancel_temperature_change(lv_event_t * e);
extern void action_change_fan(lv_event_t * e);
extern void action_nochange_fan(lv_event_t * e);
extern void action_cancel_fan_change(lv_event_t * e);
extern void action_go_to_timer(lv_event_t * e);
extern void action_out_clock(lv_event_t * e);
extern void action_inc_clock_tool(lv_event_t * e);
extern void action_dec_clock_tool(lv_event_t * e);
extern void action_confirm_clock(lv_event_t * e);
extern void action_out_timer_tool(lv_event_t * e);
extern void action_back_timer(lv_event_t * e);
extern void action_change_timer_mode_up(lv_event_t * e);
extern void action_change_timer_mode_down(lv_event_t * e);
extern void action_confirm_timer_mode(lv_event_t * e);
extern void action_power_off_with_timer(lv_event_t * e);
extern void action_set_temp_with_timer(lv_event_t * e);
extern void action_set_fan_mode_with_timer(lv_event_t * e);
extern void action_go_to_menu_with_timer(lv_event_t * e);
extern void action_go_to_timer_with_timer(lv_event_t * e);
extern void action_open_configuration(lv_event_t * e);
extern void action_open_settings(lv_event_t * e);
extern void action_open_pid(lv_event_t * e);
extern void action_open_temps_datchiks(lv_event_t * e);
extern void action_open_calibration(lv_event_t * e);
extern void action_open_real_datchiks_value(lv_event_t * e);
extern void action_open_modbus_parameters(lv_event_t * e);
extern void action_out_configuration(lv_event_t * e);
extern void action_out_grafik(lv_event_t * e);
extern void action_write_1(lv_event_t * e);
extern void action_write_2(lv_event_t * e);
extern void action_write_3(lv_event_t * e);
extern void action_write_4(lv_event_t * e);
extern void action_write_5(lv_event_t * e);
extern void action_write_6(lv_event_t * e);
extern void action_backspace(lv_event_t * e);
extern void action_write_7(lv_event_t * e);
extern void action_write_8(lv_event_t * e);
extern void action_write_9(lv_event_t * e);
extern void action_write_0(lv_event_t * e);
extern void action_write_underline(lv_event_t * e);
extern void action_enter_password(lv_event_t * e);
extern void action_select_mon(lv_event_t * e);
extern void action_select_tue(lv_event_t * e);
extern void action_select_wed(lv_event_t * e);
extern void action_select_thu(lv_event_t * e);
extern void action_select_fri(lv_event_t * e);
extern void action_select_sat(lv_event_t * e);
extern void action_select_sun(lv_event_t * e);
extern void action_select_onetime(lv_event_t * e);
extern void action_change_theme(lv_event_t * e);
extern void action_nochange_theme(lv_event_t * e);
extern void action_out_dispetcher(lv_event_t * e);
extern void action_out_setting(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/