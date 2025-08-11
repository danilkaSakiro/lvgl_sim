#include "OnState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>
#include "StateMachine.hpp"

OnState::OnState(StatesID id)
    : State(id)
    , c(25)
    , a(3)
{

}

OnState::~OnState()
{

}

void OnState::activate(void *arg)
{
    printf("[OnState]::[activate]\r\n");
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_ON_STATE_MAINSCREEN);
    AUXTIM_set_CB([](void *arg)
                  {
        OnState* ptr = static_cast<OnState*>(arg);
        // ptr->a -= 3;
        // ptr->b += 3;
        // ptr->c = 15;
        EventSystem::throwEvent(new Event_updateScreen); }, this, 2000, true);

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

    if (current_screen == ScreensEnum::SCREEN_ID_ON_STATE_CHANGE_TEMP)
    {
        screen_manager::screen_pt()->updateScreen(temp_changed ? c_preview : c);
    }
    else if (current_screen == ScreensEnum::SCREEN_ID_ON_STATE_CHANGE_RPM)
    {
        screen_manager::screen_pt()->updateScreen(rpm_changed ? a_preview : a);
    }
    else if (current_screen == ScreensEnum::SCREEN_ID_ON_STATE_MAINSCREEN)
    {
        screen_manager::screen_pt()->updateScreen(c); // <-- добавлено
    }

    return true;
}

bool OnState::onEvent(Event_btn *obj)
{
    if (obj->getBtn() == 1)
    {
        c_preview = c;
        temp_changed = true;
        screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_ON_STATE_CHANGE_TEMP);
    }
    else if (obj->getBtn() == 2)
    {
        a_preview = a;
        rpm_changed = true;
        screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_ON_STATE_CHANGE_RPM);
    }
    else if (obj->getBtn() == 3)
    {
        screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_ON_STATE_MAINSCREEN);
    }
    else if (obj->getBtn() == 4)
    {
        if (temp_changed)
        {
            if (c_preview < 35) c_preview += 1;
        }
        else
        {
            if (c < 35) c += 1;
        }
    }
    else if (obj->getBtn() == 5)
    {
        if (temp_changed)
        {
            if (c_preview > 15) c_preview -= 1;
        }
        else
        {
            if (c > 15) c -= 1;
        }
    }
    else if (obj->getBtn() == 6)
    {
        if (temp_changed)
        {
            c = c_preview;
            temp_changed = false;
            screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_ON_STATE_MAINSCREEN);
        }
        else if (rpm_changed)
        {
            a = a_preview;
            rpm_changed = false;
            screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_ON_STATE_MAINSCREEN);
        }
    }
    else if (obj->getBtn() == 7)
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
    else if (obj->getBtn() == 8)
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