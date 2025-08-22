#pragma once
#include "TimerState.hpp"

class TimerParametrsState : public TimerState
{
public:
    TimerParametrsState(StatesID id);
    ~TimerParametrsState() override;

    void activate(void* arg) override;
    void deactivate() override;

    bool onEvent(Event_btn* obj) override;

protected:
    bool updateScreenAction(const uint32_t &mask) override;

private:


};