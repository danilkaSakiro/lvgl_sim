#pragma once
#include "screen_main.hpp"
#include "ui.h"
#include "actions.h"

class screen_temp : public screen_main
{
public:
    screen_temp(int screen_id);
    virtual ~screen_temp();

protected:
    void updateScreenAction(int c) override;

private:
    friend void action_back_to_mainscreen_from_temp(lv_event_t * e);
    friend void action_inc_temp(lv_event_t * e);
    friend void action_dec_temp(lv_event_t * e);
    friend void action_confirm_temp(lv_event_t * e);
 
};