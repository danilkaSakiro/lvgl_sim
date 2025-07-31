#include "MenuState.hpp"

MenuState::MenuState(StatesID id) 
    : State(id) 
{
    printf("MenuState::MenuState == CONSTRUCTOR\r\n");
}
MenuState::~MenuState() 
{
    printf("MenuState::MenuState == DESTRUCTOR\r\n");
}

void MenuState::activate(void* arg)
{
    AUXTIM_set_CB([](void* arg)
    {

    }, this, 1000, false);
    printf("MenuState::activate\r\n");
}

void MenuState::deactivate()
{
    printf("MenuState::deactivate\r\n");
}

bool MenuState::updateScreenAction(const uint32_t &mask)
{
    printf("MenuState::updateScreen\r\n");

    return true;
}

bool MenuState::onEvent(Event_btn* obj)
{

    return true;
}