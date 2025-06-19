#include "Ball.h"

#include "NL/nlMath.h"
#include "NL/nlMemory.h"

#include "PhysicsAIBall.h"
#include "PhysicsObject.h"
#include "RayCollider.h"
#include "PhysicsFakeBall.h"

#include "AudioLoader.h"

cBall* g_pBall = NULL;

nlMatrix4 m3Ident = { 1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f };

inline void* operator new(unsigned long, void* p)
{
    return p;
}

/**
 * Offset/Address/Size: 0x0 | 0x800099D4 | size: 0x10C
 */
float cBall::PredictLandingSpotAndTime(nlVector3& landingSpot)
{
    float sp10;
    float spC;
    int sp8;
    float dVar9;
    float fVar5;
    float pfVar7;
    float dVar8;
    float dVar10;

    // m_unk_0x58.x = 0;
    // m_unk_0x58.y = 0;
    // m_unk_0x58.z = 0;

    dVar8 = 0.1f;
    if (m_rayPosition.z > 1.0f)
    {
        SolveQuadratic(dVar8, 0.5f * m_aiBall->m_gravity, m_unk_0x58.z, sp8, spC, sp10);

        pfVar7 = spC;         // pfVar7 = &local_14;
        dVar8 = 100000000.0f; // dVar8 = (double)Ball::@1409;
        fVar5 = 0.f;
        dVar10 = dVar8;
        if (sp8 > 0)
        {
            do
            {
                dVar9 = pfVar7;
                dVar8 = dVar10;
                if ((0.f <= dVar9) && (dVar8 = dVar9, dVar10 <= dVar9))
                {
                    dVar8 = dVar10;
                }
                pfVar7 = pfVar7 + 1;
                sp8 -= 1;
                dVar10 = dVar8;
            } while (sp8 != 0);
        }

        landingSpot.x = (dVar8 * m_unk_0x58.x) + m_rayPosition.x;
        landingSpot.y = (dVar8 * m_unk_0x58.y) + m_rayPosition.y;
        // landingSpot.z = (dVar8 * m_unk_0x58.z) + m_rayPosition.z;
        landingSpot.z = 0.f;
        return dVar8;
    }

    float x = m_rayPosition.x;
    float y = m_rayPosition.y;
    float z = m_rayPosition.z;
    landingSpot.x = x;
    landingSpot.y = y;
    landingSpot.z = z;
    return 0.f;
}

/**
 * Offset/Address/Size: 0x10C | 0x80009AE0 | size: 0x44
 */
