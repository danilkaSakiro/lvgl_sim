#include "screen_second.hpp"
#include "StateMachine.hpp"
#include "screen_manager.hpp"

extern void action_power_off(lv_event_t * e);

screen_second::screen_second(int screen_id)
    : screen_base(screen_id)
{
};

screen_second::~screen_second() 
{   
};

void screen_second::updateScreenAction(int a) 
{
    char buf_RPM[32];
    snprintf(buf_RPM, sizeof(buf_RPM), "%d", a);
    lv_label_set_text(objects.set_rpm_value, buf_RPM);
};

// ====================================================================

void action_button4_action(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    printf("action_button4_action; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(4));
}

void action_button5_action(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    printf("action_button5_action; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(5));
}

void action_button6_action(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    printf("action_button6_action; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(6));
}
