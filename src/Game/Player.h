#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Character.h"

#include "NL/nlTimer.h"

class cBall;
class cPoseAccumulator;
class cPN_SingleAxisBlender;
class cPN_SAnimController;
class CollisionPlayerWallData;
class cAIPad;
class CollisionPlayerPlayerData;
class SpaceSearch;
class cSHierarchy;
class cAnimInventory;
class CharacterPhysicsData;
class AnimRetargetList;

#include "CharacterTweaks.h"

class cPlayer : public cCharacter
{
public:
    virtual ~cPlayer();
    cPlayer(int, eCharacterClass, const int*, cSHierarchy*, cAnimInventory*, const CharacterPhysicsData*, PlayerTweaks*, AnimRetargetList*, eClassTypes);

    s32 GetUniqueID(int) const;
    void SetNoPickUpTime(float);
    void GetAIDefNetLocation(const nlVector3*);
    void GetAIOffNetLocation(const nlVector3*);
    void CanPickupBallFromPass(cBall*);
    virtual void CanPickupBall(cBall*);
    virtual void PostPhysicsUpdate();
    virtual void PreUpdate(float);
    virtual void PrePhysicsUpdate(float);
    void PlayerHeadTrackCallback(unsigned int, unsigned int, cPoseAccumulator*, unsigned int, int);
    void CreateSingleAxisBlender(const int*, int, int, void (*)(unsigned int, cPN_SingleAxisBlender*), float, cPN_SAnimController*);
    virtual void CollideWithWallCallback(const CollisionPlayerWallData*);
    void SetPowerupAnimState(int);
    void ClearSwapControllerTimer();
    void ClearPowerupAnimState(bool);
    void DoRegularPassing(cPlayer*, bool, bool, bool, bool);
    void ResetUnPossessionTimer();
    void ReleaseBall();
    void GetGlobalPad();
    void DoFindBestPassTarget(bool, bool);
    void IsCaptain() const;
    void IsOnSameTeam(cPlayer*);
    void SetAIPad(cAIPad*);
    void PlayAttackReactionSounds(float);
    void PickupBall(cBall*);
    void GetClosestOpponentFielder(nlVector3*);
    virtual void CollideWithCharacterCallback(CollisionPlayerPlayerData*);
    virtual void CollideWithBallCallback(cBall*);
    void DoFlashLight(const nlVector3&, unsigned short, float, float, float);
    void DoFlashLight(const nlVector3&, const nlVector3&, unsigned short, float, float, float);
    virtual void SetAnimID(int);
    void GetAnimatedBallOrientation(nlQuaternion&);
    virtual void Update(float);
    void SwapController();
    void SetDesiredFacingDirection();
    void ResetDesiredDirections(unsigned short);
    void SetSpaceSearch(SpaceSearch*);
    virtual void InitActionPostWhistle();

    /* 0x00 */ u8 m_padding_0x00[0x30];
    /* 0x30 */ nlVector3 m_velocity;
    /* 0x34 */ u8 m_padding_0x34[0x80];
    /* 0xB4 */ s32 m_playerType; // m_unk_0xB4
    /* 0xB8 */ u8 m_padding_0xB8[0x38];
    /* 0x12C */ s32 m_unk_0x12C;
    

    /* 0x130 */ u8 m_padding_0x130[0x34];

    /* 0x164 */ Timer *m_timer;

    /* 0x168 */ u8 m_padding_0x168[0x14];

    /* 0x17C */ u32 m_unk_0x17C;
    /* 0x180 */ u32 m_unk_0x180;
    /* 0x184 */ u32 m_unk_0x184;
    /* 0x188 */ u32 m_unk_0x188;   
    /* 0x18C */ bool m_unk_0x18C;

    /* 0x190 */ u8 m_padding_0x190[0x3C];

    /* 0x1CC */ s32 *m_unk_0x1CC;
};


// class Timer
// {
// public:
//     void __defctor();
// };

#endif // _PLAYER_H_
