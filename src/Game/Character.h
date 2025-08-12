#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "types.h"
#include "NL/nlMath.h"

#include "CharacterEffects.h"
#include "Blinker.h"

#include "PhysicsCharacter.h"
#include "CharacterAudio.h"

#include "ObjectBlur.h"

class Event;

// Forward declarations
class cSHierarchy;
class cAnimInventory;
class CharacterPhysicsData;
class AnimRetargetList;
class cPoseAccumulator;
class GLSkinMesh;
class glModel;
class EmissionController;
class EffectsGroup;
class cTeam;

// Enums
enum eCharacterClass
{
    eCharacterClass_0 = 0
};

enum eClassTypes
{
    eClassTypes_0 = 0
};

enum PosUpdateMethod
{
    PosUpdateMethod_0 = 0
};

class cPN_SAnimController;

class cCharacter //: public PhysicsCharacterBase
{
public:
    virtual ~cCharacter();
    cCharacter(eCharacterClass, const int*, cSHierarchy*, cAnimInventory*, const CharacterPhysicsData*, float, float, AnimRetargetList*,
               eClassTypes);

    virtual void PostPhysicsUpdate();
    virtual void PrePhysicsUpdate(float);
    virtual void PreUpdate(float);
    virtual void SetAnimID(int);

    void AddRandomDirt();
    void SetElectrocutionTextureEnabled(bool);
    void PerformBlinking(GLSkinMesh*, glModel*) const;
    void UpdateBlinking(float);
    void PlayRandomCharDialogue(unsigned long, PosUpdateMethod, float, float);
    void Play3DSFX(Audio::eCharSFX, PosUpdateMethod, float);
    void StopPlayingAllTrackedSFX();
    void StopSFX(Audio::eCharSFX);
    int PlaySFX(Audio::SoundAttributes&);
    void SetSFX(SoundPropAccessor*);
    void UpdateMovementState(float);
    bool IsPlayingEffect(const EffectsGroup*) const;
    void EndEffect(const EffectsGroup*);
    void KillEffect(const EffectsGroup*);
    void ShouldStartCrossBlend(int);
    void SetVelocity(const nlVector3&);
    virtual void SetPosition(const nlVector3&);
    void SetFacingDirection(unsigned short);
    void SetAnimState(int, bool, float, bool, bool);
    float SeekSpeedExponential(float, float, float, float);
    void ResetEffects();
    void CreateWorldMatrix();
    void PoseSkinMesh(cPoseAccumulator*);
    void PoseLocalSpace();
    void NewAnimController(int, bool, bool, void (*)(unsigned int, cPN_SAnimController*), unsigned int);
    void MatchAnimSpeedToCharacterSpeed(unsigned int, cPN_SAnimController*);
    void InitMovementStrafing(float, float, float, float);
    void InitMovementRunningNoTurn(float, float);
    void InitMovementRunning(float, float, float, float);
    void InitMovementNone(float, float);
    void InitMovementFromAnimSeek(float, float);
    void InitMovementFromAnim(short, const nlVector3&, float, bool);
    void InitMovementDecelerateExponential(float);
    void InitMovementCoast();
    void EndBlur();
    void InitBlur(int);
    void GetPrevJointPosition(int);
    void GetCurrentAnimFuture(int, float, nlVector3&, nlVector3&, unsigned short&);
    void GetJointPositionFuture(nlVector3*, int, int, float, bool, bool, bool);
    void GetJointPosition(int) const;
    void GetFacingDeltaToPosition(const nlVector3&);
    void CalcAnimTurnAdjust(unsigned short, unsigned short, int);
    void AttachEffect(EmissionController*);
    void AdjustPoseMatrices();
    void GetSkinMesh() const;

    virtual void Update(float);

    /* 0x00 */ u8 m_padding_0x00[0x10];
    /* 0x14 */ PhysicsCharacter* m_physicsCharacter;
    /* 0x18 */ nlVector3 m_position;
    /* 0x24 */ nlVector3 m_unk_0x24;

