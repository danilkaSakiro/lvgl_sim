#pragma once
#include "MenuState.hpp"

enum class ClockSetup {
    HOUR,
    MINUTE,
    DAY,
    MONTH,
    YEAR,
    DONE
};

class ClockState : public MenuState
{
public:
    ClockState(StatesID id);
    ~ClockState() override;

    void activate(void* arg) override;
    void deactivate() override;

    bool onEvent(Event_btn* obj) override;

protected:
    bool updateScreenAction(const uint32_t &mask) override;

private:
    int last_date;
    float last_time;
    ClockSetup step;
    int hour, minute, day, month, year;

};