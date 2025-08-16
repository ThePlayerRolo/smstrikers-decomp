#ifndef _TLCOMPONENT_H_
#define _TLCOMPONENT_H_

#include "types.h"

#include "Game/FE/feLibObject.h"

class TLSlide;

class TLComponent : public FELibObject
{
public:
    void SetActiveSlide(unsigned long);
    void SetActiveSlide(const char*);

    /* 0x40 */ u8 pad40[0x28];
    /* 0x68 */ TLSlide* m_slides;
    /* 0x6C */ TLSlide* m_activeSlide;
};

#endif // _TLCOMPONENT_H_
