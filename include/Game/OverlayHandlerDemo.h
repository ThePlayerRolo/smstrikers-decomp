#ifndef _OVERLAYHANDLERDEMO_H_
#define _OVERLAYHANDLERDEMO_H_


#include "Game/FE/feNSNMessenger.h"

class DemoOverlay : public BaseOverlayHandler
{
public:
    DemoOverlay();
    virtual ~DemoOverlay();
    virtual void Update(float);
    virtual void SceneCreated();
};

#endif // _OVERLAYHANDLERDEMO_H_
