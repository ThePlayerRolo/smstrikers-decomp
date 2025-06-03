#include <types.h>

#include "PhysicsSphere.h"

/**
 * Address: 0x80201288
 * Size: 0xC8 bytes
 */
PhysicsSphere(CollisionSpace* collisionSpace, PhysicsWorld* world, float radius /* guess */)
{

}

// void *__ct__13PhysicsSphereFP14CollisionSpaceP12PhysicsWorldf(void *arg0, void *arg1, s32 arg2, f32 arg8) {
//     ? sp8;
//     s32 var_r3;

//     __ct__13PhysicsObjectFP12PhysicsWorld(arg2);
//     arg0->unk0 = &__vt__13PhysicsSphere;
//     dMassSetZero(&sp8, &__vt__13PhysicsSphere);
//     var_r3 = 0;
//     if (arg1 != NULL) {
//         var_r3 = arg1->unk4;
//     }
//     arg0->unk8 = dCreateSphere(var_r3, arg8);
//     if ((u32) arg0->unk4 != 0U) {
//         dGeomSetBody(arg0->unk8);
//         dMassSetSphereTotal(&sp8, @247, arg8);
//         dBodySetMass(arg0->unk4, &sp8);
//     }
//     dGeomSetData(arg0->unk8, arg0);
//     SetDefaultCollideBits__13PhysicsObjectFv(arg0);
//     return arg0;
// }

/**
 * Address: 0x80201240
 * Size: 0x24 bytes
 */
void SetRadius(float radius)
{
//   collision_std::dGeomSphereSetRadius((double)param_1,*(undefined4 *)(this + 8));
}

/**
 * Address: 0x80201264
 * Size: 0x24 bytes
 */
float GetRadius()
{
    // dGeomSphereGetRadius(this->unk8);
}
