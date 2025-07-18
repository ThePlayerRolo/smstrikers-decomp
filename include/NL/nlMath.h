#ifndef _NLMATH_H_
#define _NLMATH_H_

#include "Dolphin/mtx.h"

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

#define NL_VECTOR3_COPY_U32(dst, src) do { \
    u32* _src_ptr = (u32*)&(src); \
    u32* _dst_ptr = (u32*)&(dst); \
    _dst_ptr[0] = _src_ptr[0]; \
    _dst_ptr[1] = _src_ptr[1]; \
    _dst_ptr[2] = _src_ptr[2]; \
} while(0)

#define COPY_VECTOR3_U32_2(dst, src) do { \
    u32 y = *(const u32*)&src.y; \
    u32 x = *(const u32*)&src.x; \
    *(u32*)&dst.x = x; \
    u32 z = *(const u32*)&src.z; \
    *(u32*)&dst.y = y; \
    *(u32*)&dst.z = z; \
} while(0)

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
    nlVector4(){}
    nlVector4(float x, float y, float z, float w)
        : x(x)
        , y(y)
        , z(z)
        , w(w)
    {
    }
};

struct nlMatrix3
{
    float m[3*3];      // Flat array access

    inline nlVector2 operator*(const nlVector2& v_in) const 
    {
        nlVector2 tmp;
        tmp.x = m[6] + ((m[0] * v_in.x) + (m[3] * v_in.y));
        tmp.y = m[7] + ((m[1] * v_in.x) + (m[4] * v_in.y));
        return tmp;
    }
};

// struct nlVector2;
// struct nlVector3;
// struct nlVector4;
// struct nlMatrix3;
// struct nlMatrix4;

/*

m[0][0] m[0][1] m[0][2] m[0][3]  // Row 0: offset 0x00, 0x04, 0x08, 0x0C
m[1][0] m[1][1] m[1][2] m[1][3]  // Row 1: offset 0x10, 0x14, 0x18, 0x1C  
m[2][0] m[2][1] m[2][2] m[2][3]  // Row 2: offset 0x20, 0x24, 0x28, 0x2C
m[3][0] m[3][1] m[3][2] m[3][3]  // Row 3: offset 0x30, 0x34, 0x38, 0x3C

*/

struct nlMatrix4
{
    Mtx44 m;

    void SetIdentity();
    void SetColumn(int col, const nlVector3& v);
    
    inline nlVector4 operator*(const nlVector4& v_in) const 
    {
        nlVector4 tmp;
        tmp.x = (m[3][0] * v_in.w) + ((m[2][0] * v_in.z) + ((m[0][0] * v_in.x) + (m[1][0] * v_in.y)));
        tmp.z = (m[3][2] * v_in.w) + ((m[2][2] * v_in.z) + ((m[0][2] * v_in.x) + (m[1][2] * v_in.y)));
        tmp.y = (m[3][1] * v_in.w) + ((m[2][1] * v_in.z) + ((m[0][1] * v_in.x) + (m[1][1] * v_in.y)));
        tmp.w = (m[3][3] * v_in.w) + ((m[2][3] * v_in.z) + ((m[0][3] * v_in.x) + (m[1][3] * v_in.y)));
        return tmp;
    }
};

void nlBezier(float*, int, float);
float nlATan2f(float, float);
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
#include "NL/platqmath.h"
#include "NL/utility.h"

#endif
