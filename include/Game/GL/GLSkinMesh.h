#ifndef _GLSKINMESH_H_
#define _GLSKINMESH_H_

#include "NL/nlMath.h"

class SkinMatrix
{
public:
    void Set(const nlMatrix4&);
    void Get(nlMatrix4&) const;
    void Get4x3(float*) const;
};

void nlMultMatrices(SkinMatrix&, const SkinMatrix&, const SkinMatrix&);

#endif // _GLSKINMESH_H_
