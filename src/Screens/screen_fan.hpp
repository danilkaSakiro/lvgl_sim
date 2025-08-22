#pragma once
#include "screen_main.hpp"
#include "ui.h"
#include "actions.h"

class screen_fan : public screen_main
{
public:
    screen_fan(int screen_id);
    virtual ~screen_fan();

protected:
    void updateScreenAction(int c) override;

private:
    friend void action_back_to_mainscreen_from_fan(lv_event_t * e);
    friend void action_inc_fan(lv_event_t * e);
    friend void action_dec_fan(lv_event_t * e);
    friend void action_confirm_fan(lv_event_t * e);
};