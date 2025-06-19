#ifndef _EVENTMAN_H_
#define _EVENTMAN_H_

// void nlDeleteDLRing<EventHandler>(EventHandler**);
// void nlDLRingRemoveStart<Event>(Event**);
// void nlDLRingGetStart<EventHandler>(EventHandler*);
// void nlDLRingRemove<EventHandler>(EventHandler**, EventHandler*);
// void nlDLRingRemove<Event>(Event**, Event*);
// void nlDLRingAddEnd<EventHandler>(EventHandler**, EventHandler*);
// void nlDLRingAddEnd<Event>(Event**, Event*);
// void nlDLRingAddStart<Event>(Event**, Event*);
// void nlDLRingAddStart<EventHandler>(EventHandler**, EventHandler*);
// void nlDeleteRing<EventHandler>(EventHandler**);

class EventHandler;
class Event;

class EventManager
{
public:
    virtual ~EventManager();

    void DispatchEvents();
    void CreateValidEvent(unsigned long, unsigned long);
    void AllocateDestArray(unsigned long, unsigned long);
    void RemoveEventHandler(EventHandler*);
    void AddEventHandler(void (*)(Event*, void*), void*, unsigned long);
    void Create(unsigned long, unsigned long);
};

#endif // _EVENTMAN_H_
