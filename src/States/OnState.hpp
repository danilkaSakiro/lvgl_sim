#pragma once
#include "State.hpp"

class OnState : public State
{
public:
    OnState(StatesID id);
    ~OnState() override;

    void activate(void* arg) override;
    void deactivate() override;

    bool onEvent(Event_btn* obj) override;

protected:
    bool updateScreenAction(const uint32_t &mask) override;

private:
    int c;
    int c_preview;
    int a;
    int a_preview;
    bool rpm_changed;
    bool temp_changed;
};