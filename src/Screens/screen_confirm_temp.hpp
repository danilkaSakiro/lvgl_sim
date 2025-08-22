#pragma once
#include "screen_temp.hpp"
#include "ui.h"
#include "actions.h"

class screen_confirm_temp : public screen_temp
{
public:
    screen_confirm_temp(int screen_id);
    virtual ~screen_confirm_temp();

protected:
    void updateScreenAction(int c) override;

private:
    friend void action_change_temp(lv_event_t * e);
    friend void action_nochange_temp(lv_event_t * e);
    friend void action_cancel_temperature_change(lv_event_t * e);
 
};