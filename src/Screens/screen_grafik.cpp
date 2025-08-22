#include "screen_grafik.hpp"
#include "StateMachine.hpp"
#include "screen_manager.hpp"

screen_grafik::screen_grafik(int screen_id)
    : screen_menu(screen_id)
{
};

screen_grafik::~screen_grafik() 
{   
};

void screen_grafik::updateScreenAction(int c) 
{
    char buf[32];
    snprintf(buf, sizeof(buf), "%d", TempChanges::gettemperature());
    lv_label_set_text(objects.target_temp_grafik, buf);
};

// ====================================================================

void action_out_grafik(lv_event_t * e)
{
    auto ev = lv_event_get_code(e);
    StateMachine::changeState(StatesID::menu);
}
