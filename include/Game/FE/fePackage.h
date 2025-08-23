#ifndef _FEPACKAGE_H_
#define _FEPACKAGE_H_

#include "Game/FE/fePresentation.h"

class FEPackage
{
public:
    void Update(float);
    FEPresentation* GetPresentation() const;

    /* 0x0 */ char pad0[4];
    /* 0x4 */ FEPresentation* m_presentation;
};

#endif // _FEPACKAGE_H_
