#include "NL/gl/glView.h"
#include "NL/gl/glPlat.h"
#include "NL/gl/glStruct.h"
#include "NL/gl/glMatrix.h"
#include "NL/gl/glRenderList.h"
#include "NL/nlMemory.h"
#include <string.h>

bool gl_ViewEnable[34] = { true,  false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
                           false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false };
glView* views[34];

/**
 * Offset/Address/Size: 0x0 | 0x801DE4A4 | size: 0x18
 */
bool glViewSetEnable(eGLView view, bool enable)
{
    bool uVar1 = gl_ViewEnable[view];
    gl_ViewEnable[view] = enable;
    return uVar1;
}

/**
 * Offset/Address/Size: 0x18 | 0x801DE4BC | size: 0x10
 */
bool glViewGetEnable(eGLView view)
{
    return gl_ViewEnable[view];
}

/**
 * Offset/Address/Size: 0x28 | 0x801DE4CC | size: 0x1C
 */
eGLTarget glViewSetFilterSource(eGLView view, eGLTarget target)
{
    eGLTarget temp_r3;
    glView* temp_r5;

    temp_r5 = views[view];
    temp_r3 = temp_r5->m_filterSource;
    temp_r5->m_filterSource = target;
    return temp_r3;
}

/**
 * Offset/Address/Size: 0x44 | 0x801DE4E8 | size: 0x18
 */
eGLFilter glViewGetFilter(eGLView view)
{
    return views[view]->m_filter;
}

/**
 * Offset/Address/Size: 0x5C | 0x801DE500 | size: 0x1C
 */
eGLFilter glViewSetFilter(eGLView view, eGLFilter filter)
{
    eGLFilter temp_r3 = views[view]->m_filter;
    views[view]->m_filter = filter;
    return temp_r3;
}

/**
 * Offset/Address/Size: 0x78 | 0x801DE51C | size: 0x1C
 */
eGLTarget glViewSetTarget(eGLView view, eGLTarget target)
{
    eGLTarget temp_r3 = views[view]->m_target;
    views[view]->m_target = target;
    return temp_r3;
}

/**
 * Offset/Address/Size: 0x94 | 0x801DE538 | size: 0x20
 */
void glViewProjectPoint(eGLView view, const nlVector3& point, nlVector3& result)
{
    glplatViewProjectPoint(view, point, result);
}

/**
 * Offset/Address/Size: 0xB4 | 0x801DE558 | size: 0x94
 */
void glViewGetProjectionMatrix(eGLView view, nlMatrix4& result)
{
    u32 v1, v2;
    u32* dst = (u32*)&result.m;
    u32* src = (u32*)&views[view]->m_projectionMatrix;

    v1 = src[0];
    v2 = src[1];
    dst[0] = v1;
    dst[1] = v2;
    v2 = src[2];
    v1 = src[3];
    dst[2] = v2;
    dst[3] = v1;
    v2 = src[4];
    v1 = src[5];
    dst[4] = v2;
    dst[5] = v1;
    v2 = src[6];
    v1 = src[7];
    dst[6] = v2;
    dst[7] = v1;
    v2 = src[8];
    v1 = src[9];
    dst[8] = v2;
    dst[9] = v1;
    v2 = src[10];
    v1 = src[11];
    dst[10] = v2;
    dst[11] = v1;
    v1 = src[12];
    v2 = src[13];
    dst[12] = v1;
    dst[13] = v2;
    v2 = src[15];
    v1 = src[14];
    dst[14] = v2;
    dst[15] = v1;
}

/**
 * Offset/Address/Size: 0x148 | 0x801DE5EC | size: 0x94
 */
void glViewGetViewMatrix(eGLView view, nlMatrix4& result)
{
    u32 v1, v2;
    glView* view_ptr = views[view];
    u32* dst = (u32*)&result.m;
    u32* src = (u32*)&(view_ptr->m_viewMatrix);
    // u32 *src = (u32*)((u8*)&views[view] + 0x20);

    v1 = src[0];
    v2 = src[1];
    dst[0] = v1;
    dst[1] = v2;
    v2 = src[2];
    v1 = src[3];
    dst[2] = v2;
    dst[3] = v1;
    v2 = src[4];
    v1 = src[5];
    dst[4] = v2;
    dst[5] = v1;
    v2 = src[6];
    v1 = src[7];
    dst[6] = v2;
    dst[7] = v1;
    v2 = src[8];
    v1 = src[9];
    dst[8] = v2;
    dst[9] = v1;
    v2 = src[10];
    v1 = src[11];
    dst[10] = v2;
    dst[11] = v1;
    v1 = src[12];
    v2 = src[13];
    dst[12] = v1;
    dst[13] = v2;
    v2 = src[15];
    v1 = src[14];
    dst[14] = v2;
    dst[15] = v1;
}

