#include "PhysicsObject.h"
#include "ode/collision.h"
#include "types.h"

/**
 * Offset/Address/Size: 0x0 | 0x801FFCFC | size: 0x70
 */
void ConvertDMat3ToNLMat4(const float* mat3, nlMatrix4* mat4)
{
    mat4->v[0] = (f32) mat3[0];
    mat4->v[4] = (f32) mat3[1];
    mat4->v[8] = (f32) mat3[2];
    mat4->v[1] = (f32) mat3[4];
    mat4->v[5] = (f32) mat3[5];
    mat4->v[9] = (f32) mat3[6];
    mat4->v[2] = (f32) mat3[8];
    mat4->v[6] = (f32) mat3[9];
    mat4->v[10] = (f32) mat3[10];
    mat4->v[12] = 1.0f;
    mat4->v[13] = 1.0f;
    mat4->v[14] = 1.0f;
    mat4->v[15] = 0.0f;
    mat4->v[3] = 1.0f;
    mat4->v[7] = 1.0f;
    mat4->v[11] = 1.0f;
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
    if (_bodyID != NULL) 
    {
        dBodyDestroy(_bodyID);
        _bodyID = NULL;
    }
    dGeomSetBody(_geomID, NULL);
}


    // /* 0x04 */ dBodyID _bodyID;
    // /* 0x08 */ dGeomID _geomID;
    // /* 0x10 */ float _gravity;

/**
 * Offset/Address/Size: 0x2D8 | 0x801FFFD4 | size: 0x6C
 */
void PhysicsObject::SetMass(float mass)
{
    dMass m;
    if (_bodyID != nullptr) 
    {
        dMassSetZero(&m);
        dBodyGetMass(_bodyID, &m);
        dMassAdjust(&m, mass);
        dBodySetMass(_bodyID, &m);
    }
}

/**
 * Offset/Address/Size: 0x344 | 0x80200040 | size: 0x50
 */
void PhysicsObject::Reconnect(dxSpace* space)
{
    dSpaceAdd(space,_geomID);
    dGeomSetBody(_geomID,_bodyID);
    if (_bodyID != 0) 
    {
        dBodyEnable(_bodyID);
    }
}

/**
 * Offset/Address/Size: 0x344 | 0x80200040 | size: 0x50
 */
void PhysicsObject::Disconnect()
{
    dSpaceID space;
    space = dGeomGetSpace(_geomID);
    if (space != nullptr)
    {
        dSpaceRemove(space, _geomID);
    }
    dGeomSetBody(_geomID, 0);
    if (_bodyID != nullptr)
    {
        dBodyDisable(_bodyID);
    }
}

/**
 * Offset/Address/Size: 0x3FC | 0x802000F8 | size: 0x24
 */
void PhysicsObject::EnableCollisions()
{
    dGeomEnable(_geomID);
}

/**
 * Offset/Address/Size: 0x420 | 0x8020011C | size: 0x24
 */
void PhysicsObject::DisableCollisions()
{
    dGeomDisable(_geomID);
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
//   if (this != (PhysicsObject *)0x0) {
//     *(undefined1 **)this = &__vt;
//     if (*(int *)(this + 4) != 0) {
    
    if (_bodyID != nullptr)
    {
      dBodyDestroy(_bodyID);
      _bodyID = nullptr;
    }

    if (_geomID != nullptr)
    {
        dGeomDestroy(_geomID);
        _geomID = nullptr;
    }

    // if (0 < in_r4) {
    //   nlMemory::operator_delete(this);
    // }
//   }
}

/**
 * Offset/Address/Size: 0x13B8 | 0x802010B4 | size: 0x7C
 */
PhysicsObject::PhysicsObject(PhysicsWorld* pWorld)
{
//   undefined4 uVar1;
//   *(undefined1 **)this = &__vt;
//   *(undefined4 *)(this + 4) = 0;
  _bodyID = nullptr;
//   *(undefined4 *)(this + 8) = 0;
  _geomID = nullptr;

//   *(undefined4 *)(this + 0xc) = 0;

//   *(undefined4 *)(this + 0x10) = _DefaultGravity;
    _gravity = _DefaultGravity;

//   if (param_1 != (PhysicsWorld *)0x0) {
    if (pWorld != nullptr)
    {
    // uVar1 = ode::dBodyCreate(*(undefined4 *)param_1);
    // *(undefined4 *)(this + 4) = uVar1;
        // _bodyID = dBodyCreate(pWorld);

    // ode::dBodySetData(*(undefined4 *)(this + 4),this);
        dBodySetData(_bodyID,this);

    // ode::dBodySetGravityMode(*(undefined4 *)(this + 4),0);
        dBodySetGravityMode(_bodyID,0);
    }
}
