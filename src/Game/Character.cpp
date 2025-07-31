#include "Character.h"

#include "EmissionManager.h"

extern unsigned int nlDefaultSeed;

/**
 * Offset/Address/Size: 0x0 | 0x8000DF4C | size: 0x88
 */
void cCharacter::AddRandomDirt()
{
    m_unk_0x110 += nlRandomf(0.05f, &nlDefaultSeed);
    if (m_unk_0x110 > 0.2f) {
        m_unk_0x110 = 0.2f;
    }

    m_unk_0x10C += 0.5f + nlRandomf(0.39999998f, &nlDefaultSeed);
    if (m_unk_0x10C > 1.0f) {
        m_unk_0x10C = 1.0f;
    }    
}

/**
 * Offset/Address/Size: 0x88 | 0x8000DFD4 | size: 0x74
 */
void cCharacter::SetElectrocutionTextureEnabled(bool arg0)
{
    if ((m_unk_0xB8 == false) && (arg0 != false)) {
        m_unk_0x11C = fxGetTexturing((eEffectsTextureType) 4);
    }
    if ((m_unk_0xB8 != false) && (arg0 == false)) {
        m_unk_0x11C = 0;
    }
    m_unk_0xB8 = arg0;    
}

/**
 * Offset/Address/Size: 0xFC | 0x8000E048 | size: 0x30
 */
void cCharacter::PerformBlinking(GLSkinMesh*, glModel*) const
{
}

/**
 * Offset/Address/Size: 0x12C | 0x8000E078 | size: 0x2C
 */
void cCharacter::UpdateBlinking(float)
{
}

/**
 * Offset/Address/Size: 0x158 | 0x8000E0A4 | size: 0x80
 */
void cCharacter::PlayRandomCharDialogue(unsigned long, PosUpdateMethod, float, float)
{
}

/**
 * Offset/Address/Size: 0x1D8 | 0x8000E124 | size: 0xD0
 */
void cCharacter::Play3DSFX(Audio::eCharSFX, PosUpdateMethod, float)
{
}

/**
 * Offset/Address/Size: 0x2A8 | 0x8000E1F4 | size: 0x3C
 */
void cCharacter::StopPlayingAllTrackedSFX()
{
}

/**
 * Offset/Address/Size: 0x2E4 | 0x8000E230 | size: 0x50
 */
void cCharacter::StopSFX(Audio::eCharSFX)
{
}

/**
 * Offset/Address/Size: 0x334 | 0x8000E280 | size: 0x60
 */
void cCharacter::PlaySFX(Audio::SoundAttributes&)
{
}

/**
 * Offset/Address/Size: 0x394 | 0x8000E2E0 | size: 0x78
 */
void cCharacter::SetSFX(SoundPropAccessor*)
{
}

/**
 * Offset/Address/Size: 0x40C | 0x8000E358 | size: 0x650
 */
void cCharacter::UpdateMovementState(float)
{
}

/**
 * Offset/Address/Size: 0xA5C | 0x8000E9A8 | size: 0x34
 */
void cCharacter::IsPlayingEffect(const EffectsGroup*) const
{
}

/**
 * Offset/Address/Size: 0xA90 | 0x8000E9DC | size: 0x34
 */
void cCharacter::EndEffect(const EffectsGroup*)
{
}

/**
 * Offset/Address/Size: 0xAC4 | 0x8000EA10 | size: 0x34
 */
void cCharacter::KillEffect(const EffectsGroup*)
{
}

/**
 * Offset/Address/Size: 0xAF8 | 0x8000EA44 | size: 0x1FC
 */
void cCharacter::Update(float)
{
}

/**
 * Offset/Address/Size: 0xCF4 | 0x8000EC40 | size: 0x84
 */
void cCharacter::ShouldStartCrossBlend(int)
{
}

/**
 * Offset/Address/Size: 0xD78 | 0x8000ECC4 | size: 0x40
 */
