#include "Game/PadMonkey.h"

/**
 * Offset/Address/Size: 0x39C | 0x80194B34 | size: 0xF4
 */
PadMonkey::PadMonkey(int)
{
}

/**
 * Offset/Address/Size: 0x338 | 0x80194AD0 | size: 0x64
 */
u32 PadMonkey::IsPressed(int, bool)
{
    return 0;
}

/**
 * Offset/Address/Size: 0x2E8 | 0x80194A80 | size: 0x50
 */
f32 PadMonkey::GetPressure(int, bool)
{
    return 0.0f;
}

/**
 * Offset/Address/Size: 0x270 | 0x80194A08 | size: 0x78
 */
u32 PadMonkey::PlatJustPressed(int, bool)
{
    return 0;
}

/**
 * Offset/Address/Size: 0x1F8 | 0x80194990 | size: 0x78
 */
u32 PadMonkey::PlatJustReleased(int, bool)
{
    return 0;
}

/**
 * Offset/Address/Size: 0x1F0 | 0x80194988 | size: 0x8
 */
f32 PadMonkey::GetButtonStateTime(int, bool)
{
    return 0.0f;
}

/**
 * Offset/Address/Size: 0x48 | 0x801947E0 | size: 0x1A8
 */
void PadMonkey::Update(float dt)
{
}

/**
 * Offset/Address/Size: 0x0 | 0x80194798 | size: 0x48
 */
void PadMonkey::SetButtonChance(int, float)
{
}
