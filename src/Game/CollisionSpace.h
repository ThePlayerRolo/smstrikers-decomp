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

    // /* 0x00 */ u8 m_padding[4];
    /* 0x04 */ dSpaceID m_spaceID;
};

class SimpleCollisionSpace : public CollisionSpace
{
public:
    SimpleCollisionSpace(PhysicsWorld*);
    virtual ~SimpleCollisionSpace();

    // /* 0x00 */ u8 m_padding[0xc];
    /* 0x0c */ PhysicsWorld *m_physicsWorld;
};

#endif // _COLLISIONSPACE_H_
