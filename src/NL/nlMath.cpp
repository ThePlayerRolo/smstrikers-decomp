#include "types.h"

static float fUnk_504 = 0.0000000004656613f;

extern void seedMT(u32 p);

/**
 * Offset/Address/Size: 0x0 | 0x801D1474 | size: 0x1D4
 */
void nlBezier(float*, int, float)
{
}

/**
 * Offset/Address/Size: 0x1D4 | 0x801D1648 | size: 0x244
 */
void nlATan2f(float, float)
{
}

/**
 * Offset/Address/Size: 0x418 | 0x801D188C | size: 0x48
 */
void nlTan(unsigned short)
{
}

/**
 * Offset/Address/Size: 0x460 | 0x801D18D4 | size: 0x12C
 */
void nlACos(float)
{
}

/**
 * Offset/Address/Size: 0x58C | 0x801D1A00 | size: 0x164
 */
void nlSinCos(float*, float*, unsigned short)
{
}

/**
 * Offset/Address/Size: 0x6F0 | 0x801D1B64 | size: 0xA0
 */
void nlSin(unsigned short)
{
}

/**
 * Offset/Address/Size: 0x790 | 0x801D1C04 | size: 0x70
 */
void nlRecipSqrt(float, bool)
{
}

/**
 * Offset/Address/Size: 0x800 | 0x801D1C74 | size: 0xEC
 */
float nlSqrt(float, bool)
{
}

/**
 * Offset/Address/Size: 0x8EC | 0x801D1D60 | size: 0x84
 */
void nlRandomf(float, float, unsigned int*)
{
}

/**
 * Offset/Address/Size: 0x970 | 0x801D1DE4 | size: 0x7C
 */
void nlRandomf(float, unsigned int*)
{
}

/**
 * Offset/Address/Size: 0x9EC | 0x801D1E60 | size: 0x34
 */
int nlRandom(uint param_1, uint* param_2)
{
    uint uVar1;
    uint uVar2;
    uint uVar3;

    uVar1 = *param_2;
    uVar2 = uVar1 ^ 0x1d872b41;
    uVar3 = uVar2 ^ (uVar2 >> 5);
    *param_2 = uVar2 ^ uVar3 ^ (uVar3 << 0x1b);
    return uVar1 - (uVar1 / param_1) * param_1;
}

/**
 * Offset/Address/Size: 0xA20 | 0x801D1E94 | size: 0x2C
 */
void nlSetRandomSeed(uint initialSeed, uint* seedStorage)
{
    uint shiftedValue;
    uint mixedValue;

    *seedStorage = initialSeed;

    mixedValue = *seedStorage ^ 0x1d872b41;        // Mix with constant
    shiftedValue = mixedValue ^ (mixedValue >> 5); // Mix with right-shifted value

    *seedStorage = shiftedValue ^ (mixedValue ^ (shiftedValue << 0x1b)); // Final mixing
}

/**
 * Offset/Address/Size: 0xA4C | 0x801D1EC0 | size: 0x24
 */
void nlInitRandom()
{
    seedMT(0x1105);
}
