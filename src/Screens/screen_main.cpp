#include "screen_main.hpp"
#include <cstdlib>
#include "screen_manager.hpp"
#include "StateMachine.hpp"

screen_main::screen_main(int screen_id)
    : screen_base(screen_id)
{
};

screen_main::~screen_main() 
{
};

void screen_main::updateScreenAction(int a, int b, int c) 
{
    lv_label_set_text_fmt(objects.random1, "val %d", a);
    lv_label_set_text_fmt(objects.random2, "val %d", b);
    lv_label_set_text_fmt(objects.random3, "val %d", c);
};

// ====================================================================

void action_button1_action(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    printf("action_button1_action; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(1));
}

void action_button2_action(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    printf("action_button2_action; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(2));
}

void action_button3_action(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    printf("action_button3_action; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(3));
}

void action_button4_action(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    printf("action_button4_action; Event: %d\r\n", ev);

    StateMachine::changeState(StatesID::off_state);
}