void cCharacter::SetVelocity(const nlVector3&)
{
}

/**
 * Offset/Address/Size: 0xDB8 | 0x8000ED04 | size: 0x58
 */
void cCharacter::SetPosition(const nlVector3& position)
{
    m_position = position;
    m_unk_0x24 = position;
    m_unk_0x14->SetCharacterPositionXY(m_position);
}

/**
 * Offset/Address/Size: 0xE10 | 0x8000ED5C | size: 0x30
 */
void cCharacter::SetFacingDirection(unsigned short)
{
}

/**
 * Offset/Address/Size: 0xE40 | 0x8000ED8C | size: 0x148
 */
void cCharacter::SetAnimState(int, bool, float, bool, bool)
{
}

/**
 * Offset/Address/Size: 0xF88 | 0x8000EED4 | size: 0x8
 */
void cCharacter::SetAnimID(int)
{
}

/**
 * Offset/Address/Size: 0xF90 | 0x8000EEDC | size: 0x50
 */
void cCharacter::SeekSpeedExponential(float, float, float, float)
{
}

/**
 * Offset/Address/Size: 0xFE0 | 0x8000EF2C | size: 0x3C
 */
void cCharacter::ResetEffects()
{
}

/**
 * Offset/Address/Size: 0x101C | 0x8000EF68 | size: 0xF0
 */
void cCharacter::PostPhysicsUpdate()
{
}

/**
 * Offset/Address/Size: 0x110C | 0x8000F058 | size: 0x6C
 */
void cCharacter::CreateWorldMatrix()
{
}

/**
 * Offset/Address/Size: 0x1178 | 0x8000F0C4 | size: 0x4
 */
void cCharacter::PreUpdate(float)
{
}

/**
 * Offset/Address/Size: 0x117C | 0x8000F0C8 | size: 0x68
 */
void cCharacter::PrePhysicsUpdate(float)
{
}

/**
 * Offset/Address/Size: 0x11E4 | 0x8000F130 | size: 0x4C
 */
void cCharacter::PoseSkinMesh(cPoseAccumulator*)
{
}

/**
 * Offset/Address/Size: 0x1230 | 0x8000F17C | size: 0x40
 */
void cCharacter::PoseLocalSpace()
{
}

/**
 * Offset/Address/Size: 0x1270 | 0x8000F1BC | size: 0x33C
 */
void cCharacter::NewAnimController(int, bool, bool, void (*)(unsigned int, cPN_SAnimController*), unsigned int)
{
}

/**
 * Offset/Address/Size: 0x15AC | 0x8000F4F8 | size: 0xD4
 */
void cCharacter::MatchAnimSpeedToCharacterSpeed(unsigned int, cPN_SAnimController*)
{
}

/**
 * Offset/Address/Size: 0x1680 | 0x8000F5CC | size: 0x1C
 */
void cCharacter::InitMovementStrafing(float, float, float, float)
{
}

/**
 * Offset/Address/Size: 0x169C | 0x8000F5E8 | size: 0x14
 */
void cCharacter::InitMovementRunningNoTurn(float, float)
{
}

/**
 * Offset/Address/Size: 0x16B0 | 0x8000F5FC | size: 0x1C
 */
void cCharacter::InitMovementRunning(float, float, float, float)
{
}

/**
 * Offset/Address/Size: 0x16CC | 0x8000F618 | size: 0x14
 */
void cCharacter::InitMovementNone(float, float)
{
}

/**
 * Offset/Address/Size: 0x16E0 | 0x8000F62C | size: 0x14
 */
void cCharacter::InitMovementFromAnimSeek(float, float)
{
}

/**
 * Offset/Address/Size: 0x16F4 | 0x8000F640 | size: 0x3C
 */
void cCharacter::InitMovementFromAnim(short, const nlVector3&, float, bool)
{
}

/**
 * Offset/Address/Size: 0x1730 | 0x8000F67C | size: 0x10
 */
