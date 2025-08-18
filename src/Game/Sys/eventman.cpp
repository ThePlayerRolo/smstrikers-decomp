#include "eventman.h"

#include "NL/nlString.h"
#include "NL/nlDLRing.h"
#include "NL/nlMemory.h"

EventManager* g_pEventManager = 0;

/**
 * Offset/Address/Size: 0x488 | 0x801FAE08 | size: 0x94
 */
EventManager::~EventManager()
{
    if (m_pool)
    {
        delete (u32*)m_pool;
    }

    if (m_dest)
    {
        delete[] m_dest;
        m_dest = 0;
    }

    if (m_handlers)
    {
        nlDeleteDLRing(&m_handlers);
    }
}

/**
 * Offset/Address/Size: 0x370 | 0x801FACF0 | size: 0x118
 */
void EventManager::Create(unsigned long count, unsigned long size)
{
    EventManager* m = (EventManager*)nlMalloc(sizeof(EventManager), 8, false);
    if (m)
    {
        // Zero all state (matches stores in asm)
        m->m_dispatching = 0;
        m->m_handlers = 0;
        m->m_free = 0;
        m->m_keep = 0;
        m->m_queue = 0;
        m->m_deferred = 0;
        m->m_dest = 0;
        m->m_pool = 0;
        m->m_count = count; // +0x20
        m->m_size = size;   // +0x24

        // Allocate pool: count * size
        u32 total = m->m_count * m->m_size;
        m->m_pool = nlMalloc(total, 8, false);

        nlPrintf("Event Manager: Allocating %d events of size %d. Total = %d bytes\n", m->m_count, m->m_size, total); // @342

        for (u32 i = 0; i < m->m_count; ++i)
        {
            char* base = (char*)m->m_pool + i * m->m_size;
            Event* e = (Event*)base;
            e->m_next = 0;
            e->m_prev = 0;
            e->m_flags = 0;
            // EventData vptr is set by constructing the subobject; we only need it to be a valid base
            // The original TU writes the vptr slot; letting the compiler emit that via default ctor:
            new (&e->m_data) EventData();
            nlDLRingAddEnd(&m->m_free, e);
        }

        // Finish default destination setup
        m->SetupDestArray();
    }
    g_pEventManager = m;
}

/**
 * Offset/Address/Size: 0x30C | 0x801FAC8C | size: 0x64
 */
EventHandler* EventManager::AddEventHandler(EventCallback callback, void* arg1, unsigned long arg2)
{
    EventHandler* temp_r3 = (EventHandler*)nlMalloc(0x14, 8, 0);
    temp_r3->callback = callback;
    temp_r3->mask = arg2;
    temp_r3->unkC = arg1;
    nlDLRingAddEnd<EventHandler>(&this->m_handlers, temp_r3);
    return temp_r3;
}

/**
 * Offset/Address/Size: 0x2D4 | 0x801FAC54 | size: 0x38
 */
void EventManager::RemoveEventHandler(EventHandler* h)
{
    nlDLRingRemove<EventHandler>(&m_handlers, h);
    delete h;
}

/**
 * Offset/Address/Size: 0x1C4 | 0x801FAB44 | size: 0x110
 */
void EventManager::AllocateDestArray(unsigned long count, unsigned long maskDefault)
{
    m_dest = (u32*)nlMalloc(count * sizeof(u32), 8, false);
    for (u32 i = 0; i < count; ++i)
    {
        m_dest[i] = maskDefault;
    }
}

/**
 * Offset/Address/Size: 0xF4 | 0x801FAA74 | size: 0xD0
 */
Event* EventManager::CreateValidEvent(unsigned long type, unsigned long sizeCheck)
{
    if (sizeCheck > m_size)
    {
        nlPrintf("Event Manager: Size mismatch on event creation (%d vs %d)!\n", sizeCheck, m_size); // @326
        return 0;
    }

    Event* e;
    if (!m_free)
    {
        nlPrintf("Event Manager: There are no more free events in the free event list!\n"); // @293
        e = 0;
    }
    else
    {
        e = nlDLRingRemoveStart(&m_free);
        if (m_dispatching)
        {
            nlDLRingAddEnd(&m_deferred, e);
        }
        else
        {
            nlDLRingAddEnd(&m_queue, e);
        }
    }

    if (!e)
        return 0;
    e->m_type = type; // stw at +0x08
    return e;

    // Event* var_r31;
    // u32 temp_r4;

    // temp_r4 = this->unk24;
    // if (arg1 > temp_r4)
    // {
    //     nlPrintf("Event Manager: Size mismatch on event creation (%d vs %d)!\n", temp_r4);
    //     return NULL;
    // }
    // if (this->m_free == NULL)
    // {
    //     nlPrintf("Event Manager: There are no more free events in the free event list!\n", temp_r4);
    //     var_r31 = NULL;
    // }
    // else
    // {
    //     var_r31 = nlDLRingRemoveStart<Event>(&this->m_free);
    //     // if (this->unk0 != 0)
    //     if (this->m_dispatching) // this is strang... 0x00 cannot exist as class has virtual methods and 0x0 is taken by the vtable
    //     {
    //         nlDLRingAddEnd<Event>(&this->m_deferred, var_r31);
    //     }
    //     else
    //     {
    //         nlDLRingAddEnd<Event>(&this->m_queue, var_r31);
    //     }
    // }
    // if (var_r31 == NULL)
    // {
    //     return NULL;
    // }
    // var_r31->m_type = arg0;
    // return var_r31;
}

