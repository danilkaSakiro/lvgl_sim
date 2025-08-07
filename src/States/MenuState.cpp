#include "MenuState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>

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
    AUXTIM_set_CB([](void* arg)
    {
        // ptr->a -= 3;
        // ptr->b += 3;
        // ptr->c = 15;
        // EventSystem::throwEvent(new Event_updateScreen);
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
    if (obj->getBtn() == 7)
    {
        screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_WI_FI_MENU);
    }
    else if (obj->getBtn() == 8)
    {
        screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_BRIGHTNESS_MENU);
    }
    else if (obj->getBtn() == 9)
    {
        screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_SOUND_MENU);
    }
    else if (obj->getBtn() == 10)
    {
        screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_LANGUAGE_MENU);
    }
    else if (obj->getBtn() == 11)
    {
        screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_WINDOW_MENU);
    }
    else if (obj->getBtn() == 12)
    {
        screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_ABOBA_MENU);
    }
    if (obj->getBtn() == 13)
    {
        screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_MAIN);
    }
    needUpdateScreen();

    return true;
}