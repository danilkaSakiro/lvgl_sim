#include "screen_second.hpp"
#include "StateMachine.hpp"
#include "screen_manager.hpp"

screen_second::screen_second(int screen_id)
    : screen_base(screen_id)
{
};

screen_second::~screen_second() 
{   
};

void screen_second::updateScreenAction(std::string a, int b)
{
    lv_label_set_text(objects.odd_even, a.c_str());
    lv_label_set_text_fmt(objects.arc_val, "%d", b);
};

// ====================================================================

void action_arc_value(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    printf("action_arc_value; Event: %d\r\n", ev);
    EventSystem::throwEventNoBlock(new Event_arc(lv_arc_get_value(objects.arc)));
}

void action_button5_action(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    printf("action_button5_action; Event: %d\r\n", ev);

    StateMachine::changeState(StatesID::on_state);
}