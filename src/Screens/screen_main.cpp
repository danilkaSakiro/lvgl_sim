#include "screen_main.hpp"
#include <cstdlib>
#include "screen_manager.hpp"
#include "StateMachine.hpp"

screen_main::screen_main(int screen_id)
    : screen_base(screen_id)
{
};

screen_main::~screen_main() 
{
};

void screen_main::updateScreenAction(int c) 
{
    char buf[32];
    snprintf(buf, sizeof(buf), "%d", TempChanges::gettemperature());
    lv_label_set_text(objects.main_temp, buf);

};

// ====================================================================

void action_power_off(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_button1_action; Event: %d\r\n", ev);

    StateMachine::changeState(StatesID::off_state);
}

void action_set_temp(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_button2_action; Event: %d\r\n", ev);

    StateMachine::changeState(StatesID::temp_onstate);
}

void action_set_fan_mode(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_fan_tool_action; Event: %d\r\n", ev);

    StateMachine::changeState(StatesID::fan_onstate);
}

void action_go_to_menu(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_button_tool_action; Event: %d\r\n", ev);

    StateMachine::changeState(StatesID::menu);
}
