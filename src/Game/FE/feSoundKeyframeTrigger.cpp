#include "Game/FE/feSoundKeyframeTrigger.h"

#include "Game/FE/feAnimation.h"

#include "NL/nlDLRing.h"

inline fAnimationKeyframe* GetAnimationKeyframe(fAnimationKeyframe* start, float t)
{
    fAnimationKeyframe* it = start;
    do
    {
        if (t <= it->unkC)
        {
            return it;
        }
        it = it->m_next;
    } while (it != start);
    return NULL;
}

/**
 * Offset/Address/Size: 0x0 | 0x8010EF64 | size: 0x1A8
 */
void SoundKeyframeTrigger::Update(float arg0, float arg1)
{
    f32 var_f29;
    f32 temp_f0;
    fAnimationKeyframe* first_kf;
    UnkStruct* temp_r3_2;
    TLInstance* temp_r5;
    fAnimationKeyframe* var_r28;
    fAnimationKeyframe* var_r31;
    fAnimationKeyframe* var_r4;
    FEAnimation* var_r29;
    FEAnimation* temp_r30;

    var_f29 = arg0;
    if (var_f29 != arg1)
    {
        temp_r30 = m_slide->m_animations;
        var_r29 = nlDLRingGetStart<FEAnimation>(temp_r30);
    loop_2:
        if (var_r29 != NULL)
        {
            if ((var_r29->unk10 == 0) && (var_r29->unk14 == 6))
            {
                // var_r28 = GetAnimationKeyframe(nlDLRingGetStart<fAnimationKeyframe>(var_r29->unk18), var_f29);
                first_kf = nlDLRingGetStart<fAnimationKeyframe>(var_r29->unk18);
                var_r4 = first_kf;
            loop_6:
                if (var_f29 <= var_r4->unkC)
                {
                    var_r28 = var_r4;
                }
                else
                {
                    var_r4 = var_r4->m_next;
                    if (var_r4 == first_kf)
                    {
                        var_r28 = NULL;
                    }
                    else
                    {
                        goto loop_6;
                    }
                }

                var_r31 = var_r28;
            loop_23:
                if (var_r28 != NULL)
                {
                    if ((var_f29 > arg1) && (arg1 > var_r31->unkC))
                    {
                        var_f29 = 0.0f;
                    }
                    temp_f0 = var_r31->unkC;
                    if (var_f29 <= temp_f0)
                    {
                        if (arg1 >= temp_f0)
                        {
                            if (var_r31->unk0 >= 255.0f)
                            {
                                temp_r5 = var_r29->m_instance;
                                temp_r3_2 = temp_r5->m_unk_0x18;
                                if ((temp_r3_2 != NULL) && (temp_r3_2->unk0 == 0x73) && (temp_r3_2->unk1 == 0x66)
                                    && (temp_r3_2->unk2 == 0x78))
                                {
                                    temp_r5->m_enableSoundTriggers = 0;
                                    temp_r5->m_unk_0x38->PlayAnimAudioEvent(*(u32*)temp_r5, false);
                                }
                            }
                            var_r31 = var_r31->m_next;
                            if (var_r31 != var_r28)
                            {
                                goto loop_23;
                            }
                        }
                    }
                }
            }
            if (nlDLRingIsEnd<FEAnimation>(temp_r30, var_r29) == 0)
            {
                var_r29 = var_r29->m_next;
                goto loop_2;
            }
        }
    }
}

// /**
//  * Offset/Address/Size: 0x0 | 0x8010F10C | size: 0x20
//  */
// void nlDLRingIsEnd<FEAnimation>(FEAnimation*, FEAnimation*)
// {
// }

// /**
//  * Offset/Address/Size: 0x20 | 0x8010F12C | size: 0x18
//  */
// void nlDLRingGetStart<fAnimationKeyframe>(fAnimationKeyframe*)
// {
// }

// /**
//  * Offset/Address/Size: 0x38 | 0x8010F144 | size: 0x18
//  */
// void nlDLRingGetStart<FEAnimation>(FEAnimation*)
// {
// }
