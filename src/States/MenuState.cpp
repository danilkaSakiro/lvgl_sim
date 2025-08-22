#include "MenuState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>
#include "StateMachine.hpp"

MenuState::MenuState(StatesID id) 
    : State(id) 
{
}

MenuState::~MenuState()
{
}

void MenuState::activate(void *arg)
{   
    printf("[MenuState]::[activate]\r\n");
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_TOOLS);
    returnToToolsPending = false;
    AUXTIM_set_CB([](void* arg)
    {
        auto self = static_cast<MenuState*>(arg);
        if (self->returnToToolsPending)
        {
            screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_TOOLS);
            self->returnToToolsPending = false;
        }
    }, this, 2000, true);
    AUXTIM_start();
}

void MenuState::deactivate()
{
    printf("[MenuState]::[deactivate]\r\n");
    AUXTIM_clear();
}

bool MenuState::updateScreenAction(const uint32_t &mask)
{

}