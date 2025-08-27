#include "NL/gl/glDraw3.h"

#include "NL/gl/gl.h"
#include "NL/gl/glState.h"
#include "NL/gl/glView.h"
#include "NL/gl/glStruct.h"
#include "NL/gl/glMatrix.h"

#include "NL/gl/glModel.h"
#include "NL/gl/glUserData.h"

// #include "Game/GL/GLMeshWriter.h"
#include "Game/GL/gluMeshWriter.h"

static unsigned long _defaultProgram = glGetProgram("3d unlit");

/**
 * Offset/Address/Size: 0x4B4 | 0x801D8300 | size: 0x6C
 */
bool glAttachQuad3(eGLView view, unsigned long count, glQuad3* quads, bool useDefaultProgram)
{
    int i = 0;
    glQuad3* quad = quads;
    for (; i < count; i++, quad++)
    {
        glViewAttachModel(view, 0, quad->GetModel(useDefaultProgram));
    }
    return true;
}

/**
 * Offset/Address/Size: 0x2F8 | 0x801D8144 | size: 0x1BC
 */
const glModel* glQuad3::GetModel(bool useDefaultProgram) const
{
    unsigned long prevProgram = 0;
    eGLStream sStreams[3] = { (eGLStream)0, (eGLStream)2, (eGLStream)3 };
    static const unsigned int stripmap[4] = { 3, 0, 2, 1 };

    GLMeshWriter writer;
    gl_GetCurrentStateBundle();

    if (useDefaultProgram)
        prevProgram = glSetCurrentProgram(_defaultProgram);

    const glModel* outModel = 0;

    if (glHasQuads())
    {
        if (writer.Begin(4, (eGLPrimitive)3, 3, sStreams, false))
        {
            for (int i = 0; i < 4; ++i)
            {
                writer.Colour(m_colour[i]);
                writer.Texcoord(m_uv[i]);
                writer.Vertex(m_pos[i]);
            }
        }
    }
    else
    {
        // static const unsigned int stripmap[4] = { 3, 0, 2, 1 };

        if (writer.Begin(4, (eGLPrimitive)1, 3, sStreams, false))
        {
            for (int i = 0; i < 4; ++i)
            {
                const unsigned int idx = stripmap[i];
                writer.Colour(m_colour[idx]);
                writer.Texcoord(m_uv[idx]);
                writer.Vertex(m_pos[idx]);
            }
        }
    }

    if (writer.End())
        outModel = writer.GetModel();

    if (useDefaultProgram)
        glSetCurrentProgram(prevProgram);

    return outModel;
}

/**
 * Offset/Address/Size: 0x2A8 | 0x801D80F4 | size: 0x50
 */
bool glQuad3::Attach(eGLView view, int stream, bool useDefaultProgram)
{
    glViewAttachModel(view, (unsigned long)stream, GetModel(useDefaultProgram));
    return true;
}

/**
 * Offset/Address/Size: 0x5C | 0x801D7EA8 | size: 0x24C
 */
void glQuad3::SetupRotatedRectangle(float w, float h, const nlMatrix4& mtx, bool flipU, bool flipV)
{
    // f32 sp10;
    // f32 spC;
    // f32 sp8;
    // nlVector3 sp8;
    nlVector3 sp8;

    // f32 v3[3];

    f32 temp_f29;
    f32 temp_f30;
    f32 temp_f31;
    f32 temp_f31_2;

    temp_f29 = -w * 0.5f;
    temp_f31 = -h * 0.5f;

    sp8.f.x = temp_f29;
    sp8.f.y = temp_f31;
    sp8.f.z = 0.0f;
    nlMultPosVectorMatrix(sp8, sp8, mtx);
    m_pos[0] = sp8;

    temp_f30 = w * 0.5f;

    sp8.f.x = temp_f30;
    sp8.f.y = temp_f31;
    sp8.f.z = 0.0f;
    nlMultPosVectorMatrix(sp8, sp8, mtx);
    m_pos[1] = sp8;

    temp_f31_2 = h * 0.5f;

    sp8.f.x = temp_f30;
    sp8.f.y = temp_f31_2;
    sp8.f.z = 0.0f;
    nlMultPosVectorMatrix(sp8, sp8, mtx);
    m_pos[2] = sp8;

    sp8.f.x = temp_f29;
    sp8.f.y = temp_f31_2;
    sp8.f.z = 0.0f;
    nlMultPosVectorMatrix(sp8, sp8, mtx);
    m_pos[3] = sp8;

    f32 var_f0;
    f32 var_f1;
    f32 var_f2;
    f32 var_f3;

    if (flipU != 0)
    {
        var_f0 = 1.0f;
    }
    else
    {
        var_f0 = 0.0f;
    }

    if (flipU != 0)
    {
        var_f1 = 0.0f;
    }
    else
    {
        var_f1 = 1.0f;
    }

    if (flipV != 0)
    {
        var_f2 = 1.0f;
    }
    else
    {
        var_f2 = 0.0f;
    }

    if (flipV != 0)
    {
        var_f3 = 0.0f;
    }
    else
    {
        var_f3 = 1.0f;
    }

    m_uv[0].x = var_f0;
    m_uv[0].y = var_f2;
    m_uv[1].x = var_f1;
    m_uv[1].y = var_f2;
    m_uv[2].x = var_f1;
    m_uv[2].y = var_f3;
    m_uv[3].x = var_f0;
    m_uv[3].y = var_f3;

    // this->unk30 = var_f0;
    // this->unk34 = var_f2;
    // this->unk38 = var_f1;
    // this->unk3C = var_f2;
    // this->unk40 = var_f1;
    // this->unk44 = var_f3;
    // this->unk48 = var_f0;
    // this->unk4C = var_f3;

    m_colour[0].r = 0xFF;
    m_colour[0].g = 0xFF;
    m_colour[0].b = 0xFF;
    m_colour[0].a = 0xFF;
    m_colour[1].r = 0xFF;
    m_colour[1].g = 0xFF;
    m_colour[1].b = 0xFF;
    m_colour[1].a = 0xFF;
    m_colour[2].r = 0xFF;
    m_colour[2].g = 0xFF;
    m_colour[2].b = 0xFF;
    m_colour[2].a = 0xFF;
    m_colour[3].r = 0xFF;
    m_colour[3].g = 0xFF;
    m_colour[3].b = 0xFF;
    m_colour[3].a = 0xFF;

    // this->unk50 = 0xFF;
    // this->unk51 = 0xFF;
    // this->unk52 = 0xFF;
    // this->unk53 = 0xFF;
    // this->unk54 = 0xFF;
    // this->unk55 = 0xFF;
    // this->unk56 = 0xFF;
    // this->unk57 = 0xFF;
    // this->unk58 = 0xFF;
    // this->unk59 = 0xFF;
    // this->unk5A = 0xFF;
    // this->unk5B = 0xFF;
    // this->unk5C = 0xFF;
    // this->unk5D = 0xFF;
    // this->unk5E = 0xFF;
    // this->unk5F = 0xFF;
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
