#pragma once
#include "State.hpp"

class MenuState : public State
{
public:
    MenuState(StatesID id);
    ~MenuState() override;

    void activate(void* arg) override;
    void deactivate() override;

    bool onEvent(Event_btn* obj) override;

protected:
    bool updateScreenAction(const uint32_t &mask) override;

private:
    
};