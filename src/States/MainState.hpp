#pragma once
#include "State.hpp"
#include "DeviceSettings/DeviceSettings.hpp"

class MainState : public State
{
public:
    MainState(StatesID id);
    ~MainState() override;

    void activate(void* arg) override;
    void deactivate() override;
    
protected:
    bool updateScreenAction(const uint32_t &mask) override;

private:
    int temp;
    int temp_preview;
    bool temp_changed;
};