#include "EventSystem.hpp"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include <stdio.h>

QueueHandle_t EventSystem::xQueue = nullptr;
std::list<Event_interface*> EventSystem::subscribers_list;

void EventSystem::init()
{
    xQueue = xQueueCreate(64, sizeof(Event*));
    xTaskCreate(EventTask, "Evnt_Task", 8192, NULL, 4, NULL);
}

void EventSystem::throwEvent(Event *event, bool highPrior)
{
    if (highPrior)
    {
        xQueueSendToFront(xQueue, &event, portMAX_DELAY);
    }
    else
    {
        xQueueSendToBack(xQueue, &event, portMAX_DELAY);
    }
        
}

void EventSystem::throwEventNoBlock(Event *event, bool highPrior)
{
    if (highPrior)
    {
        xQueueSendToFront(xQueue, &event, 0);
    }
    else
    {
        xQueueSendToBack(xQueue, &event, 0);
    }
}

void EventSystem::subscribe(Event_interface *ptr)
{
    subscribers_list.push_back(ptr);
}

//########################################################################################################
//##########################################--Events Task--###############################################
//########################################################################################################
void EventSystem::EventTask(void *pvParameters)
{
    Event* event = nullptr;
    for(;;)
    {
        xQueueReceive(xQueue, &event, portMAX_DELAY);
        for (auto sbscr : subscribers_list)
        {
            if (sbscr->onEvent(event)) break;
        }
        delete event;
    }
}