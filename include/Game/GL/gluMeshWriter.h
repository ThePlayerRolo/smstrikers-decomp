#ifndef _GLUMESHWRITER_H_
#define _GLUMESHWRITER_H_

#include "Game/GL/GLMeshWriter.h"

#include "NL/nlMath.h"

class GLMeshWriter : public GLMeshWriterCore
{
public:
    // GLMeshWriter()
    //     : GLMeshWriterCore() { };
    // virtual ~GLMeshWriter() { };

    virtual bool End();
    virtual void Normal(const nlVector3&);
    virtual void Texcoord(const nlVector2&);
    virtual void Texcoord(short, short);
};

#endif // _GLUMESHWRITER_H_
