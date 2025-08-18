#include "Game/FE/feAnimation.h"
#include "NL/nlMath.h"

/**
 * Offset/Address/Size: 0x0 | 0x8020E580 | size: 0x19C
 */
void FEAnimation::Update(float time)
{
    u16 temp_r0 = unk10;
    
    switch (temp_r0) {
        case 1:
            AnimateTargetAtTimeWithVector3(time);
            return;
        case 0: {
            fAnimationKeyframe* temp_r3 = nlDLRingGetStart<fAnimationKeyframe>((fAnimationKeyframe*)m_DLRingHead);
            fAnimationKeyframe* var_r31 = temp_r3;
            
            if (var_r31 != temp_r3->m_next) {
                if (time == var_r31->unkC) {
loop_9:
                    if (time > var_r31->unkC) {
                        var_r31 = var_r31->m_next;
                        if (nlDLRingIsEnd<fAnimationKeyframe>((fAnimationKeyframe*)m_DLRingHead, var_r31) == 0) {
                            goto loop_9;
                        }
                    }
                    
                    float temp_f2 = var_r31->unkC;
                    float var_f31;
                    
                    if (time == temp_f2) {
                        var_f31 = var_r31->unk0;
                    } else if (!(time > temp_f2) || (var_r31->unk4 != -1.0f)) {
                        fAnimationKeyframe* temp_r9 = (fAnimationKeyframe*)var_r31->m_prev;
                        float temp_f0 = temp_r9->unkC;
                        
                        float spC, sp10, sp14, sp18;
                        spC = temp_r9->unk0;
                        sp10 = temp_r9->unk4;
                        sp14 = temp_r9->unk8;
                        sp18 = var_r31->unk0;
                        
                        var_f31 = nlBezier(&spC, 3, (time - temp_f0) / (temp_f2 - temp_f0));
                    } else {
                        var_f31 = var_r31->unk0;
                    }
                    
                    if ((var_f31 != -1.0f) && (unk14 == 6)) {
                        const nlColour* color = m_instance->GetAssetColour();
                        nlColour newColor = *color;
                        newColor.a = (u8)var_f31;
                        m_instance->SetAssetColour(newColor);
                    }
                }
            }
            return;
        }
    }
}

/**
 * Offset/Address/Size: 0x19C | 0x8020E71C | size: 0x298
 */
void FEAnimation::AnimateTargetAtTimeWithVector3(float time)
{
    float var_f29 = time;
    v3AnimationKeyframe* temp_r3 = nlDLRingGetStart<v3AnimationKeyframe>((v3AnimationKeyframe*)m_DLRingHead);
    float temp_f0 = temp_r3->unkC;
    v3AnimationKeyframe* var_r31 = temp_r3;
    
    if (var_f29 < temp_f0) {
        var_f29 = temp_f0;
    }
    
loop_4:
    if ((var_f29 > var_r31->unkC) && ((var_r31->unk4 != -1.0f) || (var_r31->unk8 != -1.0f))) {
        var_r31 = var_r31->m_next;
        if (nlDLRingIsEnd<v3AnimationKeyframe>((v3AnimationKeyframe*)m_DLRingHead, var_r31) == 0) {
            goto loop_4;
        }
    }
    
    float temp_f2 = var_r31->unkC;
    float var_f31, var_f30, var_f3;
    
    if (var_f29 == temp_f2) {
        var_f31 = var_r31->unk0;
        var_f30 = var_r31->unk10;
        var_f3 = var_r31->unk20;
    } else if (!(var_f29 > temp_f2) || (var_r31->unk4 != -1.0f)) {
        v3AnimationKeyframe* temp_r29 = (v3AnimationKeyframe*)var_r31->m_prev;
        float temp_f0_2 = temp_r29->unkC;
        float temp_f29 = (var_f29 - temp_f0_2) / (temp_f2 - temp_f0_2);
        
        // X component bezier calculation
        float sp28, sp2C, sp30, sp34;
        sp28 = temp_r29->unk0;
        sp2C = temp_r29->unk4;
        sp30 = temp_r29->unk8;
        sp34 = var_r31->unk0;
        var_f31 = nlBezier(&sp28, 3, temp_f29);
        
        // Y component bezier calculation
        float sp18, sp1C, sp20, sp24;
        sp18 = temp_r29->unk10;
        sp1C = temp_r29->unk14;
        sp20 = temp_r29->unk18;
        sp24 = var_r31->unk10;
        var_f30 = nlBezier(&sp18, 3, temp_f29);
        
        // Z component bezier calculation
        float sp8, spC, sp10, sp14;
        sp8 = temp_r29->unk20;
        spC = temp_r29->unk24;
        sp10 = temp_r29->unk28;
        sp14 = var_r31->unk20;
        var_f3 = nlBezier(&sp8, 3, temp_f29);
    } else {
        var_f31 = var_r31->unk0;
        var_f30 = var_r31->unk10;
        var_f3 = var_r31->unk20;
    }
    
    s32 temp_r0 = unk14;
    switch (temp_r0) {
        case 1:
            m_instance->SetAssetPosition(var_f31, var_f30, var_f3);
            return;
        case 2:
            m_instance->SetAssetRotation(var_f31, var_f30, var_f3);
            return;
        case 3:
            m_instance->SetAssetScale(var_f31, var_f30, var_f3);
            return;
    }
}

// /**
//  * Offset/Address/Size: 0x0 | 0x8020E9B4 | size: 0x20
//  */
// void nlDLRingIsEnd<v3AnimationKeyframe>(v3AnimationKeyframe*, v3AnimationKeyframe*)
// {
// }

// /**
//  * Offset/Address/Size: 0x20 | 0x8020E9D4 | size: 0x20
//  */
// void nlDLRingIsEnd<fAnimationKeyframe>(fAnimationKeyframe*, v3AnimationKeyframe*)
// {
// }

// /**
//  * Offset/Address/Size: 0x40 | 0x8020E9F4 | size: 0x18
//  */
// void nlDLRingGetStart<v3AnimationKeyframe>(v3AnimationKeyframe*)
// {
// }
