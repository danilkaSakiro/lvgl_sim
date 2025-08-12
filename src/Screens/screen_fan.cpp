#include "screen_fan.hpp"
#include "StateMachine.hpp"
#include "screen_manager.hpp"

screen_fan::screen_fan(int screen_id)
    : screen_main(screen_id)
{
};

screen_fan::~screen_fan() 
{   
};

void screen_fan::updateScreenAction(int c) 
{
    char buf_RPM[32];
    snprintf(buf_RPM, sizeof(buf_RPM), "%d", c);
    lv_label_set_text(objects.set_rpm_value, buf_RPM);
};

// ====================================================================
void action_back_to_mainscreen_from_fan(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_inc_rpm; Event: %d\r\n", ev);

    StateMachine::changeState(StatesID::main_onstate);
}

void action_inc_fan(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_inc_rpm; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(1));
}

void action_dec_fan(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_dec_rpm; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(2));
}

void action_confirm_fan(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_confirm; Event: %d\r\n", ev);

    StateMachine::changeState(StatesID::confirm_fan_onstate);
}