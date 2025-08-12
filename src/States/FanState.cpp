#include "FanState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>
#include "StateMachine.hpp"

FanState::FanState(StatesID id)
    : MainState(id)
    , a(3)
{

}

FanState::~FanState()
{

}

void FanState::activate(void *arg)
{
    printf("[FanState]::[activate]\r\n");
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_ON_STATE_CHANGE_FAN);
    AUXTIM_set_CB([](void *arg)
                  {
        FanState* ptr = static_cast<FanState*>(arg);
        // ptr->a -= 3;
        // ptr->b += 3;
        // ptr->c = 15;
        EventSystem::throwEvent(new Event_updateScreen); }, this, 2000, true);

    AUXTIM_start();
}

void FanState::deactivate()
{
    printf("[FanState]::[deactivate]\r\n");
    AUXTIM_clear();
}

bool FanState::updateScreenAction(const uint32_t &mask)
{
    auto current_screen = screen_manager::screen_pt()->id();

    screen_manager::screen_pt()->updateScreen(rpm_changed ? a_preview : a);

    return true;
}

bool FanState::onEvent(Event_btn *obj)
{
    if (obj->getBtn() == 1)
    {
        if (rpm_changed)
        {
            if (a_preview < 9) a_preview += 1;
        }
        else
        {
            if (a < 9) a += 1;
        }
    }
    else if (obj->getBtn() == 2)
    {
        if (rpm_changed)
        {
            if (a_preview > 0) a_preview -= 1;
        }
        else
        {
            if (a > 0) a -= 1;
        }
    }

    needUpdateScreen();

    return true;
}