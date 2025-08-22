#include "screen_manager.hpp"
#include "stdio.h"
#include "EventSystem.hpp"
#include "esp_lvgl_port.h"

extern int c;

screen_base* screen_manager::current_screen = nullptr;
uint32_t screen_manager::MY_EVENT;

void screen_manager::changeToScreen_event(lv_event_t * e)
{
    ScreensEnum screenId = (ScreensEnum)(lv_uintptr_t)lv_event_get_param(e);

    if (!getScreenObj(screenId)) 
    {
        create_screen_by_id(screenId);
        if (!getScreenObj(screenId))
        {
            return;
        }
    }

    if (current_screen != nullptr)
    {
        if (current_screen->id() == screenId)
        {
            return;
        }

        delete current_screen;
        current_screen = nullptr;
    }

    loadScreen(screenId);
}

void screen_manager::init() {
    lvgl_port_lock(0);
    MY_EVENT = lv_event_register_id();

    lv_display_add_event_cb(lv_disp_get_default(), changeToScreen_event, (lv_event_code_t)MY_EVENT, nullptr);

    lvgl_port_unlock();
}

void action_screen(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    if (ev == LV_EVENT_SCREEN_LOADED)
    {
        int scr = (int)(lv_uintptr_t)lv_event_get_user_data(e);

        switch (scr)
        {
        case SCREEN_ID_ON_STATE_MAINSCREEN:
            screen_manager::current_screen = new screen_main(SCREEN_ID_ON_STATE_MAINSCREEN);
            break;
        case SCREEN_ID_ON_STATE_CHANGE_TEMP:
            screen_manager::current_screen = new screen_temp(SCREEN_ID_ON_STATE_CHANGE_TEMP);
            break;
        case SCREEN_ID_ON_STATE_CONFIRM_TEMP:
            screen_manager::current_screen = new screen_confirm_temp(SCREEN_ID_ON_STATE_CONFIRM_TEMP);
            break;    
        case SCREEN_ID_ON_STATE_CHANGE_FAN:
            screen_manager::current_screen = new screen_fan(SCREEN_ID_ON_STATE_CHANGE_FAN);
            break; 
        case SCREEN_ID_ON_STATE_CONFIRM_FAN:
            screen_manager::current_screen = new screen_confirm_fan(SCREEN_ID_ON_STATE_CONFIRM_FAN);
            break;           
        case SCREEN_ID_TOOLS:
            screen_manager::current_screen = new screen_tool(SCREEN_ID_TOOLS);
            break;
        case SCREEN_ID_CLOCK_MENU:
            screen_manager::current_screen = new screen_tool(SCREEN_ID_CLOCK_MENU);
            break;
        case SCREEN_ID_TIMER_MENU:
            screen_manager::current_screen = new screen_tool(SCREEN_ID_TIMER_MENU);
            break;
        case SCREEN_ID_TIMER_PARAMETR_MENU:
            screen_manager::current_screen = new screen_tool(SCREEN_ID_TIMER_PARAMETR_MENU);
            break;
        case SCREEN_ID_ON_STATE_MAINSCREEN_WITH_TIMER:
            screen_manager::current_screen = new screen_tool(SCREEN_ID_ON_STATE_MAINSCREEN_WITH_TIMER);
            break;
        case SCREEN_ID_SETTING_MENU:
            screen_manager::current_screen = new screen_tool(SCREEN_ID_SETTING_MENU);
            break;
        case SCREEN_ID_CONFIGURATION_MENU:
            screen_manager::current_screen = new screen_tool(SCREEN_ID_CONFIGURATION_MENU);
            break;
        case SCREEN_ID_GRAFIK_MENU:
            screen_manager::current_screen = new screen_tool(SCREEN_ID_GRAFIK_MENU);
            break;
        case SCREEN_ID_DISPETCHER_MENU:
            screen_manager::current_screen = new screen_tool(SCREEN_ID_DISPETCHER_MENU);
            break;
        case SCREEN_ID_THEMES_MENU:
            screen_manager::current_screen = new screen_tool(SCREEN_ID_THEMES_MENU);
            break;
        case SCREEN_ID_VISUAL_MENU:
            screen_manager::current_screen = new screen_tool(SCREEN_ID_VISUAL_MENU);
            break;
        case SCREEN_ID_PASWORD_MENU:
            screen_manager::current_screen = new screen_tool(SCREEN_ID_PASWORD_MENU);
            break;
        default:
            break;
        }
        EventSystem::throwEventNoBlock(new Event_updateScreen);
    }
    else if (ev == LV_EVENT_SCREEN_UNLOADED)
    {
        delete_screen_by_id((enum ScreensEnum)(lv_uintptr_t)lv_event_get_user_data(e));
    }
}

void screen_manager::changeToScreen(enum ScreensEnum screenId) 
{
    lvgl_port_lock(0);
    lv_display_send_event(lv_disp_get_default(), (lv_event_code_t)screen_manager::getMY_EVENT(), (void*)screenId);
    lvgl_port_unlock();
}

lv_obj_t *screen_manager::getScreenObj(enum ScreensEnum screenId) 
{
    return ((lv_obj_t **)&objects)[screenId - 1];
}