#include "screen_tool.hpp"
#include <cstdlib>
#include "screen_manager.hpp"
#include "StateMachine.hpp"

// Конструктор
screen_tool::screen_tool(int screen_id)
    : screen_base(screen_id)
{
}

// Деструктор
screen_tool::~screen_tool()
{
}

// Переопределение updateScreenAction
void screen_tool::updateScreenAction(std::string a)
{
    printf("[screen_tool] Action: %s\n", a.c_str());
}

// Обработчик Wi-Fi
void action_wi_fi_action(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    printf("action_wi_fi_action; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(6));
}

// Обработчик яркости
void action_brightness_action(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    printf("action_brightness_action; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(7));
}

// Обработчик звука
void action_sound_action(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    printf("action_sound_action; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(8));
}


