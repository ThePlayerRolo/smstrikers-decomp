#include "PhysicsColumn.h"
#include "PhysicsWorld.h"
#include "NL/nlMath.h"
#include "NL/platvmath.h"
#include "ode/ext/dColumn.h"

#include <joint.h>

static dxJoint *createJoint (dWorldID w, dJointGroupID group, dxJoint::Vtable *vtable);

/**
 * Offset/Address/Size: 0x0 | 0x801FE888 | size: 0x24
 */
void PhysicsColumn::GetRadius(float* radius)
{
    dGeomColumnGetParams(m_geomID, radius);
}

/**
 * Offset/Address/Size: 0x24 | 0x801FE8AC | size: 0x128
 */
PhysicsColumn::PhysicsColumn(CollisionSpace* collisionSpace, PhysicsWorld* world, float radius)
    : PhysicsObject(world)
{
    dMass m;
    dMassSetZero(&m); 
    
    dSpaceID spaceID = NULL;
    if (collisionSpace != NULL)
    {
        spaceID = collisionSpace->m_spaceID;
    }

    m_geomID = dCreateColumn(spaceID, radius);

    if (m_bodyID != NULL)
    {
        dGeomSetBody(m_geomID, m_bodyID);
        dMassSetCappedCylinderTotal(&m, 1.f, 1.f, radius, 1.f);
        dBodySetMass(m_bodyID, &m);
    }

    dGeomSetData(m_geomID, this);
    SetDefaultCollideBits();

    m_jointID = dJointCreateCharacter(world->m_worldID, NULL);
    dJointAttach(m_jointID, m_bodyID, NULL);

    nlVector3 v(0.f, 0.f, 1.f);
    dJointSetCharacterNoMotionDirection(m_jointID, (float*)&v);

    dBodySetAutoDisableFlag(m_bodyID, 0);
}

/**
 * Offset/Address/Size: 0x14C | 0x801FE9D4 | size: 0x60
 */
PhysicsColumn::~PhysicsColumn()
{
}

/**
 * Offset/Address/Size: 0x0 | 0x801FEA34 | size: 0x8
 */
int PhysicsColumn::GetObjectType() const
{
    return 0x4;
}
