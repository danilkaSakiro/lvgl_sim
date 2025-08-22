#pragma once
#include <cstdint>

enum StatesID : int
{
    noState = -1,
    off_state,
    main_onstate,
    temp_onstate,
    confirm_temp_onstate,
    fan_onstate,
    confirm_fan_onstate,
    menu,
    clock_state,
    timer_state,
    timer_patametr_state,
    main_with_timer_state,
    tool_state,
    configuration_state,
    grafik_state,
    dispetcher_state,
    themes_state,
    visual_state,

    state_count
};

#define STATES_CNT static_cast<int>(StatesID::state_count)