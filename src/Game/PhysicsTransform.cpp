#include "PhysicsTransform.h"

/**
 * Offset/Address/Size: 0x0 | 0x80201350 | size: 0x70
 */
void PhysicsTransform::SetSubObjectTransform(const nlMatrix4&, PhysicsObject::CoordinateType)
{
}

/**
 * Offset/Address/Size: 0x70 | 0x802013C0 | size: 0x24
 */
void PhysicsTransform::SetSubObjectPosition(const nlVector3&, PhysicsObject::CoordinateType)
{
}

/**
 * Offset/Address/Size: 0x94 | 0x802013E4 | size: 0x12C
 */
void PhysicsTransform::Release()
{
}

/**
 * Offset/Address/Size: 0x1C0 | 0x80201510 | size: 0xDC
 */
void PhysicsTransform::Attach(PhysicsObject*, PhysicsObject*)
{
}

/**
 * Offset/Address/Size: 0x29C | 0x802015EC | size: 0x84
 */
PhysicsTransform::~PhysicsTransform()
{
}

/**
 * Offset/Address/Size: 0x320 | 0x80201670 | size: 0x60
 */
PhysicsTransform::PhysicsTransform()
{
}

/**
 * Offset/Address/Size: 0x0 | 0x802016D0 | size: 0x30
 */
void PhysicsTransform::GetObjectType() const
{
}
