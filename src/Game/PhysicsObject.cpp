#include "PhysicsObject.h"

/**
 * Offset/Address/Size: 0x0 | 0x801FFCFC | size: 0x70
 */
void ConvertDMat3ToNLMat4(const float* fpIn, nlMatrix4* pMat)
{

}

/**
 * Offset/Address/Size: 0x70 | 0x801FFD6C | size: 0x1A8
 */
void PhysicsObject::CloneObject(const PhysicsObject&)
{

}

/**
 * Offset/Address/Size: 0x218 | 0x801FFF14 | size: 0x44
 */
void PhysicsObject::Contact(PhysicsObject*, dContact*, int, PhysicsObject*)
{

}

/**
 * Offset/Address/Size: 0x25C | 0x801FFF58 | size: 0x30
 */
void PhysicsObject::Contact(PhysicsObject*, dContact*, int)
{

}

/**
 * Offset/Address/Size: 0x28C | 0x801FFF88 | size: 0x4C
 */
void PhysicsObject::MakeStatic()
{

}

/**
 * Offset/Address/Size: 0x2D8 | 0x801FFFD4 | size: 0x6C
 */
void PhysicsObject::SetMass(float)
{

}

/**
 * Offset/Address/Size: 0x344 | 0x80200040 | size: 0x50
 */
void PhysicsObject::Reconnect(dxSpace*)
{

}

/**
 * Offset/Address/Size: 0x344 | 0x80200040 | size: 0x50
 */
void PhysicsObject::Disconnect()
{

}

/**
 * Offset/Address/Size: 0x3FC | 0x802000F8 | size: 0x24
 */
void PhysicsObject::EnableCollisions()
{

}

/**
 * Offset/Address/Size: 0x420 | 0x8020011C | size: 0x24
 */
void PhysicsObject::DisableCollisions()
{

}

/**
 * Offset/Address/Size: 0x444 | 0x80200140 | size: 0xD4
 */
void PhysicsObject::SetWorldMatrix(const nlMatrix4&)
{

}

/**
 * Offset/Address/Size: 0x518 | 0x80200214 | size: 0x78
 */
void PhysicsObject::SetContactInfo(dContact*, PhysicsObject*, bool)
{

}

/**
 * Offset/Address/Size: 0x590 | 0x8020028C | size: 0x34
 */
void PhysicsObject::SetDefaultContactInfo(dContact*)
{

}

/**
 * Offset/Address/Size: 0x5C4 | 0x802002C0 | size: 0x50
 */
void PhysicsObject::ZeroForceAccumulators()
{

}

/**
 * Offset/Address/Size: 0x614 | 0x80200310 | size: 0x30
 */
void PhysicsObject::AddForceAtCentreOfMass(const nlVector3&)
{

}

/**
 * Offset/Address/Size: 0x644 | 0x80200340 | size: 0x1AC
 */
void PhysicsObject::GetAngularVelocity(nlVector3*) const
{

}

/**
 * Offset/Address/Size: 0x7F0 | 0x802004EC | size: 0x30
 */
void PhysicsObject::SetAngularVelocity(const nlVector3&)
{

}

/**
 * Offset/Address/Size: 0x820 | 0x8020051C | size: 0x34
 */
void PhysicsObject::GetLinearVelocity()
{

}

/**
 * Offset/Address/Size: 0x854 | 0x80200550 | size: 0x1AC
 */
void PhysicsObject::GetLinearVelocity(nlVector3*) const
{

}

/**
 * Offset/Address/Size: 0xA00 | 0x802006FC | size: 0x30
 */
void PhysicsObject::SetLinearVelocity(const nlVector3&)
{

}

/**
 * Offset/Address/Size: 0xA30 | 0x8020072C | size: 0x1E0
 */
void PhysicsObject::GetRotation(nlMatrix4*) const
{

}

/**
 * Offset/Address/Size: 0xC10 | 0x8020090C | size: 0xAC
 */
void PhysicsObject::SetRotation(const nlMatrix4&)
{

}

/**
 * Offset/Address/Size: 0xCBC | 0x802009B8 | size: 0x94
 */
void PhysicsObject::SetRotation(const nlMatrix3&)
{

}

/**
 * Offset/Address/Size: 0xD50 | 0x80200A4C | size: 0x34
 */
void PhysicsObject::GetPosition()
{

}

/**
 * Offset/Address/Size: 0xD84 | 0x80200A80 | size: 0x32C
 */
void PhysicsObject::GetPosition(nlVector3*) const
{

}

/**
 * Offset/Address/Size: 0x10B0 | 0x80200DAC | size: 0x118
 */
void PhysicsObject::SetPosition(const nlVector3&, PhysicsObject::CoordinateType)
{

}

/**
 * Offset/Address/Size: 0x11C8 | 0x80200EC4 | size: 0x20
 */
void PhysicsObject::PostUpdate()
{

}

/**
 * Offset/Address/Size: 0x11E8 | 0x80200EE4 | size: 0x78
 */
void PhysicsObject::PreUpdate()
{

}

/**
 * Offset/Address/Size: 0x1260 | 0x80200F5C | size: 0x48
 */
void PhysicsObject::CheckForNaN()
{

}

/**
 * Offset/Address/Size: 0x12A8 | 0x80200FA4 | size: 0x24
 */
void PhysicsObject::SetCategory(unsigned int)
{

}

/**
 * Offset/Address/Size: 0x12CC | 0x80200FC8 | size: 0x24
 */
void PhysicsObject::SetCollide(unsigned int)
{

}

/**
 * Offset/Address/Size: 0x12F0 | 0x80200FEC | size: 0x40
 */
void PhysicsObject::SetDefaultCollideBits()
{

}

/**
 * Offset/Address/Size: 0x1330 | 0x8020102C | size: 0x88
 */
PhysicsObject::~PhysicsObject()
{

}

/**
 * Offset/Address/Size: 0x13B8 | 0x802010B4 | size: 0x7C
 */
PhysicsObject::PhysicsObject(PhysicsWorld*)
{

}
