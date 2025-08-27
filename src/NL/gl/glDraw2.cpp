#include "NL/gl/glDraw2.h"

#include "NL/nlMath.h"

#include "NL/gl/gl.h"
#include "NL/gl/glState.h"
#include "NL/gl/glView.h"
#include "NL/gl/glStruct.h"
#include "NL/gl/glMatrix.h"

#include "NL/gl/glModel.h"
#include "NL/gl/glUserData.h"

#include "Game/GL/gluMeshWriter.h"

static const unsigned long StripMap[4] = { 3, 0, 2, 1 };
static const unsigned long QuadMap[4] = { 0, 1, 2, 3 };
static const unsigned long TriListMap[6] = { 3, 0, 2, 0, 2, 1 };

static unsigned long _defaultProgram = glGetProgram("2d unlit");

/**
 * Offset/Address/Size: 0x0 | 0x801D7600 | size: 0x18
 */
void glPoly2::SetColour(const nlColour& col)
{
    c0 = *((unsigned long*)&col);
    c1 = *((unsigned long*)&col);
    c2 = *((unsigned long*)&col);
    c3 = *((unsigned long*)&col);
}

/**
 * Offset/Address/Size: 0x18 | 0x801D7618 | size: 0x1D4
 */
void glPoly2::SetupRotatedRectangle(float cx, float cy, float w, float h, float angle, float z)
{
    nlVector2 v;
    nlMatrix3 m;
    f32 temp_f26;
    f32 temp_f25;
    f32 temp_f31;

    nlMakeRotationMatrixZ(m, angle);

    temp_f26 = -w * 0.5f;
    temp_f31 = -h * 0.5f;
    v.x = temp_f26;
    v.y = temp_f31;
    nlMultVectorMatrix(v, v, m);
    temp_f25 = h * 0.5f;
    x0 = v.x + cx;
    y0 = v.y + cy;
    v.x = temp_f26;
    v.y = temp_f25;
    nlMultVectorMatrix(v, v, m);
    temp_f26 = w * 0.5f;
    x1 = v.x + cx;
    y1 = v.y + cy;
    v.x = temp_f26;
    v.y = temp_f25;
    nlMultVectorMatrix(v, v, m);
    x2 = v.x + cx;
    y2 = v.y + cy;
    v.x = temp_f26;
    v.y = temp_f31;
    nlMultVectorMatrix(v, v, m);
    x3 = v.x + cx;
    y3 = v.y + cy;

    u0 = 0.0f;
    v0 = 0.0f;
    u1 = 0.0f;
    v1 = 1.0f;
    u2 = 1.0f;
    v2 = 1.0f;
    u3 = 1.0f;
    v3 = 0.0f;

    if (z != 1e10f)
    {
        depth = z;
    }
}

/**
 * Offset/Address/Size: 0x1EC | 0x801D77EC | size: 0x64
 */
void glPoly2::SetupRectangle(float x, float y, float w, float h, float z)
{
    f32 bottom_y;
    f32 right_x;

    x0 = x;
    bottom_y = y + h;
    right_x = x + w;
    y0 = y;
    x1 = x;
    y1 = bottom_y;
    x2 = right_x;
    y2 = bottom_y;
    x3 = right_x;
    y3 = y;

    u0 = 0;
    v0 = 0;
    u1 = 0;
    v1 = 1;
    u2 = 1;
    v2 = 1;
    u3 = 1;
    v3 = 0;

    if (z != 1e10f)
    {
        depth = z;
    }
}

/**
 * Offset/Address/Size: 0x250 | 0x801D7850 | size: 0xEC
 */
