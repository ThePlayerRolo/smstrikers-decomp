#pragma pool_data off

#include "Game/TrophyInfo.h"

/**
 * Offset/Address/Size: 0x0 | 0x801918A0 | size: 0xA8
 */
const char* GetThrophyModelName(eTrophyType type)
{
    if (type == TROPHY_MUSHROOM)
        return "gameplay/MushroomCup";
    if (type == TROPHY_FLOWER)
        return "gameplay/FlowerCup";
    if (type == TROPHY_STAR)
        return "gameplay/StarCup";
    if (type == TROPHY_BOWSER)
        return "gameplay/BowserCup";
    if (type == TROPHY_SUPER_MUSHROOM)
        return "gameplay/SuperMushroomCup";
    if (type == TROPHY_SUPER_FLOWER)
        return "gameplay/SuperFlowerCup";
    if (type == TROPHY_SUPER_STAR)
        return "gameplay/SuperStarCup";
    if (type == TROPHY_SUPER_BOWSER)
        return "gameplay/SuperBowserCup";
    return "invalid eTrophyType";
}
