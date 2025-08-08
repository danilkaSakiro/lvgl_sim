#include "screen_rpm.hpp"
#include "StateMachine.hpp"
#include "screen_manager.hpp"

extern void action_go_mainscreen(lv_event_t * e);
extern void action_confirm(lv_event_t * e);

screen_rpm::screen_rpm(int screen_id)
    : screen_base(screen_id)
{
};

screen_rpm::~screen_rpm() 
{   
};

void screen_rpm::updateScreenAction(int c) 
{
    char buf_RPM[32];
    snprintf(buf_RPM, sizeof(buf_RPM), "%d", c);
    lv_label_set_text(objects.set_rpm_value, buf_RPM);
};

// ====================================================================

void action_inc_rpm(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_inc_rpm; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(7));
}

void action_dec_rpm(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    // printf("action_dec_rpm; Event: %d\r\n", ev);

    EventSystem::throwEvent(new Event_btn(8));
}
