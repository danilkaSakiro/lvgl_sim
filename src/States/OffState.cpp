#include "OffState.hpp"
#include "screen_manager.hpp"

OffState::OffState(StatesID id)
    : State(id)
    , val(0)
{
}

OffState::~OffState()
{
}

void OffState::activate(void* arg)
{
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_SECOND);
}

void OffState::deactivate()
{
}

bool OffState::updateScreenAction(const uint32_t &mask)
{
    screen_manager::screen_pt()->updateScreen((val % 2 != 0) ? "ODD" : "EVEN", val);
    
    return true;
}

bool OffState::onEvent(Event_arc* obj)
{
    val = obj->getVal();
    needUpdateScreen();
    return true;
}