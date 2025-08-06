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
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_TOOLS);
    AUXTIM_set_CB([](void* arg)
    {
        // ptr->a -= 3;
        // ptr->b += 3;
        // ptr->c = 15;
        EventSystem::throwEvent(new Event_updateScreen);
    }, this, 2000, true);
    AUXTIM_start();
}

void MenuState::deactivate()
{
    AUXTIM_clear();
}

bool MenuState::updateScreenAction(const uint32_t &mask)
{
    screen_manager::screen_pt()->updateScreen("Wi-Fi");
    return true;
}

bool MenuState::onEvent(Event_btn* obj)
{
    int btn = obj->getBtn();
    printf("[MenuState] Button Event: btn = %d\n", btn);

    // if (obj->getBtn() == 1)
    // {
    //     c -= 3;
    // }
    // else if (obj->getBtn() == 2)
    // {
    //     c += 3;
    // }
    // else if (obj->getBtn() == 3)
    // {
    //     c = 25;
    // }

    needUpdateScreen();

    return true;
}