#include "screen_confirm_temp.hpp"
#include <cstdlib>
#include "screen_manager.hpp"
#include "StateMachine.hpp"
#include "DeviceSettings/DeviceSettings.hpp"

screen_confirm_temp::screen_confirm_temp(int screen_id)
    : screen_temp(screen_id)
{
};

screen_confirm_temp::~screen_confirm_temp() 
{
};

void screen_confirm_temp::updateScreenAction(int c) 
{

};

// ====================================================================

void action_change_temp(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    TempChanges::settemp_change(true);
    EventSystem::throwEvent(new Event_change_temp);

}

void action_nochange_temp(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    TempChanges::settemperature_ch(TempChanges::gettemperature());
    TempChanges::settemp_change(false);
    StateMachine::changeState(StatesID::temp_onstate);
}

void action_cancel_temperature_change(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    TempChanges::settemp_change(false);
    TempChanges::settemperature_ch(TempChanges::gettemperature());
    StateMachine::changeState(StatesID::temp_onstate);
}