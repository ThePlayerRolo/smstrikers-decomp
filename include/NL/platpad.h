#ifndef _PLATPAD_H_
#define _PLATPAD_H_

#include "types.h"
#include "NL/globalpad.h"

void VBlankPadUpdate();
void UpdatePlatPad(float);
void InitPlatPad();
u32 GetButtonIndex(int);
void UseDefaultPad();
void UseFixedUpdatePad();

class cPlatPad : public cGlobalPad
{
public:
    static bool m_bDisableRumble;

    virtual ~cPlatPad();

    /* 0x0C */ virtual bool IsConnected();
    /* 0x10 */ virtual bool IsPressed(int button, bool remap);
    /* 0x14 */ virtual f32 GetPressure(int button, bool remap);
    /* 0x18 */ virtual f32 GetPressureDerivative(int button, bool remap);
    /* 0x1C */ virtual bool PlatJustPressed(int button, bool remap);
    /* 0x20 */ virtual bool PlatJustReleased(int button, bool remap);
    /* 0x24 */ virtual f32 GetButtonStateTime(int button, bool remap);
    /* 0x28 */ virtual f32 AnalogLeftX();
    /* 0x2C */ virtual f32 AnalogLeftY();
    /* 0x30 */ virtual f32 AnalogRightX();
    /* 0x34 */ virtual f32 AnalogRightY();
    /* 0x38 */ virtual bool RumbleActive();
    /* 0x3C */ virtual void StartRumble(float, float, float);
    /* 0x40 */ virtual void StopRumble();
};

class PadStatus
{
public:
    static PADStatus s_A;
    static PADStatus s_B;
    static PADStatus s_C;
    static PADStatus s_D;
    static PADStatus* s_Current;
    static PADStatus* s_Next;

    void Update(float);

    /* 0x00 */ f32 m_leftX;
    /* 0x04 */ f32 m_leftY;
    /* 0x08 */ f32 m_rightX;
    /* 0x0C */ f32 m_rightY;
    /* 0x10 */ f32 m_pressure1;
    /* 0x14 */ f32 m_pressure2;
    /* 0x18 */ f32 m_buttonStateTimes[48]; // ? 48 buttons
    /* 0xD8 */ f32 m_rumbleIntensity;
    /* 0xDC */ bool m_rumbleActive;
    /* .... */ u16 m_button; // this is not correct, I have not clue where the button data is stored yet..
}; // size 0xE0 (!!! m_button just work because of 4 byte alignment)

#endif // _PLATPAD_H_
