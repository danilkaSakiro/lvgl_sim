#pragma once
#include "screen_menu.hpp"
#include "ui.h"
#include "actions.h"

class screen_configuration : public screen_menu
{
public:
    screen_configuration(int screen_id);
    virtual ~screen_configuration();

protected:
    void updateScreenAction(int c) override;

private:
    friend void action_open_configuration(lv_event_t * e);
    friend void action_open_settings(lv_event_t * e);
    friend void action_open_pid(lv_event_t * e);
    friend void action_open_temps_datchiks(lv_event_t * e);
    friend void action_open_calibration(lv_event_t * e);
    friend void action_open_real_datchiks_value(lv_event_t * e);
    friend void action_open_modbus_parameters(lv_event_t * e);
    friend void action_out_configuration(lv_event_t * e);
};