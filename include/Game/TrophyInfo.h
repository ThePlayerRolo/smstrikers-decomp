#ifndef _TROPHYINFO_H_
#define _TROPHYINFO_H_

#include "types.h"

enum eTrophyType
{
    TROPHY_MUSHROOM = 0,
    TROPHY_FLOWER = 1,
    TROPHY_STAR = 2,
    TROPHY_BOWSER = 3,
    TROPHY_SUPER_MUSHROOM = 4,
    TROPHY_SUPER_FLOWER = 5,
    TROPHY_SUPER_STAR = 6,
    TROPHY_SUPER_BOWSER = 7
};

const char* GetThrophyModelName(eTrophyType);

#endif // _TROPHYINFO_H_
