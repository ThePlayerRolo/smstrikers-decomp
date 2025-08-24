#ifndef _BASEGAMESCENEMANAGER_H_
#define _BASEGAMESCENEMANAGER_H_

#include "types.h"

#include "Game/BaseSceneHandler.h"

class SceneList
{
public:
};

enum ScreenMovement
{
    ScreenMovement_None,
    ScreenMovement_Push,
    ScreenMovement_Pop,
};

class BaseGameSceneManager
{
public:
    BaseGameSceneManager();
    ~BaseGameSceneManager();
    void Push(SceneList, ScreenMovement, bool);
    void GetScene(SceneList);
    void Pop();
    void PopEntireStack();
    void GetSceneType(BaseSceneHandler*);
    void IsOnStack(SceneList);
    void GetFileName(SceneList);
    void PushLoadingScene(bool);
};

// class BaseSceneHandler
// {
// public:
//     void SetPresentation(FEPresentation*);
//     void InitializeSubHandlers();
//     ~BaseSceneHandler();
//     void SetVisible(bool);
// };

// class SlideMenuList
// {
// public:
//     void SetSlide();
// };

// class IntroMovieScene
// {
// public:
//     void PlayScreenBackSFX();
//     void PlayScreenForwardSFX();
//     ~IntroMovieScene();
// };

#endif // _BASEGAMESCENEMANAGER_H_
