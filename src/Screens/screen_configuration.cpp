#include "screen_configuration.hpp"
#include "StateMachine.hpp"
#include "screen_manager.hpp"

screen_configuration::screen_configuration(int screen_id)
    : screen_menu(screen_id)
{
};

screen_configuration::~screen_configuration() 
{   
};

void screen_configuration::updateScreenAction(int c) 
{

};

// ====================================================================

void action_open_configuration(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_out_clock; Event: %d\r\n", ev);

    StateMachine::changeState(StatesID::configuration_state);
}

void action_open_settings(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_power_on; Event: %d\r\n", ev);

    StateMachine::changeState(StatesID::configuration_state);
}

void action_open_pid(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_power_on; Event: %d\r\n", ev);

    StateMachine::changeState(StatesID::configuration_state);
}

void action_open_temps_datchiks(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_confirm_clock; Event: %d\r\n", ev);
    printf("Clock is set\r\n");

    StateMachine::changeState(StatesID::configuration_state);
}

void action_open_calibration(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_confirm_clock; Event: %d\r\n", ev);
    printf("Clock is set\r\n");

    StateMachine::changeState(StatesID::configuration_state);
}

void action_open_real_datchiks_value(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_confirm_clock; Event: %d\r\n", ev);
    printf("Clock is set\r\n");

    StateMachine::changeState(StatesID::configuration_state);
}

void action_open_modbus_parameters(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_confirm_clock; Event: %d\r\n", ev);
    printf("Clock is set\r\n");

    StateMachine::changeState(StatesID::configuration_state);
}

void action_out_configuration(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_confirm_clock; Event: %d\r\n", ev);
    printf("Clock is set\r\n");

    StateMachine::changeState(StatesID::menu);
}