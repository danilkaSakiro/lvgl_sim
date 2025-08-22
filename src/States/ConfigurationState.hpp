#pragma once
#include "MenuState.hpp"

class ConfigurationState : public MenuState
{
public:
    ConfigurationState(StatesID id);
    ~ConfigurationState() override;

    void activate(void* arg) override;
    void deactivate() override;

protected:
    bool updateScreenAction(const uint32_t &mask) override;

private:
    bool returnToConfigure; 
};