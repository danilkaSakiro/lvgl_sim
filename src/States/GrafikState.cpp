#include "GrafikState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>
#include "StateMachine.hpp"

GrafikState::GrafikState(StatesID id)
    : MenuState(id)
    , target_temp(TempChanges::gettemperature())
{

}

GrafikState::~GrafikState()
{

}

void GrafikState::activate(void *arg)
{
    printf("[GrafikState]::[activate]\r\n");
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_GRAFIK_MENU);
    // AUXTIM_set_CB([](void *arg)
    //               {
    //     FanState* ptr = static_cast<FanState*>(arg);
    //     // ptr->a -= 3;
    //     // ptr->b += 3;
    //     // ptr->c = 15;
    //     EventSystem::throwEvent(new Event_updateScreen); }, this, 2000, true);

    // AUXTIM_start();
}

void GrafikState::deactivate()
{
    printf("[GrafikState]::[deactivate]\r\n");
}

bool GrafikState::updateScreenAction(const uint32_t &mask)
{
    auto current_screen = screen_manager::screen_pt()->id();
    screen_manager::screen_pt()->updateScreen(target_temp);

    return true;
}