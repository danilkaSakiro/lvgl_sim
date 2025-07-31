#pragma once
#include <cstdint>
#include <unordered_map>
#include <functional>

#include "StatesID.hpp"
#include "EventSystem.hpp"

class State;

class StateMachine : public Event_interface
{
public:
    using StateFabricMethod = std::function<State*()>;

    using FuncPTR = void(*)();

    struct StateParam
    {
        State* st;
        uint32_t bit;
    };

public:
    StateMachine();
    ~StateMachine();

    static StateMachine* pt()
    {
        if (_pt == nullptr) _pt = new StateMachine();
        return _pt;
    }

    template<typename T>
    static void registerState(StatesID id)
    {
        States_fabric.emplace(id, [id]() -> State* {
            return new T(id);
        });
    }

    static State* testFabric(StatesID id) {
        return States_fabric[id]();
    }

    static StatesID       getState();
    static void           changeState(StatesID id, void* data = nullptr);
    static void           changeState(StatesID id, uint32_t cancelMask, void* data = nullptr);
    static void           changeState(StatesID id, uint32_t cancelMask, bool disableDeactivate, void* data = nullptr);

    static inline uint32_t bit(StatesID id)
    {
        if (id == StatesID::noState) return 0;
	    else return 1 << id;
    }

    //=====================--Events--========================//
    bool           onEvent(Event* evnt) override;
    bool           onEvent(Event_changeState* obj) override;
    bool           onEvent(Event_updateScreen* obj) override;
   
private:

private:
    static std::unordered_map<StatesID, StateFabricMethod> States_fabric;
    static State* activeState;
    static StateMachine*  _pt; 
};