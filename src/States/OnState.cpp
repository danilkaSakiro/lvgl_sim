#include "OnState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>

OnState::OnState(StatesID id) 
    : State(id) 
    , a(0)
    , b(0)
    , c(0)
{
    printf("OnState::OnState == CONSTRUCTOR\r\n");
}
OnState::~OnState() 
{
    printf("OnState::OnState == DESTRUCTOR\r\n");
}

void OnState::activate(void* arg)
{
    printf("OnState::activate\r\n");

    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_MAIN);

    AUXTIM_set_CB([](void* arg)
    {
        OnState* ptr = static_cast<OnState*>(arg);
        printf("OnState::TIMER\r\n");
        ptr->a = rand() % 101;
        ptr->b = rand() % 101;
        ptr->c = rand() % 101;
        EventSystem::throwEvent(new Event_updateScreen);
    }, this, 2000, true);

    AUXTIM_start();
}

void OnState::deactivate()
{
    printf("OnState::deactivate\r\n");
    AUXTIM_clear();
}

bool OnState::updateScreenAction(const uint32_t &mask)
{
    printf("OnState::updateScreenAction\r\n");
    screen_manager::screen_pt()->updateScreen(a, b, c);
    return true;
}

bool OnState::onEvent(Event_btn* obj)
{
    if (obj->getBtn() == 1)
    {
        a = rand() % 101;
    }
    else if (obj->getBtn() == 2)
    {
        b = rand() % 101;
    }
    else if (obj->getBtn() == 3)
    {
        c = rand() % 101;
    }

    needUpdateScreen();

    return true;
}