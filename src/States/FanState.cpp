#include "FanState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>
#include "StateMachine.hpp"

FanState::FanState(StatesID id)
    : MainState(id)
    , Fan_mode_preview(FanChanges::getfan_mode_ch())  
{

}

FanState::~FanState()
{

}

void FanState::activate(void *arg)
{
    printf("[FanState]::[activate]\r\n");
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_ON_STATE_CHANGE_FAN);
}

void FanState::deactivate()
{
    printf("[FanState]::[deactivate]\r\n");
}

bool FanState::updateScreenAction(const uint32_t &mask)
{
    auto screen = screen_manager::screen_pt();
    if (screen)
    {
        screen->updateScreen(FanChanges::getfan_mode_change() ? Fan_mode_preview : FanChanges::getfan_mode());
    } 
    return true;
}

bool FanState::onEvent(Event_btn *obj)
{
    if (!obj) return false;
    
     if (obj->getBtn() == 1 && Fan_mode_preview < 9)
    {
        Fan_mode_preview++;
        FanChanges::setfan_mode_ch(Fan_mode_preview);
        FanChanges::setfan_mode_change(true);
    }
    else if (obj->getBtn() == 2 && Fan_mode_preview > 0)
    {
        Fan_mode_preview--;
        FanChanges::setfan_mode_ch(Fan_mode_preview);
        FanChanges::setfan_mode_change(true);
    }
    needUpdateScreen();
    return true;
}