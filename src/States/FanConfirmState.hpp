#pragma once
#include "FanState.hpp"

class FanConfirmState : public FanState
{
public:
    FanConfirmState(StatesID id);
    ~FanConfirmState() override;

    void activate(void* arg) override;
    void deactivate() override;

    bool onEvent(Event_btn* obj) override;

protected:
    bool updateScreenAction(const uint32_t &mask) override;

private:

};