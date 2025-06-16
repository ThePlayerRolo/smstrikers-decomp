#ifndef _BALL_H_
#define _BALL_H_

#include <types.h>
#include "NL/nlMath.h"
#include "NL/nlTimer.h"

#include "Player.h"

#include "PhysicsAIBall.h"
#include "RayCollider.h"

// void nlStrNCpy<char>(char*, const char*, unsigned long);
// void 0x8028D270..0x8028D274 | size: 0x4;

enum eSpinType
{
    eSpinType_0 = 0
};

enum eBallShotEffectType
{
    eBallShotEffectType_0 = 0
};

struct _something
{
    u8 padding2[0x8c];
    u32 m_ix8c;
};

class cBall //: public RayCollider//, protected PhysicsAIBall
{
public:
    void PredictLandingSpotAndTime(nlVector3&);
    void KillBlurHandler();
    void ClearPassTarget();
    void SetPassTargetTimer(float);
    void SetPassTarget(cPlayer*, const nlVector3&, bool);
    void WarpTo(const nlVector3&);
    void UpdateOrientation(float);
    void Update(float);
    void ShootAtFast(nlVector3&, const nlVector3&, float);
    void ShootRelease(const nlVector3&, eSpinType);
    void Shoot(const nlVector3&, const nlVector3&, eSpinType, bool, bool, bool);
    void SetVisible(bool);
    void SetVelocity(const nlVector3&, eSpinType, const nlVector3*);
    void SetPerfectPass(bool, bool);
    void SetPosition(const nlVector3&);
    void SetOwner(cPlayer*);
    void IsBuzzerBeaterSet() const;
    void HandleBuzzerBeater(float);
    void ClearBallBlur();
    void ClearShotInProgress();
    void InitiateBallBlur(eBallShotEffectType, cPlayer*);
    void GetInNet(int&);
    cPlayer* GetPassTargetFielder() const;
    cPlayer* GetOwnerGoalie();
    cPlayer* GetOwnerFielder() const;
    nlVector3 GetDrawablePosition() const;
    nlVector3 GetAIVelocity() const;
    void PostPhysicsUpdate(float);
    void CollideWithWallCallback();
    void CollideWithGroundCallback();
    void CollideWithCharacterCallback(cPlayer*, const nlVector3&);
    void ClearBallEffects();
    void ClearOwner();

    ~cBall();
    cBall();
   
   /* 0x00 */ u8 m_unk_0x00;
   /* 0x04 */ u8 m_unk_0x04;

    /* 0x08 */ Timer *m_timer_0x08;
    /* 0x0C */ Timer *m_timer_0x0C;
    /* 0x10 */ Timer *m_timer_0x10;
    /* 0x14 */ Timer *m_timer_0x14;
    
    /* 0x18 */ u8 m_unk_0x18[0x20];

        // /* 0x20 */ _something m_ix20[3];

    /* 0x38 */ PhysicsAIBall *m_aiBall;
    /* 0x3C */ RayCollider *m_rayCollider;
    /* 0x40 */ nlVector3 m_rayPosition;

    u8 m_unk_0xA2;

};

extern cBall* g_pBall;

// class BasicString<char, Detail
// {
// public:
//     void TempStringAllocator>::AppendInPlace(const char*);
//     void TempStringAllocator>::insert(char*, const char*, const char*);
//     void TempStringAllocator>::~BasicString();
// };


// class FuzzyVariant
// {
// public:
//     void Reset();
// };


// class Variant
// {
// public:
//     void Reset();
// };


// class PhysicsSphere
// {
// public:
//     void GetObjectType() const;
//     ~PhysicsSphere();
// };


// class PhysicsObject
// {
// public:
//     void PreCollide();
// };


// class PassBallData
// {
// public:
//     void GetID();
// };


// class EventData
// {
// public:
//     void GetID();
// };

#endif // _BALL_H_
