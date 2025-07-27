#ifndef _POSEACCUMULATOR_H_
#define _POSEACCUMULATOR_H_

#include "NL/nlMath.h"
#include "PoseNode.h"
class cSHierarchy;

class cPoseAccumulator
{
public:
    void SetBuildNodeMatrixCallback(int, void (*)(unsigned int, unsigned int, cPoseAccumulator*, unsigned int, int), unsigned int, unsigned int);
    void MultNodeMatrices(const nlMatrix4*);
    void GetNumNodes() const;
    void GetNodeMatrixByHashID(unsigned int) const;
    void GetNodeMatrix(int) const;
    void BlendTransIdentity(int, float);
    void BlendScaleIdentity(int, float);
    void BlendRotIdentity(int, float);
    void BlendTrans(int, const nlVector3*, float, bool);
    void BlendScale(int, const nlVector3*, float, bool);
    void BlendRotAroundZ(int, unsigned short, float);
    void BlendRot(int, const nlQuaternion*, float, bool);
    void BuildNodeMatrices(const nlMatrix4&);
    void InitAccumulators();
    void Pose(const cPoseNode&, const nlMatrix4&);
    cPoseAccumulator(cSHierarchy*, bool);
};

#endif // _POSEACCUMULATOR_H_
