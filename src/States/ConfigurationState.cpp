#include "ConfigurationState.hpp"
#include <stdio.h>
#include "screen_manager.hpp"
#include <cstdlib>
#include "StateMachine.hpp"

ConfigurationState::ConfigurationState(StatesID id)
    : MenuState(id)
{

}

ConfigurationState::~ConfigurationState()
{

}

void ConfigurationState::activate(void *arg)
{
    printf("[ConfigurationState]::[activate]\r\n");
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_CONFIGURATION_MENU);
    returnToConfigure = false;
    AUXTIM_set_CB([](void* arg)
    {
        auto self = static_cast<ConfigurationState*>(arg);
        if (self->returnToConfigure)
        {
            screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_CONFIGURATION_MENU);
            self->returnToConfigure = false;
        }
    }, this, 2000, true);
    AUXTIM_start();
}

void ConfigurationState::deactivate()
{
    printf("[ConfigurationState]::[deactivate]\r\n");
}

bool ConfigurationState::updateScreenAction(const uint32_t &mask)
{
    
}
