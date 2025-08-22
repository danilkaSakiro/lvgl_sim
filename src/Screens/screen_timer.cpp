#include "screen_timer.hpp"
#include "StateMachine.hpp"
#include "screen_manager.hpp"

screen_timer::screen_timer(int screen_id)
    : screen_menu(screen_id)
{
};

screen_timer::~screen_timer() 
{   
};

void screen_timer::updateScreenAction(int c) 
{

};

// ====================================================================


void action_out_timer_tool(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_out_timer_tool; Event: %d\r\n", ev);

    StateMachine::changeState(StatesID::menu);
}

void action_select_mon(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_select_mon; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(1));
    StateMachine::changeState(StatesID::timer_patametr_state);
}

void action_select_tue(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_select_tue; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(2));
    StateMachine::changeState(StatesID::timer_patametr_state);
}

void action_select_wed(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_select_wed; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(3));
    StateMachine::changeState(StatesID::timer_patametr_state);
}

void action_select_thu(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_select_thu; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(4));
    StateMachine::changeState(StatesID::timer_patametr_state);
}

void action_select_fri(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_select_fri; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(5));
    StateMachine::changeState(StatesID::timer_patametr_state);
}

void action_select_sat(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_select_sat; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(6));
    StateMachine::changeState(StatesID::timer_patametr_state);
}

void action_select_sun(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_select_sun; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(7));
    StateMachine::changeState(StatesID::timer_patametr_state);
}

void action_select_onetime(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_select_onetime; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(8));
    StateMachine::changeState(StatesID::timer_patametr_state);
}