void cCharacter::InitMovementDecelerateExponential(float)
{
}

/**
 * Offset/Address/Size: 0x1740 | 0x8000F68C | size: 0xC
 */
void cCharacter::InitMovementCoast()
{
}

/**
 * Offset/Address/Size: 0x174C | 0x8000F698 | size: 0x44
 */
void cCharacter::EndBlur()
{
}

/**
 * Offset/Address/Size: 0x1790 | 0x8000F6DC | size: 0xBC
 */
void cCharacter::InitBlur(int)
{
}

/**
 * Offset/Address/Size: 0x184C | 0x8000F798 | size: 0x18
 */
void cCharacter::GetPrevJointPosition(int)
{
}

/**
 * Offset/Address/Size: 0x1864 | 0x8000F7B0 | size: 0x244
 */
void cCharacter::GetCurrentAnimFuture(int, float, nlVector3&, nlVector3&, unsigned short&)
{
}

/**
 * Offset/Address/Size: 0x1AA8 | 0x8000F9F4 | size: 0x324
 */
void cCharacter::GetJointPositionFuture(nlVector3*, int, int, float, bool, bool, bool)
{
}

/**
 * Offset/Address/Size: 0x1DCC | 0x8000FD18 | size: 0x28
 */
void cCharacter::GetJointPosition(int) const
{
}

/**
 * Offset/Address/Size: 0x1DF4 | 0x8000FD40 | size: 0x68
 */
void cCharacter::GetFacingDeltaToPosition(const nlVector3&)
{
}

/**
 * Offset/Address/Size: 0x1E5C | 0x8000FDA8 | size: 0x148
 */
void cCharacter::CalcAnimTurnAdjust(unsigned short, unsigned short, int)
{
}

/**
 * Offset/Address/Size: 0x1FA4 | 0x8000FEF0 | size: 0x5C
 */
void cCharacter::AttachEffect(EmissionController*)
{
}

/**
 * Offset/Address/Size: 0x2000 | 0x8000FF4C | size: 0x2C
 */
void cCharacter::AdjustPoseMatrices()
{
}

/**
 * Offset/Address/Size: 0x202C | 0x8000FF78 | size: 0x24
 */
void cCharacter::GetSkinMesh() const
{
}

/**
 * Offset/Address/Size: 0x2050 | 0x8000FF9C | size: 0x1E8
 */
cCharacter::~cCharacter()
{
    EmissionManager *emissionManager = NULL; //(EmissionManager *)CharacterTemplate::GetCharacterIndex();
    emissionManager->Destroy(false, NULL);
}

/**
 * Offset/Address/Size: 0x2238 | 0x80010184 | size: 0x468
 */
cCharacter::cCharacter(eCharacterClass, const int*, cSHierarchy*, cAnimInventory*, const CharacterPhysicsData*, float, float, AnimRetargetList*, eClassTypes)
{
}

/**
 * Offset/Address/Size: 0x26A0 | 0x800105EC | size: 0x1A58
 */
void AIEventHandler(Event*, void*)
{
}

/**
 * Offset/Address/Size: 0x0 | 0x80012044 | size: 0x6C
 */
cPN_SAnimController::~cPN_SAnimController()
{
}

/**
 * Offset/Address/Size: 0x0 | 0x800120B0 | size: 0x48
 */
cHeadTrack::~cHeadTrack()
{
}

/**
 * Offset/Address/Size: 0x48 | 0x800120F8 | size: 0x60
 */
PhysicsCharacter::~PhysicsCharacter()
{
}

/**
 * Offset/Address/Size: 0x0 | 0x80012158 | size: 0x48
 */
GLSkinMesh::~GLSkinMesh()
{
}

/**
 * Offset/Address/Size: 0x0 | 0x800121A0 | size: 0x8
 */
u32 CharacterDirectionData::GetID()
{
    return 0x175;   
}

/**
 * Offset/Address/Size: 0x8 | 0x800121A8 | size: 0x8
 */
