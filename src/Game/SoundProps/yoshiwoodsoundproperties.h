#ifndef _YOSHIWOODSOUNDPROPERTIES_H_
#define _YOSHIWOODSOUNDPROPERTIES_H_

#include "SoundPropAccessor.h"

class YOSHIWOODSoundPropAccessor : public SoundPropAccessor
{
public:
    YOSHIWOODSoundPropAccessor() { ResetSoundPropTable(); };
    virtual SoundProperties* GetSoundProperty(unsigned int index) const;
    virtual SoundProperties* GetSoundPropTable();
    virtual u32 GetNumSFX() const;
    virtual const char* GetSoundPropTableName() const;
    virtual const char* GetHTMLFileName() const;
    virtual bool IsUsingOrigTable() const;
    virtual void ResetSoundPropTable();
};

#endif // _YOSHIWOODSOUNDPROPERTIES_H_
