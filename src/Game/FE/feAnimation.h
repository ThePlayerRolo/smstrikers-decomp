#ifndef _FEANIMATION_H_
#define _FEANIMATION_H_

// void nlDLRingIsEnd<v3AnimationKeyframe>(v3AnimationKeyframe*, v3AnimationKeyframe*);
// void nlDLRingIsEnd<fAnimationKeyframe>(fAnimationKeyframe*, fAnimationKeyframe*);
// void nlDLRingGetStart<v3AnimationKeyframe>(v3AnimationKeyframe*);

class FEAnimation
{
public:
    void Update(float);
    void AnimateTargetAtTimeWithVector3(float);
};

#endif // _FEANIMATION_H_
