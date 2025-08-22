#include "VisualState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>
#include "StateMachine.hpp"

VisualState::VisualState(StatesID id)
    : MenuState(id)
{

}

VisualState::~VisualState()
{

}

void VisualState::activate(void *arg)
{
    printf("[VisualState]::[activate]\r\n");
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_VISUAL_MENU);
    // AUXTIM_set_CB([](void *arg)
    //               {
    //     FanState* ptr = static_cast<FanState*>(arg);
    //     // ptr->a -= 3;
    //     // ptr->b += 3;
    //     // ptr->c = 15;
    //     EventSystem::throwEvent(new Event_updateScreen); }, this, 2000, true);

    // AUXTIM_start();
}

void VisualState::deactivate()
{
    printf("[VisualState]::[deactivate]\r\n");
}

bool VisualState::updateScreenAction(const uint32_t &mask)
{
    // auto current_screen = screen_manager::screen_pt()->id();

    // screen_manager::screen_pt()->updateScreen(rpm_changed ? a_preview : a);

    return true;
}

bool VisualState::onEvent(Event_btn *obj)
{

    needUpdateScreen();

    return true;
}