#include "glView.h"

/**
 * Offset/Address/Size: 0x0 | 0x801DE4A4 | size: 0x18
 */
void glViewSetEnable(eGLView, bool)
{
}

/**
 * Offset/Address/Size: 0x18 | 0x801DE4BC | size: 0x10
 */
void glViewGetEnable(eGLView)
{
}

/**
 * Offset/Address/Size: 0x28 | 0x801DE4CC | size: 0x1C
 */
void glViewSetFilterSource(eGLView, eGLTarget)
{
}

/**
 * Offset/Address/Size: 0x44 | 0x801DE4E8 | size: 0x18
 */
void glViewGetFilter(eGLView)
{
}

/**
 * Offset/Address/Size: 0x5C | 0x801DE500 | size: 0x1C
 */
void glViewSetFilter(eGLView, eGLFilter)
{
}

/**
 * Offset/Address/Size: 0x78 | 0x801DE51C | size: 0x1C
 */
void glViewSetTarget(eGLView, eGLTarget)
{
}

/**
 * Offset/Address/Size: 0x94 | 0x801DE538 | size: 0x20
 */
void glViewProjectPoint(eGLView, const nlVector3&, nlVector3&)
{
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
void gl_ViewGetRenderList(eGLView)
{
}
