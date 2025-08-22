#include "screen_fan.hpp"
#include <cstdlib>
#include "screen_manager.hpp"
#include "StateMachine.hpp"
#include "FanState.hpp"

screen_fan::screen_fan(int screen_id)
    : screen_main(screen_id)
{
};

screen_fan::~screen_fan() 
{   
};

void screen_fan::updateScreenAction(int c) 
{
    char buf_fan[32];
    if (FanChanges::getfan_mode_change())
    {
        snprintf(buf_fan, sizeof(buf_fan), "%d", FanChanges::getfan_mode_ch());
    }
    else
    {
        snprintf(buf_fan, sizeof(buf_fan), "%d", FanChanges::getfan_mode());
    }
    lv_label_set_text(objects.set_fan_mode, buf_fan);

};

// ====================================================================
void action_back_to_mainscreen_from_fan(lv_event_t * e)
{
    auto ev = lv_event_get_code(e); 
    StateMachine::changeState(StatesID::main_onstate);
}

void action_inc_fan(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    EventSystem::throwEvent(new Event_btn(1));
}

void action_dec_fan(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    EventSystem::throwEvent(new Event_btn(2));
}

void action_confirm_fan(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    auto current = StateMachine::getCurrentState();
    auto fanState = dynamic_cast<FanState*>(current);
    int confirmedFan_mode = 0;
    StateMachine::changeState(StatesID::confirm_fan_onstate, (void*)(intptr_t)confirmedFan_mode);
}