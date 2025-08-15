#ifndef _TLCOMPONENT_H_
#define _TLCOMPONENT_H_

#include "types.h"

#include "Game/FE/tlSlide.h"

class TLComponent
{
public:
    void SetActiveSlide(unsigned long);
    void SetActiveSlide(const char*);

    /* 0x00 */ char pad0[0x68];
    /* 0x68 */ TLSlide* m_slides;      // Offset 0x68 - linked list of slides
    /* 0x6C */ TLSlide* m_activeSlide; // Offset 0x6C - currently active slide
};

#endif // _TLCOMPONENT_H_
