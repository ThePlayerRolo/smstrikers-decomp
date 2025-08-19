#include "mariogensoundproperties.h"

static SoundProperties MARIOSoundProperties[]
    = { { "CHARSFX_KICK_ATTEMPT", "SFXCHAR_GEN_Kick", 0.3f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_SHOT_WINDUP", "SFXCHAR_GEN_Charge_Windup", 0.9f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_SHOT_LOCK", "SFXCHAR_GEN_Charge_Lock", 0.9f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_SHOT_RELEASE", "SFXCHAR_GEN_Charge_Release", 0.7f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_S2S_METER_GLOW", "SFXCHAR_GEN_StS_Meter_Glow", 0.9f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_HIT_BODY", "SFXCHAR_GEN_Hit_Body", 0.75f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_HIT_BODY_BONE", "SFXCHAR_GEN_Hit_Body_Bone", 0.75f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_HIT_SLIDE", "SFXCHAR_GEN_Hit_Slide", 0.75f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_BODYFALL_BONECRUNCH", "SFXCHAR_GEN_Bodyfall_Bone_Crunch", 0.5f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_SUPER_KICK_WINDUP", "SFXCHAR_GEN_Kick_Super", 0.5f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_PWRUP_MUSH_IN_EFFECT", "SFXPWRUP_MUSH_In_Effect", 0.5f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_PWRUP_STAR_IN_EFFECT", "SFXPWRUP_STAR_In_Effect", 0.8f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_SHELL_FREEZE_HIT", "SFXCHAR_GEN_SHELL_FREEZE_Hit", 0.7f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_SHELL_FREEZE_END", "SFXCHAR_GEN_SHELL_FREEZE_End", 0.7f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_EFFORTS_ATTACK_01", "SFXCHAR_MARIO_EFFORTS_Attack_01", 0.85f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_ATTACK_02", "SFXCHAR_MARIO_EFFORTS_Attack_02", 0.8f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_ATTACK_03", "SFXCHAR_MARIO_EFFORTS_Attack_03", 0.8f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_HIT_01", "SFXCHAR_MARIO_EFFORTS_Hit_01", 0.7f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_HIT_02", "SFXCHAR_MARIO_EFFORTS_Hit_02", 0.7f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_HIT_03", "SFXCHAR_MARIO_EFFORTS_Hit_03", 0.7f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_GET_HIT_01", "SFXCHAR_MARIO_EFFORTS_GetHit_01", 0.75f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_GET_HIT_02", "SFXCHAR_MARIO_EFFORTS_GetHit_02", 0.75f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_GET_HIT_03", "SFXCHAR_MARIO_EFFORTS_GetHit_03", 0.7f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_PAIN_01", "SFXCHAR_MARIO_EFFORTS_Pain_01", 0.55f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_PAIN_02", "SFXCHAR_MARIO_EFFORTS_Pain_02", 0.55f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_PAIN_03", "SFXCHAR_MARIO_EFFORTS_Pain_03", 0.55f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_ELECTROCUTE_01", "SFXCHAR_MARIO_EFFORTS_Electrocute_01", 0.85f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_ELECTROCUTE_02", "SFXCHAR_MARIO_EFFORTS_Electrocute_02", 0.85f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_ELECTROCUTE_03", "SFXCHAR_MARIO_EFFORTS_Electrocute_03", 0.85f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_EXERT_01", "SFXCHAR_MARIO_EFFORTS_Exert_01", 0.65f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_EXERT_02", "SFXCHAR_MARIO_EFFORTS_Exert_02", 0.7f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_EXERT_03", "SFXCHAR_MARIO_EFFORTS_Exert_03", 0.7f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_KICK_01", "SFXCHAR_MARIO_EFFORTS_Kick_01", 0.85f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_KICK_02", "SFXCHAR_MARIO_EFFORTS_Kick_02", 0.85f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_KICK_03", "SFXCHAR_MARIO_EFFORTS_Kick_03", 0.7f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_DAZED", "SFXCHAR_MARIO_EFFORTS_Dazed", 0.6f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_HEAD_SHAKE", "SFXBALL_Chest", 0.7f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_EFFORTS_KICK_SUPER", "SFXCHAR_MARIO_EFFORTS_Kick_Super_01", 0.75f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_SHOT_WINDUP", "SFXCHAR_MARIO_EFFORTS_Windup_Super_01", 0.7f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_STS_JUMP_01", "SFXCHAR_MARIO_EFFORTS_STS_Jump_01", 0.65f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_STS_FLOAT_01", "SFXCHAR_MARIO_EFFORTS_STS_Float_01", 0.85f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_EFFORTS_STS_KICK_01", "SFXCHAR_MARIO_EFFORTS_STS_Kick_01", 1.0f, 0.0f, 0.7f, 13, 0 },
        { "CHARSFX_EFFORTS_PERFECT_PASS", "SFXCHAR_MARIO_EFFORTS_PPass_01", 0.8f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_CALL_HEY_01", "SFXCHAR_MARIO_CALL_Hey_01", 0.75f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_CALL_HEY_02", "SFXCHAR_MARIO_CALL_Hey_02", 0.65f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_CALL_WO_01", "SFXCHAR_MARIO_CALL_Wo_01", 0.7f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_CALL_WO_02", "SFXCHAR_MARIO_CALL_Wo_02", 0.75f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_CALL_PERFECT_PASS", "SFXCHAR_MARIO_CALL_PPass_01", 0.6f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_BREATH_WITH_BALL", "SFXCHAR_MARIO_Breath_Run", 0.5f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_HEAD_POP", "SFXCHAR_GEN_Head_Pop", 1.0f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_DAZED", "SFXBALL_Chest", 0.5f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_ELECTROCUTED", "SFXSTAD_GEN_Electrocute", 0.5f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_THROW", "SFXCHAR_GEN_Throw", 0.5f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_GEN_STOS_JUMP", "SFXCHAR_GEN_StoS_Jump", 0.4f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_GEN_STOS_FLOAT", "SFXCHAR_GEN_StoS_Float", 1.0f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_GEN_STOS_FLOAT_HYPER", "SFXCHAR_GEN_StoS_Float_Hyper", 1.0f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_MARIO_NIS_ENTER_HOME_01", "SFXCHAR_MARIO_NIS_Enter_Home_01", 0.9f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_MARIO_NIS_ENTER_AWAY_01", "SFXCHAR_MARIO_NIS_Enter_Away_01", 0.8f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_MARIO_NIS_ATTITUDE_01", "SFXCHAR_MARIO_NIS_Attitude_01", 0.8f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_MARIO_NIS_ATTITUDE_02", "SFXCHAR_MARIO_NIS_Attitude_02", 0.8f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_MARIO_NIS_GOAL_HIGH_01", "SFXCHAR_MARIO_NIS_Goal_High_01", 0.9f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_MARIO_NIS_GOAL_HIGH_02", "SFXCHAR_MARIO_NIS_Goal_High_02", 0.9f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_MARIO_NIS_GOAL_LOW_01", "SFXCHAR_MARIO_NIS_Goal_Low_01", 0.9f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_MARIO_NIS_GAME_WIN_01", "SFXCHAR_MARIO_NIS_Game_Win_01", 0.9f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_MARIO_NIS_GAME_WIN_02", "SFXCHAR_MARIO_NIS_Game_Win_02", 0.9f, 0.0f, 0.5f, 13, 0 },
        { "CHARSFX_NIS_CLAP_01", "SFXCHAR_GEN_NIS_Clap_01", 1.0f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_NIS_CLAP_02", "SFXCHAR_GEN_NIS_Clap_02", 1.0f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_NIS_CLAP_03", "SFXCHAR_GEN_NIS_Clap_03", 1.0f, 0.0f, 0.5f, 1, 0 },
        { "CHARSFX_NIS_SPIN_LOOP", "SFXCHAR_GEN_NIS_Spin_Loop", 0.6f, 0.0f, 0.5f, 1, 0 } };

MARIOSoundPropAccessor gMARIOSoundPropAccessor;
SoundPropAccessor* gpMARIOSoundPropAccessor = &gMARIOSoundPropAccessor;

/**
 * Offset/Address/Size: 0xF0 | 0x801B000C | size: 0x10
 */
void MARIOSoundPropAccessor::ResetSoundPropTable()
{
    m_pTable = MARIOSoundProperties;
}

/**
 * Offset/Address/Size: 0xD4 | 0x801AFFF0 | size: 0x1C
 */
bool MARIOSoundPropAccessor::IsUsingOrigTable() const
{
    return (m_pTable == MARIOSoundProperties) ? true : false;
}

/**
 * Offset/Address/Size: 0xC8 | 0x801AFFE4 | size: 0xC
 */
const char* MARIOSoundPropAccessor::GetHTMLFileName() const
{
    return "mariogensoundproperties.htm";
}

/**
 * Offset/Address/Size: 0xC0 | 0x801AFFDC | size: 0x8
 */
const char* MARIOSoundPropAccessor::GetSoundPropTableName() const
{
    return "MARIO";
}

/**
 * Offset/Address/Size: 0xB8 | 0x801AFFD4 | size: 0x8
 */
u32 MARIOSoundPropAccessor::GetNumSFX() const
{
    return sizeof(MARIOSoundProperties) / sizeof(SoundProperties);
}

/**
 * Offset/Address/Size: 0xB0 | 0x801AFFCC | size: 0x8
 */
SoundProperties* MARIOSoundPropAccessor::GetSoundPropTable()
{
    return m_pTable;
}

/**
 * Offset/Address/Size: 0x50 | 0x801AFF6C | size: 0x60
 */
SoundProperties* MARIOSoundPropAccessor::GetSoundProperty(unsigned int index) const
{
    u32 n = GetNumSFX();
    if (index >= n)
        return NULL;
    return &m_pTable[index];
}
