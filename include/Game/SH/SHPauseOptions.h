#ifndef _SHPAUSEOPTIONS_H_
#define _SHPAUSEOPTIONS_H_

class PauseOptionsScene
{
public:
    enum Mode
    {
        Mode_0 = 0
    };

    PauseOptionsScene(PauseOptionsScene::Mode);
    ~PauseOptionsScene();
    void SceneCreated();
    void Update(float);
};

#endif // _SHPAUSEOPTIONS_H_
