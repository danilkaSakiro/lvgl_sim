#include "ErrorState.hpp"

ErrorState::ErrorState(StatesID id) 
    : OnState(id)
    , ledStatus(false)
{
    printf("ErrorState::ErrorState == CONSTRUCTOR\r\n");
}

ErrorState::~ErrorState() 
{
    printf("ErrorState::ErrorState == DESTRUCTOR\r\n");
}

void ErrorState::activate(void* arg)
{
    AUXTIM_set_CB([](void* arg)
    {
        ErrorState* ptr = static_cast<ErrorState*>(arg);
        // ets_printf("=========================== Error: FLAG: %x\n", Errors::getErrorFlag());

    }, this, 1000, true);

    AUXTIM_start();

    printf("ErrorState::activate\r\n");
}

void ErrorState::deactivate()
{
    printf("ErrorState::deactivate\r\n");
    AUXTIM_clear();
}

bool ErrorState::updateScreenAction(const uint32_t &mask)
{   
    printf("ErrorState::updateScreen\r\n");
    return true;
}

bool ErrorState::onEvent(Event_btn* obj)
{
    
    return true;
}