#pragma once
#include "screen_base.hpp"
#include "ui.h"
#include "actions.h"

class screen_temp : public screen_base
{
public:
    screen_temp(int screen_id);
    virtual ~screen_temp();

protected:
    void updateScreenAction(int c) override;

private:
    friend void action_go_mainscreen(lv_event_t * e);
    friend void action_inc_temp(lv_event_t * e);
    friend void action_dec_temp(lv_event_t * e);
    friend void action_confirm(lv_event_t * e);
 
};