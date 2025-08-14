#ifndef _FEPOPUPMENU_H_
#define _FEPOPUPMENU_H_

#include "fePresentation.h"

// void CastToSomeType<TLInstance>(TLInstance*, void*);
// void CastToSomeType<TLSlide>(TLSlide*, void*);
// void FindItemByHashID<TLInstance>(TLInstance*, unsigned long);
// void FindItemByHashID<TLSlide>(TLSlide*, unsigned long);

class FEPopupMenu
{
public:
    void SetOptionTextColourOnCurrent(bool);
    void ResizeHighlight();
    void CentrePopup(float, float);
    void SetPositions();
    void Update(float);
    void SceneCreated();
    ~FEPopupMenu();
    FEPopupMenu();

    /* 0x0 */ TLSlide* m_slides;
};

// class FEFinder<TLTextInstance, 3>
// {
// public:
//     void Find<FEPresentation>(FEPresentation*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
//     void _Find<FEPresentation>(FEPresentation*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned
//     long); void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long); void
//     _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
// };

// class FEFinder<TLImageInstance, 2>
// {
// public:
//     void Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
//     void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
// };

// class FEFinder<TLComponentInstance, 4>
// {
// public:
//     void Find<FEPresentation>(FEPresentation*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
//     void _Find<FEPresentation>(FEPresentation*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned
//     long); void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long); void
//     _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long); void
//     Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
// };

// class BasicString<unsigned short, Detail
// {
// public:
//     void TempStringAllocator>::operator=(BasicString<unsigned short, Detail::TempStringAllocator>);
//     void TempStringAllocator>::~BasicString();
//     void TempStringAllocator>::BasicString(const unsigned short*);
//     void TempStringAllocator>::insert(unsigned short*, const unsigned short*, const unsigned short*);
//     void TempStringAllocator>::erase(const unsigned short*, const unsigned short*);
// };

// class nlBSearch<nlLocalization
// {
// public:
//     void StringLookup, unsigned long>(const unsigned long&, nlLocalization::StringLookup*, int);
// };

// class LexicalCast<BasicString<unsigned short, Detail
// {
// public:
//     void TempStringAllocator>, BasicString<unsigned short, Detail::TempStringAllocator>>(const BasicString<unsigned short,
//     Detail::TempStringAllocator>&); void TempStringAllocator>, const unsigned short*>(const unsigned short* const&);
// };

// class Detail
// {
// public:
//     void LexicalCastImpl<BasicString<unsigned short, Detail::TempStringAllocator>, BasicString<unsigned short,
//     Detail::TempStringAllocator>>::Do(const BasicString<unsigned short, Detail::TempStringAllocator>&); void
//     LexicalCastImpl<BasicString<unsigned short, Detail::TempStringAllocator>, const unsigned short*>::Do(const unsigned short* const&);
// };

// class Format<BasicString<unsigned short, Detail
// {
// public:
//     void TempStringAllocator>, BasicString<unsigned short, Detail::TempStringAllocator>, BasicString<unsigned short,
//     Detail::TempStringAllocator>, BasicString<unsigned short, Detail::TempStringAllocator>>(const BasicString<unsigned short,
//     Detail::TempStringAllocator>&, const BasicString<unsigned short, Detail::TempStringAllocator>&, const BasicString<unsigned short,
//     Detail::TempStringAllocator>&, const BasicString<unsigned short, Detail::TempStringAllocator>&); void TempStringAllocator>,
//     BasicString<unsigned short, Detail::TempStringAllocator>>(const BasicString<unsigned short, Detail::TempStringAllocator>&, const
//     BasicString<unsigned short, Detail::TempStringAllocator>&); void TempStringAllocator>, unsigned short[4]>(const BasicString<unsigned
//     short, Detail::TempStringAllocator>&, const unsigned short(&)[4]);
// };

// class FormatImpl<BasicString<unsigned short, Detail
// {
// public:
//     void TempStringAllocator>>::operator BasicString<unsigned short, Detail::TempStringAllocator>() const;
//     void TempStringAllocator>>::operator%<BasicString<unsigned short, Detail::TempStringAllocator>>(const BasicString<unsigned short,
//     Detail::TempStringAllocator>&); void TempStringAllocator>>::operator%<const unsigned short*>(const unsigned short* const&);
// };

#endif // _FEPOPUPMENU_H_
