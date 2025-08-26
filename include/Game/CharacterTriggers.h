#ifndef _CHARACTERTRIGGERS_H_
#define _CHARACTERTRIGGERS_H_

#include "NL/nlMath.h"

enum eBallShotEffectType
{
    eBallShotEffectType_0,
    eBallShotEffectType_1,
    eBallShotEffectType_2,
    eBallShotEffectType_3,
};

class cCharacter;
class cPlayer;
class cFielder;
class EmissionController;

void KillSlideTackleTrail(cCharacter*);
void EmitSlideTackleTrail(cCharacter*);
void EmitTackleImpact(cPlayer*);
void EmitChainBite(cFielder*);
void KillStar(cFielder*);
void EmitStar(cFielder*);
void KillMushroom(cFielder*);
void EmitMushroom(cFielder*);
void EmitDust(cPlayer*, const char*);
void EmitTurbo(cPlayer*, const char*);
void KillWindup(cCharacter*, const char*, bool);
void KillWindups(cCharacter*);
void EmitWindupAtCharacter(cCharacter*, const char*);
void EmitWindupAtBall(cCharacter*, const char*);
void EmitShootToScoreHyperStrike(cFielder*);
void EmitGoalieCatch(cPlayer*, const char*, bool);
void EmitBallWallHit(const char*);
void CharacterElectrocutionEffect(cCharacter*, const nlVector3&, const nlVector3&);
void ElectrocutionUpdateCallback(EmissionController&);
void ElectrocutionFinishedCallback(EmissionController&);
void EmitUnFreeze(cPlayer*);
void EmitFreeze(cPlayer*);
void KillDaze(cPlayer*);
void EmitDaze(cPlayer*);
void EmitElectrocutionExplosion(cCharacter*);
void EmitSolidRumble(cPlayer*);
void KillBallShot(const char*, bool);
void EmitBallShot(cPlayer*, eBallShotEffectType, cPlayer*, bool);
void EmitBallPass(cPlayer*);
void EmitBallImpact(cPlayer*, bool);
void GetCurrentAnimTriggerTime(cCharacter*, unsigned long, unsigned int);
void GetAnimTriggerInfo(cCharacter*, int, bool (*)(float, float, unsigned long, float, void*), void*);
void CharacterTriggerHandler(unsigned int);
void EmitGeneric(cCharacter*, const char*, const char*);
void UpdateEmitterFromBall(EmissionController&);
void UpdateEmitterPoseFromCharacter(EmissionController&);
void UpdateEmitterFromCharacter(EmissionController&);
void UpdateEmitterFromCharacterIdxWithCoordSys(EmissionController&, int);
void UpdateEmitterFromCharacterIdxWithoutAnimController(EmissionController&, int);

#endif // _CHARACTERTRIGGERS_H_
