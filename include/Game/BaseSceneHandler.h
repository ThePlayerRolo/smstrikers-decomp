#ifndef _BASESCENEHANDLER_H_
#define _BASESCENEHANDLER_H_

#include "types.h"

#include "Game/FE/FEPresentation.h"
#include "Game/FE/FEScene.h"

// void nlDLRingAddEnd<BaseScreenHandler>(BaseScreenHandler**, BaseScreenHandler*);
// void nlDLRingAddStart<BaseScreenHandler>(BaseScreenHandler**, BaseScreenHandler*);

typedef struct BaseScreenHandler
{
    /* 0x00 */ char pad0[4];
    /* 0x04 */ BaseScreenHandler* m_next; /* inferred */
    /* 0x08 */ BaseScreenHandler* m_prev; /* inferred */
    /* 0x0C */ char padC[4];
    /* 0x10 */ FEScene* m_scene; /* inferred */
} BaseScreenHandler;

class BaseSceneHandler
{
public:
    BaseSceneHandler()
    {
        m_visible = true;
        m_screenHandler = NULL;
        m_unk_0x10 = NULL;
        m_presentation = NULL;
        m_unk_0x18 = NULL;
    };
    virtual ~BaseSceneHandler() { };
    virtual void Update(float);
    virtual void InitializeSubHandlers() { };
    virtual void AddScreenHandler(BaseScreenHandler*);
    virtual void RemoveScreenHandler(BaseScreenHandler*);
    virtual void SetPresentation(FEPresentation* presentation) { m_presentation = presentation; };
    virtual void OnActivate();
    virtual void SceneCreated();
    virtual void SetVisible(bool visible) { m_visible = visible; };

    /* 0x04 */ char pad04[0x4];
    /* 0x08 */ bool m_visible;
    /* 0x0C */ BaseScreenHandler* m_screenHandler;
    /* 0x10 */ void** m_unk_0x10;
    /* 0x14 */ FEPresentation* m_presentation;
    /* 0x18 */ FEScene* m_unk_0x18;
};

#endif // _BASESCENEHANDLER_H_
