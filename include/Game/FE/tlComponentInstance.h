#ifndef _TLCOMPONENTINSTANCE_H_
#define _TLCOMPONENTINSTANCE_H_

#include "Game/FE/tlSlide.h"

class TLComponentInstance
{
public:
    void GetActiveSlide();
    void SetActiveSlide(TLSlide*);
    void SetActiveSlide(unsigned long);
    void SetActiveSlide(const char*);
    void Update(float);
};

#endif // _TLCOMPONENTINSTANCE_H_
