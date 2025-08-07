#include "OnState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>
#include "StateMachine.hpp"

OnState::OnState(StatesID id) 
    : State(id) 
    , c(25.0f)
    , a(1000)
{
}
OnState::~OnState() 
{
}

void OnState::activate(void* arg)
{
    printf("[OnState]::[activate]\r\n");
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_MAIN);
    AUXTIM_set_CB([](void* arg)
    {
        OnState* ptr = static_cast<OnState*>(arg);
        // ptr->a -= 3;
        // ptr->b += 3;
        // ptr->c = 15;
        EventSystem::throwEvent(new Event_updateScreen);
    }, this, 2000, true);

    AUXTIM_start();
}

void OnState::deactivate()
{
    printf("[OnState]::[deactivate]\r\n");
    AUXTIM_clear();
}

bool OnState::updateScreenAction(const uint32_t &mask)
{
    auto current_screen = screen_manager::screen_pt()->id();

    if (current_screen == ScreensEnum::SCREEN_ID_MAIN)
    {
        screen_manager::screen_pt()->updateScreen(c); // temp
    }
    else if (current_screen == ScreensEnum::SCREEN_ID_SECOND)
    {
        screen_manager::screen_pt()->updateScreen(a); // RPM
    }
}

bool OnState::onEvent(Event_btn* obj)
{
    if (obj->getBtn() == 1)
    {
        c -= 3.0f;
    }
    else if (obj->getBtn() == 2)
    {
        c += 3.0f;
    }
    else if (obj->getBtn() == 3)
    {
        screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_SECOND);
    }
    else if (obj->getBtn() == 4)
    {
        a -= 250;
    }
    else if (obj->getBtn() == 5)
    {
        a += 250;
    }
    if (obj->getBtn() == 6)
    {
        screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_MAIN);
    }
    needUpdateScreen();

    return true;
}