#ifndef _EVENTMAN_H_
#define _EVENTMAN_H_

#include "types.h"

class EventHandler;
class EventManager;

typedef struct Event /* size >= 0x14 */
{
    /* 0x00 */ Event* m_next;
    /* 0x04 */ Event* m_prev;
    /* 0x08 */ u32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ void* unk10;
} Event;

class EventHandler /* size >= 0x2C */
{
public:
    /* 0x00 */ s8 unk0;
    /* 0x01 */ char pad1[3];
    /* 0x04 */ EventHandler* m_next;
    /* 0x08 */ Event* unk8;
    /* 0x0C */ void* unkC;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ EventHandler* m_prev;
    /* 0x20 */ EventManager* m_manager;
    /* 0x24 */ u32 unk24;
    // /* 0x28 */ struct __vt__12EventManager* vtable28; /* inferred */
};

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

class EventManager
{
public:
    virtual ~EventManager();

    void Create(unsigned long, unsigned long);
    void AddEventHandler(void (*)(Event*, void*), void*, unsigned long);
    void RemoveEventHandler(EventHandler*);
    void AllocateDestArray(unsigned long, unsigned long);
    void CreateValidEvent(unsigned long, unsigned long);
    void DispatchEvents();

    /* 0x04 */ EventHandler* unk4;
    /* 0x08 */ Event* unk8;
    /* 0x0C */ Event* unkC;
    /* 0x10 */ Event* unk10;
    /* 0x14 */ Event* unk14;
    /* 0x18 */ EventHandler* unk18;
    /* 0x1C */ void* unk1C;
    /* 0x20 */ char pad20[4];
    /* 0x24 */ u32 unk24;
};

#endif // _EVENTMAN_H_
