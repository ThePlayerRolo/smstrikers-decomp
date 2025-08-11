#ifndef _POSEACCUMULATOR_H_
#define _POSEACCUMULATOR_H_

#include "NL/nlMath.h"

#include "SHierarchy.h"
#include "PoseNode.h"

class cPoseAccumulator;

typedef void (*BuildNodeMatrixFn)(unsigned int, unsigned int, cPoseAccumulator*, unsigned int, int);

struct BuildNodeCB
{
    /* 0x00 */ BuildNodeMatrixFn fn;
    /* 0x04 */ unsigned int a;
    /* 0x08 */ unsigned int b;
}; // size: 0x0C

struct RotAccum
{
    /* 0x00 */ nlQuaternion q;
    /* 0x10 */ float weight;
    /* 0x14 */ u32 angleZ;
    /* 0x18 */ float weightZ;
    /* 0x1C */ bool locked;
    /* 0x1D */ u8 _pad[3];
}; // size: 0x20

struct ScaleAccum
{
    /* 0x00 */ float x;
    /* 0x04 */ float y;
    /* 0x08 */ float z;
    /* 0x0C */ float weight;
    /* 0x10 */ bool locked;
    /* 0x11 */ u8 _pad[3];
}; // size: 0x14

struct TransAccum
{
    /* 0x00 */ float x;
    /* 0x04 */ float y;
    /* 0x08 */ float z;
    /* 0x0C */ float weight;
    /* 0x10 */ bool locked;
    /* 0x11 */ u8 _pad[3];
}; // size: 0x14

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
    nlMatrix4* GetNodeMatrixByHashID(unsigned int) const;
    s32 GetNumNodes() const;
    void MultNodeMatrices(const nlMatrix4*);
    void SetBuildNodeMatrixCallback(int, BuildNodeMatrixFn, unsigned int, unsigned int);

    /* 0x00 */ cSHierarchy* m_hierarchy;
    /* 0x04 */ nlMatrix4* m_matsA;
    /* 0x08 */ s32 m_unk_0x08;
    /* 0x0C */ s32 m_unk_0x0C;
    /* 0x10 */ nlMatrix4* m_matsB;
    /* 0x14 */ s32 m_unk_0x14;
    /* 0x18 */ s32 m_unk_0x18;
    /* 0x1C */ RotAccum* m_rot;
    /* 0x20 */ s32 m_unk_0x20;
    /* 0x24 */ s32 m_unk_0x24;
    /* 0x28 */ ScaleAccum* m_scale;
    /* 0x2C */ s32 _unk_0x2C;
    /* 0x30 */ s32 _unk_0x30;
    /* 0x34 */ TransAccum* m_trans;
    /* 0x38 */ s32 _unk_0x38;
    /* 0x3C */ s32 _unk_0x3C;
    /* 0x40 */ BuildNodeCB m_cb[2];
    // /* 0x44 */ s32 unk44;
    // /* 0x48 */ s32 unk48;
    // /* 0x4C */ void* unk4C;
    // /* 0x50 */ s32 unk50;
    // /* 0x54 */ s32 unk54;
};

#endif // _POSEACCUMULATOR_H_
