#include <types.h>
#include "Ball.h"

static cBall* g_pBall = NULL;

void cBall::PredictLandingSpotAndTime(nlVector3&)
{
}

void cBall::KillBlurHandler()
{
}

void cBall::ClearPassTarget()
{
}

void cBall::SetPassTargetTimer(float)
{
}

void cBall::SetPassTarget(cPlayer*, const nlVector3&, bool)
{
}

void cBall::WarpTo(const nlVector3&)
{
}

void cBall::UpdateOrientation(float)
{
}

void cBall::Update(float)
{
}

void cBall::ShootAtFast(nlVector3&, const nlVector3&, float)
{
}

void cBall::ShootRelease(const nlVector3&, eSpinType)
{
}

void cBall::Shoot(const nlVector3&, const nlVector3&, eSpinType, bool, bool, bool)
{
}

/**
 * Address: 0x8000AAAC
 * Size: 0x2C bytes
 */
void cBall::SetVisible(bool visible)
{
    // int iVar1;
    // iVar1 = *(int*)(this + 0x20);
    _something* _ix20 = &this->m_ix20[0];
    if (visible)
    {
        _ix20->m_ix8c = _ix20->m_ix8c | 1;
        return;
    }
    // *(uint*)(iVar1 + 0x8c) = *(uint*)(iVar1 + 0x8c) & 0xfffffffe;
    _ix20->m_ix8c = _ix20->m_ix8c & 0xfffffffe;
}

void cBall::SetVelocity(const nlVector3&, eSpinType, const nlVector3*)
{
}

void cBall::SetPerfectPass(bool, bool)
{
}

void cBall::SetPosition(const nlVector3&)
{
}

void cBall::SetOwner(cPlayer*)
{
}

bool cBall::IsBuzzerBeaterSet() const
{
    return false;
}

void cBall::HandleBuzzerBeater(float)
{
}

void cBall::ClearBallBlur()
{
}

void cBall::ClearShotInProgress()
{
}

void cBall::InitiateBallBlur(eBallShotEffectType, cPlayer*)
{
}

void cBall::GetInNet(int&)
{
}

cPlayer* cBall::GetPassTargetFielder() const
{
    return nullptr;
}

cPlayer* cBall::GetOwnerGoalie()
{
    return nullptr;
}

cPlayer* cBall::GetOwnerFielder() const
{
    return nullptr;
}

nlVector3 cBall::GetDrawablePosition() const
{
    return nlVector3(0.0f, 0.0f, 0.0f);
}

nlVector3 cBall::GetAIVelocity() const
{
    return nlVector3(0.0f, 0.0f, 0.0f);
}

void cBall::PostPhysicsUpdate(float)
{
}

void cBall::CollideWithWallCallback()
{
}

void cBall::CollideWithCharacterCallback(cPlayer*, const nlVector3&)
{
}

void cBall::ClearBallEffects()
{
}

void cBall::ClearOwner()
{
}

cBall::~cBall()
{
}

cBall::cBall()
    : PhysicsSphere(nullptr, nullptr, 0.1f)
{
    // Additional ball initialization code can go here
}
