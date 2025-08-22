#include "ToolState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>
#include "StateMachine.hpp"

ToolState::ToolState(StatesID id)
    : MenuState(id)
{

}

ToolState::~ToolState()
{

}

void ToolState::activate(void *arg)
{
    printf("[ToolState]::[activate]\r\n");
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_TOOLS);
    // AUXTIM_set_CB([](void *arg)
    //               {
    //     FanState* ptr = static_cast<FanState*>(arg);
    //     // ptr->a -= 3;
    //     // ptr->b += 3;
    //     // ptr->c = 15;
    //     EventSystem::throwEvent(new Event_updateScreen); }, this, 2000, true);

    // AUXTIM_start();
}

void ToolState::deactivate()
{
    printf("[ToolState]::[deactivate]\r\n");
}

bool ToolState::updateScreenAction(const uint32_t &mask)
{
    // auto current_screen = screen_manager::screen_pt()->id();

    // screen_manager::screen_pt()->updateScreen(rpm_changed ? a_preview : a);

    return true;
}

bool ToolState::onEvent(Event_btn *obj)
{

    needUpdateScreen();

    return true;
}