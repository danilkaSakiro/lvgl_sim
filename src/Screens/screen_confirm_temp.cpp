#include "screen_confirm_temp.hpp"
#include <cstdlib>
#include "screen_manager.hpp"
#include "StateMachine.hpp"

screen_confirm_temp::screen_confirm_temp(int screen_id)
    : screen_temp(screen_id)
{
};

screen_confirm_temp::~screen_confirm_temp() 
{
};

void screen_confirm_temp::updateScreenAction(int c) 
{
    // char buf[32];
    // snprintf(buf, sizeof(buf), "%d.0", c);
    // lv_label_set_text(objects.set_temperature_value, buf);

};

// ====================================================================

void action_change_temp(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_go_mainscreen; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(1));
}

void action_nochange_temp(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_inc_temp; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(2));
}

void action_save_temperature_change(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_dec_temp; Event: %d\r\n", ev);

    // EventSystem::throwEvent(new Event_btn(2));
    StateMachine::changeState(StatesID::temp_onstate);
}