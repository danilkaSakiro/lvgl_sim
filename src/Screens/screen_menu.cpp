#include "screen_menu.hpp"
#include <cstdlib>
#include "screen_manager.hpp"
#include "StateMachine.hpp"

// Конструктор
screen_menu::screen_menu(int screen_id)
    : screen_base(screen_id)
{
}

// Деструктор
screen_menu::~screen_menu()
{
}

// Переопределение updateScreenAction
void screen_menu::updateScreenAction(std::string a)
{
    
}

// ====================================================================

void action_time_tool(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    StateMachine::changeState(StatesID::clock_state);
}

void action_timer_tool(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    StateMachine::changeState(StatesID::timer_state);
}

void action_configuration_tool(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    StateMachine::changeState(StatesID::configuration_state);
}

void action_change_tool(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    StateMachine::changeState(StatesID::tool_state);
}

void action_grafik_tool(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    StateMachine::changeState(StatesID::grafik_state);
}

void action_dispetcher_tool(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    StateMachine::changeState(StatesID::dispetcher_state);
}

void action_thems_tool(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    StateMachine::changeState(StatesID::themes_state);
}

void action_visual_tool(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    StateMachine::changeState(StatesID::visual_state);
}

void action_menu_out(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    StateMachine::changeState(StatesID::main_onstate);
}

