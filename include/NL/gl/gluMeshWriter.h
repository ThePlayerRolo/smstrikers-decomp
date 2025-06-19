#ifndef _GLUMESHWRITER_H_
#define _GLUMESHWRITER_H_

#include "NL/nlMath.h"

class GLMeshWriter
{
public:
    void Texcoord(short, short);
    void Texcoord(const nlVector2&);
    void Normal(const nlVector3&);
    void End();
};

#endif // _GLUMESHWRITER_H_
