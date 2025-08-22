#include "TempState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>
#include "StateMachine.hpp"

TempState::TempState(StatesID id)
    : MainState(id)
    , Temp_preview(TempChanges::gettemperature_ch())  
{

}

TempState::~TempState()
{

}

void TempState::activate(void *arg)
{
    printf("[TempState]::[activate] %d\r\n", TempChanges::gettemperature_ch());
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_ON_STATE_CHANGE_TEMP);
}

void TempState::deactivate()
{
    printf("[TempState]::[deactivate]\r\n");
}

bool TempState::updateScreenAction(const uint32_t &mask)
{
    auto screen = screen_manager::screen_pt();
    if (screen)
    {
        screen->updateScreen(TempChanges::gettemp_change() ? Temp_preview : TempChanges::gettemperature());
    } 
    return true;
}

bool TempState::onEvent(Event_btn *obj)
{
    if (!obj) return false;
    
    if (obj->getBtn() == 1 && Temp_preview < 35)
    {
        Temp_preview++;
        TempChanges::settemperature_ch(Temp_preview);
        TempChanges::settemp_change(true);
    }
    else if (obj->getBtn() == 2 && Temp_preview > 15)
    {
        Temp_preview--;
        TempChanges::settemperature_ch(Temp_preview);
        TempChanges::settemp_change(true);
    }
    needUpdateScreen();
    return true;
}