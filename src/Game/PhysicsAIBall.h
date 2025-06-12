#ifndef _PHYSICSAIBALL_H_
#define _PHYSICSAIBALL_H_

#include "NL/nlMath.h"
#include "PhysicsObject.h"

class PhysicsAIBall
{
public:
    void IsBallOutsideNet(const nlVector3&);
    void DidBallJustEnterNet(const nlVector3&, nlVector3);
    void CheckIfBallWentThroughGoalPost();
    void CheckIfBallWentThroughGoalie();
    void PostUpdate();
    void PreUpdate();
    void Contact(PhysicsObject*, dContact*, int);
    PhysicsAIBall(float);
    virtual int GetObjectType() const;
};


class PhysicsBall
{
public:
    ~PhysicsBall();
};

#endif // _PHYSICSAIBALL_H_
