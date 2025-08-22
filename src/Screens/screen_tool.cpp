#include "screen_tool.hpp"
#include <cstdlib>
#include "screen_manager.hpp"
#include "StateMachine.hpp"

// Конструктор
screen_tool::screen_tool(int screen_id)
    : screen_menu(screen_id)
{
}

// Деструктор
screen_tool::~screen_tool()
{
}

// Переопределение updateScreenAction
void screen_tool::updateScreenAction(std::string a)
{
    
}

// ====================================================================

void action_out_setting(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_out_setting; Event: %d\r\n", ev);

    StateMachine::changeState(StatesID::clock_state);
}
