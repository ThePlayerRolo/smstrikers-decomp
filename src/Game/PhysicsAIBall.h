#ifndef _PHYSICSAIBALL_H_
#define _PHYSICSAIBALL_H_

#include "NL/nlMath.h"
#include "PhysicsBall.h"

class PhysicsAIBall : public PhysicsBall
{
public:
    void IsBallOutsideNet(const nlVector3&);
    void DidBallJustEnterNet(const nlVector3&, nlVector3);
    void CheckIfBallWentThroughGoalPost();
    void CheckIfBallWentThroughGoalie();
    
    virtual void PostUpdate();
    virtual void PreUpdate();
    
    virtual int Contact(PhysicsObject*, dContact*, int);
    
    virtual ~PhysicsAIBall();
    PhysicsAIBall(float);
  
    virtual int GetObjectType() const override;

    // /* 0x4C */ float m_unk_0x4c;
    /* 0x4C */ u8 m_padding[4];
    /* 0x58 */ u8 m_unk_0x58;
};

#endif // _PHYSICSAIBALL_H_
