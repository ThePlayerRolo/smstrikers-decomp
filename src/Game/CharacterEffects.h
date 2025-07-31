#ifndef _CHARACTEREFFECTS_H_
#define _CHARACTEREFFECTS_H_

#include "types.h"

enum eEffectsTextureType
{
    eEffectsTextureType_0 = 0,
    eEffectsTextureType_1,
    eEffectsTextureType_2,
    eEffectsTextureType_3,
    eEffectsTextureType_4
};

u32 fxGetTexturing(eEffectsTextureType);

// void 0x8028D2D4..0x8028D2D8 | size: 0x4;
#endif // _CHARACTEREFFECTS_H_
