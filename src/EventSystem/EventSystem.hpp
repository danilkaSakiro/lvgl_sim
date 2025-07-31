#pragma once
#include <cstdint>
#include "Event_interface.hpp"
#include <list>

struct QueueDefinition;

class EventSystem
{
public:
    static void               init();
    static void               throwEvent(Event *event, bool highPrior = false);
    static void               subscribe(Event_interface *ptr);

private:
    EventSystem();

    static void               EventTask(void *pvParameters);

private:
    static QueueDefinition*   xQueue;
    static std::list<Event_interface*> subscribers_list;
};