/**
 * Offset/Address/Size: 0x1DC | 0x801DE680 | size: 0x54
 */
nlMatrix4* glViewSetProjectionMatrix(eGLView view, unsigned long value)
{
    glView* view_ptr = views[view];
    nlMatrix4* temp_r31 = view_ptr->m_unk_0x18;
    view_ptr->m_unk_0x18 = (nlMatrix4*)value;
    view_ptr->m_unk_0xE0 = 1;

    glGetMatrix(value, view_ptr->m_projectionMatrix);

    return temp_r31;
}

/**
 * Offset/Address/Size: 0x230 | 0x801DE6D4 | size: 0x18
 */
nlMatrix4* glViewGetProjectionMatrix(eGLView view)
{
    glView* view_ptr = views[view];
    return view_ptr->m_unk_0x18;
}

/**
 * Offset/Address/Size: 0x248 | 0x801DE6EC | size: 0x54
 */
nlMatrix4* glViewSetViewMatrix(eGLView view, unsigned long value)
{
    glView* view_ptr = views[view];
    nlMatrix4* temp_r31 = view_ptr->m_unk_0x14;
    view_ptr->m_unk_0x14 = (nlMatrix4*)value;
    view_ptr->m_unk_0xE0 = 1;

    glGetMatrix(value, view_ptr->m_viewMatrix);

    return temp_r31;
}

/**
 * Offset/Address/Size: 0x29C | 0x801DE740 | size: 0x18
 */
nlMatrix4* glViewGetViewMatrix(eGLView view)
{
    glView* view_ptr = views[view];
    return view_ptr->m_unk_0x14;
}

/**
 * Offset/Address/Size: 0x2B4 | 0x801DE758 | size: 0x24
 */
eGLViewSort glViewSetSortMode(eGLView view, eGLViewSort value)
{
    glView* view_ptr = views[view];
    eGLViewSort temp_r3 = (eGLViewSort)view_ptr->m_unk_0x00;
    view_ptr->m_unk_0x00 = value;
    view_ptr->renderList->m_unk_0x04 = value;
    return temp_r3;
}

/**
 * Offset/Address/Size: 0x2D8 | 0x801DE77C | size: 0x1C
 */
bool glViewSetDepthClear(eGLView view, bool value)
{
    glView* view_ptr = views[view];
    bool temp_r3 = view_ptr->m_depthClear;
    view_ptr->m_depthClear = value;
    return temp_r3;
}

/**
 * Offset/Address/Size: 0x2F4 | 0x801DE798 | size: 0x18
 */
bool glViewGetDepthClear(eGLView view)
{
    // return (*(&views + (arg0 * 4)))->unkED;
    glView* view_ptr = views[view];
    return view_ptr->m_depthClear;
}

/**
 * Offset/Address/Size: 0x30C | 0x801DE7B0 | size: 0x164
 */
