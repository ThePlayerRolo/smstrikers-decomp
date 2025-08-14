#ifndef _FESCENE_H_
#define _FESCENE_H_

class FEScene
{
public:
    void Update(float);
    void AllResourcesLoadedCallback();
    void UnloadPackage();
    void LoadPackage(const char*);
    ~FEScene();
    FEScene();
};

// class QueueResourceLoadCallback
// {
// public:
//     void Callback(FEResourceHandle*);
// };

// class UnloadResourceCallback
// {
// public:
//     void Callback(FEResourceHandle*);
// };

// class nlWalkRing<FEResourceHandle, QueueResourceLoadCallback>(FEResourceHandle*, QueueResourceLoadCallback*, void
// (QueueResourceLoadCallback
// {
// public:
//     void *)(FEResourceHandle*));
// };

// class nlWalkRing<FEResourceHandle, UnloadResourceCallback>(FEResourceHandle*, UnloadResourceCallback*, void (UnloadResourceCallback
// {
// public:
//     void *)(FEResourceHandle*));
// };

#endif // _FESCENE_H_
