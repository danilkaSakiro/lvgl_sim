#pragma once
#include "screen_menu.hpp"
#include "ui.h"
#include "actions.h"

class screen_dispetcher : public screen_menu
{
public:
    screen_dispetcher(int screen_id);
    virtual ~screen_dispetcher();

protected:
    void updateScreenAction(int c) override;

private:
    friend void action_out_grafik(lv_event_t * e);

};