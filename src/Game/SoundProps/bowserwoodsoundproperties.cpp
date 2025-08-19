#include "bowserwoodsoundproperties.h"

static SoundProperties BOWSERWOODSoundProperties[] = { { "CHARSFX_RUN_01", "SFXCHAR_BIG_Run_Wood_01", 0.8f, 0.0f, 0.5f, 1, 0 },
                                                       { "CHARSFX_RUN_02", "SFXCHAR_BIG_Run_Wood_02", 0.8f, 0.0f, 0.5f, 1, 0 },
                                                       { "CHARSFX_RUN_03", "SFXCHAR_BIG_Run_Wood_03", 0.8f, 0.0f, 0.5f, 1, 0 },
                                                       { "CHARSFX_RUN_04", "SFXCHAR_BIG_Run_Wood_04", 0.8f, 0.0f, 0.5f, 1, 0 },
                                                       { "CHARSFX_RUN_05", "SFXCHAR_BIG_Run_Wood_05", 0.8f, 0.0f, 0.5f, 1, 0 },
                                                       { "CHARSFX_WALK_01", "SFXCHAR_BOWSER_Walk_Wood_01", 0.8f, 0.0f, 0.5f, 1, 0 },
                                                       { "CHARSFX_WALK_02", "SFXCHAR_BOWSER_Walk_Wood_02", 0.8f, 0.0f, 0.5f, 1, 0 },
                                                       { "CHARSFX_WALK_03", "SFXCHAR_BOWSER_Walk_Wood_03", 0.8f, 0.0f, 0.5f, 1, 0 },
                                                       { "CHARSFX_WALK_04", "SFXCHAR_BOWSER_Walk_Wood_04", 0.8f, 0.0f, 0.5f, 1, 0 },
                                                       { "CHARSFX_WALK_05", "SFXCHAR_BOWSER_Walk_Wood_05", 0.8f, 0.0f, 0.5f, 1, 0 },
                                                       { "CHARSFX_LAND", "SFXCHAR_BOWSER_Land_Wood", 0.8f, 0.0f, 0.5f, 1, 0 },
                                                       { "CHARSFX_SLIDE", "SFXCHAR_BOWSER_Roll_Wood", 0.8f, 0.0f, 0.5f, 1, 0 },
                                                       { "CHARSFX_JUMP", "SFXCHAR_BOWSER_Jump", 0.8f, 0.0f, 0.5f, 1, 0 },
                                                       { "CHARSFX_TURN", "SFXCHAR_GEN_Turn_Wood", 0.4f, 0.0f, 0.5f, 1, 0 },
                                                       { "CHARSFX_DEKE_LEFT", "SFXCHAR_GEN_Deek_Wood_Left", 0.5f, 0.0f, 0.5f, 1, 0 },
                                                       { "CHARSFX_DEKE_RIGHT", "SFXCHAR_GEN_Deek_Wood_Right", 0.5f, 0.0f, 0.5f, 1, 0 },
                                                       { "CHARSFX_BODYFALL", "SFXCHAR_BOWSER_Bodyfall_Wood", 0.8f, 0.0f, 0.5f, 1, 0 },
                                                       { "CHARSFX_BOWSER_ENTER", "SFXCHAR_BOWSER_Enter_Wood", 0.8f, 0.0f, 0.5f, 1, 0 } };

BOWSERWOODSoundPropAccessor gBOWSERWOODSoundPropAccessor;
SoundPropAccessor* gpBOWSERWOODSoundPropAccessor = &gBOWSERWOODSoundPropAccessor;

/**
 * Offset/Address/Size: 0xF4 | 0x801AE5B8 | size: 0x10
 */
void BOWSERWOODSoundPropAccessor::ResetSoundPropTable()
{
    m_pTable = BOWSERWOODSoundProperties;
}

/**
 * Offset/Address/Size: 0xD8 | 0x801AE59C | size: 0x1C
 */
bool BOWSERWOODSoundPropAccessor::IsUsingOrigTable() const
{
    return (m_pTable == BOWSERWOODSoundProperties) ? true : false;
}

/**
 * Offset/Address/Size: 0xCC | 0x801AE590 | size: 0xC
 */
const char* BOWSERWOODSoundPropAccessor::GetHTMLFileName() const
{
    return "bowserwoodsoundproperties.htm";
}

/**
 * Offset/Address/Size: 0xC0 | 0x801AE584 | size: 0xC
 */
const char* BOWSERWOODSoundPropAccessor::GetSoundPropTableName() const
{
    return "BOWSERWOOD";
}

/**
 * Offset/Address/Size: 0xB8 | 0x801AE57C | size: 0x8
 */
u32 BOWSERWOODSoundPropAccessor::GetNumSFX() const
{
    return sizeof(BOWSERWOODSoundProperties) / sizeof(SoundProperties);
}

/**
 * Offset/Address/Size: 0xB0 | 0x801AE574 | size: 0x8
 */
SoundProperties* BOWSERWOODSoundPropAccessor::GetSoundPropTable()
{
    return m_pTable;
}

/**
 * Offset/Address/Size: 0x50 | 0x801AE514 | size: 0x60
 */
SoundProperties* BOWSERWOODSoundPropAccessor::GetSoundProperty(unsigned int index) const
{
    u32 n = GetNumSFX();
    if (index >= n)
        return NULL;
    return &m_pTable[index];
}
