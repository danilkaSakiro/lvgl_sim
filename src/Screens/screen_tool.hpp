#pragma once
#include "screen_menu.hpp"
#include "ui.h"
#include "actions.h"

class screen_tool : public screen_menu
{
public:
    screen_tool(int screen_id);
    virtual ~screen_tool();

protected:
    void updateScreenAction(std::string a) override;

private:
    friend void action_out_setting(lv_event_t * e);

};