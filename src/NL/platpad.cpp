#include "NL/platpad.h"
#include "Dolphin/pad.h"

#include "global.h"

PadStatus PadStatus::s_A;
PadStatus PadStatus::s_B;
PadStatus* PadStatus::s_Current = &PadStatus::s_A;
PadStatus* PadStatus::s_Next = &PadStatus::s_B;

int g_nPadMasks[] = { 0x80000000, 0x40000000, 0x20000000, 0x10000000 };

bool cPlatPad::m_bDisableRumble = false;

namespace
{
int padCategories[100];
PadStatus* padStatus = &PadStatus::s_A;
} // namespace

/**
 * Offset/Address/Size: 0x0 | 0x801C2FB0 | size: 0x5C
 */
cPlatPad::~cPlatPad()
{
}

/**
 * Offset/Address/Size: 0x5C | 0x801C300C | size: 0x524
 */
void VBlankPadUpdate()
{
}

/**
 * Offset/Address/Size: 0x580 | 0x801C3530 | size: 0x40
 */
void cPlatPad::StopRumble()
{
    padStatus[m_channel].m_rumbleActive = 0;
    PADControlMotor(m_channel, 2);
}

/**
 * Offset/Address/Size: 0x5C0 | 0x801C3570 | size: 0x78
 */
void cPlatPad::StartRumble(float param1, float param2, float param3)
{
    if (m_bDisableRumble == 0)
    {
        PADControlMotor(m_channel, 1);
        padStatus[m_channel].m_rumbleIntensity = param1;
        padStatus[m_channel].m_rumbleActive = 1;
    }
}

/**
 * Offset/Address/Size: 0x638 | 0x801C35E8 | size: 0x18
 */
u8 cPlatPad::RumbleActive()
{
    return padStatus[m_channel].m_rumbleActive;
}

/**
 * Offset/Address/Size: 0x650 | 0x801C3600 | size: 0x18
 */
f32 cPlatPad::AnalogRightY()
{
    return padStatus[m_channel].m_rightY;
}

/**
 * Offset/Address/Size: 0x668 | 0x801C3618 | size: 0x18
 */
f32 cPlatPad::AnalogRightX()
{
    return padStatus[m_channel].m_rightX;
}

/**
 * Offset/Address/Size: 0x680 | 0x801C3630 | size: 0x18
 */
f32 cPlatPad::AnalogLeftY()
{
    return padStatus[m_channel].m_leftY;
}

/**
 * Offset/Address/Size: 0x698 | 0x801C3648 | size: 0x14
 */
f32 cPlatPad::AnalogLeftX()
{
    return padStatus[m_channel].m_leftX;
}

/**
 * Offset/Address/Size: 0x6AC | 0x801C365C | size: 0x8
 */
f32 cPlatPad::GetPressureDerivative(int, bool)
{
    return 0.f;
}

/**
 * Offset/Address/Size: 0x6B4 | 0x801C3664 | size: 0x84
 */
f32 cPlatPad::GetPressure(int button, bool arg2)
{
    s32 var_r4 = button;
    if (arg2 != 0)
    {
        var_r4 = cPadManager::m_pRemapArray[var_r4];
    }
    switch (var_r4)
    { /* irregular */
    case 0x40:
        return padStatus[m_channel].m_pressure1;
    case 0x20:
        return padStatus[m_channel].m_pressure2;
    default:
        if (var_r4 & *(s32*)(PadStatus::s_Current + (m_channel * 0xC)) == 0)
        {
            return 1.f;
        }
        return 0.f;
    }
}

/**
 * Offset/Address/Size: 0x738 | 0x801C36E8 | size: 0x3C
 */
f32 cPlatPad::GetButtonStateTime(int button, bool remap)
{
    s32 var_r4 = button;
    if (remap != 0)
    {
        var_r4 = cPadManager::m_pRemapArray[var_r4];
        // var_r4 = *(cPadManager::m_pRemapArray + (var_r4 * 4));
    }

    // 0x1F - __cntlzw(var_r4) -> is the index of the button state time, looking at the bits of the button-bitfield
    int offset = 0x1F - __cntlzw(var_r4);
    offset = offset * 4;

    return *(f32*)((u8*)padStatus + (m_channel * 0xE0) + offset + 0x18);
}

/**
 * Offset/Address/Size: 0x774 | 0x801C3724 | size: 0x3C
 */
u32 cPlatPad::PlatJustReleased(int button, bool remap)
{
    s32 temp_r3;
    s32 var_r4 = button;
    if (remap != 0)
    {
        var_r4 = cPadManager::m_pRemapArray[var_r4];
    }

    temp_r3 = (uint) * (u16*)((u8*)padStatus + (m_channel << 1) + 0x388) & var_r4;
    return (u32)(-temp_r3 | temp_r3) >> 0x1FU;
}

/**
 * Offset/Address/Size: 0x7B0 | 0x801C3760 | size: 0x3C
 */
u32 cPlatPad::PlatJustPressed(int button, bool remap)
{
    s32 temp_r3;
    s32 var_r4 = button;
    if (remap != 0)
    {
        var_r4 = cPadManager::m_pRemapArray[var_r4];
    }

    temp_r3 = (u32) * (u16*)((u8*)padStatus + (m_channel << 1) + 0x380) & var_r4;
    return (u32)(-temp_r3 | temp_r3) >> 0x1FU;
}

/**
 * Offset/Address/Size: 0x7EC | 0x801C379C | size: 0x38
 */
u32 cPlatPad::IsPressed(int button, bool remap)
{
    s32 temp_r3;
    s32 var_r4 = button;
    if (remap != 0)
    {
        var_r4 = cPadManager::m_pRemapArray[var_r4];
    }

    temp_r3 = var_r4 & *(u16*)((u8*)PadStatus::s_Current + (m_channel * 0xC));
    return (u32)(-temp_r3 | temp_r3) >> 0x1FU;
}

/**
 * Offset/Address/Size: 0x824 | 0x801C37D4 | size: 0x34
 */
bool cPlatPad::IsConnected()
{
    u8 temp_r4;
    temp_r4 = *((u8*)PadStatus::s_Current + (m_channel * 0xC) + 0x0A);
    if (((s8)temp_r4 == 0) || ((s8)temp_r4 == -3))
    {
        return 1;
    }
    return 0;
}

/**
 * Offset/Address/Size: 0x858 | 0x801C3808 | size: 0x270
 */
void PadStatus::Update(float)
{
}

/**
 * Offset/Address/Size: 0xAC8 | 0x801C3A78 | size: 0x24
 */
void UpdatePlatPad(float)
{
}

/**
 * Offset/Address/Size: 0xAEC | 0x801C3A9C | size: 0xB0
 */
void InitPlatPad()
{
}

/**
 * Offset/Address/Size: 0xB9C | 0x801C3B4C | size: 0xC
 */
void GetButtonIndex(int)
{
}

/**
 * Offset/Address/Size: 0xBA8 | 0x801C3B58 | size: 0x10
 */
void UseDefaultPad()
{
}

/**
 * Offset/Address/Size: 0xBB8 | 0x801C3B68 | size: 0x14
 */
void UseFixedUpdatePad()
{
}
