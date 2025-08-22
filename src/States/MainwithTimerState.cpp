#include "MainwithTimerState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>
#include "StateMachine.hpp"

MainwithTimerState::MainwithTimerState(StatesID id)
    : State(id)
    , c(25)
    , a(3)
{

}

MainwithTimerState::~MainwithTimerState()
{

}

void MainwithTimerState::activate(void *arg)
{
    printf("[MainwithTimerState]::[activate]\r\n");
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_ON_STATE_MAINSCREEN_WITH_TIMER);

}

void MainwithTimerState::deactivate()
{
    printf("[MainwithTimerState]::[deactivate]\r\n");

}

bool MainwithTimerState::updateScreenAction(const uint32_t &mask)
{

}

bool MainwithTimerState::onEvent(Event_btn *obj)
{

    needUpdateScreen();

    return true;
}