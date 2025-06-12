#ifndef _PHYSICSBOX_H_
#define _PHYSICSBOX_H_


class PhysicsBox
{
public:
    void SetDensity(float);
    PhysicsBox(CollisionSpace*, PhysicsWorld*, float, float, float);
};

#endif // _PHYSICSBOX_H_