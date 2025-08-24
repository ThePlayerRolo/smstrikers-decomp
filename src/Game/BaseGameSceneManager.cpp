#include "Game/BaseGameSceneManager.h"

// /**
//  * Offset/Address/Size: 0x64 | 0x80096B94 | size: 0x4
//  */
// void IntroMovieScene::PlayScreenBackSFX()
// {
// }

// /**
//  * Offset/Address/Size: 0x60 | 0x80096B90 | size: 0x4
//  */
// void IntroMovieScene::PlayScreenForwardSFX()
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x80096B30 | size: 0x60
//  */
// IntroMovieScene::~IntroMovieScene()
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x80096AF8 | size: 0x38
//  */
// void SlideMenuList::SetSlide()
// {
// }

/**
 * Offset/Address/Size: 0x54 | 0x80096AF0 | size: 0x8
 */
// void BaseSceneHandler::SetPresentation(FEPresentation*)
// {
// }

/**
 * Offset/Address/Size: 0x50 | 0x80096AEC | size: 0x4
 */
// void BaseSceneHandler::InitializeSubHandlers()
// {
// }

/**
 * Offset/Address/Size: 0x8 | 0x80096AA4 | size: 0x48
 */
// BaseSceneHandler::~BaseSceneHandler()
// {
// }

/**
 * Offset/Address/Size: 0x0 | 0x80096A9C | size: 0x8
 */
// void BaseSceneHandler::SetVisible(bool)
// {
// }

/**
 * Offset/Address/Size: 0x142C | 0x800969E8 | size: 0xB4
 */
BaseGameSceneManager::BaseGameSceneManager()
{
}

/**
 * Offset/Address/Size: 0x13B0 | 0x8009696C | size: 0x7C
 */
BaseGameSceneManager::~BaseGameSceneManager()
{
}

/**
 * Offset/Address/Size: 0x324 | 0x800958E0 | size: 0x108C
 */
void BaseGameSceneManager::Push(SceneList, ScreenMovement, bool)
{
}

/**
 * Offset/Address/Size: 0x2D8 | 0x80095894 | size: 0x4C
 */
void BaseGameSceneManager::GetScene(SceneList)
{
}

/**
 * Offset/Address/Size: 0x288 | 0x80095844 | size: 0x50
 */
void BaseGameSceneManager::Pop()
{
}

/**
 * Offset/Address/Size: 0x23C | 0x800957F8 | size: 0x4C
 */
void BaseGameSceneManager::PopEntireStack()
{
}

/**
 * Offset/Address/Size: 0x1F4 | 0x800957B0 | size: 0x48
 */
void BaseGameSceneManager::GetSceneType(BaseSceneHandler*)
{
}

/**
 * Offset/Address/Size: 0x1C0 | 0x8009577C | size: 0x34
 */
void BaseGameSceneManager::IsOnStack(SceneList)
{
}

/**
 * Offset/Address/Size: 0x68 | 0x80095624 | size: 0x158
 */
void BaseGameSceneManager::GetFileName(SceneList)
{
}

/**
 * Offset/Address/Size: 0x0 | 0x800955BC | size: 0x68
 */
void BaseGameSceneManager::PushLoadingScene(bool)
{
}
