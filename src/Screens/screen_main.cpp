#include "screen_main.hpp"
#include <cstdlib>
#include "screen_manager.hpp"
#include "StateMachine.hpp"

screen_main::screen_main(SemaphoreHandle_t mux, int screen_id)
    : screen_base(mux, screen_id)
{
    printf("[screen_main]:::CONSTRUCTOR\r\n");
};

screen_main::~screen_main() 
{
    printf("[screen_main]:::DESTRUCTOR\r\n");
};

void screen_main::updateScreenAction(int a, int b, int c) 
{
    printf("[screen_main]::updateScreenAction\r\n");
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
    // lv_label_set_text_fmt(objects.random1, "val %d", rand() % 101);
}

void action_button2_action(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    printf("action_button2_action; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(2));
    // lv_label_set_text_fmt(objects.random2, "val %d", rand() % 101);
}

void action_button3_action(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    printf("action_button3_action; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(3));
    lv_label_set_text_fmt(objects.random3, "val %d", rand() % 101);
}

void action_button4_action(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    printf("action_button4_action; Event: %d\r\n", ev);

    StateMachine::changeState(StatesID::off_state);
    // screen_manager::changeToScreen(ScreensEnum::SCREEN_ID_SECOND);
}
