#include "screen_confirm_fan.hpp"
#include <cstdlib>
#include "screen_manager.hpp"
#include "StateMachine.hpp"

screen_confirm_fan::screen_confirm_fan(int screen_id)
    : screen_fan(screen_id)
{
};

screen_confirm_fan::~screen_confirm_fan() 
{
};

void screen_confirm_fan::updateScreenAction(int c) 
{
    char buf[32];
    snprintf(buf, sizeof(buf), "%d.0", c);
    lv_label_set_text(objects.set_temperature_value, buf);

};

// ====================================================================

void action_change_fan(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_go_mainscreen; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(1));
}

void action_nochange_fan(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_inc_temp; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(2));
}

void action_save_fan_change(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_dec_temp; Event: %d\r\n", ev);

    // EventSystem::throwEvent(new Event_btn(2));
    StateMachine::changeState(StatesID::fan_onstate);
}