/**
 * Offset/Address/Size: 0x0 | 0x801FA980 | size: 0xF4
 */
void EventManager::DispatchEvents()
{

    m_dispatching = 1; // stb 1 at +0
    while (m_queue != 0)
    {
        Event* e = nlDLRingRemoveStart(&m_queue); // free->queue ring
        if (m_handlers != 0)
        {
            EventHandler* it = nlDLRingGetStart(m_handlers);
            EventHandler* end = m_handlers;
            do
            {
                u32 mask = m_dest[e->m_type]; // dest[type]
                if ((it->mask & mask) != 0)
                {
                    void (*fn)(Event*, void*) = it->callback;
                    void* ud = it->unkC;
                    (*fn)(e, ud); // bctrl
                }

                if (it == end)
                    break;

                it = it->m_next;
            } while (1);
        }
        if (e->m_flags != 0)
        {
            nlDLRingAddEnd(&m_keep, e);
        }
        else
        {
            nlDLRingAddEnd(&m_free, e);
        }
    }

    //     Event* event;
    //     EventHandler* eventHandlers;
    //     EventHandler* eventHandler;

    // loop_10:
    //     if (this->m_queue != NULL)
    //     {
    //         eventHandlers = this->unk4;
    //         event = nlDLRingRemoveStart<Event>(&this->m_queue);
    //         if (eventHandlers != NULL)
    //         {
    //             eventHandler = nlDLRingGetStart<EventHandler>(eventHandlers);
    //         loop_3:
    //             // if (eventHandler->unk10 & *(this->unk18[event->unk8]))
    //             if (eventHandler->unk10 == (this->unk18[event->m_type]).unk10)
    //             {
    //                 eventHandler->unk8(event, eventHandler->unkC);
    //             }

    //             if (eventHandler != this->unk4)
    //             {
    //                 eventHandler = eventHandler->m_next;
    //                 goto loop_3;
    //             }
    //         }
    //         if (event->m_flags != 0)
    //         {
    //             nlDLRingAddEnd<Event>(&this->unkC, event);
    //         }
    //         else
    //         {
    //             nlDLRingAddEnd<Event>(&this->unk8, event);
    //         }
    //         goto loop_10;
    //     }

    m_dispatching = 0;
    m_queue = m_deferred;
    m_deferred = NULL;
}

// /**
//  * Offset/Address/Size: 0x0 | 0x801FAE9C | size: 0x20
//  */
// void nlDeleteDLRing<EventHandler>(EventHandler**)
// {
// }

// /**
//  * Offset/Address/Size: 0x20 | 0x801FAEBC | size: 0x38
//  */
// void nlDLRingRemoveStart<Event>(Event**)
// {
// }

// /**
//  * Offset/Address/Size: 0x58 | 0x801FAEF4 | size: 0x18
//  */
// void nlDLRingGetStart<EventHandler>(EventHandler*)
// {
// }

// /**
//  * Offset/Address/Size: 0x70 | 0x801FAF0C | size: 0x44
//  */
// void nlDLRingRemove<EventHandler>(EventHandler**, EventHandler*)
// {
// }

// /**
//  * Offset/Address/Size: 0xB4 | 0x801FAF50 | size: 0x44
//  */
// void nlDLRingRemove<Event>(Event**, Event*)
// {
// }

// /**
//  * Offset/Address/Size: 0xF8 | 0x801FAF94 | size: 0x3C
//  */
// void nlDLRingAddEnd<EventHandler>(EventHandler**, EventHandler*)
// {
// }

// /**
//  * Offset/Address/Size: 0x134 | 0x801FAFD0 | size: 0x3C
//  */
// void nlDLRingAddEnd<Event>(Event**, Event*)
// {
// }

// /**
//  * Offset/Address/Size: 0x170 | 0x801FB00C | size: 0x38
//  */
// void nlDLRingAddStart<Event>(Event**, Event*)
// {
// }

// /**
//  * Offset/Address/Size: 0x1A8 | 0x801FB044 | size: 0x38
//  */
// void nlDLRingAddStart<EventHandler>(EventHandler**, EventHandler*)
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x801FB07C | size: 0x70
//  */
// void nlDeleteRing<EventHandler>(EventHandler**)
// {
// }
