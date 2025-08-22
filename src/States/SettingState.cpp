#include "SettingState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>
#include "StateMachine.hpp"

SettingState::SettingState(StatesID id)
    : MenuState(id)
{

}

SettingState::~SettingState()
{

}

void SettingState::activate(void *arg)
{
    printf("[SettingState]::[activate]\r\n");
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_SETTING_MENU);
    // AUXTIM_set_CB([](void *arg)
    //               {
    //     FanState* ptr = static_cast<FanState*>(arg);
    //     // ptr->a -= 3;
    //     // ptr->b += 3;
    //     // ptr->c = 15;
    //     EventSystem::throwEvent(new Event_updateScreen); }, this, 2000, true);

    // AUXTIM_start();
}

void SettingState::deactivate()
{
    printf("[SettingState]::[deactivate]\r\n");
}

bool SettingState::updateScreenAction(const uint32_t &mask)
{
    // auto current_screen = screen_manager::screen_pt()->id();

    // screen_manager::screen_pt()->updateScreen(rpm_changed ? a_preview : a);

    return true;
}

bool SettingState::onEvent(Event_btn *obj)
{

    needUpdateScreen();

    return true;
}