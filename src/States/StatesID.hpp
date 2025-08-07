#pragma once
#include <cstdint>

enum StatesID : int
{
    noState = -1,
    off_state,
    on_state,
    menu,

    state_count
};

#define STATES_CNT static_cast<int>(StatesID::state_count)