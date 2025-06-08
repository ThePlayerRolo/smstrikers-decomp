#ifndef _COLLISIONSPACE_H_
#define _COLLISIONSPACE_H_

#include "ode/collision.h"

class PhysicsWorld;
class PhysicsObject;

class SimpleCollisionSpace
{
public:
    SimpleCollisionSpace(PhysicsWorld*);
    ~SimpleCollisionSpace();
};


class CollisionSpace
{
public:
    void PreUpdate();
    void PreCollide();
    void CallPreCollide(PhysicsObject*);
    void DoCollide(void*, void (*)(void*, dxGeom*, dxGeom*));

    ~CollisionSpace();

    /* 0x00 */ u8 m_padding[4];
    /* 0x04 */ dSpaceID m_spaceID;
};

#endif // _COLLISIONSPACE_H_
