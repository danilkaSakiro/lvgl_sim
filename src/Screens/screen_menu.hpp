#pragma once
#include "screen_base.hpp"
#include "ui.h"
#include "actions.h"

class screen_menu : public screen_base
{
public:
    screen_menu(int screen_id);
    virtual ~screen_menu();

protected:
    void updateScreenAction(std::string a) override;

private:
    friend void action_time_tool(lv_event_t * e);
    friend void action_timer_tool(lv_event_t * e);
    friend void action_configuration_tool(lv_event_t * e);
    friend void action_change_tool(lv_event_t * e);
    friend void action_grafik_tool(lv_event_t * e);
    friend void action_dispetcher_tool(lv_event_t * e); 
    friend void action_thems_tool(lv_event_t * e);
    friend void action_visual_tool(lv_event_t * e);
    friend void action_menu_out(lv_event_t * e);
};