#pragma once
#include "MenuState.hpp"

class VisualState : public MenuState
{
public:
    VisualState(StatesID id);
    ~VisualState() override;

    void activate(void* arg) override;
    void deactivate() override;

    bool onEvent(Event_btn* obj) override;

protected:
    bool updateScreenAction(const uint32_t &mask) override;

private:

};