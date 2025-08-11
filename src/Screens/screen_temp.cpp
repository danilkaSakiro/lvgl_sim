#include "screen_temp.hpp"
#include <cstdlib>
#include "screen_manager.hpp"
#include "StateMachine.hpp"

screen_temp::screen_temp(int screen_id)
    : screen_base(screen_id)
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

void action_go_mainscreen(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_go_mainscreen; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(3));
}

void action_inc_temp(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_inc_temp; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(4));
}

void action_dec_temp(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_dec_temp; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(5));
}

void action_confirm(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_confirm; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(6));
}
