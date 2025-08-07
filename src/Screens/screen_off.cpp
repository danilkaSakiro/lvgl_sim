#include "screen_off.hpp"
#include "StateMachine.hpp"
#include "screen_manager.hpp"

screen_off::screen_off(int screen_id)
    : screen_base(screen_id)
{
};

screen_off::~screen_off() 
{   
};

void screen_off::updateScreenAction(float c) 
{

};

// ====================================================================

void action_power_on(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    printf("action_power_on; Event: %d\r\n", ev);

    StateMachine::changeState(StatesID::on_state);
}