#include "NL/gl/glDraw3.h"

#include "NL/gl/gl.h"
#include "NL/gl/glState.h"
#include "NL/gl/glView.h"
#include "NL/gl/glStruct.h"
#include "NL/gl/glMatrix.h"

#include "NL/gl/glModel.h"
#include "NL/gl/glUserData.h"

#include "Game/GL/GLMeshWriter.h"

static unsigned long _defaultProgram = glGetProgram("3d unlit");

/**
 * Offset/Address/Size: 0x0 | 0x801D7E4C | size: 0x44
 */
void glQuad3::SetColour(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    unsigned char* dst = (unsigned char*)(&m_colour[0]);
    dst[0x0] = r;
    dst[0x1] = g;
    dst[0x2] = b;
    dst[0x3] = a;
    dst[0x4] = r;
    dst[0x5] = g;
    dst[0x6] = b;
    dst[0x7] = a;
    dst[0x8] = r;
    dst[0x9] = g;
    dst[0xA] = b;
    dst[0xB] = a;
    dst[0xC] = r;
    dst[0xD] = g;
    dst[0xE] = b;
    dst[0xF] = a;
}

/**
 * Offset/Address/Size: 0x44 | 0x801D7E90 | size: 0x18
 */
void glQuad3::SetColour(const nlColour& c)
{
    const unsigned long packed = *(const unsigned long*)(&c);
    *(unsigned long*)(&m_colour[0]) = packed;
    *(unsigned long*)(&m_colour[1]) = packed;
    *(unsigned long*)(&m_colour[2]) = packed;
    *(unsigned long*)(&m_colour[3]) = packed;
}

/**
 * Offset/Address/Size: 0x5C | 0x801D7EA8 | size: 0x24C
 */
void glQuad3::SetupRotatedRectangle(float, float, const nlMatrix4&, bool, bool)
{
}

/**
 * Offset/Address/Size: 0x2A8 | 0x801D80F4 | size: 0x50
 */
bool glQuad3::Attach(eGLView view, int stream, bool useDefaultProgram)
{
    const glModel* model = GetModel(useDefaultProgram);
    glViewAttachModel(view, (unsigned long)stream, model);
    return true;
}

/**
 * Offset/Address/Size: 0x2F8 | 0x801D8144 | size: 0x1BC
 */
const glModel* glQuad3::GetModel(bool) const
{
    return nullptr;
}

/**
 * Offset/Address/Size: 0x4B4 | 0x801D8300 | size: 0x6C
 */
bool glAttachQuad3(eGLView, unsigned long, glQuad3*, bool)
{
    return false;
}
