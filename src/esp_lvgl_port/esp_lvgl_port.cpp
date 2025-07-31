#include "esp_lvgl_port.h"
#include "FreeRTOS.h"
#include "semphr.h"

namespace
{
    SemaphoreHandle_t _mux = nullptr;  
};


void lvgl_port_init()
{
    _mux = xSemaphoreCreateMutex();
}

bool lvgl_port_lock(int val)
{
    if( xSemaphoreGetMutexHolder(_mux) != xTaskGetCurrentTaskHandle() )
        return xSemaphoreTake(_mux, portMAX_DELAY);
    else
        return false;
}

void lvgl_port_unlock()
{
    xSemaphoreGive(_mux);
}