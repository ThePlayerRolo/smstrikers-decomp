#ifndef _GLMESHWRITER_H_
#define _GLMESHWRITER_H_

#include "types.h"

#include "NL/nlColour.h"
#include "NL/nlMath.h"
#include "NL/gl/glModel.h"

enum eGLPrimitive
{
    eGLPrimitive_0 = 0,
    eGLPrimitive_1,
    eGLPrimitive_2,
    eGLPrimitive_3,
};

enum eGLStream
{
    eGLStream_0,
    eGLStream_1,
    eGLStream_2,
    eGLStream_3,
};

class GLMeshWriterCore
{
public:
    GLMeshWriterCore();
    ~GLMeshWriterCore();
    bool Begin(int, eGLPrimitive, int, const eGLStream*, bool);
    bool End();
    glModel* GetModel();
    void Colour(const nlColour&);
    void ColourPlat(unsigned long);
    void Texcoord(const nlVector2&);
    void Vertex(const nlVector3&);
    void Vertex(const nlVector4&);
    void Position(const nlVector3&);
};

#endif // _GLMESHWRITER_H_
