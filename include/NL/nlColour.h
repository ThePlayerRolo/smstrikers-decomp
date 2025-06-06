#ifndef _NLCOLOUR_H_
#define _NLCOLOUR_H_

struct nlColour
{
    float r;
    float g;
    float b;

    nlColour()
        : r(0.0f)
        , g(0.0f)
        , b(0.0f)
    {
    }
    nlColour(float _x, float _y, float _z)
        : r(_x)
        , g(_y)
        , b(_z)
    {
    }
};

#endif // _NLCOLOUR_H_
