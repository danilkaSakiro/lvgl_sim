#pragma once
#include <cstdint>
#include <stdio.h>

#include "EventSystem.hpp"
#include "StatesID.hpp"

struct tmrTimerControl;

class State : public Event_interface
{
public:
    using AuxTimCB = void(*)(void*);

public:
    State(StatesID id);
    virtual ~State() = 0;

    StatesID getStateId() {return _id;}

    virtual void activate(void* arg);
    virtual void deactivate();
    bool updateScreen(const uint32_t &mask);

    void needUpdateScreen();
    bool isNeedUpdateScreen();

    void AUXTIM_start();
    void AUXTIM_stop();
    void AUXTIM_clear();
    void AUXTIM_set_CB(AuxTimCB c, void* a, int per, bool autorel);
    void AUXTIM_set_interval(int i);
    void AUXTIM_set_autoreload(bool st);

protected:
    virtual bool updateScreenAction(const uint32_t &mask);
    
private:
    StatesID _id;
    bool mIsNeedUpdateScreen;
    static tmrTimerControl* aux_tim;
    static AuxTimCB cb;
    static void* _arg;
};