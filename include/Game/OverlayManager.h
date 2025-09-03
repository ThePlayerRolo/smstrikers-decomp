#ifndef _OVERLAYMANAGER_H_
#define _OVERLAYMANAGER_H_

#include "Game/Sys/eventman.h"
#include "types.h"
#include "Game/BaseGameSceneManager.h"

enum OverlaySlideName {
    SLIDE_NAME_INVALID = -1,
    SLIDE_NAME_TEXT_GOAL = 0,
    SLIDE_NAME_TEXT_KICKOFF = 1,
    SLIDE_NAME_TEXT_WINNER = 2,
    SLIDE_NAME_TEXT_PAUSE = 3,
    SLIDE_NAME_TEXT_TIE = 4,
    SLIDE_NAME_TEXT_LOADING = 5,
    SLIDE_NAME_TEXT_SHOOT = 6,
    SLIDE_NAME_TEXT_REPLAY = 7,
    NUM_SLIDE_NAMES = 8,
};

class OverlayManager : public BaseGameSceneManager
{
public:
    OverlayManager();
    ~OverlayManager();
    virtual BaseSceneHandler* Push(SceneList, ScreenMovement, bool);
    virtual void Pop();
    void SetCurrentTextOverlaySlide(OverlaySlideName);
    void Update(float);
    void FEEventHandler(Event*, void*);
    void SetVisible(SceneList, bool, bool);
    void HandleStateTransition(u32, u32);
    void DestroyMessengerManager();
    void ShowDemoSlide();
    void RestartGoalOverlay();

    static nlSingleton<OverlayManager> s_pInstance;

    class InGameTextOverlay * mInGameTextOverlay; // offset 0x108, size 0x4
    bool mIsHUDSlideIn; // offset 0x10C, size 0x1
    bool mDoHUDSlideIn; // offset 0x10D, size 0x1
    bool mIsInHighlights; // offset 0x10E, size 0x1
    bool mIsDemoSlideVisible; // offset 0x10F, size 0x1
    f32 mHUDDelay; // offset 0x110, size 0x4
    class FEInGameMessengerManager * mIGMessengerManager; // offset 0x114, size 0x4


};

#endif // _OVERLAYMANAGER_H_
