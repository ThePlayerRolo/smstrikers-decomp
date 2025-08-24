#include "Game/BaseSceneHandler.h"

// /**
//  * Offset/Address/Size: 0x3C | 0x80212980 | size: 0x38
//  */
// void nlDLRingAddStart<BaseScreenHandler>(BaseScreenHandler**, BaseScreenHandler*)
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x80212944 | size: 0x3C
//  */
// void nlDLRingAddEnd<BaseScreenHandler>(BaseScreenHandler**, BaseScreenHandler*)
// {
// }

/**
 * Offset/Address/Size: 0x68 | 0x80212920 | size: 0x24
 */
void BaseSceneHandler::Update(float)
{
}

/**
 * Offset/Address/Size: 0x3C | 0x802128F4 | size: 0x2C
 */
void BaseSceneHandler::AddScreenHandler(BaseScreenHandler*)
{
}

/**
 * Offset/Address/Size: 0x38 | 0x802128F0 | size: 0x4
 */
void BaseSceneHandler::RemoveScreenHandler(BaseScreenHandler*)
{
}

/**
 * Offset/Address/Size: 0x0 | 0x802128B8 | size: 0x38
 */
void BaseSceneHandler::OnActivate()
{
}
