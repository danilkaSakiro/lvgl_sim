#include "screen_temp.hpp"
#include <cstdlib>
#include "screen_manager.hpp"
#include "StateMachine.hpp"

screen_temp::screen_temp(int screen_id)
    : screen_main(screen_id)
{
};

screen_temp::~screen_temp() 
{
};

void screen_temp::updateScreenAction(int c) 
{
    char buf[32];
    snprintf(buf, sizeof(buf), "%d.0", c);
    lv_label_set_text(objects.set_temperature_value, buf);

};

// ====================================================================

void action_back_to_mainscreen_from_temp(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_go_mainscreen; Event: %d\r\n", ev);

    StateMachine::changeState(StatesID::main_onstate);
}

void action_inc_temp(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_inc_temp; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(1));
}

void action_dec_temp(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_dec_temp; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(2));
}

void action_confirm_temp(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_confirm; Event: %d\r\n", ev);

    StateMachine::changeState(StatesID::confirm_temp_onstate);
}
