#pragma once
#include "screen_menu.hpp"
#include "ui.h"
#include "actions.h"

class screen_timer : public screen_menu
{
public:
    screen_timer(int screen_id);
    virtual ~screen_timer();

protected:
    void updateScreenAction(int c) override;

private:
    friend void action_out_timer_tool(lv_event_t * e);
    friend void action_select_mon(lv_event_t * e);
    friend void action_select_tue(lv_event_t * e);
    friend void action_select_wed(lv_event_t * e);
    friend void action_select_thu(lv_event_t * e);
    friend void action_select_fri(lv_event_t * e);
    friend void action_select_sat(lv_event_t * e);
    friend void action_select_sun(lv_event_t * e);
    friend void action_select_onetime(lv_event_t * e);

};