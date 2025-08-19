#ifndef _WARIOGENSOUNDPROPERTIES_H_
#define _WARIOGENSOUNDPROPERTIES_H_


class WARIOSoundPropAccessor
{
public:
    void GetSoundProperty(unsigned int) const;
    void GetSoundPropTable();
    void GetNumSFX() const;
    void GetSoundPropTableName() const;
    void GetHTMLFileName() const;
    void IsUsingOrigTable() const;
    void ResetSoundPropTable();
};

#endif // _WARIOGENSOUNDPROPERTIES_H_