    /* 0x30 */ nlVector3 m_velocity;

    /* 0x3C */ u32 m_unk_0x3C;

    /* 0x40 */ u8 m_pad_0x40[0x02];

    /* 0x42 */ unsigned short m_unk_0x42;
    /* 0x44 */ unsigned short m_unk_0x44;

    /* 0x46 */ u8 m_padding_0x46[0xE];

    /* 0x54 */ float m_unk_0x54;
    /* 0x58 */ float m_unk_0x58;
    /* 0x5C */ float m_unk_0x5C;
    /* 0x60 */ float m_unk_0x60;

    /* 0x64 */ u8 m_padding_0x64[0x0C];

    /* 0x70 */ s16 m_unk_0x70;
    /* 0x74 */ nlVector3 m_unk_0x74;

    /* 0x80 */ u8 m_padding_0x80[0x14];

    /* 0x94 */ u32 m_unk_0x94;

    /* 0x98 */ u8 m_padding_0x98[0x1C];

    /* 0xB4 */ u32 m_unk_0xB4;
    /* 0xB8 */ bool m_unk_0xB8;
    /* 0xBC */ Audio::cCharacterSFX* m_sfx;

    /* 0xC0 */ u8 m_padding_0xC0[0xC];

    /* 0xCC */ nlMatrix4 m_worldMatrix;
    /* 0x10C */ float m_unk_0x10C;
    /* 0x110 */ float m_unk_0x110;

    /* 0x114 */ BlurHandler* m_unk_0x114;
    /* 0x118 */ Blinker* m_unk_0x118;
    /* 0x11C */ FxTexturingEntry* m_unk_0x11C;

    /* 0x120 */ u8 m_padding_0x120[0xAC];

    /* 0x1CC */ cTeam* m_unk_0x1CC;
};

class cPN_SAnimController
{
public:
    ~cPN_SAnimController();
};

class cHeadTrack
{
public:
    virtual ~cHeadTrack();
};

// class PhysicsCharacter
// {
// public:
//     ~PhysicsCharacter();
// };

class GLSkinMesh
{
public:
    ~GLSkinMesh();
};

class CharacterDirectionData
{
public:
    virtual u32 GetID();
};

class PowerupData
{
public:
    virtual u32 GetID();
};

class PenaltyData
{
public:
    virtual u32 GetID();
};

class ShotAtGoalData
{
public:
    virtual u32 GetID();
};

class ReceiveBallData
{
public:
    virtual u32 GetID();
};

class CollisionBobombData
{
public:
    virtual u32 GetID();
};

class CollisionPlayerBananaData
{
public:
    virtual u32 GetID();
};

class CollisionBallShellData
{
public:
    virtual u32 GetID();
};

class CollisionPlayerFreezeData
{
public:
    virtual u32 GetID();
};

class CollisionPowerupStatsData
{
public:
    virtual u32 GetID();
};

class CollisionPlayerShellData
{
public:
    virtual u32 GetID();
};

class CollisionBowserPlayerData
{
public:
    virtual u32 GetID();
};

class CollisionChainPlayerData
{
public:
    virtual u32 GetID();
};

class CollisionPlayerShootToScoreBallData
{
public:
    virtual u32 GetID();
};

class CollisionPlayerBallData
{
public:
    virtual u32 GetID();
};

class CollisionPlayerWallData
{
public:
    virtual u32 GetID();
};

class CollisionPowerupWallData
{
public:
    virtual u32 GetID();
};

class CollisionBallGoalpostData
{
public:
    virtual u32 GetID();
};

class CollisionBallWallData
{
public:
    virtual u32 GetID();
};

class CollisionBallGroundData
{
public:
    virtual u32 GetID();
};

class CollisionPlayerPlayerData
{
public:
    virtual u32 GetID();
};

#endif // _CHARACTER_H_
