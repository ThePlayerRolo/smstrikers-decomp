#include "Game/FE/feScene.h"

/**
 * Offset/Address/Size: 0x0 | 0x80209D74 | size: 0x24
 */
void FEScene::Update(float)
{
}

/**
 * Offset/Address/Size: 0x24 | 0x80209D98 | size: 0x4
 */
void FEScene::AllResourcesLoadedCallback()
{
}

/**
 * Offset/Address/Size: 0x28 | 0x80209D9C | size: 0x24
 */
// void QueueResourceLoadCallback::Callback(FEResourceHandle*)
// {
// }

/**
 * Offset/Address/Size: 0x4C | 0x80209DC0 | size: 0x70
 */
void FEScene::UnloadPackage()
{
}

/**
 * Offset/Address/Size: 0xBC | 0x80209E30 | size: 0x24
 */
// void UnloadResourceCallback::Callback(FEResourceHandle*)
// {
// }

/**
 * Offset/Address/Size: 0xE0 | 0x80209E54 | size: 0x26C
 */
void FEScene::LoadPackage(const char*)
{
}

/**
 * Offset/Address/Size: 0x34C | 0x8020A0C0 | size: 0x7C
 */
FEScene::~FEScene()
{
}

/**
 * Offset/Address/Size: 0x3C8 | 0x8020A13C | size: 0x8C
 */
FEScene::FEScene()
{
}

// /**
//  * Offset/Address/Size: 0x0 | 0x8020A1C8 | size: 0x60
//  */
// void nlWalkRing<FEResourceHandle, QueueResourceLoadCallback>(FEResourceHandle*, QueueResourceLoadCallback*, void
// (QueueResourceLoadCallback::*)(FEResourceHandle*))
// {
// }

// /**
//  * Offset/Address/Size: 0x60 | 0x8020A228 | size: 0x60
//  */
// void nlWalkRing<FEResourceHandle, UnloadResourceCallback>(FEResourceHandle*, UnloadResourceCallback*, void
// (UnloadResourceCallback::*)(FEResourceHandle*))
// {
// }
