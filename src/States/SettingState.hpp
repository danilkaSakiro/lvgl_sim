#pragma once
#include "MenuState.hpp"

class SettingState : public MenuState
{
public:
    SettingState(StatesID id);
    ~SettingState() override;

    void activate(void* arg) override;
    void deactivate() override;

    bool onEvent(Event_btn* obj) override;

protected:
    bool updateScreenAction(const uint32_t &mask) override;

private:

};