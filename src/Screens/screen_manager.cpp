#include "screen_manager.hpp"
#include "stdio.h"
#include "EventSystem.hpp"

screen_base* screen_manager::current_screen = nullptr;
SemaphoreHandle_t screen_manager::_mux = nullptr;

void action_screen(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    if (ev == LV_EVENT_SCREEN_LOADED)
    {
        int scr = (int)(lv_uintptr_t)lv_event_get_user_data(e);

        switch (scr)
        {
        case SCREEN_ID_MAIN:
            screen_manager::current_screen = new screen_main(screen_manager::_mux, SCREEN_ID_MAIN);
            break;
        case SCREEN_ID_SECOND:
            screen_manager::current_screen = new screen_second(screen_manager::_mux, SCREEN_ID_SECOND);
            break;
        
        default:
            break;
        }

        EventSystem::throwEvent(new Event_updateScreen);

        printf("screen_loaded: %d\r\n", (int)(lv_uintptr_t)lv_event_get_user_data(e));
    }
    else if (ev == LV_EVENT_SCREEN_UNLOADED)
    {
        delete_screen_by_id((enum ScreensEnum)(lv_uintptr_t)lv_event_get_user_data(e));
        printf("screen_unloaded: %d\r\n", (int)(lv_uintptr_t)lv_event_get_user_data(e));
    }
}

void screen_manager::init()
{
    if (_mux == nullptr)
        _mux = xSemaphoreCreateMutex();
}

void screen_manager::lvgl_lock()
{
    if( xSemaphoreGetMutexHolder(_mux) != xTaskGetCurrentTaskHandle() )
        xSemaphoreTake(_mux, portMAX_DELAY);
}

void screen_manager::lvgl_unlock()
{
    xSemaphoreGive(_mux);
}

void screen_manager::changeToScreen(enum ScreensEnum screenId) 
{
    printf("[screen_manager]:::changeToScreen to: %d\r\n", screenId);
    if (!getScreenObj(screenId)) 
    {
        printf("[screen_manager]:::screen not exist; Create screen: %d\r\n", screenId);
        create_screen_by_id(screenId);
        if (!getScreenObj(screenId))
        {
            printf("[screen_manager]:::Wrong screenId!: %d\r\n", screenId);
            return;
        }
    }

    if (current_screen != nullptr)
    {
        if (current_screen->id() == screenId)
        {
            printf("[screen_manager]:::screen %d allready loaded\r\n", screenId);
            return;
        }

        delete current_screen;
        current_screen = nullptr;
    }
    lvgl_lock();
    loadScreen(screenId);
    lvgl_unlock();
}

lv_obj_t *screen_manager::getScreenObj(enum ScreensEnum screenId) 
{
    return ((lv_obj_t **)&objects)[screenId - 1];
}