#ifndef _WORLDMANAGER_H_
#define _WORLDMANAGER_H_


class WorldManager
{
public:
    void DestroyWorld();
    void LoadWorld(const char*, bool);
    void UpdateWorld(float);
    void RenderWorld();
};

#endif // _WORLDMANAGER_H_