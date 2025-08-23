#ifndef _SHCHOOSECUP_H_
#define _SHCHOOSECUP_H_

#include "types.h"
#include "Game/FE/TLComponentInstance.h"

void continueCup(bool);
void startNewCup(bool);
void confirmedNewCup(bool);

enum eTeamID
{
    eTeamID_0 = 0
};

class ChooseCupSceneV2
{
public:
    ChooseCupSceneV2(bool);
    ~ChooseCupSceneV2();
    void SceneCreated();
    void Update(float);
    void DisplayCup();
    void SetCurrentChamp(eTeamID, bool, TLComponentInstance*);
    void Proceed();
};

// class FEFinder<TLComponentInstance, 4>
// {
// public:
//     void _Find<FEPresentation>(FEPresentation*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned
//     long); void Find<FEPresentation>(FEPresentation*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher,
//     InlineHasher); void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long,
//     unsigned long); void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned
//     long); void Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
// };

// class FEFinder<TLTextInstance, 3>
// {
// public:
//     void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
// };

// class FEFinder<TLImageInstance, 2>
// {
// public:
//     void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
// };

// class BasicString<unsigned short, Detail
// {
// public:
//     void TempStringAllocator>::Append(const unsigned short*) const;
//     void TempStringAllocator>::AppendInPlace<Detail::TempStringAllocator>(const BasicString<unsigned short,
//     Detail::TempStringAllocator>&); void TempStringAllocator>::Append<Detail::TempStringAllocator>(const BasicString<unsigned short,
//     Detail::TempStringAllocator>&) const;
// };

#endif // _SHCHOOSECUP_H_
