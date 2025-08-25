#include "Game/FE/feScene.h"

#include "NL/nlMemory.h"
#include "NL/gl/glMatrix.h"
#include "NL/nlDLRing.h"

extern bool gSebringLoadPackageToVirtualMemory;

// FEResourceHandle FEScene::m_resourceHandler;

/**
 * Offset/Address/Size: 0x0 | 0x80209D74 | size: 0x24
 */
void FEScene::Update(float dt)
{
    m_package->Update(dt);
}

/**
 * Offset/Address/Size: 0x24 | 0x80209D98 | size: 0x4
 */
void FEScene::AllResourcesLoadedCallback()
{
    // EMPTY
}

/**
 * Offset/Address/Size: 0x28 | 0x80209D9C | size: 0x24
 */
void QueueResourceLoadCallback::Callback(FEResourceHandle* handle)
{
    m_resourceManager->QueueResourceLoad(handle);
}

/**
 * Offset/Address/Size: 0x4C | 0x80209DC0 | size: 0x70
 */
void FEScene::UnloadPackage()
{
    UnloadResourceCallback unloadResourceCallback;
    nlWalkRing<FEResourceHandle, UnloadResourceCallback>(&m_resourceHandler, &unloadResourceCallback, &UnloadResourceCallback::Callback);
    FEResourceManager::s_pInstance.Instance()->UnloadResource(&m_resourceHandler);
}

/**
 * Offset/Address/Size: 0xBC | 0x80209E30 | size: 0x24
 */
void UnloadResourceCallback::Callback(FEResourceHandle* handle)
{
    m_resourceManager->UnloadResource(handle);
}

/**
 * Offset/Address/Size: 0xE0 | 0x80209E54 | size: 0x26C
 */
void FEScene::LoadPackage(const char*)
{
}

/**
 * Offset/Address/Size: 0x34C | 0x8020A0C0 | size: 0x7C
 */
FEScene::~FEScene()
{
    if (m_package != NULL)
    {
        if (gSebringLoadPackageToVirtualMemory)
        {
            nlVirtualFree(m_package);
        }
        else
        {
            delete[] m_package;
        }
        m_package = NULL;
        m_unk_0x04 = 0;
    }
}

/**
 * Offset/Address/Size: 0x3C8 | 0x8020A13C | size: 0x8C
 */
FEScene::FEScene()
{
    m_package = NULL;
    m_unk_0x04 = 0;
    m_unk_0x08 = false;
    m_unk_0x4C = 0;

    const nlVector3 FROM(0.0f, 0.0f, 600.0f);
    const nlVector3 TO(0.0f, 0.0f, 0.0f);
    const nlVector3 UP(0.0f, 1.0f, 0.0f);

    glMatrixLookAt(m_transf, FROM, TO, UP);
}
