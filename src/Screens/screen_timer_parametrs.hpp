#pragma once
#include "screen_timer.hpp"
#include "ui.h"
#include "actions.h"

class screen_timer_parametrs : public screen_timer
{
public:
    screen_timer_parametrs(int screen_id);
    virtual ~screen_timer_parametrs();

protected:
    void updateScreenAction(int c) override;

private:
    friend void action_back_timer(lv_event_t * e);
    friend void action_change_timer_mode_up(lv_event_t * e);
    friend void action_change_timer_mode_down(lv_event_t * e);
    friend void action_confirm_timer_mode(lv_event_t * e);

};