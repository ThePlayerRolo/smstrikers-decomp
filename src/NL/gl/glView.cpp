#include "NL/gl/glView.h"
#include "NL/gl/glPlat.h"

struct glView
{
    /* 0x0 */ u8 m_padding_0x00[0x1C];
    /* 0x1C */ eGLTarget m_target;
    /* 0x20 */ u8 m_padding_0x20[0xC4];
    /* 0xE4 */ eGLFilter m_filter;
    /* 0xE8 */ eGLTarget m_filterSource;
    /* 0xEC */ u8 m_padding_0xEC[0x04];
    /* 0xF0 */ u32 renderList;
};

bool gl_ViewEnable[34] = {true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
glView *views[34];

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
    glView *temp_r5;

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
void glViewGetProjectionMatrix(eGLView, nlMatrix4&)
{
}

/**
 * Offset/Address/Size: 0x148 | 0x801DE5EC | size: 0x94
 */
void glViewGetViewMatrix(eGLView, nlMatrix4&)
{
}

/**
 * Offset/Address/Size: 0x1DC | 0x801DE680 | size: 0x54
 */
void glViewSetProjectionMatrix(eGLView, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x230 | 0x801DE6D4 | size: 0x18
 */
void glViewGetProjectionMatrix(eGLView)
{
}

/**
 * Offset/Address/Size: 0x248 | 0x801DE6EC | size: 0x54
 */
void glViewSetViewMatrix(eGLView, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x29C | 0x801DE740 | size: 0x18
 */
void glViewGetViewMatrix(eGLView)
{
}

/**
 * Offset/Address/Size: 0x2B4 | 0x801DE758 | size: 0x24
 */
void glViewSetSortMode(eGLView, eGLViewSort)
{
}

/**
 * Offset/Address/Size: 0x2D8 | 0x801DE77C | size: 0x1C
 */
void glViewSetDepthClear(eGLView, bool)
{
}

/**
 * Offset/Address/Size: 0x2F4 | 0x801DE798 | size: 0x18
 */
void glViewGetDepthClear(eGLView)
{
}

/**
 * Offset/Address/Size: 0x30C | 0x801DE7B0 | size: 0x164
 */
void gl_ViewStartup()
{
}

/**
 * Offset/Address/Size: 0x470 | 0x801DE914 | size: 0xA8
 */
void gl_ViewIterate(eGLView, void (*)(eGLView, unsigned long, const glModelPacket*))
{
}

/**
 * Offset/Address/Size: 0x518 | 0x801DE9BC | size: 0x54
 */
void glViewCompact()
{
}

/**
 * Offset/Address/Size: 0x56C | 0x801DEA10 | size: 0x68
 */
void gl_ViewReset()
{
}

/**
 * Offset/Address/Size: 0x5D4 | 0x801DEA78 | size: 0x70
 */
void glViewAttachPacket(eGLView, const glModelPacket*)
{
}

/**
 * Offset/Address/Size: 0x644 | 0x801DEAE8 | size: 0x38
 */
void glViewAttachModel(eGLView, const glModel*)
{
}

/**
 * Offset/Address/Size: 0x67C | 0x801DEB20 | size: 0x40
 */
void glViewAttachModel(eGLView, unsigned long, const glModel*)
{
}

/**
 * Offset/Address/Size: 0x6BC | 0x801DEB60 | size: 0x18
 */
u32 gl_ViewGetRenderList(eGLView view)
{
    return views[view]->renderList;
}
