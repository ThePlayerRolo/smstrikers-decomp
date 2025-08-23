#ifndef _SHBACKGROUND_H_
#define _SHBACKGROUND_H_

#include "types.h"

class BackgroundScene
{
public:
    BackgroundScene();
    ~BackgroundScene();
    void SceneCreated();
    void Update(float);
};

#endif // _SHBACKGROUND_H_
