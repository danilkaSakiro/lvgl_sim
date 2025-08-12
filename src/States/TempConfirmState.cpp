#include "TempConfirmState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>
#include "StateMachine.hpp"

TempConfirmState::TempConfirmState(StatesID id)
    : TempState(id)
    , source_state(nullptr)
{

}

TempConfirmState::~TempConfirmState()
{

}

void TempConfirmState::activate(void *arg)
{
    printf("[TempConfirmState]::[activate]\r\n");

    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_ON_STATE_CONFIRM_TEMP);
    AUXTIM_set_CB([](void *arg)
                  {
        TempConfirmState* ptr = static_cast<TempConfirmState*>(arg);
        EventSystem::throwEvent(new Event_updateScreen); }, this, 2000, true);

    AUXTIM_start();
}

void TempConfirmState::deactivate()
{
    printf("[TempConfirmState]::[deactivate]\r\n");
    AUXTIM_clear();
    source_state = nullptr;
}

bool TempConfirmState::updateScreenAction(const uint32_t &mask)
{
    if (source_state) 
    {
        screen_manager::screen_pt()->updateScreen(source_state->getCPreview());
    }
    return true;
}

bool TempConfirmState::onEvent(Event_btn *obj)
{
    if (obj->getBtn() == 1)
    {
        source_state->setC(source_state->getCPreview());
        source_state->setTempChanged(false);
        StateMachine::changeState(StatesID::temp_onstate);
    }
    else if (obj->getBtn() == 2)
    {
        StateMachine::changeState(StatesID::temp_onstate);
    }

    needUpdateScreen();
    return true;
}