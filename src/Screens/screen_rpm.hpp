#pragma once
#include "screen_base.hpp"
#include "ui.h"
#include "actions.h"

class screen_rpm : public screen_base
{
public:
    screen_rpm(int screen_id);
    virtual ~screen_rpm();

protected:
    void updateScreenAction(int RPM) override;

private:
    friend void action_inc_rpm(lv_event_t * e);
    friend void action_dec_rpm(lv_event_t * e);

};