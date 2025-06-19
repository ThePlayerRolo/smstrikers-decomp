#include "NL/platpad.h"

#include "PowerPC_EABI_Support/Runtime/__mem.h"

#include "global.h"

PADStatus PadStatus::s_A;
PADStatus PadStatus::s_B;
PADStatus* PadStatus::s_Current = &PadStatus::s_A;
PADStatus* PadStatus::s_Next = &PadStatus::s_B;

int g_nPadMasks[PAD_MAX_CONTROLLERS] = { 0x80000000, 0x40000000, 0x20000000, 0x10000000 };

bool cPlatPad::m_bDisableRumble = false;

namespace
{
PadStatus padCategories[PAD_MAX_CONTROLLERS];
PadStatus* padStatus = NULL;
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
        if ((var_r4 & PadStatus::s_Current[m_channel].button) != 0)
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

    temp_r3 = var_r4 & PadStatus::s_Current[m_channel].button;
    return (u32)(-temp_r3 | temp_r3) >> 0x1FU;
}

/**
 * Offset/Address/Size: 0x824 | 0x801C37D4 | size: 0x34
 */
bool cPlatPad::IsConnected()
{
    s8 err = PadStatus::s_Current[m_channel].err;
    if ((err != 0) && (err != -3))
    {
        return 0;
    }
    return 1;
}

/**
 * Offset/Address/Size: 0x858 | 0x801C3808 | size: 0x270
 */
void PadStatus::Update(float)
{
    s32* var_r28;
    s32 var_r26;
    s32 var_r31;
    u32 var_r27;
    u8 temp_r4;
    void* temp_r3;
    void* var_r29;
    void* var_r30;

    var_r27 = 0;
    // var_r28 = &g_nPadMasks;
    var_r26 = 0;
    // var_r30 = arg0;
    // var_r29 = arg0;
    var_r31 = 0;
    do
    {
        temp_r3 = PadStatus::s_Current + var_r31;
        // temp_r4 = temp_r3->unkA;
        if ((s8)temp_r4 == 0)
        {
            // var_r30->unk0 = (f32) ((f32) (s8) temp_r3->unk2 / @496);
            // var_r30->unk4 = (f32) ((f32) (s8) *(s_Current__9PadStatus + (var_r31 + 3)) / @496);
            // var_r30->unk8 = (f32) ((f32) (s8) *(s_Current__9PadStatus + (var_r31 + 4)) / @589);
            // var_r30->unkC = (f32) ((f32) (s8) *(s_Current__9PadStatus + (var_r31 + 5)) / @589);
            // var_r30->unk10 = (f32) ((f32) *(s_Current__9PadStatus + (var_r31 + 6)) / @590);
            // var_r30->unk14 = (f32) ((f32) *(s_Current__9PadStatus + (var_r31 + 7)) / @590);
            // var_r29->unk380 = (s16) (*(s_Current__9PadStatus + var_r31) & ~var_r29->unk390);
            // var_r29->unk388 = (s16) (var_r29->unk390 & ~*(s_Current__9PadStatus + var_r31));
            // var_r29->unk390 = (u16) *(s_Current__9PadStatus + var_r31);
            // *(arg0 + (var_r26 + 0x398)) = *(s_Current__9PadStatus + (var_r31 + 0xA));
        }
        else if ((s8)temp_r4 == -1)
        {
            // if ((s8) *(arg0 + (var_r26 + 0x398)) == 0) {
            //     memset(var_r30, 0, 0xE0);
            // }
            // var_r29->unk380 = 0;
            // var_r27 |= *var_r28;
            // var_r29->unk388 = 0;
            // var_r29->unk390 = 0U;
        }
        // if ((u8) var_r30->unkDC != 0) {
        // var_r30->unkD8 = (f32) (var_r30->unkD8 - arg8);
        // if (var_r30->unkD8 < @498) {
        //     var_r30->unkDC = 0U;
        //     PADControlMotor(var_r26, 0);
        // }
        // }
        // var_r26 += 1;
        // var_r30 += 0xE0;
        // var_r29 += 2;
        // var_r28 += 4;
        // var_r31 += 0xC;
    } while (var_r26 < 4);

    if (var_r27 != 0)
    {
        PADReset(var_r27);
    }
}

/**
 * Offset/Address/Size: 0xAC8 | 0x801C3A78 | size: 0x24
 */
void UpdatePlatPad(float arg0)
{
    ((PadStatus*)padStatus)->Update(arg0);
}

/**
 * Offset/Address/Size: 0xAEC | 0x801C3A9C | size: 0xB0
 */
void InitPlatPad()
{
    // int iVar1;
    // int iVar2;
    // undefined* __s;
    // undefined* puVar3;
    // undefined* puVar4;
    // int iVar5;

    PADRead(PadStatus::s_Current);
    memcpy(::PadStatus::s_Next, ::PadStatus::s_Next, 4);
    // iVar1 = 0;
    // iVar2 = 0;
    // do
    // {
    //     iVar5 = 0;
    //     puVar4 = ::@unnamed @platpad_cpp @ ::padStatus + iVar2;
    //     __s = puVar4;
    //     puVar3 = puVar4;
    //     do
    //     {
    //         *(undefined2*)(puVar3 + 0x380) = 0;
    //         *(undefined2*)(puVar3 + 0x388) = 0;
    //         *(undefined2*)(puVar3 + 0x390) = 0;
    //         puVar4[iVar5 + 0x398] = 0;
    //         runtime.ppceabi.h::memset(__s, 0, 0xe0);
    //         iVar5 = iVar5 + 1;
    //         __s = __s + 0xe0;
    //         puVar3 = puVar3 + 2;
    //     } while (iVar5 < 4);
    //     iVar1 = iVar1 + 1;
    //     iVar2 = iVar2 + 0x39c;
    // } while (iVar1 < 2);
    return;
}

/**
 * Offset/Address/Size: 0xB9C | 0x801C3B4C | size: 0xC
 */
u32 GetButtonIndex(int button)
{
    return 0x1F - __cntlzw(button);
}

/**
 * Offset/Address/Size: 0xBA8 | 0x801C3B58 | size: 0x10
 */
void UseDefaultPad()
{
    padStatus = &padCategories[0];
}

/**
 * Offset/Address/Size: 0xBB8 | 0x801C3B68 | size: 0x14
 */
void UseFixedUpdatePad()
{
    padStatus = &padCategories[1];
}
