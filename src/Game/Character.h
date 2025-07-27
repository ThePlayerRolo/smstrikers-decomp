#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <types.h>
#include "NL/nlMath.h"

#include "PhysicsCharacter.h"

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
class SoundPropAccessor;
class EffectsGroup;

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

// Audio namespace and types (forward declarations)
namespace Audio
{
enum eCharSFX
{
    eCharSFX_0 = 0
};

struct SoundAttributes
{
    // Placeholder structure
};
} // namespace Audio

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
    void PlaySFX(Audio::SoundAttributes&);
    void SetSFX(SoundPropAccessor*);
    void UpdateMovementState(float);
    void IsPlayingEffect(const EffectsGroup*) const;
    void EndEffect(const EffectsGroup*);
    void KillEffect(const EffectsGroup*);
    void ShouldStartCrossBlend(int);
    void SetVelocity(const nlVector3&);
    virtual void SetPosition(const nlVector3&);
    void SetFacingDirection(unsigned short);
    void SetAnimState(int, bool, float, bool, bool);
    void SeekSpeedExponential(float, float, float, float);
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

    /* 0x00 */ u8 m_padding_0x00[0x14];
    /* 0x14 */ PhysicsCharacter* m_unk_0x14;
    /* 0x18 */ nlVector3 m_position;
    /* 0x24 */ nlVector3 m_unk_0x24;
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
