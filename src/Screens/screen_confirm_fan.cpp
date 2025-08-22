#include "screen_confirm_fan.hpp"
#include <cstdlib>
#include "screen_manager.hpp"
#include "StateMachine.hpp"
#include "DeviceSettings/DeviceSettings.hpp"

screen_confirm_fan::screen_confirm_fan(int screen_id)
    : screen_fan(screen_id)
{
};

screen_confirm_fan::~screen_confirm_fan() 
{
};

void screen_confirm_fan::updateScreenAction(int c) 
{

};

// ====================================================================

void action_change_fan(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    FanChanges::setfan_mode_change(true);
    EventSystem::throwEvent(new Event_change_fan);
}

void action_nochange_fan(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    FanChanges::setfan_mode_ch(FanChanges::getfan_mode());
    FanChanges::setfan_mode_change(false);
    StateMachine::changeState(StatesID::fan_onstate);
}

void action_cancel_fan_change(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    FanChanges::setfan_mode_ch(FanChanges::getfan_mode());
    FanChanges::setfan_mode_change(false);
    StateMachine::changeState(StatesID::fan_onstate);
}