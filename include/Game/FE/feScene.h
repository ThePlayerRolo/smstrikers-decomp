#ifndef _FESCENE_H_
#define _FESCENE_H_

#include "types.h"

#include "Game/FE/FEPackage.h"
#include "Game/FE/FEResourceManager.h"

class FEScene
{
public:
    FEScene();
    ~FEScene();

    void AllResourcesLoadedCallback();
    void LoadPackage(const char*);
    void UnloadPackage();
    void Update(float);

    /* 0x00 */ FEPackage* m_package;
    /* 0x04 */ s32 m_unk_0x04;
    /* 0x08 */ bool m_unk_0x08;
    // /* 0x09 */ char m_unk_0x09[3];
    /* 0x0C */ nlMatrix4 m_transf;
    /* 0x4C */ s32 m_unk_0x4C;
    /* 0x50 */ static FEResourceHandle m_resourceHandler;
    /* 0x54 */ s32 m_unk_0x54;
    /* 0x58 */ s32 m_unk_0x58;
    /* 0x5C */ s32 m_unk_0x5C;
    /* 0x60 */ char pad60[4];
    /* 0x64 */ FEScene* m_scene;
};

class QueueResourceLoadCallback
{
public:
    void Callback(FEResourceHandle*);
    FEResourceManager* m_resourceManager;
};

class UnloadResourceCallback
{
public:
    void Callback(FEResourceHandle*);
    FEResourceManager* m_resourceManager;
};

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
