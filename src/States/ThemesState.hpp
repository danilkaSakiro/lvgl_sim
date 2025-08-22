#pragma once
#include "MenuState.hpp"

class ThemesState : public MenuState
{
public:
    ThemesState(StatesID id);
    ~ThemesState() override;

    void activate(void* arg) override;
    void deactivate() override;

    bool onEvent(Event_btn* obj) override;

protected:
    bool updateScreenAction(const uint32_t &mask) override;

private:

};