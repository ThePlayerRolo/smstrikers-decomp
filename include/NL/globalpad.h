#ifndef _GLOBALPAD_H_
#define _GLOBALPAD_H_

#include "types.h"

class cPadManager
{
public:
    void Update(float);
    void GetPad(int);

    static s32* m_pRemapArray;
};

class cGlobalPad
{
public:
    virtual bool IsConnected();
    
    virtual u32 IsPressed(int, bool) = 0;
    virtual f32 GetPressure(int, bool) = 0;
    virtual f32 GetPressureDerivative(int, bool) = 0;

    virtual u32 PlatJustPressed(int, bool) = 0;
    virtual u32 PlatJustReleased(int, bool) = 0;
    virtual f32 GetButtonStateTime(int, bool) = 0;

    virtual f32 AnalogLeftX() = 0;
    virtual f32 AnalogLeftY() = 0;
    virtual f32 AnalogRightX() = 0;
    virtual f32 AnalogRightY() = 0;

    virtual u8 RumbleActive() = 0;
    virtual void StartRumble(float, float, float) = 0;
    virtual void StopRumble() = 0;
    virtual void Update(float);

    void JustReleased(int, bool);
    void JustPressed(int, bool);
};

#endif // _GLOBALPAD_H_
