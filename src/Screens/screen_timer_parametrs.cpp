#include "screen_timer_parametrs.hpp"
#include "StateMachine.hpp"
#include "screen_manager.hpp"

screen_timer_parametrs::screen_timer_parametrs(int screen_id)
    : screen_timer(screen_id)
{
};

screen_timer_parametrs::~screen_timer_parametrs() 
{   
};

void screen_timer_parametrs::updateScreenAction(int c) 
{

};

// ====================================================================

void action_back_timer(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    StateMachine::changeState(StatesID::menu);
}

void action_change_timer_mode_up(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    EventSystem::throwEvent(new Event_btn(1));
}

void action_change_timer_mode_down(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    EventSystem::throwEvent(new Event_btn(2));
}

void action_confirm_timer_mode(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    StateMachine::changeState(StatesID::main_with_timer_state);
}
