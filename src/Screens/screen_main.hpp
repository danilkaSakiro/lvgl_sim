#pragma once
#include "screen_base.hpp"
#include "ui.h"
#include "actions.h"

class screen_main : public screen_base
{
public:
    screen_main(int screen_id);
    virtual ~screen_main();

protected:
    void updateScreenAction(int с) override;

private:
    friend void action_power_off(lv_event_t * e);
    friend void action_set_temp(lv_event_t * e);
    friend void action_set_fan_mode(lv_event_t * e);
    friend void action_go_to_menu(lv_event_t * e);
};