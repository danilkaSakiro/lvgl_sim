#pragma once
#include "OnState.hpp"

class ErrorState : public OnState
{

public:
         ErrorState(StatesID id);
         ~ErrorState() override;
    void activate(void* arg) override;
    void deactivate() override;

    bool onEvent(Event_btn* obj) override;

protected:
    bool updateScreenAction(const uint32_t &mask) override;
    

private:
    bool ledStatus;
};