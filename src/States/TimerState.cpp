#include "TimerState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>
#include "StateMachine.hpp"

TimerState::TimerState(StatesID id)
    : MenuState(id)

{

}

TimerState::~TimerState()
{

}

void TimerState::activate(void *arg)
{
    printf("[TimerState]::[activate]\r\n");
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_TIMER_MENU);
}

void TimerState::deactivate()
{
    printf("[TimerState]::[deactivate]\r\n");
}

bool TimerState::updateScreenAction(const uint32_t &mask)
{
    
    return true;
}

bool TimerState::onEvent(Event_btn *obj)
{
   
    needUpdateScreen();
    return true;
}