void glPoly2::FullCoverage(const nlColour& col, float z)
{
    // Screen extents (orthographic), with a border at ScreenInfo+0x20.
    const float width = glGetOrthographicWidth();   // f30  :contentReference[oaicite:16]{index=16}
    const float height = glGetOrthographicHeight(); // f31  :contentReference[oaicite:17]{index=17}
    gl_ScreenInfo* screenInfo = glGetScreenInfo();
    const float border = screenInfo->m_unk_0x20;

    // positions
    x0 = -border;
    y0 = -border;
    x1 = -border;
    y1 = height - border;
    x2 = width - border;
    y2 = height - border;
    x3 = width - border;
    y3 = -border;

    // UVs (0,0)-(0,1)-(1,1)-(1,0)
    u0 = 0.0f;
    v0 = 0.0f;
    u1 = 0.0f;
    v1 = 1.0f;
    u2 = 1.0f;
    v2 = 1.0f;
    u3 = 1.0f;
    v3 = 0.0f; // :contentReference[oaicite:19]{index=19}

    // per-vertex colour (same)
    const unsigned long v = *reinterpret_cast<const unsigned long*>(&col);
    c0 = v;
    c1 = v;
    c2 = v;
    c3 = v; // stw to 0x40..0x4C. :contentReference[oaicite:20]{index=20}

    depth = z; // stfs to 0x50. :contentReference[oaicite:21]{index=21}
}

/**
 * Offset/Address/Size: 0x33C | 0x801D793C | size: 0x2D4
 */
bool glAttachPoly2(eGLView view, unsigned long count, glPoly2* polys, unsigned long* pMatrix, const void* user)
{
    const eGLStream streamsDesc[3] = { eGLStream_0, eGLStream_2, eGLStream_3 };

    if (*(unsigned char*)((char*)gl_GetCurrentStateBundle() + 0x30) != 1)
    {
        // immediate path
        for (unsigned long i = 0; i < count; ++i)
        {
            if (!polys[i].Attach(view, 0, 0, 0xFFFFFFFFu))
                return false;
        }
        return true;
    }

    // streams = {0,2,3}
    GLMeshWriter writer;

    // pick map & prim and vertices-per-poly
    const unsigned long* map;
    int vertsPerPoly;
    eGLPrimitive prim;
    if (glHasQuads())
    {
        map = QuadMap;
        vertsPerPoly = 4;
        prim = (eGLPrimitive)3; // QUADS
    }
    else
    {
        map = TriListMap;
        vertsPerPoly = 6;
        prim = (eGLPrimitive)0; // TRIANGLES
    }

    // program & matrix
    unsigned long oldProg = glSetCurrentProgram(_defaultProgram);
    unsigned long mat = pMatrix ? *pMatrix : glGetIdentityMatrix();
    unsigned long oldMat = glSetCurrentMatrix(mat);

    // total vertices: vertsPerPoly * count
    if (!writer.Begin((int)(vertsPerPoly * count), prim, 3, streamsDesc, false))
    {
        // teardown mirrors asm
        glSetCurrentMatrix(oldMat);
        glSetCurrentProgram(oldProg);
        return false;
    }

    // outer: each poly; inner: emit using selected map
    for (unsigned long i = 0; i < count; ++i)
    {
        glPoly2* p = &polys[i];
        for (int k = 0; k < vertsPerPoly; ++k)
        {
            const unsigned long idx = map[k % (prim == (eGLPrimitive)3 ? 4 : 6)]; // map indexing matches table

            // colour
            const nlColour& c = *(const nlColour*)((char*)p + 0x40 + (idx << 2));
            writer.Colour(c);

            // always has texcoords in this path (writer path in glAttachPoly2)
            const nlVector2& uv = *(const nlVector2*)((char*)p + 0x20 + (idx << 3));
            writer.Texcoord(uv);

            // position + depth
            const float* pos2 = (const float*)((char*)p + (idx << 3));
            nlVector3 v;
            v.f.x = pos2[0];
            v.f.y = pos2[1];
            v.f.z = p->depth;
            writer.Vertex(v);
        }
    }

    // finalize & attach
    const glModel* model = writer.GetModel();

    if (!user)
    {
        glViewAttachModel(view, model);
    }
    else
    {
        // duplicate, attach user data to each packet, then attach model
        const glModel* dup = glModelDupNoStreams(model, true, false);
        glModelPacket* pkt = *(glModelPacket**)((char*)dup + 0x0C);
        const int num = *(int*)((char*)dup + 0x00);
        char* it = (char*)pkt;
        char* end = it + num * 0x4A;
        while (it < end)
        {
            glUserAttach(user, (glModelPacket*)it, false);
            it += 0x4A;
        }
        glViewAttachModel(view, dup);
    }

    glSetCurrentProgram(oldProg);
    glSetCurrentMatrix(oldMat);
    return true;
}

