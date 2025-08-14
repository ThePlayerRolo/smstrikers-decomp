#ifndef _FEHELPFUNCS_H_
#define _FEHELPFUNCS_H_

void MakeTextBoxReallyWide(TLTextInstance&);
void GetCupStreamName(eTrophyType);
void GetMemCardDescription();
void GetMemCardTitle();
void EnableAutoPressed();
void FindComponent(TLSlide*, const char*);
void GetLOCRank(int);
void ConvertToSidekickID(const char*);
void ConvertToTeamID(const char*);
void GetSidekickName(eSidekickID);
void GetTeamName(eTeamID);
void ConvertToCharacterClass(eSidekickID);
void ConvertToCharacterClass(eTeamID);
void GetLOCTrophyName(eTrophyType);
void GetLOCTeamName(eTeamID);
void GetLOCSidekickName(eSidekickID);
void GetLOCCharacterName(eTeamID, bool, bool);
void GetStadiumStringID(eStadiumID);

class TakeGameMemSnapshot
{
public:
    void WriteToDisk();
    void ResetTimers();
    void Update(float);
    void Format<BasicString<char, Detail::TempStringAllocator>, unsigned long, unsigned int, unsigned int>(const BasicString<char, Detail::TempStringAllocator>&, const unsigned long&, const unsigned int&, const unsigned int&);
    void FormatImpl<BasicString<char, Detail::TempStringAllocator>>::operator BasicString<char, Detail::TempStringAllocator>() const;
    void FormatImpl<BasicString<char, Detail::TempStringAllocator>>::operator%<unsigned int>(const unsigned int&);
    void FormatImpl<BasicString<char, Detail::TempStringAllocator>>::operator%<unsigned long>(const unsigned long&);
    void LexicalCast<BasicString<char, Detail::TempStringAllocator>, unsigned long>(const unsigned long&);
    void Detail::LexicalCastImpl<BasicString<char, Detail::TempStringAllocator>, unsigned long>::Do(unsigned long);
    void LexicalCast<BasicString<char, Detail::TempStringAllocator>, unsigned int>(const unsigned int&);
    void Detail::LexicalCastImpl<BasicString<char, Detail::TempStringAllocator>, unsigned int>::Do(unsigned int);
};


class FECharacterSound
{
public:
    void PlayCaptainSlideIn(eTeamID);
    void PlaySidekickName(eSidekickID);
    void PlayCaptainName(eTeamID);
};


class CaptainSidekickFilename
{
public:
    void Build(CaptainSidekickFilename::Type, char*, int, int, int);
};


class SingleHighlite
{
public:
    void CloseItem(TLComponentInstance*);
    void OpenItem(TLComponentInstance*);
    void TempDisableSound();
};


class DoubleHighlite
{
public:
    void CloseItem(TLComponentInstance*);
    void OpenItem(TLComponentInstance*);
    void TempDisableSound();
};


class GetLOCDifficultyName(GameplaySettings
{
public:
    void eSkillLevel);
};


class GetLOCStandingsName(GameInfoManager
{
public:
    void eGameModes);
};


class GetLOCModeName(GameInfoManager
{
public:
    void eGameModes);
};


class FEFinder<TLImageInstance, 2>
{
public:
    void Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
    void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
    void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
};


class FEFinder<TLComponentInstance, 4>
{
public:
    void Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
    void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
    void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
};

#endif // _FEHELPFUNCS_H_