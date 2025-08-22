#include "ThemesState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>
#include "StateMachine.hpp"

ThemesState::ThemesState(StatesID id)
    : MenuState(id)

{

}

ThemesState::~ThemesState()
{

}

void ThemesState::activate(void *arg)
{
    printf("[ThemesState]::[activate]\r\n");
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_THEMES_MENU);
}

void ThemesState::deactivate()
{
    printf("[ThemesState]::[deactivate]\r\n");
}

bool ThemesState::updateScreenAction(const uint32_t &mask)
{
    
    return true;
}

bool ThemesState::onEvent(Event_btn *obj)
{
   
    needUpdateScreen();
    return true;
}