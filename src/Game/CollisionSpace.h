#ifndef _COLLISIONSPACE_H_
#define _COLLISIONSPACE_H_

#include "ode/collision.h"

class PhysicsWorld;
class PhysicsObject;
class CollisionSpace;

class CollisionSpace
{
public:
    void PreUpdate();
    void PreCollide();
    void CallPreCollide(PhysicsObject*);
    void DoCollide(void* data, dNearCallback *callback);

    virtual ~CollisionSpace();

    /* 0x00 */ dSpaceID m_spaceID;
    /* 0x04 */ CollisionSpace *m_nextCollisionSpace;
};

class SimpleCollisionSpace : public CollisionSpace
{
public:
    SimpleCollisionSpace(PhysicsWorld*);
    virtual ~SimpleCollisionSpace();

    /* 0x0c */ PhysicsWorld *m_physicsWorld;
};

#endif // _COLLISIONSPACE_H_
