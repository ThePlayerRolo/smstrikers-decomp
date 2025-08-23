#ifndef _SHCUPOPTIONS_H_
#define _SHCUPOPTIONS_H_

#include "types.h"

class SceneList
{
public:
    SceneList();
    ~SceneList();
};

class CupOptionsScene
{
public:
    CupOptionsScene(SceneList, SceneList);
    ~CupOptionsScene();
    void SceneCreated();
    void Update(float);
};

#endif // _SHCUPOPTIONS_H_
