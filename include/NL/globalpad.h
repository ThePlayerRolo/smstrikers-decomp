#ifndef _GLOBALPAD_H_
#define _GLOBALPAD_H_

#include "types.h"
#include "Dolphin/pad.h"

class cGlobalPad;

class cPadManager
{
public:
    void Update(float);
    cGlobalPad* GetPad(int);

    static s32* m_pRemapArray;
    static cGlobalPad* m_aPads[PAD_MAX_CONTROLLERS];
    static float m_DeltaT;
};

class cGlobalPad
{
public:
    cGlobalPad();
    virtual ~cGlobalPad();

    virtual bool IsConnected();
    
    virtual u32 IsPressed(int, bool) = 0;
    virtual f32 GetPressure(int, bool) = 0;
    virtual f32 GetPressureDerivative(int, bool) = 0;

    virtual u32 PlatJustPressed(int, bool) = 0; // 0x0c
    virtual u32 PlatJustReleased(int, bool) = 0; // 0x10
    virtual f32 GetButtonStateTime(int, bool) = 0; // 0x14

    virtual f32 AnalogLeftX() = 0; // 0x18
    virtual f32 AnalogLeftY() = 0; // 0x1C
    virtual f32 AnalogRightX() = 0; // 0x20
    virtual f32 AnalogRightY() = 0; // 0x24

    virtual u8 RumbleActive() = 0; // 0x28
    virtual void StartRumble(float, float, float) = 0; // 0x3C
    virtual void StopRumble() = 0; // 0x40
    virtual void Update(float); // 0x44

    void JustReleased(int, bool);
    void JustPressed(int, bool);

    /* 0x04 */ u8 m_padding_0x04[4];
    /* 0x08 */ s16 m_unk_0x08;
    /* 0x0C */ f32 m_unk_0x0C;
    /* 0x10 */ s16 m_unk_0x10;
    /* 0x14 */ f32 m_unk_0x14;
};

#endif // _GLOBALPAD_H_
