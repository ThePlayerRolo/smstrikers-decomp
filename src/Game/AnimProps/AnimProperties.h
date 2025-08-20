#ifndef SOUND_PROP_ACCESSOR_H
#define SOUND_PROP_ACCESSOR_H

#include "types.h"

struct AnimProperties
{
    const char* id;   // 0x00
    const char* clip; // 0x04
    u32 i0;           // 0x08
    float f0;         // 0x0C
    u32 i1;           // 0x10
    u32 i2;           // 0x10
    u32 i3;           // 0x14
    u32 i4;           // 0x18
}; // sizeof = 0x1C

#endif // SOUND_PROP_ACCESSOR_H
