#ifndef _YOSHIWOODSOUNDPROPERTIES_H_
#define _YOSHIWOODSOUNDPROPERTIES_H_

#include "SoundPropAccessor.h"

class YOSHIWOODSoundPropAccessor : public SoundPropAccessor
{
public:
    SoundProperties* GetSoundProperty(unsigned int index) const;
    SoundProperties* GetSoundPropTable();
    u32 GetNumSFX() const;
    const char* GetSoundPropTableName() const;
    const char* GetHTMLFileName() const;
    u32 IsUsingOrigTable() const;
    void SetSoundPropTable(SoundProperties* table);
    void ResetSoundPropTable();
};

#endif // _YOSHIWOODSOUNDPROPERTIES_H_
