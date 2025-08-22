#pragma once
#include "State.hpp"

class MenuState : public State
{
public:
    MenuState(StatesID id);
    ~MenuState() override;

    void activate(void* arg) override;
    void deactivate() override;

protected:
    bool updateScreenAction(const uint32_t &mask) override;

private:
    bool returnToToolsPending = false;
};