#include "screens_core.hpp"

#include "actions.h"
#include "stdio.h"

#include "screen_manager.hpp"

//===============================================================================

// static lv_obj_t *getScreenObj(enum ScreensEnum screenId) {
//     return ((lv_obj_t **)&objects)[screenId - 1];
// }

// void action_screen_action(lv_event_t * e)
// {
//     auto ev = lv_event_get_code(e);
//     if (ev == LV_EVENT_SCREEN_LOADED)
//     {
//         printf("screen_loaded: %d\r\n", (int)(lv_uintptr_t)lv_event_get_user_data(e));
//     }
//     else if (ev == LV_EVENT_SCREEN_UNLOADED)
//     {
//         enum ScreensEnum screenId = (enum ScreensEnum)(lv_uintptr_t)lv_event_get_user_data(e);
//         delete_screen_by_id(screenId);
//         printf("screen_unloaded: %d\r\n", (int)(lv_uintptr_t)lv_event_get_user_data(e));
//     }
// }

// void changeToScreen(enum ScreensEnum screenId) {
//     if (!getScreenObj(screenId)) {
//         create_screen_by_id(screenId);
//         if (!getScreenObj(screenId)) {
//             return;
//         }
//     }

//     loadScreen(screenId);
// }

//===============================================================================

// void action_button1_action(lv_event_t * e)
// {
//     auto ev = lv_event_get_code(e);
//     printf("action_button1_action; Event: %d\r\n", ev);

//     screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_SECOND);
// }

// void action_button2_action(lv_event_t * e)
// {
//     auto ev = lv_event_get_code(e);
//     printf("action_button2_action; Event: %d\r\n", ev);
// }

// void action_button3_action(lv_event_t * e)
// {
//     auto ev = lv_event_get_code(e);
//     printf("action_button3_action; Event: %d\r\n", ev);
// }

// void action_button4_action(lv_event_t * e)
// {
//     auto ev = lv_event_get_code(e);
//     printf("action_button4_action; Event: %d\r\n", ev);
// }

// void action_button5_action(lv_event_t * e)
// {
//     auto ev = lv_event_get_code(e);
//     printf("action_button4_action; Event: %d\r\n", ev);
//     screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_MAIN);
// }

// void action_arc_value(lv_event_t * e)
// {
//     auto ev = lv_event_get_code(e);
//     printf("action_arc_val; Event: %d\r\n", ev);
// }

//========================================================================
