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

struct nlVector3
{
    float x;
    float y;
    float z;

    nlVector3()
        : x(0.0f)
        , y(0.0f)
        , z(0.0f)
    {
    }
    nlVector3(float _x, float _y, float _z)
        : x(_x)
        , y(_y)
        , z(_z)
    {
    }
};

struct nlMatrix4
{
    float v[4*4];      // Flat array access
};

struct nlMatrix3
{
    float v[4*3];      // Flat array access
};

struct nlQuaternion
{
    float x;
    float y;
    float z;
    float w;
};

#endif
