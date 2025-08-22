#include "State.hpp"

#include "FreeRTOS.h"
#include "timers.h"
#include "screen_manager.hpp"
TimerHandle_t State::aux_tim = nullptr;
State::AuxTimCB State::cb = nullptr;
void* State::_arg = nullptr;

State::State(StatesID id)
    : _id(id)
    , mIsNeedUpdateScreen(false)
{
    if (aux_tim == nullptr)
    {
        aux_tim = xTimerCreate(  "aux_anim", pdMS_TO_TICKS(5000), pdFALSE, nullptr, [] (TimerHandle_t xTimer)
        {
            if (cb != nullptr) cb(_arg);
        });
    }
}

State::~State()
{
}

void State::activate(void* arg)
{
}

void State::deactivate()
{
}

bool State::updateScreen(const uint32_t &mask)
{
    if (screen_manager::screen_pt() == nullptr)
    {
        printf("Huyavert\n\r");
        return false;
    }

    return updateScreenAction(mask);
}

bool State::updateScreenAction(const uint32_t &mask)
{
    return false;
}

void State::needUpdateScreen()
{
    mIsNeedUpdateScreen = true;
}

bool State::isNeedUpdateScreen()
{
    if (!mIsNeedUpdateScreen)
    {
        return false;
    }
    else
    {
        mIsNeedUpdateScreen = false;
        return true;
    }
}

void State::AUXTIM_start()
{
    if (aux_tim == nullptr) 
        return;    

    xTimerReset(aux_tim, portMAX_DELAY);
}

void State::AUXTIM_stop()
{
    if (aux_tim == nullptr) 
        return;

    xTimerStop(aux_tim, portMAX_DELAY);
}

void State::AUXTIM_clear()
{
    if (aux_tim == nullptr) 
        return;

    xTimerStop(aux_tim, portMAX_DELAY);
    vTimerSetReloadMode(aux_tim, pdFALSE);
    cb = nullptr;
    _arg = nullptr;
}

void State::AUXTIM_set_CB(AuxTimCB c, void* a, int per, bool autorel)
{
    if (aux_tim == nullptr) 
        return;

    vTimerSetReloadMode(aux_tim, autorel ? pdTRUE : pdFALSE);
    xTimerChangePeriod(aux_tim, pdMS_TO_TICKS(per), portMAX_DELAY);
    _arg = a;
    cb = c;
    xTimerStop(aux_tim, portMAX_DELAY);
}

void State::AUXTIM_set_interval(int i)
{
    if (aux_tim == nullptr) 
        return;

    xTimerChangePeriod(aux_tim, pdMS_TO_TICKS(i), portMAX_DELAY);
}

void State::AUXTIM_set_autoreload(bool st)
{
    if (aux_tim == nullptr) 
        return;
        
    vTimerSetReloadMode(aux_tim, st ? pdTRUE : pdFALSE);
}