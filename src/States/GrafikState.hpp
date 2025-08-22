#pragma once
#include "MenuState.hpp"

class GrafikState : public MenuState
{
public:
    GrafikState(StatesID id);
    ~GrafikState() override;

    void activate(void* arg) override;
    void deactivate() override;

protected:
    bool updateScreenAction(const uint32_t &mask) override;

private:
    int target_temp, onroom_temp, real_temp;
};