#include "screen_dispetcher.hpp"
#include "StateMachine.hpp"
#include "screen_manager.hpp"

screen_dispetcher::screen_dispetcher(int screen_id)
    : screen_menu(screen_id)
{
};

screen_dispetcher::~screen_dispetcher() 
{   
};

void screen_dispetcher::updateScreenAction(int c) 
{

};

// ====================================================================

void action_out_dispetcher(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_out_grafik; Event: %d\r\n", ev);

    StateMachine::changeState(StatesID::menu);
}
