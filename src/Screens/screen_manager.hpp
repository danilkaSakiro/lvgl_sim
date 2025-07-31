#pragma once
#include "screen_main.hpp"
#include "screen_second.hpp"

#include "FreeRTOS.h"
#include "semphr.h"

class screen_manager
{
public:
    screen_manager() {};
    ~screen_manager() {};

    static void init();
    static void changeToScreen(enum ScreensEnum screenId);
    static screen_base * screen_pt() {return current_screen;}

    static void lvgl_lock();
    static void lvgl_unlock();

private:
    static lv_obj_t *getScreenObj(enum ScreensEnum screenId);
    static SemaphoreHandle_t _mux;
    static screen_base* current_screen;

    friend void action_screen(lv_event_t * e);
};