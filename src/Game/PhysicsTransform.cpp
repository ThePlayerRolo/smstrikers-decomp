#include "PhysicsTransform.h"

/**
 * Offset/Address/Size: 0x0 | 0x80201350 | size: 0x70
 */
void PhysicsTransform::SetSubObjectTransform(const nlMatrix4& transform, PhysicsObject::CoordinateType coordinateType)
{
    _unk_2c->SetRotation(transform);
    
    nlVector3 v = nlVector3(transform.v[12], transform.v[13], transform.v[14]);

    _unk_2c->SetPosition(v, coordinateType);
}

/**
 * Offset/Address/Size: 0x70 | 0x802013C0 | size: 0x24
 */
void PhysicsTransform::SetSubObjectPosition(const nlVector3& position, PhysicsObject::CoordinateType coordinateType)
{
    _unk_2c->SetPosition(position, coordinateType);
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
//   undefined4 uVar1;
  
//   if (*(int *)(this + 0x2c) == 0) {
//     if (param_2 != (PhysicsObject *)0x0) {
//       *(undefined4 *)(this + 4) = *(undefined4 *)(param_2 + 4);
//     }
//     collision_kernel::dGeomSetData(*(undefined4 *)(this + 8),param_1);
//     uVar1 = collision_kernel::dGeomGetCategoryBits(*(undefined4 *)(param_1 + 8));
//     collision_kernel::dGeomSetCategoryBits(*(undefined4 *)(this + 8),uVar1);
//     uVar1 = collision_kernel::dGeomGetCollideBits(*(undefined4 *)(param_1 + 8));
//     collision_kernel::dGeomSetCollideBits(*(undefined4 *)(this + 8),uVar1);
//     uVar1 = PhysicsObject::Disconnect(param_1);
//     collision_transform::dGeomTransformSetGeom
//               (*(undefined4 *)(this + 8),*(undefined4 *)(param_1 + 8));
//     PhysicsObject::EnableCollisions((PhysicsObject *)this);
//     collision_space::dSpaceAdd(uVar1,*(undefined4 *)(this + 8));
//     collision_kernel::dGeomSetBody(*(undefined4 *)(this + 8),*(undefined4 *)(this + 4));
//     *(PhysicsObject **)(param_1 + 0xc) = param_2;
//     *(PhysicsObject **)(this + 0x2c) = param_1;
//   }    
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
//   undefined4 uVar1;
//   PhysicsObject::PhysicsObject((PhysicsObject *)this,(PhysicsWorld *)0x0);
//   *(undefined1 **)this = &__vt;
//   uVar1 = dCreateGeomTransform(0);
  _geomID = dCreateGeomTransform(NULL);

//   *(undefined4 *)(this + 8) = uVar1;
  dGeomTransformSetInfo(_geomID,1);
  _unk_2c = nullptr;
}

/**
 * Offset/Address/Size: 0x0 | 0x802016D0 | size: 0x30
 */
void PhysicsTransform::GetObjectType() const
{
}
