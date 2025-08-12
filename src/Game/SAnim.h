#ifndef _SANIM_H_
#define _SANIM_H_

#include "types.h"

#include "NL/nlMath.h"

#include "PoseAccumulator.h"

struct nlChunk
{
};

class cSAnim
{
public:
    void GetMorphWeight(int, float) const;
    void CreateCallback(float, unsigned int, void (*)(unsigned int));
    void GetRootTrans(float, nlVector3*) const;
    void GetRootRot(float, unsigned short*) const;
    void Destroy();
    void BlendTrans(int, int, float, float, cPoseAccumulator*, bool) const;
    void BlendScale(int, int, float, float, cPoseAccumulator*, bool) const;
    void BlendRot(int, int, float, float, cPoseAccumulator*, bool) const;

    static cSAnim* Initialize(nlChunk*);
};

#endif // _SANIM_H_
