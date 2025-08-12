#pragma once
#include "screen_main.hpp"
#include "screen_temp.hpp"
#include "screen_confirm_temp.hpp"
#include "screen_fan.hpp"
#include "screen_confirm_fan.hpp"
#include "screen_tool.hpp"
#include "actions.h"

class screen_manager
{
public:
    screen_manager() {};
    ~screen_manager() {};

    static void init();
    static void changeToScreen(enum ScreensEnum screenId);
    static screen_base * screen_pt() {return current_screen;}

    static uint32_t getMY_EVENT() {return MY_EVENT;}

private:
    static lv_obj_t *getScreenObj(enum ScreensEnum screenId);
    static screen_base* current_screen;

    friend void action_screen(lv_event_t * e);

    static void changeToScreen_event(lv_event_t * e);

    static uint32_t MY_EVENT;
};