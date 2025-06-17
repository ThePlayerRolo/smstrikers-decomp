#include "FixedUpdateTask.h"

static bool g_bRunSimAndRenderInLockStep;
static float g_fSimulationTick = 0.02f;

/**
 * Offset/Address/Size: 0x0 | 0x8016E330 | size: 0x280
 */
void FixedUpdateTask::Run(float)
{
    // TODO for later: huge amount of references to other TU
}

/**
 * Offset/Address/Size: 0x280 | 0x8016E5B0 | size: 0x44
 */
void FixedUpdateTask::DecrementFrameLock(float f)
{
    float temp_f1 = mfFrameLockTime - f;
    mfFrameLockTime = temp_f1;
    if (temp_f1 < 0.f) {
        nlTaskManager::SetNextState(2);
        mfFrameLockTime = 0.f;
    }    
}

/**
 * Offset/Address/Size: 0x2C4 | 0x8016E5F4 | size: 0x8
 */
float FixedUpdateTask::GetPhysicsUpdateTick()
{
    return g_fSimulationTick;
}

/**
 * Offset/Address/Size: 0x2CC | 0x8016E5FC | size: 0xC
 */
const char* FixedUpdateTask::GetName()
{
    return "Game Fixed Update";
}

/**
 * Offset/Address/Size: 0x2D8 | 0x8016E608 | size: 0x30
 */
FixedUpdateTask::FixedUpdateTask()
{
    mSimulationTime = 0.f;
    mAccumulatedDeltaT = g_fSimulationTick;
    mfFrameLockTime = 0.f;
}

/**
 * Offset/Address/Size: 0x308 | 0x8016E638 | size: 0xC
 */
// void 0x8028D334..0x8028D338 | size: 0x4
// {
// }
