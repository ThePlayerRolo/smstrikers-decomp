#include "eventman.h"

#include "NL/nlString.h"
#include "NL/nlDLRing.h"
#include "NL/nlMemory.h"

/**
 * Offset/Address/Size: 0x488 | 0x801FAE08 | size: 0x94
 */
EventManager::~EventManager()
{
    Event* temp_r3 = this->unk1C;
    if (temp_r3 != NULL)
    {
        delete (temp_r3);
    }
    EventHandler* temp_r3_2 = this->unk18;
    if (temp_r3_2 != NULL)
    {
        delete[] temp_r3_2;
        this->unk18 = NULL;
    }
    if (this->unk4 != NULL)
    {
        nlDeleteDLRing<EventHandler>(&this->unk4);
    }
}

/**
 * Offset/Address/Size: 0x370 | 0x801FACF0 | size: 0x118
 */
void EventManager::Create(unsigned long, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x30C | 0x801FAC8C | size: 0x64
 */
EventHandler* EventManager::AddEventHandler(EventCallback callback, void* arg1, unsigned long arg2)
{
    EventHandler* temp_r3 = (EventHandler*)nlMalloc(0x14, 8, 0);
    temp_r3->unk8 = callback;
    temp_r3->unk10 = arg2;
    temp_r3->unkC = arg1;
    nlDLRingAddEnd<EventHandler>(&this->unk4, temp_r3);
    return temp_r3;
}

/**
 * Offset/Address/Size: 0x2D4 | 0x801FAC54 | size: 0x38
 */
void EventManager::RemoveEventHandler(EventHandler* handler)
{
    nlDLRingRemove<EventHandler>(&this->unk4, handler);
    delete handler;
}
/**
 * Offset/Address/Size: 0x1C4 | 0x801FAB44 | size: 0x110
 */
void EventManager::AllocateDestArray(unsigned long, unsigned long)
{
}

/**
 * Offset/Address/Size: 0xF4 | 0x801FAA74 | size: 0xD0
 */
Event* EventManager::CreateValidEvent(unsigned long arg0, unsigned long arg1)
{
    Event* var_r31;
    u32 temp_r4;

    temp_r4 = this->unk24;
    if (arg1 > temp_r4)
    {
        nlPrintf("Event Manager: Size mismatch on event creation (%d vs %d)!\n", temp_r4);
        return NULL;
    }
    if (this->unk8 == NULL)
    {
        nlPrintf("Event Manager: There are no more free events in the free event list!\n", temp_r4);
        var_r31 = NULL;
    }
    else
    {
        var_r31 = nlDLRingRemoveStart<Event>(&this->unk8);
        // if (this->unk0 != 0)
        if (this->unk14)
        {
            nlDLRingAddEnd<Event>(&this->unk14, var_r31);
        }
        else
        {
            nlDLRingAddEnd<Event>(&this->unk10, var_r31);
        }
    }
    if (var_r31 == NULL)
    {
        return NULL;
    }
    var_r31->unk8 = arg0;
    return var_r31;
}

/**
 * Offset/Address/Size: 0x0 | 0x801FA980 | size: 0xF4
 */
void EventManager::DispatchEvents()
{
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
