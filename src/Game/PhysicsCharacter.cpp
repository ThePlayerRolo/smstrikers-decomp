#include "PhysicsCharacter.h"

/**
 * Offset/Address/Size: 0x0 | 0x80136218 | size: 0x3C
 */
void PhysicsCharacter::SetCharacterVelocityXY(const nlVector3&)
{
}

/**
 * Offset/Address/Size: 0x3C | 0x80136254 | size: 0x44
 */
void PhysicsCharacter::GetCharacterVelocityXY(nlVector3*)
{
}

/**
 * Offset/Address/Size: 0x80 | 0x80136298 | size: 0x3C
 */
void PhysicsCharacter::SetCharacterPositionXY(const nlVector3&)
{
}

/**
 * Offset/Address/Size: 0xBC | 0x801362D4 | size: 0x44
 */
void PhysicsCharacter::GetCharacterPositionXY(nlVector3*)
{
}

/**
 * Offset/Address/Size: 0x100 | 0x80136318 | size: 0x608
 */
void PhysicsCharacter::PostUpdate()
{
}

/**
 * Offset/Address/Size: 0x708 | 0x80136920 | size: 0x384
 */
void PhysicsCharacter::ResolvePhysicsBoneIDFromName(const char*)
{
}

/**
 * Offset/Address/Size: 0xA8C | 0x80136CA4 | size: 0x98
 */
void PhysicsCharacter::PreCollide()
{
}

/**
 * Offset/Address/Size: 0xB24 | 0x80136D3C | size: 0x518
 */
void PhysicsCharacter::Contact(PhysicsObject*, dContact*, int, PhysicsObject*)
{
}

/**
 * Offset/Address/Size: 0x103C | 0x80137254 | size: 0x70
 */
void PhysicsCharacter::SetContactInfo(dContact*, PhysicsObject*, bool)
{
}

/**
 * Offset/Address/Size: 0x10AC | 0x801372C4 | size: 0x24
 */
void PhysicsCharacter::GetRadius(float*)
{
}

/**
 * Offset/Address/Size: 0x10D0 | 0x801372E8 | size: 0xFC
 */
PhysicsCharacter::PhysicsCharacter(float, float)
{
}

/**
 * Offset/Address/Size: 0x0 | 0x801373E4 | size: 0x8
 */
void PhysicsCharacter::GetObjectType() const
{
}
