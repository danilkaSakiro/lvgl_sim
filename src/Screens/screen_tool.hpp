#pragma once
#include "screen_base.hpp"
#include "ui.h"
#include "actions.h"

class screen_tool : public screen_base
{
public:
    screen_tool(int screen_id);
    virtual ~screen_tool();

protected:
    void updateScreenAction(std::string a) override;

private:
    friend void action_brightness_action(lv_event_t * e);
    friend void action_lang_action(lv_event_t * e);
    friend void action_wi_fi_action(lv_event_t * e);
    friend void action_sound_action(lv_event_t * e);
    friend void action_go_back(lv_event_t * e);
    friend void action_window_action(lv_event_t * e);
    friend void action_aboba_action(lv_event_t * e); 
};