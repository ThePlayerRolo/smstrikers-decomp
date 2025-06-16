#ifndef _UTILITY_H_
#define _UTILITY_H_

#include "NL/nlMath.h"

void SolveQuadratic(float a, float b, float c, int& numRoots, float& x1, float& x2);
void SweepSpheres(float, const nlVector3&, const nlVector3&, float, const nlVector3&, const nlVector3&);

#endif // _UTILITY_H_
