#include "PhysicsNPC.h"

/**
 * Offset/Address/Size: 0x0 | 0x8013B4B8 | size: 0x70
 */
PhysicsNPC::~PhysicsNPC()
{
}

/**
 * Offset/Address/Size: 0x70 | 0x8013B528 | size: 0x50
 */
void PhysicsNPC::SetContactInfo(dContact*, PhysicsObject*, bool)
{
}

/**
 * Offset/Address/Size: 0xC0 | 0x8013B578 | size: 0x378
 */
void PhysicsNPC::Contact(PhysicsObject*, dContact*, int)
{
}

/**
 * Offset/Address/Size: 0x438 | 0x8013B8F0 | size: 0x8
 */
void PhysicsNPC::SetCallbackFunction(void (*)(PhysicsObject*, PhysicsObject*, const nlVector3&))
{
}

/**
 * Offset/Address/Size: 0x440 | 0x8013B8F8 | size: 0x68
 */
PhysicsNPC::PhysicsNPC(float)
{
}

/**
 * Offset/Address/Size: 0x0 | 0x8013B960 | size: 0x8
 */
void PhysicsNPC::GetObjectType() const
{
}