void gl_ViewStartup()
{
    int* piVar1;
    u32 uVar2;
    u32 uVar3;
    nlMatrix4* uVar4;
    glView* iVar5;
    GLRenderList* renderList;
    glView* puVar6;
    int iVar7;
    int iVar8;
    bool* puVar9;
    glView** piVar10;

    uVar2 = glGetScreenWidth();
    uVar3 = glGetScreenHeight();
    uVar4 = (nlMatrix4*)glGetIdentityMatrix();
    piVar10 = &views[0];
    iVar8 = 0;
    puVar9 = &gl_ViewEnable[0];
    iVar7 = 0;
    do
    {
        *puVar9 = 1;

        iVar5 = (glView*)nlMalloc(0xFC, 8, FALSE);
        if (iVar5 != NULL)
        {
            renderList = (GLRenderList*)nlMalloc(0x30, 8, FALSE);
            if (renderList != NULL)
            {
                renderList = new (renderList) GLRenderList();
            }

            iVar5->renderList = renderList;
            iVar5->m_preIterateCallback = NULL;
            iVar5->m_postIterateCallback = NULL;
            iVar5->m_unk_0xEC = false;
            iVar5->m_depthClear = false;
        }

        *piVar10 = iVar5;

        puVar6 = views[iVar7];
        puVar6->m_unk_0x00 = 0;
        puVar6->renderList->m_unk_0x04 = eGLViewSort_0;

        puVar6->m_unk_0x14 = uVar4;
        puVar6->m_unk_0xE0 = 1;

        glGetMatrix(*(u32*)uVar4, puVar6->m_viewMatrix);

        puVar6->m_unk_0x18 = uVar4;
        puVar6->m_unk_0xE0 = 1;

        glGetMatrix(*(u32*)uVar4, puVar6->m_projectionMatrix);

        puVar9++;

        puVar6->m_target = eGLTarget_0;

        puVar6->m_unk_0x04 = 0;
        puVar6->m_unk_0x08 = 0;
        puVar6->m_screenWidth = uVar2;
        puVar6->m_screenHeight = uVar3;

        // puVar6->m_filterSource = eGLTarget_0;

        //   puVar6 = *(undefined4 **)((int)&views + iVar7);
        //   *puVar6 = 0;
        //   *(undefined4 *)(puVar6[0x3c] + 4) = 0;
        //   iVar5 = *(int *)((int)&views + iVar7);
        //   *(undefined4 *)(iVar5 + 0x14) = uVar4;
        //   *(undefined1 *)(iVar5 + 0xe0) = 1;
        //   glMatrix::glGetMatrix(uVar4,iVar5 + 0x20);
        //   iVar5 = *(int *)((int)&views + iVar7);
        //   *(undefined4 *)(iVar5 + 0x18) = uVar4;
        //   *(undefined1 *)(iVar5 + 0xe0) = 1;
        //   glMatrix::glGetMatrix(uVar4,iVar5 + 0x60);
        //   puVar9 = puVar9 + 1;
        //   *(undefined4 *)(*(int *)((int)&views + iVar7) + 0x1c) = 0;
        //   iVar5 = *(int *)((int)&views + iVar7);
        //   *(undefined4 *)(iVar5 + 4) = 0;
        //   *(undefined4 *)(iVar5 + 8) = 0;
        //   *(undefined4 *)(iVar5 + 0xc) = uVar2;
        //   *(undefined4 *)(iVar5 + 0x10) = uVar3;

        puVar6->m_filter = eGLFilter_0;
        puVar6->m_filterSource = eGLTarget_0;
        puVar6->m_unk_0xEC = false;
        puVar6->m_depthClear = false;

        //   *(undefined4 *)(*(int *)((int)&views + iVar7) + 0xe4) = 0;
        //   *(undefined4 *)(*(int *)((int)&views + iVar7) + 0xe8) = 0;
        //   *(undefined1 *)(*(int *)((int)&views + iVar7) + 0xec) = 0;
        //   piVar1 = (int *)((int)&views + iVar7);
        //   iVar7 = iVar7 + 4;
        //   *(undefined1 *)(*piVar1 + 0xed) = 0;
        //   iVar5 = *piVar10;
        //   piVar10 = piVar10 + 1;
        //   **(int **)(iVar5 + 0xf0) = iVar8;
        puVar6->renderList->m_unk_0x00 = iVar8;

        piVar10++;
        iVar8++;
    } while (iVar8 < 0x22);
}

/**
 * Offset/Address/Size: 0x470 | 0x801DE914 | size: 0xA8
 */
void gl_ViewIterate(eGLView view, glViewPacketCallback callback)
{
    glView* view_ptr = views[view];
    if (view_ptr->m_preIterateCallback != NULL)
    {
        view_ptr->m_preIterateCallback(view, 1);
    }

    view_ptr->renderList->Iterate(view, callback);

    if (view_ptr->m_postIterateCallback != NULL)
    {
        view_ptr->m_postIterateCallback(view, 0);
    }
}

/**
 * Offset/Address/Size: 0x518 | 0x801DE9BC | size: 0x54
 */
void glViewCompact()
{
    for (int i = 0; i < 34; i++)
    {
        views[i]->renderList->Compact();
    }
}

/**
 * Offset/Address/Size: 0x56C | 0x801DEA10 | size: 0x68
 */
void gl_ViewReset()
{
    for (int i = 0; i < 0x22; i++)
    {
        views[i]->renderList->Clear();
        views[i]->m_unk_0xE0 = 1;
    }
}

/**
 * Offset/Address/Size: 0x5D4 | 0x801DEA78 | size: 0x70
 */
void glViewAttachPacket(eGLView view, const glModelPacket* packet)
{
    glModel model;
    memset(&model, 0, 0x10);
    model.m_count = 1;
    model.m_packets = (glModelPacket*)packet;

    glView* view_ptr = views[view];
    view_ptr->renderList->AttachModel(&model, 0);
}

/**
 * Offset/Address/Size: 0x644 | 0x801DEAE8 | size: 0x38
 */
void glViewAttachModel(eGLView view, const glModel* model)
{
    glView* view_ptr = views[view];
    view_ptr->renderList->AttachModel(model, 0);
}

/**
 * Offset/Address/Size: 0x67C | 0x801DEB20 | size: 0x40
 */
void glViewAttachModel(eGLView view, unsigned long arg, const glModel* model)
{
    glView* view_ptr = views[view];
    view_ptr->renderList->AttachModel(model, arg);
}

/**
 * Offset/Address/Size: 0x6BC | 0x801DEB60 | size: 0x18
 */
GLRenderList* gl_ViewGetRenderList(eGLView view)
{
    return views[view]->renderList;
}
