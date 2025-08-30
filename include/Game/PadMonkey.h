#ifndef _PADMONKEY_H_
#define _PADMONKEY_H_

#include "types.h"
#include "NL/globalpad.h"

class PadMonkey : public cGlobalPad
{
public:
    PadMonkey(int);
    /* 0x08 */ virtual ~PadMonkey() { };
    /* 0x0C */ virtual bool IsConnected() { return m_isConnected; };
    /* 0x10 */ virtual u32 IsPressed(int, bool);
    /* 0x14 */ virtual f32 GetPressure(int, bool);
    /* 0x18 */ virtual f32 GetPressureDerivative(int, bool) { return 0.0f; };
    /* 0x1C */ virtual u32 PlatJustPressed(int, bool);
    /* 0x20 */ virtual u32 PlatJustReleased(int, bool);
    /* 0x24 */ virtual f32 GetButtonStateTime(int, bool);
    /* 0x28 */ virtual f32 AnalogLeftX() { return m_unk_0x90; };
    /* 0x2C */ virtual f32 AnalogLeftY() { return m_unk_0x94; };
    /* 0x30 */ virtual f32 AnalogRightX() { return m_unk_0x98; };
    /* 0x34 */ virtual f32 AnalogRightY() { return m_unk_0x9C; };
    /* 0x38 */ virtual bool RumbleActive() { return false; };
    /* 0x3C */ virtual void StartRumble(float, float, float) { };
    /* 0x40 */ virtual void StopRumble() { };
    /* 0x44 */ virtual void Update(float);

    void SetButtonChance(int, float);
};

#endif // _PADMONKEY_H_
