#include "screen_second.hpp"
#include "StateMachine.hpp"

screen_second::screen_second(SemaphoreHandle_t mux, int screen_id)
    : screen_base(mux, screen_id)
{
    printf("[screen_second]:::CONSTRUCTOR\r\n");
};

screen_second::~screen_second() 
{   
    printf("[screen_second]:::CONSTRUCTOR\r\n");
};

void screen_second::updateScreenAction(std::string a, int b)
{
    printf("[screen_second]::updateScreenAction\r\n");
    lv_label_set_text(objects.odd_even, a.c_str());
    lv_label_set_text_fmt(objects.arc_val, "%d", b);
};

// ====================================================================

void action_arc_value(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    printf("action_arc_val; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_arc(lv_arc_get_value(objects.arc)));
    // lv_label_set_text_fmt(objects.arc_val, "%d", lv_arc_get_value(objects.arc));
}

void action_button5_action(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    printf("action_button5_action; Event: %d\r\n", ev);

    StateMachine::changeState(StatesID::on_state);
}