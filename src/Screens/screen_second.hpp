#pragma once
#include "screen_base.hpp"
#include "ui.h"
#include "actions.h"

class screen_second : public screen_base
{
public:
    screen_second(SemaphoreHandle_t mux, int screen_id);
    virtual ~screen_second();

protected:
    void updateScreenAction(std::string a, int b) override;

private:
    friend void action_arc_value(lv_event_t * e);
    friend void action_button5_action(lv_event_t * e);
};