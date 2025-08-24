#include "Game/SH/SHBackground.h"

/**
 * Offset/Address/Size: 0x16C | 0x800A9A18 | size: 0x44
 */
BackgroundScene::BackgroundScene()
    : BaseSceneHandler()
{
    m_unk_0x1C = 3;
    m_unk_0x20 = 3;
}

/**
 * Offset/Address/Size: 0x110 | 0x800A99BC | size: 0x5C
 */
BackgroundScene::~BackgroundScene()
{
}

/**
 * Offset/Address/Size: 0xA8 | 0x800A9954 | size: 0x68
 */
void BackgroundScene::SceneCreated()
{
    TLSlide* slide;
    s32 temp_r0;

    temp_r0 = m_unk_0x1C;
    if (temp_r0 != 3)
    {
        slide = m_presentation->m_currentSlide;
        switch (temp_r0)
        {
        case 1:
            slide->m_wrapMode = 1;
            break;
        case 2:
            slide->m_wrapMode = 0;
            break;
        }
        slide->m_time = 0.0f;
        slide->Update(0.0f);
    }
}

#define assert(condition) ((condition) ? ((void)0) : ((void)0))
#define _ASSERT(cond)

/**
 * Offset/Address/Size: 0x0 | 0x800A98AC | size: 0xA8
 */
void BackgroundScene::Update(float dt)
{
    TLSlide* slide;
    // s32 temp_r4;
    s32 temp_r4 = m_unk_0x1C;
    s32 temp_r5 = m_unk_0x20;
    if ((temp_r5 != temp_r4) && (temp_r4 != 3))
    {
        slide = m_presentation->m_currentSlide;
        switch (temp_r4)
        {
        case 1:
            slide->m_wrapMode = 1;
            break;
        case 2:
            slide->m_wrapMode = 0;
            break;
        }
        slide->m_time = 0.0f;
        slide->Update(0.0f);
    }

    _ASSERT(m_unk_0x1C == 0);

    // assert(m_unk_0x1C == 0);
    // (m_unk_0x1C == 0) ? m_unk_0x1C : m_unk_0x1C; // just to produce "cmplwi r3, 0x0"

    BaseSceneHandler::Update(dt);
}
