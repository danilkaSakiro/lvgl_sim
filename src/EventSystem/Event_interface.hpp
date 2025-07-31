#pragma once
#include <cstdint>
//########################################################################3

class Event_btn;
class Event_arc;

// class Event_emerg_stop;

// class Event_test_finished;
// class Event_modbus_ok;

class Event_changeState;
class Event_updateScreen;

// class Event_wifi_AP_start;
// class Event_full_reset;
// class Event_network_reset;
// class Event_ocpp_setup_reset;

// class Event_reset_httpd_server;

//########################################################################3

class Event_interface;
class Event
{
public:
    virtual ~Event() = default;
    virtual bool dispatch(Event_interface* event) = 0;
};

class Event_interface
{
public:
    virtual ~Event_interface() {}
    virtual bool onEvent(Event* obj) {return obj->dispatch(this);}

    virtual bool onEvent(Event_btn* obj) {return false;}
    virtual bool onEvent(Event_arc* obj) {return false;}
    virtual bool onEvent(Event_changeState* obj) {return false;}
    virtual bool onEvent(Event_updateScreen* obj) {return false;}

    // virtual bool onEvent(Event_test_finished* obj) {return false;}
    // virtual bool onEvent(Event_emerg_stop* obj) {return false;}
    // virtual bool onEvent(Event_modbus_ok* obj) {return false;}

    // virtual bool onEvent(Event_wifi_AP_start* obj) {return false;}
    // virtual bool onEvent(Event_full_reset* obj) {return false;}
    // virtual bool onEvent(Event_reset_httpd_server* obj) {return false;}
    // virtual bool onEvent(Event_network_reset* obj) {return false;}
    // virtual bool onEvent(Event_ocpp_setup_reset* obj) {return false;}
    
    
};

//==============================--CRTP Event--======================================//
template <typename Child>
class Event_crtp : public Event
{
private:
    static bool access;

public:
    bool dispatch(Event_interface* obj) override 
    {
        if (Child::access)
            return obj->onEvent(static_cast<Child*>(this));
        else
            return true;
    }
    static void setAccess(bool acc) {Child::access = acc;}
    static bool getAccess() {return Child::access;}
};

template<typename Child>
bool Event_crtp<Child>::access = true;

//##################################################################################//
//==============================--User Events--=====================================//

class Event_btn final : public Event_crtp<Event_btn>
{
public:
    Event_btn(uint8_t btn)
        : _btn(btn)
    {}
    uint8_t getBtn() {return _btn;}
private:
    uint8_t _btn;   
};

class Event_arc final : public Event_crtp<Event_arc>
{
public:
    Event_arc(int val)
        : _val(val)
    {}
    int getVal() {return _val;}
private:
    int _val;   
};

// class Event_emerg_stop final : public Event_crtp<Event_emerg_stop> 
// {
// public:
//     Event_emerg_stop(int source)
//         : _source(source)
//     {}
//     int getSource() {return _source;}
// private:
//     int _source;
// };

// class Event_modbus_ok final : public Event_crtp<Event_modbus_ok> {};
// class Event_test_finished final : public Event_crtp<Event_test_finished> {};
class Event_updateScreen final : public Event_crtp<Event_updateScreen> {};

// class Event_wifi_AP_start final : public Event_crtp<Event_wifi_AP_start> {};
// class Event_full_reset final : public Event_crtp<Event_full_reset> {};
// class Event_reset_httpd_server final : public Event_crtp<Event_reset_httpd_server> {};
// class Event_network_reset final : public Event_crtp<Event_network_reset> {};
// class Event_ocpp_setup_reset final : public Event_crtp<Event_ocpp_setup_reset> {};

class Event_changeState final : public Event_crtp<Event_changeState>
{
public:
    using CancelFunc = bool(*)();

public:
    Event_changeState() 
        : m_id(-1)
        , m_data(nullptr)
        , m_cancelMask(0)
        , m_func(nullptr)
        , m_allowDeactivate(true) {}
    Event_changeState(int id, void* data = nullptr) 
        : m_id(id)
        , m_data(data)
        , m_cancelMask(0)
        , m_func(nullptr)
        , m_allowDeactivate(true) {}
    Event_changeState(int id, uint32_t cancelMask, void* data = nullptr) 
        : m_id(id)
        , m_data(data)
        , m_cancelMask(cancelMask)
        , m_func(nullptr)
        , m_allowDeactivate(true) {}

    void        disableDeactivate() {m_allowDeactivate = false;}
    bool        isAllowDeactivate() {return m_allowDeactivate;}
    bool        checkCancelFunc() {return (m_func == nullptr) ? false : m_func();}
    uint32_t    getCancelMask() {return m_cancelMask;}
    void        setCancelMask(uint32_t mask) {m_cancelMask = mask;}
    int         getId() {return m_id;}
    void        setId(int id) {m_id = id;}
    void*       getData() {return m_data;}

private:
    int         m_id;
    void*       m_data;
    uint32_t    m_cancelMask;
    CancelFunc  m_func;
    bool        m_allowDeactivate;
};


