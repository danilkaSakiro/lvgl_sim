#include "OffState.hpp"
#include "screen_manager.hpp"
#include "StateMachine.hpp"

OffState::OffState(StatesID id)
    : State(id)
{
}

OffState::~OffState()
{
}

void OffState::activate(void* arg)
{
    printf("[OffState]::[activate]\r\n");
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_OFF_STATE);
    // AUXTIM_set_CB([](void* arg)
    // {
    //     // ptr->a -= 3;
    //     // ptr->b += 3;
    //     // ptr->c = 15;
    //     EventSystem::throwEvent(new Event_updateScreen);
    // }, this, 2000, true);
    // AUXTIM_start();
}

void OffState::deactivate()
{
    printf("[OffState]::[deactivate]\r\n");
    // AUXTIM_clear();
}

bool OffState::updateScreenAction(const uint32_t &mask)
{
    screen_manager::screen_pt()->updateScreen("ABOBA");
    return true;
}
