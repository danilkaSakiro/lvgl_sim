#include "FanConfirmState.hpp"
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
    AUXTIM_set_CB([](void *arg)
                  {
        FanConfirmState* ptr = static_cast<FanConfirmState*>(arg);
        // ptr->a -= 3;
        // ptr->b += 3;
        // ptr->c = 15;
        EventSystem::throwEvent(new Event_updateScreen); }, this, 2000, true);

    AUXTIM_start();
}

void FanConfirmState::deactivate()
{
    printf("[FanConfirmState]::[deactivate]\r\n");
    AUXTIM_clear();
}

bool FanConfirmState::updateScreenAction(const uint32_t &mask)
{

    return true;
}

bool FanConfirmState::onEvent(Event_btn *obj)
{
    
    needUpdateScreen();

    return true;
}