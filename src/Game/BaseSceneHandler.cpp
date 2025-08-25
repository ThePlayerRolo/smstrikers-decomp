#include "Game/BaseSceneHandler.h"

/**
 * Offset/Address/Size: 0x68 | 0x80212920 | size: 0x24
 */
void BaseSceneHandler::Update(float dt)
{
    m_unk_0x18->Update(dt);
}

/**
 * Offset/Address/Size: 0x3C | 0x802128F4 | size: 0x2C
 */
void BaseSceneHandler::AddScreenHandler(BaseScreenHandler* handler)
{
    handler->m_scene = (FEScene*)m_unk_0x18;
    nlDLRingAddEnd<BaseScreenHandler>(&m_screenHandler, handler);
}

/**
 * Offset/Address/Size: 0x38 | 0x802128F0 | size: 0x4
 */
void BaseSceneHandler::RemoveScreenHandler(BaseScreenHandler*)
{
}

/**
 * Offset/Address/Size: 0x0 | 0x802128B8 | size: 0x38
 */
void BaseSceneHandler::OnActivate()
{
    if (m_unk_0x10 != nullptr)
    {
        m_unk_0x10->fnc3(); // TODO: not sure what this is yet
    }
}
