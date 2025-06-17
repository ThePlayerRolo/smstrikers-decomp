#ifndef _NLMATH_H_
#define _NLMATH_H_

struct nlVector2
{
    float x;
    float y;

    nlVector2()
        : x(0.0f)
        , y(0.0f)
    {
    }
    nlVector2(float _x, float _y)
        : x(_x)
        , y(_y)
    {
    }
};

#define NL_VECTOR3_SET(v, xval, yval, zval) do { \
    (v).x = (xval);                              \
    (v).y = (yval);                              \
    (v).z = (zval);                              \
} while (0)

struct nlVector3
{
    float x;
    float y;
    float z;

    nlVector3(){}
    void Set(float x, float y, float z);
};

struct nlVector4
{
    float x;
    float y;
    float z;
    float w;
};

struct nlMatrix3
{
    float m[3*3];      // Flat array access
};

struct nlQuaternion
{
    float x;
    float y;
    float z;
    float w;
};

void nlBezier(float*, int, float);
void nlATan2f(float, float);
void nlTan(unsigned short);
void nlACos(float);
void nlSinCos(float*, float*, unsigned short);
void nlSin(unsigned short);
float nlRecipSqrt(float, bool);
float nlSqrt(float, bool);
void nlRandomf(float, float, unsigned int*);
void nlRandomf(float, unsigned int*);
void nlRandom(unsigned int, unsigned int*);
void nlSetRandomSeed(unsigned int, unsigned int*);
void nlInitRandom();

#include "NL/platvmath.h"
#include "NL/utility.h"

#endif
