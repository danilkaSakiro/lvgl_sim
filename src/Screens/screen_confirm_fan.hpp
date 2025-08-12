#pragma once
#include "screen_fan.hpp"
#include "ui.h"
#include "actions.h"

class screen_confirm_fan : public screen_fan
{
public:
    screen_confirm_fan(int screen_id);
    virtual ~screen_confirm_fan();

protected:
    void updateScreenAction(int c) override;

private:
    friend void action_change_fan(lv_event_t * e);
    friend void action_nochange_fan(lv_event_t * e);
    friend void action_save_fan_change(lv_event_t * e);
 
};