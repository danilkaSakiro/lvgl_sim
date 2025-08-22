#include "DispetcherState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>
#include "StateMachine.hpp"

DispetcherState::DispetcherState(StatesID id)
    : MenuState(id)

{

}

DispetcherState::~DispetcherState()
{

}

void DispetcherState::activate(void *arg)
{
    printf("[DispetcherState]::[activate]\r\n");
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_DISPETCHER_MENU);
}

void DispetcherState::deactivate()
{
    printf("[DispetcherState]::[deactivate]\r\n");
}

bool DispetcherState::updateScreenAction(const uint32_t &mask)
{
    
    return true;
}

bool DispetcherState::onEvent(Event_btn *obj)
{
   
    needUpdateScreen();
    return true;
}