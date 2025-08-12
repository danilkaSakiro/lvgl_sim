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
    screen_manager::screen_pt()->updateScreen("Wi-Fi");
    return true;
}

bool MenuState::onEvent(Event_btn* obj)
{
    if (obj->getBtn() == 9)
    {
        screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_CLOCK_MENU);
        returnToToolsPending = true;
    }
    else if (obj->getBtn() == 10)
    {
        screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_TIMER_MENU);
        returnToToolsPending = true;
    }
    else if (obj->getBtn() == 11)
    {
        screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_SOUND_MENU);
        returnToToolsPending = true;
    }
    else if (obj->getBtn() == 12)
    {
        screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_LANGUAGE_MENU);
        returnToToolsPending = true;
    }
    else if (obj->getBtn() == 13)
    {
        screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_WINDOW_MENU);
        returnToToolsPending = true;
    }
    else if (obj->getBtn() == 14)
    {
        screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_ABOBA_MENU);
        returnToToolsPending = true;
    }
    if (obj->getBtn() == 15)
    {
        screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_ON_STATE_MAINSCREEN);
        StateMachine::changeState(StatesID::main_onstate); 
    }
    needUpdateScreen();

    return true;
}