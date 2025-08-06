#include "OnState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>

OnState::OnState(StatesID id) 
    : State(id) 
    , c(25.0f)
{
}
OnState::~OnState() 
{
}

void OnState::activate(void* arg)
{
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
    AUXTIM_clear();
}

bool OnState::updateScreenAction(const uint32_t &mask)
{
    screen_manager::screen_pt()->updateScreen(c);
    return true;
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
        c = 25.0f;
    }

    needUpdateScreen();

    return true;
}