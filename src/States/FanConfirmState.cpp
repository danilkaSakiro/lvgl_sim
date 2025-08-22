#include "FanConfirmState.hpp"
#include "FanState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>
#include "StateMachine.hpp"

FanConfirmState::FanConfirmState(StatesID id)
    : FanState(id)
{

}

FanConfirmState::~FanConfirmState()
{

}

void FanConfirmState::activate(void *arg)
{
    printf("[FanConfirmState]::[activate]\r\n");
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_ON_STATE_CONFIRM_FAN);
}

void FanConfirmState::deactivate()
{
    printf("[FanConfirmState]::[deactivate]\r\n");
}

bool FanConfirmState::onEvent(Event_change_fan *obj)
{
    if (!obj) return false;
    FanChanges::setfan_mode(FanChanges::getfan_mode_ch());
    StateMachine::changeState(StatesID::fan_onstate);
    needUpdateScreen();
    return true;
}
