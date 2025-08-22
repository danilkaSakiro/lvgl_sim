#pragma once
#include "screen_menu.hpp"
#include "ui.h"
#include "actions.h"

class screen_themes : public screen_menu
{
public:
    screen_themes(int screen_id);
    virtual ~screen_themes();

protected:
    void updateScreenAction(int c) override;

private:
    friend void action_change_theme(lv_event_t * e);
    friend void action_nochange_theme(lv_event_t * e);

};