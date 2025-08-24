#ifndef _GAMESCENEMANAGER_H_
#define _GAMESCENEMANAGER_H_

#include "types.h"

#include "Game/BaseGameSceneManager.h"

class GameSceneManager : public BaseGameSceneManager
{
public:
    GameSceneManager();
    ~GameSceneManager();

    void Pop();
};

#endif // _GAMESCENEMANAGER_H_
