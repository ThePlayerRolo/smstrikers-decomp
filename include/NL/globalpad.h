#ifndef _GLOBALPAD_H_
#define _GLOBALPAD_H_

#include "types.h"
#include "Dolphin/pad.h"

// class cPad
// {
// public:
//     // virtual void Update(float) = 0;
// };

class cGlobalPad
{
public:
    cGlobalPad() { };

    /* 0x08 */ virtual ~cGlobalPad() { };
    /* 0x0C */ virtual bool IsConnected() = 0;
    /* 0x10 */ virtual u32 IsPressed(int, bool) = 0;
    /* 0x14 */ virtual f32 GetPressure(int, bool) = 0;
    /* 0x18 */ virtual f32 GetPressureDerivative(int, bool) = 0;
    /* 0x1C */ virtual u32 PlatJustPressed(int, bool) = 0;
    /* 0x20 */ virtual u32 PlatJustReleased(int, bool) = 0;
    /* 0x24 */ virtual f32 GetButtonStateTime(int, bool) = 0;
    /* 0x28 */ virtual f32 AnalogLeftX() = 0;
    /* 0x2C */ virtual f32 AnalogLeftY() = 0;
    /* 0x30 */ virtual f32 AnalogRightX() = 0;
    /* 0x34 */ virtual f32 AnalogRightY() = 0;
    /* 0x38 */ virtual bool RumbleActive() = 0;
    /* 0x3C */ virtual void StartRumble(float, float, float) = 0;
    /* 0x40 */ virtual void StopRumble() = 0;
    /* 0x44 */ virtual void Update(float);

    void JustReleased(int, bool);
    void JustPressed(int, bool);

    void DisableLeftAnalogToDPadMap();
    void EnableLeftAnalogToDPadMap();

    /* 0x04 */ s32 m_padIndex;
    /* 0x08 */ s16 m_leftStickAngle;
    /* 0x0C */ f32 m_leftStickMagnitude;
    /* 0x10 */ s16 m_rightStickAngle;
    /* 0x14 */ f32 m_rightStickMagnitude;

    /* 0x18 */ bool m_isLeftAnalogToDPadMapEnabled;
    /* 0x19 */ bool m_isRightAnalogToDPadMapEnabled;
    /* 0x1A */ bool m_unk_0x1A;
    /* 0x1B */ bool m_unk_0x1B;
    /* 0x1C */ bool m_isConnected;

    /* 0x1D */ u8 _pad1D[0x73];

    /* 0x90 */ float m_unk_0x90; // analog left x
    /* 0x94 */ float m_unk_0x94; // analog left y
    /* 0x98 */ float m_unk_0x98; // analog right x
    /* 0x9C */ float m_unk_0x9C; // analog right y
};

class cPadManager
{
public:
    void Update(float);

    static cGlobalPad* GetPad(int idx);
    static s32* GetRemapArray(); // { return m_pRemapArray; };

    static s32* m_pRemapArray;
    static cGlobalPad* m_aPads[PAD_MAX_CONTROLLERS];
    static float m_DeltaT;
};

#endif // _GLOBALPAD_H_
