#include "Game/FE/tlComponentInstance.h"

/**
 * Offset/Address/Size: 0x0 | 0x802104F4 | size: 0xC
 */
TLSlide* TLComponentInstance::GetActiveSlide()
{
    return m_component->m_activeSlide;
}

/**
 * Offset/Address/Size: 0xC | 0x80210500 | size: 0x14
 */
void TLComponentInstance::SetActiveSlide(TLSlide* slide)
{
    m_time = 0.0f;
    m_component->m_activeSlide = slide;
}

/**
 * Offset/Address/Size: 0x20 | 0x80210514 | size: 0x2C
 */
void TLComponentInstance::SetActiveSlide(unsigned long hash)
{
    m_time = 0.0f;
    m_component->SetActiveSlide(hash);
}

/**
 * Offset/Address/Size: 0x4C | 0x80210540 | size: 0x2C
 */
void TLComponentInstance::SetActiveSlide(const char* name)
{
    m_time = 0.0f;
    m_component->SetActiveSlide(name);
}

/**
 * Offset/Address/Size: 0x78 | 0x8021056C | size: 0xD8
 */
void TLComponentInstance::Update(float dt)
{
    TLSlide* slide = m_component->m_activeSlide;
    if (!slide)
        return;

    // advance local time (0x80)
    m_time += dt;

    const float total = slide->m_start + slide->m_duration;
    if (m_time > total)
    {
        switch (slide->m_wrapMode)
        {
        case 1: // loop
            m_time = m_time - total;
            break;
        case 0: // clamp
            m_time = total;
            break;
        }
    }

    // if (*(const unsigned char*)((const char*)this + 0x7E) != 0)
    if (m_enableSoundTriggers)
    {
        SoundKeyframeTrigger t;
        t.Update(slide->m_time, m_time);
    }

    slide->m_time = m_time;
    slide->Update(dt);
}
