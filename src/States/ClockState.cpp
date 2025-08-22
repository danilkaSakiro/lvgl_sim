#include "ClockState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>
#include "StateMachine.hpp"

ClockState::ClockState(StatesID id)
    : MenuState(id)
{
}

ClockState::~ClockState()
{
}

void ClockState::activate(void *arg)
{
    printf("[ClockState]::[activate]\r\n");
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_CLOCK_MENU);
}

void ClockState::deactivate()
{
    printf("[ClockState]::[deactivate]\r\n");
}

bool ClockState::updateScreenAction(const uint32_t &mask)
{
}

bool ClockState::onEvent(Event_btn *obj)
{
    if (!obj)
        return false;

    if (obj->getBtn() == 1)
    {
        if (step == ClockSetup::HOUR)
        {
            hour = (hour + 1) % 24;
        }
        else if (step == ClockSetup::MINUTE)
        {
            minute = (minute + 1) % 60;
        }
        else if (step == ClockSetup::DAY)
        {
            day = (day % 31) + 1;
        }
        else if (step == ClockSetup::MONTH)
        {
            month = (month % 12) + 1;
        }
        else if (step == ClockSetup::YEAR)
        {
            year++;
        }
    }
    else if (obj->getBtn() == 2)
    {
        if (step == ClockSetup::HOUR) {
            hour = (hour + 23) % 24;
        }
        else if (step == ClockSetup::MINUTE) {
            minute = (minute + 59) % 60;
        }
        else if (step == ClockSetup::DAY) {
            day = (day == 1 ? 31 : day - 1);
        }
        else if (step == ClockSetup::MONTH) {
            month = (month == 1 ? 12 : month - 1);
        }
        else if (step == ClockSetup::YEAR) {
            year--;
        }
    }
    needUpdateScreen();
    return true;
}