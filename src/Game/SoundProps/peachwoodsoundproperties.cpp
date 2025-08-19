#include "peachwoodsoundproperties.h"

static SoundProperties PEACHWOODSoundProperties[] = { { "CHARSFX_RUN_01", "SFXCHAR_GEN_Run_Wood_01", 0.4f, 0.0f, 0.5f, 1, 0 },
                                                      { "CHARSFX_RUN_02", "SFXCHAR_GEN_Run_Wood_02", 0.4f, 0.0f, 0.5f, 1, 0 },
                                                      { "CHARSFX_RUN_03", "SFXCHAR_GEN_Run_Wood_03", 0.4f, 0.0f, 0.5f, 1, 0 },
                                                      { "CHARSFX_RUN_04", "SFXCHAR_GEN_Run_Wood_04", 0.4f, 0.0f, 0.5f, 1, 0 },
                                                      { "CHARSFX_RUN_05", "SFXCHAR_GEN_Run_Wood_05", 0.4f, 0.0f, 0.5f, 1, 0 },
                                                      { "CHARSFX_WALK_01", "SFXCHAR_GEN_Walk_Wood_01", 0.5f, 0.0f, 0.5f, 1, 0 },
                                                      { "CHARSFX_WALK_02", "SFXCHAR_GEN_Walk_Wood_02", 0.5f, 0.0f, 0.5f, 1, 0 },
                                                      { "CHARSFX_WALK_03", "SFXCHAR_GEN_Walk_Wood_03", 0.5f, 0.0f, 0.5f, 1, 0 },
                                                      { "CHARSFX_WALK_04", "SFXCHAR_GEN_Walk_Wood_04", 0.5f, 0.0f, 0.5f, 1, 0 },
                                                      { "CHARSFX_WALK_05", "SFXCHAR_GEN_Walk_Wood_05", 0.5f, 0.0f, 0.5f, 1, 0 },
                                                      { "CHARSFX_LAND", "SFXCHAR_GEN_Land_Wood", 0.8f, 0.0f, 0.5f, 1, 0 },
                                                      { "CHARSFX_SLIDE", "SFXCHAR_GEN_Slide_Wood", 0.4f, 0.0f, 0.5f, 1, 0 },
                                                      { "CHARSFX_JUMP", "SFXCHAR_GEN_Jump_Wood", 0.45f, 0.0f, 0.5f, 1, 0 },
                                                      { "CHARSFX_TURN", "SFXCHAR_GEN_Turn_Wood", 0.4f, 0.0f, 0.5f, 1, 0 },
                                                      { "CHARSFX_DEKE_LEFT", "SFXCHAR_GEN_Deek_Wood_Left", 0.5f, 0.0f, 0.5f, 1, 0 },
                                                      { "CHARSFX_DEKE_RIGHT", "SFXCHAR_GEN_Deek_Wood_Right", 0.5f, 0.0f, 0.5f, 1, 0 },
                                                      { "CHARSFX_BODYFALL", "SFXCHAR_GEN_Bodyfall_Wood", 0.5f, 0.0f, 0.5f, 1, 0 } };

PEACHWOODSoundPropAccessor gPEACHWOODSoundPropAccessor;
SoundPropAccessor* gpPEACHWOODSoundPropAccessor = &gPEACHWOODSoundPropAccessor;

/**
 * Offset/Address/Size: 0xF4 | 0x801B1750 | size: 0x10
 */
void PEACHWOODSoundPropAccessor::ResetSoundPropTable()
{
    m_pTable = PEACHWOODSoundProperties;
}

/**
 * Offset/Address/Size: 0xD8 | 0x801B1734 | size: 0x1C
 */
bool PEACHWOODSoundPropAccessor::IsUsingOrigTable() const
{
    return (m_pTable == PEACHWOODSoundProperties) ? true : false;
}

/**
 * Offset/Address/Size: 0xCC | 0x801B1728 | size: 0xC
 */
const char* PEACHWOODSoundPropAccessor::GetHTMLFileName() const
{
    return "peachwoodsoundproperties.htm";
}

/**
 * Offset/Address/Size: 0xC0 | 0x801B171C | size: 0xC
 */
const char* PEACHWOODSoundPropAccessor::GetSoundPropTableName() const
{
    return "PEACHWOOD";
}

/**
 * Offset/Address/Size: 0xB8 | 0x801B1714 | size: 0x8
 */
u32 PEACHWOODSoundPropAccessor::GetNumSFX() const
{
    return sizeof(PEACHWOODSoundProperties) / sizeof(SoundProperties);
}

/**
 * Offset/Address/Size: 0xB0 | 0x801B170C | size: 0x8
 */
SoundProperties* PEACHWOODSoundPropAccessor::GetSoundPropTable()
{
    return m_pTable;
}

/**
 * Offset/Address/Size: 0x50 | 0x801B16AC | size: 0x60
 */
SoundProperties* PEACHWOODSoundPropAccessor::GetSoundProperty(unsigned int index) const
{
    u32 n = GetNumSFX();
    if (index >= n)
        return NULL;
    return &m_pTable[index];
}
