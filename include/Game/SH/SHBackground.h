#ifndef _SHBACKGROUND_H_
#define _SHBACKGROUND_H_

#include "types.h"

#include "Game/BaseSceneHandler.h"

class BackgroundScene : public BaseSceneHandler
{
public:
    BackgroundScene();
    virtual ~BackgroundScene();
    virtual void Update(float);
    virtual void SceneCreated();

    /* 0x20 */ s32 m_unk_0x20;
};

#endif // _SHBACKGROUND_H_
