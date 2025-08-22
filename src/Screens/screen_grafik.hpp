#pragma once
#include "screen_menu.hpp"
#include "ui.h"
#include "actions.h"

class screen_grafik : public screen_menu
{
public:
    screen_grafik(int screen_id);
    virtual ~screen_grafik();

protected:
    void updateScreenAction(int c) override;

private:
    friend void action_out_grafik(lv_event_t * e);

};