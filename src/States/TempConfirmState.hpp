#pragma once
#include "TempState.hpp"

class TempConfirmState : public TempState
{
public:
    TempConfirmState(StatesID id);
    ~TempConfirmState() override;

    void activate(void* arg) override;
    void deactivate() override;

    bool onEvent(Event_change_temp* obj) override;

private:

};