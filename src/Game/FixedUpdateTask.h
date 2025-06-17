#ifndef _FIXEDUPDATETASK_H_
#define _FIXEDUPDATETASK_H_

#include "NL/nlTask.h"

// void 0x8028D334..0x8028D338 | size: 0x4

class FixedUpdateTask : public nlTask
{
public:
    virtual void Run(float dt);
    void DecrementFrameLock(float);
    static float GetPhysicsUpdateTick(); // static / float needs to be confirmed
    virtual const char* GetName();

    FixedUpdateTask();

    static float mAccumulatedDeltaT;
    static float mSimulationTime;
    static float mfFrameLockTime;
};

#endif // _FIXEDUPDATETASK_H_
