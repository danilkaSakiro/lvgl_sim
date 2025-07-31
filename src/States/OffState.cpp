#include "OffState.hpp"
#include "screen_manager.hpp"

OffState::OffState(StatesID id)
    : State(id)
    , val(0)
{
    printf("OffState::OffState == CONSTRUCTOR\r\n");
}

OffState::~OffState()
{
    printf("OffState::OffState == DESTRUCTOR\r\n");
}

void OffState::activate(void* arg)
{
    printf("OffState::activate\r\n");
    screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_SECOND);
}

void OffState::deactivate()
{
    printf("OffState::deactivate\r\n");
}

bool OffState::updateScreenAction(const uint32_t &mask)
{
    printf("OffState::updateScreenAction\r\n");
    screen_manager::screen_pt()->updateScreen((val % 2 != 0) ? "ODD" : "EVEN", val);
    
    return true;
}

bool OffState::onEvent(Event_arc* obj)
{
    val = obj->getVal();
    needUpdateScreen();
    return true;
}