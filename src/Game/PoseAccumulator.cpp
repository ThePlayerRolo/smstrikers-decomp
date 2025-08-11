#include "PoseAccumulator.h"

#include "math.h"

static const nlQuaternion qRotIdentity = { 0, 0, 0, 1 };
static const nlVector3 v3ScaleIdentity(1.0f, 1.0f, 1.0f);
static const nlVector3 v3TransIdentity(0.0f, 0.0f, 0.0f);

/**
 * Offset/Address/Size: 0xCD8 | 0x801EC278 | size: 0x1D74
 */
cPoseAccumulator::cPoseAccumulator(cSHierarchy*, bool)
{
}

/**
 * Offset/Address/Size: 0xB7C | 0x801EC11C | size: 0x15C
 */
void cPoseAccumulator::Pose(const cPoseNode&, const nlMatrix4&)
{
}

/**
 * Offset/Address/Size: 0xA38 | 0x801EBFD8 | size: 0x144
 */
void cPoseAccumulator::InitAccumulators()
{
}

/**
 * Offset/Address/Size: 0x644 | 0x801EBBE4 | size: 0x3F4
 */
void cPoseAccumulator::BuildNodeMatrices(const nlMatrix4&)
{
}

/**
 * Offset/Address/Size: 0x4FC | 0x801EBA9C | size: 0x148
 */
void cPoseAccumulator::BlendRot(int, const nlQuaternion*, float, bool)
{
}

/**
 * Offset/Address/Size: 0x468 | 0x801EBA08 | size: 0x94
 */
void cPoseAccumulator::BlendRotAroundZ(int idx, unsigned short angle, float w)
{
    if (fabsf(w) < 0.001f)
        return;

    RotAccum* e = &m_rot[idx];

    e->weightZ += w;
    float t = w / e->weightZ;

    short delta = (short)(angle - e->angleZ);
    delta = (short)(t * delta);

    e->angleZ = (unsigned short)(e->angleZ + delta);
    e->locked = false;
}

/**
 * Offset/Address/Size: 0x3DC | 0x801EB97C | size: 0x8C
 */
void cPoseAccumulator::BlendScale(int idx, const nlVector3* v, float w, bool /*unused*/)
{
    if (fabsf(w) < 0.001f)
        return;

    ScaleAccum* e = &m_scale[idx];

    e->weight += w;

    float t = w / e->weight;
    float inv = 1.0f - t;

    e->x = inv * e->x + t * v->f.x;
    e->y = inv * e->y + t * v->f.y;
    e->z = inv * e->z + t * v->f.z;

    e->locked = false;
}

/**
 * Offset/Address/Size: 0x2E4 | 0x801EB884 | size: 0xF8
 */
void cPoseAccumulator::BlendTrans(int idx, const nlVector3* v, float w, bool special)
{
    if (fabsf(w) < 0.001f)
        return;

    if (special)
    {
        cSHierarchy* h = m_hierarchy;

        nlVector3 vtemp;
        if (idx <= h->m_minNode || idx == h->m_maxNode)
        {
            // store: (x, -y, z)
            NL_VECTOR3_SET(vtemp, v->f.x, -v->f.y, v->f.z);
        }
        else
        {
            // store: (x, y, -z)
            NL_VECTOR3_SET(vtemp, v->f.x, v->f.y, -v->f.z);
        }

        v = &vtemp;
    }

    TransAccum* e = &m_trans[idx];
    e->weight += w;

    float t = w / e->weight;
    float inv = 1.0f - t;

    e->x = inv * e->x + t * v->f.x;
    e->y = inv * e->y + t * v->f.y;
    e->z = inv * e->z + t * v->f.z;

    e->locked = false;
}

/**
 * Offset/Address/Size: 0x258 | 0x801EB7F8 | size: 0x8C
 */
void cPoseAccumulator::BlendRotIdentity(int idx, float w)
{
    if (fabsf(w) < 0.001f)
        return;

    RotAccum* a = &m_rot[idx];
    a->weight += w;

    if (a->locked)
        return;

    const float t = w / a->weight;

    nlQuaternion tmp = a->q;
    nlQuatNLerp(a->q, tmp, qRotIdentity, t);
}

/**
 * Offset/Address/Size: 0x1CC | 0x801EB76C | size: 0x8C
 */
void cPoseAccumulator::BlendScaleIdentity(int idx, float w)
{
    if (fabsf(w) < 0.001f)
        return;

    ScaleAccum* a = &m_scale[idx];
    a->weight += w;

    if (a->locked)
        return;

    const float t = w / a->weight;
    const float inv = 1.0f - t;

    a->x = inv * a->x + t * v3ScaleIdentity.f.x;
    a->y = inv * a->y + t * v3ScaleIdentity.f.y;
    a->z = inv * a->z + t * v3ScaleIdentity.f.z;
}

/**
 * Offset/Address/Size: 0x140 | 0x801EB6E0 | size: 0x8C
 */
void cPoseAccumulator::BlendTransIdentity(int idx, float w)
{
    if (fabsf(w) < 0.001f)
        return;

    TransAccum* e = &m_trans[idx];
    e->weight += w;

    if (e->locked)
        return;

    const float f3 = w / e->weight;
    const float f2 = 1.0f - f3;

    e->x = f2 * e->x + f3 * v3TransIdentity.f.x;
    e->y = f2 * e->y + f3 * v3TransIdentity.f.y;
    e->z = f2 * e->z + f3 * v3TransIdentity.f.z;
}

/**
 * Offset/Address/Size: 0x130 | 0x801EB6D0 | size: 0x10
 */
nlMatrix4* cPoseAccumulator::GetNodeMatrix(int i) const
{
    return &m_matsA[i];
}

/**
 * Offset/Address/Size: 0xB0 | 0x801EB650 | size: 0x80
 */
nlMatrix4* cPoseAccumulator::GetNodeMatrixByHashID(unsigned int hash) const
{
    cSHierarchy* h = m_hierarchy;
    int i = 0;
    while (i < h->m_nodeCount)
    {
        if (h->GetNodeID(i) == hash)
        {
            return &m_matsA[i];
        }
        ++i;
    }
    return &m_matsA[i];
}

/**
 * Offset/Address/Size: 0xA4 | 0x801EB644 | size: 0xC
 */
s32 cPoseAccumulator::GetNumNodes() const
{
    return m_hierarchy->m_nodeCount;
}

/**
 * Offset/Address/Size: 0x28 | 0x801EB5C8 | size: 0x7C
 */
void cPoseAccumulator::MultNodeMatrices(const nlMatrix4* arg0)
{
    for (int i = 0; i < m_hierarchy->m_nodeCount; i++)
    {
        nlMatrix4* temp_r3 = m_matsA + i;
        nlMultMatrices(*temp_r3, *temp_r3, *arg0);
    }
}

/**
 * Offset/Address/Size: 0x0 | 0x801EB5A0 | size: 0x28
 */
void cPoseAccumulator::SetBuildNodeMatrixCallback(int idx, BuildNodeMatrixFn fn, unsigned int a, unsigned int b)
{
    BuildNodeCB* cb = m_cb + idx;
    cb->fn = fn;
    cb->a = a;
    cb->b = b;
}
