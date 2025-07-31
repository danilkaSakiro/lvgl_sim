#pragma once
#include "State.hpp"

class ConfigsManager;

class OffState : public State
{
public:
    OffState(StatesID id);
    ~OffState() override;

    void activate(void* arg) override;
    void deactivate() override;

    bool onEvent(Event_arc* obj) override;

protected:
    bool updateScreenAction(const uint32_t &mask) override;

private:
    int val;
};