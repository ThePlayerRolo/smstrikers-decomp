#include "SAnim.h"

#include "NL/nlMemory.h"
#include "NL/nlList.h"

/**
 * Offset/Address/Size: 0xD40 | 0x801E9F54 | size: 0x68C
 */
cSAnim* cSAnim::Initialize(nlChunk*)
{
    return NULL;
}

/**
 * Offset/Address/Size: 0x91C | 0x801E9B30 | size: 0x424
 */
void cSAnim::BlendRot(int, int, float, float, cPoseAccumulator*, bool) const
{
}

/**
 * Offset/Address/Size: 0x608 | 0x801E981C | size: 0x314
 */
void cSAnim::BlendScale(int, int, float, float, cPoseAccumulator*, bool) const
{
}

/**
 * Offset/Address/Size: 0x404 | 0x801E9618 | size: 0x204
 */
void cSAnim::BlendTrans(int, int, float, float, cPoseAccumulator*, bool) const
{
}

/**
 * Offset/Address/Size: 0x3CC | 0x801E95E0 | size: 0x38
 */
void cSAnim::Destroy()
{
    nlDeleteList<cSAnimCallback>(&m_unk_0x3C);
    m_unk_0x3C = NULL;
}

/**
 * Offset/Address/Size: 0x2EC | 0x801E9500 | size: 0xE0
 */
void cSAnim::GetRootRot(float, unsigned short*) const
{
}

/**
 * Offset/Address/Size: 0x1E0 | 0x801E93F4 | size: 0x10C
 */
void cSAnim::GetRootTrans(float, nlVector3*) const
{
}

/**
 * Offset/Address/Size: 0x160 | 0x801E9374 | size: 0x80
 */
void cSAnim::CreateCallback(float arg0, unsigned int arg1, void (*arg2)(unsigned int))
{
    cSAnimCallback* temp_r3;
    temp_r3 = (cSAnimCallback*)nlMalloc(0x10, 8, 0);

    if (temp_r3 != NULL)
    {
        temp_r3->unk0 = arg0;
        temp_r3->unk4 = arg1;
        temp_r3->unk8 = arg2;
    }

    nlListAddStart<cSAnimCallback>(&m_unk_0x3C, temp_r3, NULL);
}

/**
 * Offset/Address/Size: 0x0 | 0x801E9214 | size: 0x160
 */
void cSAnim::GetMorphWeight(int, float) const
{
}
