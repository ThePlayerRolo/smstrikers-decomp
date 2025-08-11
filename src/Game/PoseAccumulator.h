#ifndef _POSEACCUMULATOR_H_
#define _POSEACCUMULATOR_H_

#include "NL/nlMath.h"

#include "SHierarchy.h"
#include "PoseNode.h"

class cPoseAccumulator;

typedef void (*BuildNodeMatrixFn)(unsigned int, unsigned int, cPoseAccumulator*, unsigned int, int);

struct BuildNodeCB
{
    BuildNodeMatrixFn fn; // +0x00
    unsigned int a;       // +0x04
    unsigned int b;       // +0x08
};

struct VecAccum
{
    nlVector3 v;         // +0x00
    float w;             // +0x0C  (accumulated weight)
    unsigned char dirty; // +0x10 (cleared to 0 when blended, else kept nonzero)
    unsigned char _pad[3];
};

struct RotAccum
{
    nlQuaternion q;        // +0x00
    float w;               // +0x10 (accumulated weight for quaternion nlerp)
    unsigned short angleZ; // +0x14 (used by BlendRotAroundZ)
    unsigned short _pad0;  // padding from lhz/sth pattern
    float wZ;              // +0x18 (accumulated weight for Z-angle blend)
    unsigned char dirty;   // +0x1C (cleared to 0 when blended)
    unsigned char _pad[3];
};

class cPoseAccumulator
{
public:
    cPoseAccumulator(cSHierarchy*, bool);
    void Pose(const cPoseNode&, const nlMatrix4&);
    void InitAccumulators();
    void BuildNodeMatrices(const nlMatrix4&);
    void BlendRot(int, const nlQuaternion*, float, bool);
    void BlendRotAroundZ(int, unsigned short, float);
    void BlendScale(int, const nlVector3*, float, bool);
    void BlendTrans(int, const nlVector3*, float, bool);
    void BlendRotIdentity(int, float);
    void BlendScaleIdentity(int, float);
    void BlendTransIdentity(int, float);
    nlMatrix4* GetNodeMatrix(int) const;
    void GetNodeMatrixByHashID(unsigned int) const;
    s32 GetNumNodes() const;
    void MultNodeMatrices(const nlMatrix4*);
    void SetBuildNodeMatrixCallback(int, BuildNodeMatrixFn, unsigned int, unsigned int);

    /* 0x00 */ cSHierarchy* m_hier;
    /* 0x04 */ nlMatrix4* m_matsA;
    /* 0x08 */ int m_countA;
    /* 0x0C */ int m_countB;
    /* 0x10 */ nlMatrix4* m_matsB;
    /* 0x14 */ int m_swapGuard;
    /* 0x1C */ RotAccum* m_rot;
    /* 0x28 */ VecAccum* m_scale;
    /* 0x34 */ VecAccum* m_trans;
    /* 0x40 */ BuildNodeCB* m_cb;
};

#endif // _POSEACCUMULATOR_H_
