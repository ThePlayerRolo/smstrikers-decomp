#include "Ball.h"
#include "NL/nlMath.h"
#include "PhysicsAIBall.h"
#include "RayCollider.h"
#include "NL/nlMemory.h"

#include "World.h"
#include "AudioLoader.h"

cBall* g_pBall = NULL;

// Minimal placement new for MWCC (if <new> is not available)
inline void* operator new(unsigned long, void* p) { return p; }

/**
 * Offset/Address/Size: 0x0 | 0x800099D4 | size: 0x10C
 */
void cBall::PredictLandingSpotAndTime(nlVector3&)
{
}

/**
 * Offset/Address/Size: 0x10C | 0x80009AE0 | size: 0x44
 */
void cBall::KillBlurHandler()
{
}

/**
 * Offset/Address/Size: 0x150 | 0x80009B24 | size: 0x1EC
 */
void cBall::ClearPassTarget()
{
}

/**
 * Offset/Address/Size: 0x33C | 0x80009D10 | size: 0x40
 */
void cBall::SetPassTargetTimer(float)
{
}

/**
 * Offset/Address/Size: 0x37C | 0x80009D50 | size: 0x20
 */
void cBall::SetPassTarget(cPlayer*, const nlVector3&, bool)
{
}

/**
 * Offset/Address/Size: 0x39C | 0x80009D70 | size: 0x90
 */
void cBall::WarpTo(const nlVector3&)
{
}

/**
 * Offset/Address/Size: 0x42C | 0x80009E00 | size: 0x30C
 */
void cBall::UpdateOrientation(float)
{
}

/**
 * Offset/Address/Size: 0x738 | 0x8000A10C | size: 0x308
 */
void cBall::Update(float)
{
}

/**
 * Offset/Address/Size: 0xA40 | 0x8000A414 | size: 0x100
 */
void cBall::ShootAtFast(nlVector3&, const nlVector3&, float)
{
}

/**
 * Offset/Address/Size: 0xB40 | 0x8000A514 | size: 0x1EC
 */
void cBall::ShootRelease(const nlVector3&, eSpinType)
{
}

/**
 * Offset/Address/Size: 0xD2C | 0x8000A700 | size: 0x3AC
 */
void cBall::Shoot(const nlVector3&, const nlVector3&, eSpinType, bool, bool, bool)
{
}

/**
 * Offset/Address/Size: 0x10D8 | 0x8000AAAC | size: 0x2C
 */
void cBall::SetVisible(bool visible)
{
    // // int iVar1;
    // // iVar1 = *(int*)(this + 0x20);
    // _something* _ix20 = &this->m_ix20[0];
    // if (visible)
    // {
    //     _ix20->m_ix8c = _ix20->m_ix8c | 1;
    //     return;
    // }
    // // *(uint*)(iVar1 + 0x8c) = *(uint*)(iVar1 + 0x8c) & 0xfffffffe;
    // _ix20->m_ix8c = _ix20->m_ix8c & 0xfffffffe;
}

/**
 * Offset/Address/Size: 0x1104 | 0x8000AAD8 | size: 0x1D4
 */
void cBall::SetVelocity(const nlVector3&, eSpinType, const nlVector3*)
{
}

/**
 * Offset/Address/Size: 0x12D8 | 0x8000ACAC | size: 0xF0
 */
void cBall::SetPerfectPass(bool, bool)
{
}

/**
 * Offset/Address/Size: 0x13C8 | 0x8000AD9C | size: 0x6C
 */
void cBall::SetPosition(const nlVector3&)
{
}

/**
 * Offset/Address/Size: 0x1434 | 0x8000AE08 | size: 0x230
 */
void cBall::SetOwner(cPlayer*)
{
}

/**
 * Offset/Address/Size: 0x1664 | 0x8000B038 | size: 0x50
 */
void cBall::IsBuzzerBeaterSet() const
{
}

/**
 * Offset/Address/Size: 0x16B4 | 0x8000B088 | size: 0x48
 */
void cBall::HandleBuzzerBeater(float)
{
}

/**
 * Offset/Address/Size: 0x16FC | 0x8000B0D0 | size: 0x44
 */
void cBall::ClearBallBlur()
{
}

/**
 * Offset/Address/Size: 0x1740 | 0x8000B114 | size: 0x20C
 */
void cBall::ClearShotInProgress()
{
}

/**
 * Offset/Address/Size: 0x194C | 0x8000B320 | size: 0x370
 */
void cBall::InitiateBallBlur(eBallShotEffectType, cPlayer*)
{
}

/**
 * Offset/Address/Size: 0x1CBC | 0x8000B690 | size: 0xF4
 */
void cBall::GetInNet(int&)
{
}

/**
 * Offset/Address/Size: 0x1DB0 | 0x8000B784 | size: 0x20
 */
cPlayer* cBall::GetPassTargetFielder() const
{
    return NULL;
}

/**
 * Offset/Address/Size: 0x1DD0 | 0x8000B7A4 | size: 0x20
 */
cPlayer* cBall::GetOwnerGoalie()
{
    return NULL;
}

