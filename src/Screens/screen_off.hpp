#pragma once
#include "screen_base.hpp"
#include "ui.h"
#include "actions.h"

class screen_off : public screen_base
{
public:
    screen_off(int screen_id);
    virtual ~screen_off();

protected:
    void updateScreenAction(float c) override;

private:
    friend void action_power_on(lv_event_t * e);
    
};