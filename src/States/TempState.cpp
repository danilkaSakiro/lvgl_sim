#include "TempState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>
#include "StateMachine.hpp"

TempState::TempState(StatesID id)
    : MainState(id)
    , c(25)
    , c_preview(c)  
    , temp_changed(false)
{

}

TempState::~TempState()
{

}

void TempState::activate(void *arg)
{
    printf("[TempState]::[activate]\r\n");
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_ON_STATE_CHANGE_TEMP);
    AUXTIM_set_CB([](void *arg)
                  {
        TempState* ptr = static_cast<TempState*>(arg);
        // ptr->a -= 3;
        // ptr->b += 3;
        // ptr->c = 15;
        EventSystem::throwEvent(new Event_updateScreen); }, this, 2000, true);

    AUXTIM_start();
}

void TempState::deactivate()
{
    printf("[TempState]::[deactivate]\r\n");
    AUXTIM_clear();
}

bool TempState::updateScreenAction(const uint32_t &mask)
{
    screen_manager::screen_pt()->updateScreen(temp_changed ? c_preview : c);

    return true;
}

bool TempState::onEvent(Event_btn *obj)
{
    if (obj->getBtn() == 1)
    {
        if (c_preview < 35) 
        {
            c_preview += 1;
            temp_changed = true;
        }
    }
    else if (obj->getBtn() == 2)
    {
        if (c_preview > 15) 
        {
            c_preview -= 1;
            temp_changed = true;
        }
    }

    needUpdateScreen();

    return true;
}