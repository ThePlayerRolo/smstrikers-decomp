#ifndef _CBALL_H_
#define _CBALL_H_

#include <types.h>

class cPlayer;

struct nlVector3 {
    float x;
    float y;
    float z;

    nlVector3() : x(0.0f), y(0.0f), z(0.0f) {}
    nlVector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

enum eSpinType {
    eSpinType_None = 0,
    eSpinType_Topspin = 1,
    eSpinType_Backspin = 2,
};

enum eBallShotEffectType {
    eBallShotEffectType_None = 0,
    eBallShotEffectType_BuzzerBeater = 1,
    eBallShotEffectType_Pass = 2,
    eBallShotEffectType_Shot = 3,
};

struct _something {
    u8 padding2[0x8c];
    u32 m_ix8c;
};

class cBall {
public:
    // u8 padding1[0x20];
    // _something* m_ix20;
    _something m_ix20[3];

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
    bool IsBuzzerBeaterSet() const;
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
};

#endif // _CBALL_H_
