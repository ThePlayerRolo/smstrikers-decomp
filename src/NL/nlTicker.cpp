#include "NL/nlTicker.h"

#include <dolphin/os.h>

float unk_241 = 4503599627370496.0;
float unk_239 = 0.001f;

/**
 * Offset/Address/Size: 0x0 | 0x801D2874 | size: 0x58
 */
f32 nlGetTickerDifference(uint arg0, uint arg1) 
{
    uint var2;
    float var1;
    var1 = unk_239;
    var2 = arg1 - arg0;
    
    if (arg0 == arg1) {
        return var1 * (f32) ((u32) (var2 * 8) / __OSBusClock);
    } else  {
        return var1 * (f32) ((u32) (var2 * 8) / __OSBusClock);
    }
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
