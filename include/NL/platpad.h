#ifndef _PLATPAD_H_
#define _PLATPAD_H_

#include "types.h"

#include "NL/globalpad.h"

void VBlankPadUpdate();
void UpdatePlatPad(float);
void InitPlatPad();
void GetButtonIndex(int);
void UseDefaultPad();
void UseFixedUpdatePad();

class cPlatPad : public cGlobalPad
{
public:
    static bool m_bDisableRumble;

    virtual bool IsConnected();
    
    virtual u32 IsPressed(int, bool);
    virtual f32 GetPressure(int, bool);
    virtual f32 GetPressureDerivative(int, bool);

    virtual u32 PlatJustPressed(int, bool);
    virtual u32 PlatJustReleased(int, bool);
    virtual f32 GetButtonStateTime(int button, bool remap);

    virtual f32 AnalogLeftX();
    virtual f32 AnalogLeftY();
    virtual f32 AnalogRightX();
    virtual f32 AnalogRightY();

    virtual u8 RumbleActive();
    virtual void StartRumble(float, float, float);
    virtual void StopRumble();

    ~cPlatPad();

    /* 0x04 */ s32 m_channel;
};


class PadStatus
{
public:
    static PadStatus s_A;
    static PadStatus s_B;
    static PadStatus s_C;
    static PadStatus s_D;
    static PadStatus *s_Current;
    static PadStatus *s_Next;

    void Update(float);

    /* 0x00 */ f32 m_leftX;
    /* 0x04 */ f32 m_leftY;
    /* 0x08 */ f32 m_rightX;
    /* 0x0C */ f32 m_rightY;

    /* 0x10 */ f32 m_pressure1;
    /* 0x14 */ f32 m_pressure2;

    /* 0x18 */ f32 m_buttonStateTimes[48]; // 48 buttons, probably to many... 

    /** 0xD8 */ f32 m_rumbleIntensity;
    /** 0xDC */ u8 m_rumbleActive;
};


#endif // _PLATPAD_H_
