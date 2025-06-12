#ifndef _PHYSICSNET_H_
#define _PHYSICSNET_H_

void 0x8028D2E8..0x8028D2EC | size: 0x4;

class PhysicsNet
{
public:
    void StaticDestroy();
    void StaticInit(CollisionSpace*);
    void SweepTestForBallContact(const nlVector3&, const nlVector3&, const nlVector3&, float, nlVector3&, nlVector3&, PhysicsObject**) const;
    void IsAGoalWall(PhysicsObject*);
    void IsAGoalPost(PhysicsObject*);
    ~PhysicsNet();
    PhysicsNet(CollisionSpace*, bool);
    void GetObjectType() const;
};


class PhysicsCapsule
{
public:
    ~PhysicsCapsule();
    void GetObjectType() const;
};


class PhysicsFinitePlane
{
public:
    ~PhysicsFinitePlane();
    void GetObjectType() const;
};

#endif // _PHYSICSNET_H_