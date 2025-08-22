#include "screen_clock.hpp"
#include "StateMachine.hpp"
#include "screen_manager.hpp"

screen_clock::screen_clock(int screen_id)
    : screen_menu(screen_id)
{
};

screen_clock::~screen_clock() 
{   
};

void screen_clock::updateScreenAction(int c) 
{

};

// ====================================================================

void action_out_clock(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    StateMachine::changeState(StatesID::menu);
}

void action_inc_clock_tool(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    EventSystem::throwEvent(new Event_btn(1));
}

void action_dec_clock_tool(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    EventSystem::throwEvent(new Event_btn(2));
}

void action_confirm_clock(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    printf("Clock is set\r\n");
    StateMachine::changeState(StatesID::menu);
}
