#pragma once
#include "screen_base.hpp"
#include "ui.h"
#include "actions.h"

class screen_main : public screen_base
{
public:
    screen_main(int screen_id);
    virtual ~screen_main();

protected:
    void updateScreenAction(float c) override;

private:
    friend void action_button1_action(lv_event_t * e);
    friend void action_button2_action(lv_event_t * e);
    friend void action_button3_action(lv_event_t * e);
    friend void action_button4_action(lv_event_t * e);
    friend void action_tools_action(lv_event_t * e);
    friend void action_fan_tool_action(lv_event_t * e);

};