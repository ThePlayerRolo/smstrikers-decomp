#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "NL/nlMath.h"

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
class PlayerTweaks;
class AnimRetargetList;

enum eCharacterClass
{
    eCharacterClass_0 = 0
};

enum eClassTypes
{
    eClassTypes_0 = 0
};

class cPlayer
{
public:
    void GetUniqueID(int) const;
    void SetNoPickUpTime(float);
    void GetAIDefNetLocation(const nlVector3*);
    void GetAIOffNetLocation(const nlVector3*);
    void CanPickupBallFromPass(cBall*);
    void CanPickupBall(cBall*);
    void PostPhysicsUpdate();
    void PreUpdate(float);
    void PrePhysicsUpdate(float);
    void PlayerHeadTrackCallback(unsigned int, unsigned int, cPoseAccumulator*, unsigned int, int);
    void CreateSingleAxisBlender(const int*, int, int, void (*)(unsigned int, cPN_SingleAxisBlender*), float, cPN_SAnimController*);
    void CollideWithWallCallback(const CollisionPlayerWallData*);
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
    void CollideWithCharacterCallback(CollisionPlayerPlayerData*);
    void CollideWithBallCallback(cBall*);
    void DoFlashLight(const nlVector3&, unsigned short, float, float, float);
    void DoFlashLight(const nlVector3&, const nlVector3&, unsigned short, float, float, float);
    void SetAnimID(int);
    void GetAnimatedBallOrientation(nlQuaternion&);
    void Update(float);
    void SwapController();
    void SetDesiredFacingDirection();
    void ResetDesiredDirections(unsigned short);
    void SetSpaceSearch(SpaceSearch*);
    ~cPlayer();
    cPlayer(int, eCharacterClass, const int*, cSHierarchy*, cAnimInventory*, const CharacterPhysicsData*, PlayerTweaks*, AnimRetargetList*, eClassTypes);
    void InitActionPostWhistle();

    /* 0x00 */ u8 m_padding_0x00[0x30];
    /* 0x30 */ nlVector3 m_velocity;
    /* 0x34 */ u8 m_padding_0x34[0x80];
    /* 0xB4 */ s32 m_playerType; // m_unk_0xB4
};


// class Timer
// {
// public:
//     void __defctor();
// };

#endif // _PLAYER_H_