/**
 * Offset/Address/Size: 0x1DF0 | 0x8000B7C4 | size: 0x20
 */
cPlayer* cBall::GetOwnerFielder() const
{
    return NULL;
}

/**
 * Offset/Address/Size: 0x1E10 | 0x8000B7E4 | size: 0x28
 */
nlVector3 cBall::GetDrawablePosition() const
{
    return nlVector3(0, 0, 0);
}

/**
 * Offset/Address/Size: 0x1E38 | 0x8000B80C | size: 0x1C
 */
nlVector3 cBall::GetAIVelocity() const
{
    return nlVector3(0, 0, 0);
}

/**
 * Offset/Address/Size: 0x1E54 | 0x8000B828 | size: 0x400
 */
void cBall::PostPhysicsUpdate(float)
{
}

/**
 * Offset/Address/Size: 0x2254 | 0x8000BC28 | size: 0x5BC
 */
void cBall::CollideWithWallCallback()
{
}

/**
 * Offset/Address/Size: 0x2810 | 0x8000C1E4 | size: 0x3C4
 */
void cBall::CollideWithGroundCallback()
{
}

/**
 * Offset/Address/Size: 0x2BD4 | 0x8000C5A8 | size: 0xA18
 */
void cBall::CollideWithCharacterCallback(cPlayer*, const nlVector3&)
{
}

/**
 * Offset/Address/Size: 0x35EC | 0x8000CFC0 | size: 0x1A8
 */
void cBall::ClearBallEffects()
{
}

/**
 * Offset/Address/Size: 0x3794 | 0x8000D168 | size: 0x7C
 */
void cBall::ClearOwner()
{
}

/**
 * Offset/Address/Size: 0x3810 | 0x8000D1E4 | size: 0x78
 */
cBall::~cBall()
{
    delete m_aiBall;
    delete m_rayCollider;
}

/**
 * Offset/Address/Size: 0x3888 | 0x8000D25C | size: 0x80
 */
PhysicsAIBall::~PhysicsAIBall()
{
}

/**
 * Offset/Address/Size: 0x3908 | 0x8000D2DC | size: 0x260
 */
cBall::cBall()
{
    m_unk_0x00 = 0;
    m_unk_0x04 = 0;

    m_timer_0x08->SetSeconds(0.f);
    m_timer_0x0C->SetSeconds(0.f);
    m_timer_0x10->SetSeconds(0.f);
    m_timer_0x14->SetSeconds(0.f);


    void* this_00 = nlMalloc(0x5c, 8, FALSE);
    if (this_00 != NULL)
    {
        this_00 = new (this_00) PhysicsAIBall(0.18f);
    }
    m_aiBall = (PhysicsAIBall*)this_00;

    m_timer_0x14->SetSeconds(0.f);

    m_rayPosition = nlVector3(0.f, 0.f, 0.f);
    nlVector3 m_rayDir = nlVector3(1.f, 0.f, 0.f);
    void* this_01 = nlMalloc(0x2C, 8, FALSE);
    if (this_01 != NULL) {
        this_01 = new (this_01) RayCollider(1.f, m_rayPosition, m_rayDir);
    }
    m_rayCollider = (RayCollider*)this_01;    

    if (AudioLoader::IsInited() != false) {
        // gfPerfectPassSFXVol = GetSFXVol__8cGameSFXCFUl(&gStadGenSFX__5Audio, 0xBA);
    }    
}

// /**
//  * Offset/Address/Size: 0x0 | 0x8000D53C | size: 0x1B4
//  */
// void BasicString<char, Detail::TempStringAllocator>::AppendInPlace(const char*)
// {
// }

// /**
//  * Offset/Address/Size: 0x1B4 | 0x8000D6F0 | size: 0x67C
//  */
// void BasicString<char, Detail::TempStringAllocator>::insert(char*, const char*, const char*)
// {
// }

// /**
//  * Offset/Address/Size: 0x830 | 0x8000DD6C | size: 0x94
//  */
// void BasicString<char, Detail::TempStringAllocator>::~BasicString()
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x8000DE00 | size: 0x64
//  */
// void FuzzyVariant::Reset()
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x8000DE64 | size: 0x1C
//  */
// void Variant::Reset()
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x8000DE80 | size: 0x8
//  */
// void PhysicsSphere::GetObjectType() const
// {
// }

// /**
//  * Offset/Address/Size: 0x8 | 0x8000DE88 | size: 0x60
//  */
// PhysicsSphere::~PhysicsSphere()
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x8000DEE8 | size: 0x4
//  */
// void PhysicsObject::PreCollide()
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x8000DEEC | size: 0x8
//  */
// void PassBallData::GetID()
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x8000DEF4 | size: 0x8
//  */
// void EventData::GetID()
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x8000DEFC | size: 0x40
//  */
// void nlStrNCpy<char>(char*, const char*, unsigned long)
// {
// }

// /**
//  * Offset/Address/Size: 0x40 | 0x8000DF3C | size: 0x10
//  */
// void 0x8028D270..0x8028D274 | size: 0x4
// {
// }
