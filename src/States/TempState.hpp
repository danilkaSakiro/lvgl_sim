#pragma once
#include "MainState.hpp"

class TempState : public MainState
{
public:
    TempState(StatesID id);
    ~TempState() override;

    void activate(void* arg) override;
    void deactivate() override;

    bool onEvent(Event_btn* obj) override;

    int getC() const { return c; }
    void setC(int value) { c = value; }

    int getCPreview() const { return c_preview; }
    void setCPreview(int value) { c_preview = value; }

    bool isTempChanged() const { return temp_changed; }
    void setTempChanged(bool value) { temp_changed = value; }

protected:
    bool updateScreenAction(const uint32_t &mask) override;


private:
    int c;
    int c_preview;
    bool temp_changed;

};