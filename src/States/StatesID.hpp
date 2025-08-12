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

    state_count
};

#define STATES_CNT static_cast<int>(StatesID::state_count)