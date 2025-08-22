#include "TempConfirmState.hpp"
#include "TempState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>
#include "StateMachine.hpp"

TempConfirmState::TempConfirmState(StatesID id)
    : TempState(id)
{
}

TempConfirmState::~TempConfirmState()
{
}

void TempConfirmState::activate(void *arg)
{
    printf("[TempConfirmState]::[activate]\r\n");
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_ON_STATE_CONFIRM_TEMP);
}

void TempConfirmState::deactivate()
{
    printf("[TempConfirmState]::[deactivate]\r\n");
}

bool TempConfirmState::onEvent(Event_change_temp *obj)
{
    if (!obj) return false;
    TempChanges::settemperature(TempChanges::gettemperature_ch());
    StateMachine::changeState(StatesID::temp_onstate);
    needUpdateScreen();
    return true;
}
