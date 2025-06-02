#ifndef _NLMATH_H_
#define _NLMATH_H_

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

#endif
