#ifndef _SHLOADING_H_
#define _SHLOADING_H_

#include "types.h"

#include "Game/FE/tlTextInstance.h"

class SuperLoadingScene
{
public:
    SuperLoadingScene();
    ~SuperLoadingScene();
    void SceneCreated();
    void Update(float);
    void DisplayCupInfo();
    void BuildPlayerStrings(TLTextInstance*, int, bool);
};

// class BasicString<unsigned short, Detail
// {
// public:
//     void TempStringAllocator>::AppendInPlace(const unsigned short*);
// };

// class FEFinder<TLTextInstance, 3>
// {
// public:
//     void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
// };

// class FEFinder<TLComponentInstance, 4>
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

// class Format<BasicString<unsigned short, Detail
// {
// public:
//     void TempStringAllocator>, unsigned short[16]>(const BasicString<unsigned short, Detail::TempStringAllocator>&, const unsigned
//     short(&)[16]); void TempStringAllocator>, unsigned short[2]>(const BasicString<unsigned short, Detail::TempStringAllocator>&, const
//     unsigned short(&)[2]);
// };

// class FormatImpl<BasicString<unsigned short, Detail
// {
// public:
//     void TempStringAllocator>>::operator%<const unsigned short*>(const unsigned short* const&);
// };

#endif // _SHLOADING_H_
