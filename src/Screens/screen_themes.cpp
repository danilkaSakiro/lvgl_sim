#include "screen_themes.hpp"
#include "StateMachine.hpp"
#include "screen_manager.hpp"

screen_themes::screen_themes(int screen_id)
    : screen_menu(screen_id)
{
};

screen_themes::~screen_themes() 
{   
};

void screen_themes::updateScreenAction(int c) 
{

};

// ====================================================================


void action_change_theme(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_out_timer_tool; Event: %d\r\n", ev);

    StateMachine::changeState(StatesID::menu);
}

void action_nochange_theme(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_select_mon; Event: %d\r\n", ev);

    StateMachine::changeState(StatesID::menu);
}