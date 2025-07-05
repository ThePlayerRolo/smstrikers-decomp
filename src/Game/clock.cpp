#include "clock.h"

/**
 * Offset/Address/Size: 0x0 | 0x802129B8 | size: 0x68
 */
void Clock::Stop()
{
}

/**
 * Offset/Address/Size: 0x68 | 0x80212A20 | size: 0x70
 */
void Clock::Start()
{
}

/**
 * Offset/Address/Size: 0xD8 | 0x80212A90 | size: 0x74
 */
void Clock::Reset(float, float, float)
{
}

/**
 * Offset/Address/Size: 0x14C | 0x80212B04 | size: 0x8C
 */
Clock::~Clock()
{
}

/**
 * Offset/Address/Size: 0x1D8 | 0x80212B90 | size: 0x60
 */
Clock::Clock(float, float, float, unsigned long, void (*)(unsigned long, unsigned long))
{
}

/**
 * Offset/Address/Size: 0x238 | 0x80212BF0 | size: 0x1A0
 */
void ClockManager::Update(float)
{
}

/**
 * Offset/Address/Size: 0x3D8 | 0x80212D90 | size: 0x4
 */
void ClockManager::Initialize()
{
}

// /**
//  * Offset/Address/Size: 0x0 | 0x80212D94 | size: 0x44
//  */
// void nlDLRingAppendRing<Clock>(Clock**, Clock*)
// {
// }

// /**
//  * Offset/Address/Size: 0x44 | 0x80212DD8 | size: 0x9C
//  */
// void nlDLRingRemoveSafely<Clock>(Clock**, const Clock*)
// {
// }

// /**
//  * Offset/Address/Size: 0xE0 | 0x80212E74 | size: 0x40
//  */
// void nlDLRingValidateContainsElement<Clock>(Clock*, const Clock*)
// {
// }

// /**
//  * Offset/Address/Size: 0x120 | 0x80212EB4 | size: 0x44
//  */
// void nlDLRingRemove<Clock>(Clock**, Clock*)
// {
// }

// /**
//  * Offset/Address/Size: 0x164 | 0x80212EF8 | size: 0x3C
//  */
// void nlDLRingAddEnd<Clock>(Clock**, Clock*)
// {
// }

// /**
//  * Offset/Address/Size: 0x1A0 | 0x80212F34 | size: 0x38
//  */
// void nlDLRingAddStart<Clock>(Clock**, Clock*)
// {
// }
