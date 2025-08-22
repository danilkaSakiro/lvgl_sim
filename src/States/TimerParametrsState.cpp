#include "TimerParametrsState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>
#include "StateMachine.hpp"

TimerParametrsState::TimerParametrsState(StatesID id)
    : TimerState(id)
{
}

TimerParametrsState::~TimerParametrsState()
{
}

void TimerParametrsState::activate(void *arg)
{
    printf("[TimerParametrsState]::[activate]\r\n");
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_TIMER_PARAMETR_MENU);
}

void TimerParametrsState::deactivate()
{
    printf("[ClockState]::[deactivate]\r\n");
}

bool TimerParametrsState::updateScreenAction(const uint32_t &mask)
{
    
}

bool TimerParametrsState::onEvent(Event_btn *obj)
{
    if (!obj)
        return false;

    needUpdateScreen();
    return true;
}