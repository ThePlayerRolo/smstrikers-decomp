#ifndef _WORLDSOUNDPROPERTIES_H_
#define _WORLDSOUNDPROPERTIES_H_

#include "SoundPropAccessor.h"

class WORLDSoundPropAccessor : public SoundPropAccessor
{
public:
    WORLDSoundPropAccessor() { ResetSoundPropTable(); }
    virtual SoundProperties* GetSoundProperty(unsigned int index) const;
    virtual SoundProperties* GetSoundPropTable();
    virtual u32 GetNumSFX() const;
    virtual const char* GetSoundPropTableName() const;
    virtual const char* GetHTMLFileName() const;
    virtual bool IsUsingOrigTable() const;
    virtual void ResetSoundPropTable();
};

// extern WORLDSoundPropAccessor gWORLDSoundPropAccessor;
// extern SoundPropAccessor* gpWORLDSoundPropAccessor;

#endif // _WORLDSOUNDPROPERTIES_H_

// #ifndef _WORLDSOUNDPROPERTIES_H_
// #define _WORLDSOUNDPROPERTIES_H_

// class WORLDSoundPropAccessor
// {
// public:
//     void GetSoundProperty(unsigned int) const;
//     void GetSoundPropTable();
//     void GetNumSFX() const;
//     void GetSoundPropTableName() const;
//     void GetHTMLFileName() const;
//     void IsUsingOrigTable() const;
//     void ResetSoundPropTable();
// };

// #endif // _WORLDSOUNDPROPERTIES_H_
