#include "Game/FE/tlSlide.h"
#include "Game/FE/tlComponentInstance.h"

#include "NL/nlDLRing.h"

/**
 * Offset/Address/Size: 0x0 | 0x8020FBE0 | size: 0xD8
 */
void TLSlide::Update(float time)
{
    FEAnimation* anim;
    TLComponentInstance* var_r31_2;

    anim = nlDLRingGetStart<FEAnimation>(this->m_animations);
loop_1:
    if (anim != NULL)
    {
        anim->Update(m_time);
        if (nlDLRingIsEnd<FEAnimation>(this->m_animations, anim) == 0)
        {
            anim = anim->m_next;
            goto loop_1;
        }
    }
    var_r31_2 = (TLComponentInstance*)nlDLRingGetStart<TLInstance>(this->m_instances);
loop_5:
    if (var_r31_2 != NULL)
    {
        if (var_r31_2->m_unk_0x78 == 4)
        {
            var_r31_2->Update(time);
        }
        UpdateAsset(var_r31_2, time);
        if (nlDLRingIsEnd<TLInstance>(this->m_instances, var_r31_2) == 0)
        {
            var_r31_2 = (TLComponentInstance*)var_r31_2->m_next;
            goto loop_5;
        }
    }
}

/**
 * Offset/Address/Size: 0xD8 | 0x8020FCB8 | size: 0x290
 */
void TLSlide::UpdateAsset(TLInstance* instance, float time)
{
}

// /**
//  * Offset/Address/Size: 0x0 | 0x8020FF48 | size: 0x20
//  */
// void nlDLRingIsEnd<TLInstance>(TLInstance*, TLInstance*)
// {
// }

// /**
//  * Offset/Address/Size: 0x20 | 0x8020FF68 | size: 0x18
//  */
// void nlDLRingGetStart<TLInstance>(TLInstance*)
// {
// }
