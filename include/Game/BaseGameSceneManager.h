#ifndef _BASEGAMESCENEMANAGER_H_
#define _BASEGAMESCENEMANAGER_H_

#include "types.h"

#include "Game/BaseSceneHandler.h"

#define MAX_SCENE_COUNT 32

enum SceneList
{
    SceneList_None = -2,
    SceneList_0 = 0x0,
    SceneList_1 = 0x1,
    SceneList_2 = 0x2,
    SceneList_3 = 0x3,
    SceneList_4 = 0x4,
    SceneList_5 = 0x5,
    SceneList_6 = 0x6,
    SceneList_7 = 0x7,
    SceneList_8 = 0x8,
    SceneList_9 = 0x9,
    SceneList_10 = 0xA,
    SceneList_11 = 0xB,
    SceneList_12 = 0xC,
    SceneList_13 = 0xD,
    SceneList_14 = 0xE,
    SceneList_15 = 0xF,
    SceneList_16 = 0x10,
    SceneList_17 = 0x11,
    SceneList_18 = 0x12,
    SceneList_19 = 0x13,
    SceneList_20 = 0x14,
    SceneList_21 = 0x15,
    SceneList_22 = 0x16,
    SceneList_23 = 0x17,
    SceneList_24 = 0x18,
    SceneList_25 = 0x19,
    SceneList_26 = 0x1A,
    SceneList_27 = 0x1B,
    SceneList_28 = 0x1C,
    SceneList_29 = 0x1D,
    SceneList_30 = 0x1E,
    SceneList_31 = 0x1F,
};

enum ScreenMovement
{
    ScreenMovement_0,
    ScreenMovement_1,
    ScreenMovement_2,
};

class BaseGameSceneManager
{
public:
    BaseGameSceneManager();
    virtual ~BaseGameSceneManager();
    virtual BaseSceneHandler* Push(SceneList, ScreenMovement, bool);
    BaseSceneHandler* GetScene(SceneList);
    virtual void Pop();
    void PopEntireStack();
    int GetSceneType(BaseSceneHandler*);
    bool IsOnStack(SceneList);
    void GetFileName(SceneList);
    void PushLoadingScene(bool);

    /* 0x04 */ u32 m_count;
    /* 0x08 */ SceneList m_types[MAX_SCENE_COUNT];
    /* 0x88 */ BaseSceneHandler* m_handlers[MAX_SCENE_COUNT];
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
