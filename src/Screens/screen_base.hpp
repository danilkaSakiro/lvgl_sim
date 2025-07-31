#pragma once
#include "FreeRTOS.h"
#include "semphr.h"
#include <string>

class screen_base
{
public:
    screen_base(SemaphoreHandle_t mux, int screen_id) 
        : _mux(mux)
        , _screen_id(screen_id)
    {
        printf("[screen_base]:::CONSTRUCTOR\r\n");
    };
    virtual ~screen_base() {printf("[screen_base]:::DESTRUCTOR\r\n");};
    int id() {return _screen_id;}

    void updateScreen(int a, int b, int c) {
        lvgl_lock();
        updateScreenAction(a, b, c);
        lvgl_unlock();
    };
    void updateScreen(std::string a, int b) {
        lvgl_lock();
        updateScreenAction(a, b);
        lvgl_unlock();
    };

protected:
    virtual void updateScreenAction(int a, int b, int c) {};
    virtual void updateScreenAction(std::string a, int b) {};
    
private:
    void lvgl_lock() {
        if( xSemaphoreGetMutexHolder(_mux) != xTaskGetCurrentTaskHandle() )
            xSemaphoreTake(_mux, portMAX_DELAY);
    }

    void lvgl_unlock() {
        xSemaphoreGive(_mux);
    }

    SemaphoreHandle_t _mux;
    int _screen_id;
};