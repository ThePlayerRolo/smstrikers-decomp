#include "PhysicsTransform.h"
#include "NL/nlMath.h"
#include "PhysicsObject.h"

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
    // dxSpace *pdVar1;
    // float local_78;
    // float local_74;
    // float local_70;
    // nlVector3 anStack_6c [12];
    // float local_60;
    // float local_5c;
    // float local_58;
    // nlMatrix4 anStack_54 [76];

    // if (*(int *)(this + 0x2c) != 0) {
    // x   *(undefined4 *)(*(int *)(this + 0x2c) + 0xc) = 0;
    // x   PhysicsObject::GetPosition((PhysicsObject *)this,(nlVector3 *)&local_60);
    //   PhysicsObject::GetPosition(*(PhysicsObject **)(this + 0x2c),anStack_6c);
    //   pdVar1 = (dxSpace *)collision_kernel::dGeomGetSpace(*(undefined4 *)(this + 8));
    //   if (pdVar1 != (dxSpace *)0x0) {
    //     collision_space::dSpaceRemove(pdVar1,*(undefined4 *)(this + 8));
    //   }
    //   *(undefined4 *)(this + 4) = 0;
    //   collision_transform::dGeomTransformSetGeom(*(undefined4 *)(this + 8),0);
    //   PhysicsObject::Reconnect(*(PhysicsObject **)(this + 0x2c),pdVar1);
    //   PhysicsObject::GetRotation((PhysicsObject *)this,anStack_54);
    //   platvmath::nlMultPosVectorMatrix(&local_78,anStack_6c,anStack_54);
    //   local_58 = local_58 + local_70;
    //   local_5c = local_5c + local_74;
    //   local_60 = local_60 + local_78;
    //   PhysicsObject::SetPosition(*(PhysicsObject **)(this + 0x2c),&local_60,0);
    //   local_60 = @285;
    //   local_5c = @285;
    //   local_58 = @285;
    //   PhysicsObject::SetLinearVelocity(*(PhysicsObject **)(this + 0x2c),(nlVector3 *)&local_60);
    //   PhysicsObject::SetAngularVelocity(*(PhysicsObject **)(this + 0x2c),(nlVector3 *)&local_60);
    //   PhysicsObject::ZeroForceAccumulators(*(PhysicsObject **)(this + 0x2c));
    //   *(undefined4 *)(this + 0x2c) = 0;
    //   PhysicsObject::DisableCollisions((PhysicsObject *)this);
    // }

    nlVector3 vec3;
    if (_unk_2c != NULL)
    {
        _unk_2c = NULL;
        // GetPosition(&vec3);
    }
}

/**
 * Offset/Address/Size: 0x1C0 | 0x80201510 | size: 0xDC
 */
void PhysicsTransform::Attach(PhysicsObject* obj1, PhysicsObject* obj2)
{
    // if (*(int*)(this + 0x2c) == 0)
    // {
    //     if (param_2 != (PhysicsObject*)0x0)
    //     {
    //         *(int*)(this + 4) = param_2->m_bodyID;
    //     }
    //     collision_kernel::dGeomSetData(*(undefined4*)(this + 8), param_1);
    //     uVar1 = collision_kernel::dGeomGetCategoryBits(param_1->m_geomID);
    //     collision_kernel::dGeomSetCategoryBits(*(undefined4*)(this + 8), uVar1);
    //     uVar1 = collision_kernel::dGeomGetCollideBits(param_1->m_geomID);
    //     collision_kernel::dGeomSetCollideBits(*(undefined4*)(this + 8), uVar1);
    //     uVar1 = PhysicsObject::Disconnect(param_1);
    //     collision_transform::dGeomTransformSetGeom(*(undefined4*)(this + 8), param_1->m_geomID);
    //     PhysicsObject::EnableCollisions((PhysicsObject*)this);
    //     collision_space::dSpaceAdd(uVar1, *(undefined4*)(this + 8));
    //     collision_kernel::dGeomSetBody(*(undefined4*)(this + 8), *(undefined4*)(this + 4));
    //     param_1->m_parentObject = param_2;
    //     *(PhysicsObject**)(this + 0x2c) = param_1;
    // }

    if (_unk_2c == NULL)
    {
        if (obj2 != NULL)
        {
            _bodyID = obj2->m_bodyID;
        }
    }
}

/**
 * Offset/Address/Size: 0x29C | 0x802015EC | size: 0x84
 */
PhysicsTransform::~PhysicsTransform()
{
    //   if (this != (PhysicsTransform *)0x0) {
    //     *(undefined1 **)this = &__vt;
    //     piVar1 = *(int **)(this + 0x2c);
    //     if (piVar1 != (int *)0x0) {
    //       (**(code **)(*piVar1 + 8))(piVar1,1);
    //     }
    //     PhysicsObject::~PhysicsObject((PhysicsObject *)this);
    //     if (0 < in_r4) {
    //       nlMemory::operator_delete(this);
    //     }
    //   }
}

/**
 * Offset/Address/Size: 0x320 | 0x80201670 | size: 0x60
 */
PhysicsTransform::PhysicsTransform()
// : PhysicsObject(const PhysicsObject&)
{
    //   undefined4 uVar1;
    //   PhysicsObject::PhysicsObject((PhysicsObject *)this,(PhysicsWorld *)0x0);
    //   *(undefined1 **)this = &__vt;
    //   uVar1 = dCreateGeomTransform(0);
    _geomID = dCreateGeomTransform(NULL);

    //   *(undefined4 *)(this + 8) = uVar1;
    dGeomTransformSetInfo(_geomID, 1);
    _unk_2c = nullptr;
}

/**
 * Offset/Address/Size: 0x0 | 0x802016D0 | size: 0x30
 */
void PhysicsTransform::GetObjectType() const
{
}
