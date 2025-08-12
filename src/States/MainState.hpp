#pragma once
#include "State.hpp"

class MainState : public State
{
public:
    MainState(StatesID id);
    ~MainState() override;

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