/**
 * Offset/Address/Size: 0x610 | 0x801D7C10 | size: 0x210
 */
bool glPoly2::Attach(eGLView view, int layer, unsigned long* pMatrix, unsigned long /*user*/)
{
    eGLStream streamsDesc[3];
    streamsDesc[0] = eGLStream_0;
    streamsDesc[1] = eGLStream_2;
    streamsDesc[2] = eGLStream_3;

    GLMeshWriter writer;

    // pipeline state flag at +0x30
    const unsigned char stateFlag = gl_GetCurrentStateBundle()->m_nFlags;
    // = *(reinterpret_cast<unsigned char*>(gl_GetCurrentStateBundle()) + 0x30); // :contentReference[oaicite:24]{index=24}

    // program + matrix save/override
    const unsigned long prevProg = glSetCurrentProgram(_defaultProgram);  // :contentReference[oaicite:25]{index=25}
    const unsigned long mat = pMatrix ? *pMatrix : glGetIdentityMatrix(); // :contentReference[oaicite:26]{index=26}
    const unsigned long prevMat = glSetCurrentMatrix(mat);                // :contentReference[oaicite:27]{index=27}

    // choose primitive + index map (quads or strip)
    const bool hasQuads = (glHasQuads() & 0xFF) != 0;                     // :contentReference[oaicite:28]{index=28}
    const eGLPrimitive prim = hasQuads ? eGLPrimitive_3 : eGLPrimitive_1; // 3=quads, 1=tri-strip. :contentReference[oaicite:29]{index=29}
    const unsigned long* map = hasQuads ? QuadMap : StripMap;

    // stream count: flag + 2 (position/texcoord plus maybe colour)
    const int streamCount = static_cast<int>(stateFlag) + 2;

    if (!writer.Begin(4, prim, streamCount, streamsDesc, false))
    { // :contentReference[oaicite:30]{index=30}
        // cleanup + restore
        glSetCurrentProgram(prevProg);
        glSetCurrentMatrix(prevMat);
        return false; // branch to .L_801D7DC0 → 0. :contentReference[oaicite:31]{index=31}
    }

    // emit 4 vertices using the chosen map
    for (int i = 0; i < 4; ++i)
    { // :contentReference[oaicite:32]{index=32}
        const unsigned idx = static_cast<unsigned>(map[i]);

        // Colour (always)
        writer.Colour(*reinterpret_cast<const nlColour*>(reinterpret_cast<const char*>(this) + 0x40
                                                         + (idx << 2))); // :contentReference[oaicite:33]{index=33}

        // Texcoord only if stateFlag != 0 in this TU path
        if (stateFlag)
        { // cmplwi r29,0 / beq skip. :contentReference[oaicite:34]{index=34}
            writer.Texcoord(*reinterpret_cast<const nlVector2*>(reinterpret_cast<const char*>(this) + 0x20
                                                                + (idx << 3))); // :contentReference[oaicite:35]{index=35}
        }

        // Position (x,y,depth)
        const float* xy = reinterpret_cast<const float*>(reinterpret_cast<const char*>(this) + (idx << 3));
        nlVector3 p;
        p.f.x = xy[0];
        p.f.y = xy[1];
        p.f.z = depth;
        writer.Position(p); // vcall at vtbl+0x20. :contentReference[oaicite:36]{index=36}
    }

    if (!writer.End())
    { // :contentReference[oaicite:37]{index=37}
        glSetCurrentProgram(prevProg);
        glSetCurrentMatrix(prevMat);
        return false; // :contentReference[oaicite:38]{index=38}
    }

    // attach with layer variant used in this method
    glViewAttachModel(view, static_cast<unsigned long>(layer), writer.GetModel()); // :contentReference[oaicite:39]{index=39}

    // restore state + dtor
    glSetCurrentProgram(prevProg); // :contentReference[oaicite:40]{index=40}
    glSetCurrentMatrix(prevMat);   // :contentReference[oaicite:41]{index=41}
    return true;
}
