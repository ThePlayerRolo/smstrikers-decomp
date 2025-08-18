#include "yoshiwoodsoundproperties.h"

static YOSHIWOODSoundPropAccessor gYOSHIWOODSoundPropAccessor;
SoundPropAccessor* gpYOSHIWOODSoundPropAccessor = &gYOSHIWOODSoundPropAccessor;

/**
 * Offset/Address/Size: 0x50 | 0x801B3510 | size: 0x60
 */
SoundProperties* YOSHIWOODSoundPropAccessor::GetSoundProperty(unsigned int index) const
{
}

/**
 * Offset/Address/Size: 0xB0 | 0x801B3570 | size: 0x8
 */
SoundProperties* YOSHIWOODSoundPropAccessor::GetSoundPropTable()
{
}

/**
 * Offset/Address/Size: 0xB8 | 0x801B3578 | size: 0x8
 */
u32 YOSHIWOODSoundPropAccessor::GetNumSFX() const
{
}

/**
 * Offset/Address/Size: 0xC0 | 0x801B3580 | size: 0xC
 */
const char* YOSHIWOODSoundPropAccessor::GetSoundPropTableName() const
{
}

/**
 * Offset/Address/Size: 0xCC | 0x801B358C | size: 0xC
 */
const char* YOSHIWOODSoundPropAccessor::GetHTMLFileName() const
{
}

/**
 * Offset/Address/Size: 0xD8 | 0x801B3598 | size: 0x1C
 */
u32 YOSHIWOODSoundPropAccessor::IsUsingOrigTable() const
{
}

/**
 * Offset/Address/Size: 0xF4 | 0x801B35B4 | size: 0x10
 */
void YOSHIWOODSoundPropAccessor::ResetSoundPropTable()
{
}