u32 PowerupData::GetID()
{
    return 0x15c;
}

/**
 * Offset/Address/Size: 0x10 | 0x800121B0 | size: 0x8
 */
u32 PenaltyData::GetID()
{
    return 0x152;
}

/**
 * Offset/Address/Size: 0x18 | 0x800121B8 | size: 0x8
 */
u32 ShotAtGoalData::GetID()
{
    return 0x14a;
}

/**
 * Offset/Address/Size: 0x20 | 0x800121C0 | size: 0x8
 */
u32 ReceiveBallData::GetID()
{
    return 0x121;
}

/**
 * Offset/Address/Size: 0x28 | 0x800121C8 | size: 0x8
 */
u32 CollisionBobombData::GetID()
{
    return 0xED;
}

/**
 * Offset/Address/Size: 0x30 | 0x800121D0 | size: 0x8
 */
u32 CollisionPlayerBananaData::GetID()
{
    return 0xE2;
}

/**
 * Offset/Address/Size: 0x38 | 0x800121D8 | size: 0x8
 */
u32 CollisionBallShellData::GetID()
{
    return 0xC1;
}

/**
 * Offset/Address/Size: 0x40 | 0x800121E0 | size: 0x8
 */
u32 CollisionPlayerFreezeData::GetID()
{
    return 0xD7;
}

/**
 * Offset/Address/Size: 0x48 | 0x800121E8 | size: 0x8
 */
u32 CollisionPowerupStatsData::GetID()
{
    return 0x104;
}

/**
 * Offset/Address/Size: 0x50 | 0x800121F0 | size: 0x8
 */
u32 CollisionPlayerShellData::GetID()
{
    return 0xC9;
}

/**
 * Offset/Address/Size: 0x58 | 0x800121F8 | size: 0x8
 */
u32 CollisionBowserPlayerData::GetID()
{
    return 0x65;
}

/**
 * Offset/Address/Size: 0x60 | 0x80012200 | size: 0x8
 */
u32 CollisionChainPlayerData::GetID()
{
    return 0x5C;
}

/**
 * Offset/Address/Size: 0x68 | 0x80012208 | size: 0x8
 */
u32 CollisionPlayerShootToScoreBallData::GetID()
{
    return 0xB8;
}

/**
 * Offset/Address/Size: 0x70 | 0x80012210 | size: 0x8
 */
u32 CollisionPlayerBallData::GetID()
{
    return 0xA7;
}

/**
 * Offset/Address/Size: 0x78 | 0x80012218 | size: 0x8
 */
u32 CollisionPlayerWallData::GetID()
{
    return 0x6E;
}

/**
 * Offset/Address/Size: 0x80 | 0x80012220 | size: 0x8
 */
u32 CollisionPowerupWallData::GetID()
{
    return 0x9B;
}

/**
 * Offset/Address/Size: 0x88 | 0x80012228 | size: 0x8
 */
u32 CollisionBallGoalpostData::GetID()
{
    return 0x10E;
}

/**
 * Offset/Address/Size: 0x90 | 0x80012230 | size: 0x8
 */
u32 CollisionBallWallData::GetID()
{
    return 0x78;
}

/**
 * Offset/Address/Size: 0x98 | 0x80012238 | size: 0x8
 */
u32 CollisionBallGroundData::GetID()
{
    return 0x8F;
}

/**
 * Offset/Address/Size: 0xA0 | 0x80012240 | size: 0x8
 */
u32 CollisionPlayerPlayerData::GetID()
{
    return 0x51;
}

/**
 * Offset/Address/Size: 0x0 | 0x80012248 | size: 0x90
 */
// void nlStrNCat<char>(char*, const char*, const char*, unsigned long)
// {
// }

/**
 * Offset/Address/Size: 0x90 | 0x800122D8 | size: 0x10
 */
// void 0x8028D274..0x8028D278 | size: 0x4
// {
// }
