#include "MainState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>
#include "StateMachine.hpp"

MainState::MainState(StatesID id)
    : State(id)
    , temp(TempChanges::gettemperature())
{

}

MainState::~MainState()
{

}

void MainState::activate(void *arg)
{
    printf("[MainState]::[activate]\r\n");
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_ON_STATE_MAINSCREEN);
}

void MainState::deactivate()
{
    printf("[MainState]::[deactivate]\r\n");
}

bool MainState::updateScreenAction(const uint32_t &mask)
{

    auto screen = screen_manager::screen_pt();
    
    screen->updateScreen(temp_changed ? temp_preview : temp);
    
    return true;
}