void cBall::KillBlurHandler()
{
    if (m_blurHandler != NULL)
    {
        m_blurHandler->Die(0.f);
        m_blurHandler = NULL;
    }
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
void cBall::SetPassTargetTimer(float seconds)
{
    m_passTargetTimer->SetSeconds(seconds);
    m_passTimeSeconds = seconds;
}

/**
 * Offset/Address/Size: 0x37C | 0x80009D50 | size: 0x20
 */
void cBall::SetPassTarget(cPlayer* passTargetPlayer, const nlVector3& pos, bool)
{
    m_passTargetPlayer = passTargetPlayer;

    // m_unk_0x64.x = pos.x;
    // m_unk_0x64.y = pos.y;
    // m_unk_0x64.z = pos.z;
    u32 y = *(const u32*)&pos.y;
    u32 x = *(const u32*)&pos.x;
    *(u32*)&m_unk_0x64.x = x;
    u32 z = *(const u32*)&pos.z;
    *(u32*)&m_unk_0x64.y = y;
    *(u32*)&m_unk_0x64.z = z;
}

/**
 * Offset/Address/Size: 0x39C | 0x80009D70 | size: 0x90
 */
void cBall::WarpTo(const nlVector3& toPos)
{
    NL_VECTOR3_COPY_U32(m_rayPosition, toPos);
    m_aiBall->SetPosition(m_rayPosition, PhysicsObject::CoordinateType_0);
    m_aiBall->SetRotation(m3Ident);
    FakeBallWorld::InvalidateBallCache();
    m_unk_0x00 = m_unk_0x00 + 1;
    NL_VECTOR3_COPY_U32(m_unk_0x4C, toPos);
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
    DrawableObject* temp_r3 = m_drawableObject;
    if (visible != 0)
    {
        temp_r3->m_visibility = (temp_r3->m_visibility | 1);
        return;
    }
    temp_r3->m_visibility = (temp_r3->m_visibility & 0xFFFFFFFE);
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
void cBall::SetPosition(const nlVector3& pos)
{
    NL_VECTOR3_COPY_U32(m_rayPosition, pos);
    m_aiBall->SetPosition(pos, PhysicsObject::CoordinateType_0);
    m_aiBall->SetRotation(m3Ident);
    FakeBallWorld::InvalidateBallCache();
    m_unk_0x00++;
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
void cBall::HandleBuzzerBeater(float seconds)
{
    if (seconds < 0.0f)
    {
        m_timer_0x14 = NULL;
        return;
    }
    if (m_timer_0x14 == NULL)
    {
        m_timer_0x14->SetSeconds(seconds);
    }
}

/**
 * Offset/Address/Size: 0x16FC | 0x8000B0D0 | size: 0x44
 */
void cBall::ClearBallBlur()
{
    if (m_blurHandler != NULL)
    {
        m_blurHandler->Die(0.5f);
        m_blurHandler = NULL;
    }
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
    cPlayer* player = m_passTargetPlayer;
    if ((player == NULL) || (player->m_playerType != 2))
    {
        return NULL;
    }
    return player;
}

/**
 * Offset/Address/Size: 0x1DD0 | 0x8000B7A4 | size: 0x20
 */
cPlayer* cBall::GetOwnerGoalie()
{
    cPlayer* player = m_playerOwner;
    if ((player == NULL) || (player->m_playerType != 3))
    {
        return NULL;
    }
    return player;
}

/**
 * Offset/Address/Size: 0x1DF0 | 0x8000B7C4 | size: 0x20
 */
cPlayer* cBall::GetOwnerFielder() const
{
    cPlayer* player = m_playerOwner;
    if ((player == NULL) || (player->m_playerType != 2))
    {
        return NULL;
    }
    return player;
}

/**
 * Offset/Address/Size: 0x1E10 | 0x8000B7E4 | size: 0x28
 */
nlVector3* cBall::GetDrawablePosition() const
{
    nlMatrix4* mtx = m_drawableObject->GetWorldMatrix();
    return (nlVector3*)&(mtx->m[3][0]);
}

/**
 * Offset/Address/Size: 0x1E38 | 0x8000B80C | size: 0x1C
 */
nlVector3* cBall::GetAIVelocity() const
{
    cPlayer* temp_r4 = m_playerOwner;
    if (temp_r4 != NULL)
    {
        return &(temp_r4->m_velocity);
    }
    return (nlVector3*)&(m_unk_0x58);
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
    m_playerPrevOwner = m_playerOwner;
    m_playerOwner = NULL;
    m_aiBall->EnableCollisions();
    NL_VECTOR3_COPY_U32(m_unk_0x4C, m_rayPosition);
    m_aiBall->GetPosition(&m_rayPosition);
    m_aiBall->GetLinearVelocity(&m_unk_0x58);
    m_unk_0x00++;
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
    m_passTargetTimer->SetSeconds(0.f);
    m_timer_0x14->SetSeconds(0.f);

    void* this_00 = nlMalloc(0x5c, 8, FALSE);
    if (this_00 != NULL)
    {
        this_00 = new (this_00) PhysicsAIBall(0.18f);
    }
    m_aiBall = (PhysicsAIBall*)this_00;

    m_timer_0x14->SetSeconds(0.f);

    NL_VECTOR3_SET(m_rayPosition, 0.f, 0.f, 0.f);
    nlVector3 m_rayDir;
    NL_VECTOR3_SET(m_rayPosition, 0.f, 0.f, 0.f);

    void* this_01 = nlMalloc(0x2C, 8, FALSE);
    if (this_01 != NULL)
    {
        this_01 = new (this_01) RayCollider(1.f, m_rayPosition, m_rayDir);
    }
    m_rayCollider = (RayCollider*)this_01;

    if (AudioLoader::IsInited() != false)
    {
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
int PhysicsSphere::GetObjectType() const
{
    return 0x0A;
}

// /**
//  * Offset/Address/Size: 0x8 | 0x8000DE88 | size: 0x60
//  */
PhysicsSphere::~PhysicsSphere()
{
}

// /**
//  * Offset/Address/Size: 0x0 | 0x8000DEE8 | size: 0x4
//  */
int PhysicsObject::PreCollide()
{
}

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
