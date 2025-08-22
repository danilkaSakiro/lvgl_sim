#pragma once
#include "screen_menu.hpp"
#include "ui.h"
#include "actions.h"

class screen_clock : public screen_menu
{
public:
    screen_clock(int screen_id);
    virtual ~screen_clock();

protected:
    void updateScreenAction(int c) override;

private:
    friend void action_out_clock(lv_event_t * e);
    friend void action_inc_clock_tool(lv_event_t * e);
    friend void action_dec_clock_tool(lv_event_t * e);
    friend void action_confirm_clock(lv_event_t * e);

};