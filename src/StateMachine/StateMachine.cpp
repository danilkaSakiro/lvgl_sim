#include "StateMachine.hpp"
#include "EventSystem.hpp"
#include <stdio.h>
#include "State.hpp"
#include <iostream>

#define STATE_STACK_TAG "STATE_STACK"

// namespace
// {
//     SemaphoreHandle_t _mux = nullptr;
// };

StateMachine*                                               StateMachine::_pt = nullptr; 

std::unordered_map<StatesID, StateMachine::StateFabricMethod> StateMachine::States_fabric;
State* StateMachine::activeState;
SemaphoreHandle_t StateMachine::_mux = nullptr;

StateMachine::StateMachine()
    : Event_interface()
{
    if (_mux == nullptr)
        _mux = xSemaphoreCreateMutex();
}

StateMachine::~StateMachine()
{
}

bool StateMachine::onEvent(Event* evnt)
{
    bool ret = false;
    ret = evnt->dispatch(this);
    if (!ret && activeState != nullptr)
    {
        ret = evnt->dispatch(activeState);

        if (ret && activeState->isNeedUpdateScreen()) 
            activeState->updateScreen(0xFFFFFFFF);
    }
    return ret;
}

bool StateMachine::onEvent(Event_changeState* obj)
{
    printf("[StateMachine]::Change State to %d\r\n", (int)(obj->getId()));

    StatesID mId = (StatesID)obj->getId();

    if (mId == StatesID::noState)
    {
        printf("[StateMachine]::Cant change to StatesID::noState\r\n");
        return true;
    }

    if (States_fabric.find(mId) == States_fabric.end()) 
    {
        printf("[StateMachine]::State is not registered\r\n");
        return true;
    }

    xSemaphoreTake(_mux, portMAX_DELAY);

    if (activeState != nullptr)
    { 
        if (obj->getCancelMask() & bit(activeState->getStateId())) 
        {
            xSemaphoreGive(_mux);
            return true;
        }

        if (obj->isAllowDeactivate())
        {
            activeState->deactivate();
        }

        delete activeState;
        activeState = nullptr;
    }

    activeState = States_fabric[mId]();

    xSemaphoreGive(_mux);

    activeState->activate(obj->getData());
    // activeState->updateScreen(0xFFFFFFFF);
    
    return true;
}

bool StateMachine::onEvent(Event_updateScreen* obj)
{
    if (activeState != nullptr) 
        activeState->updateScreen(0xFFFFFFFF);

    return true;
}

void StateMachine::changeState(StatesID id, void* data)
{
    EventSystem::throwEvent(new Event_changeState(id, data), true);
}

void StateMachine::changeState(StatesID id, uint32_t cancelMask, void* data)
{
    EventSystem::throwEvent(new Event_changeState(id, cancelMask, data), true);
}

void StateMachine::changeState(StatesID id, uint32_t cancelMask, bool disableDeactivate, void* data)
{
    Event_changeState* evnt = new Event_changeState(id, cancelMask, data);
    if (disableDeactivate) 
        evnt->disableDeactivate();
    EventSystem::throwEvent(evnt, true);
}

void StateMachine::changeState(State* existingState)
{
    xSemaphoreTake(_mux, portMAX_DELAY);

    if (activeState != nullptr)
    {
        activeState->deactivate();
        delete activeState;
    }

    activeState = existingState;

    xSemaphoreGive(_mux);

    if (activeState != nullptr)
    {
        activeState->activate(nullptr);
        // activeState->updateScreen(0xFFFFFFFF);
    }
}

StatesID StateMachine::getState()
{
    xSemaphoreTake(_mux, portMAX_DELAY);
    StatesID id = activeState == nullptr ? StatesID::noState : activeState->getStateId();
    xSemaphoreGive(_mux);

    return id;
}

MainState* StateMachine::getCurrentState()
{
    MainState* ptr = nullptr;
    xSemaphoreTake(_mux, portMAX_DELAY);
    ptr = dynamic_cast<MainState*>(activeState);
    xSemaphoreGive(_mux);
    return ptr;
}