#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_button1_action(lv_event_t * e);
extern void action_button2_action(lv_event_t * e);
extern void action_button3_action(lv_event_t * e);
extern void action_button4_action(lv_event_t * e);
extern void action_button5_action(lv_event_t * e);
extern void action_screen(lv_event_t * e);
extern void action_arc_value(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/