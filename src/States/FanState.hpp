#pragma once
#include "MainState.hpp"

class FanState : public MainState
{
public:
    FanState(StatesID id);
    ~FanState() override;

    void activate(void* arg) override;
    void deactivate() override;

    bool onEvent(Event_btn* obj) override;

protected:
    bool updateScreenAction(const uint32_t &mask) override;

private:
    int Fan_mode_preview;

};