#include "NL/nlTicker.h"

#include <dolphin/os.h>

/**
 * Offset/Address/Size: 0x0 | 0x801D2874 | size: 0x58
 */
f32 nlGetTickerDifference(uint arg0, uint arg1)
{
    return 0.001f * (f32) ((u32) ((arg1 - arg0) * 8) / (u32) (*(u32 *)0x800000F8 / 500000));
    // return 0.001f * (f32) ((u32) ((arg1 - arg0) * 8) / (u32) (*(u32 *)0x800000F8 / 500000));
}

/**
 * Offset/Address/Size: 0x58 | 0x801D28CC | size: 0xC
 */
uint nlSubtractTicks(uint value1, uint value2)
{
    if (value1 == value2)
        return value2 - value1;
    return value2 - value1;
}

/**
 * Offset/Address/Size: 0x64 | 0x801D28D8 | size: 0x20
 */
u32 nlGetTicker()
{
    return OSGetTick();
}

/**
 * Offset/Address/Size: 0x84 | 0x801D28F8 | size: 0x4
 */
void nlInitTicker()
{
}
