#include "NL/nlMath.h"
#include "Dolphin/mtx.h"

// Conversion factor from radians to 16-bit fixed-point format
// 65536.0f / (2π) ≈ 10430.378f
#define RAD_TO_FIXED16 10430.378f

/**
 * Offset/Address/Size: 0x0 | 0x801C3B7C | size: 0x20
 */
void nlMakeScaleMatrix(nlMatrix4& m, float sx, float sy, float sz)
{
    PSMTX44Scale(m.m, sx, sy, sz);
}

/**
 * Offset/Address/Size: 0x20 | 0x801C3B9C | size: 0x1BC
 */
void nlMakeRotationMatrixEulerAngles(nlMatrix4& m, float pitch, float yaw, float roll)
{
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;

    nlSinCos(&sp1C, &sp18, (short)(RAD_TO_FIXED16 * roll));
    nlSinCos(&sp14, &sp10, (short)(RAD_TO_FIXED16 * yaw));
    nlSinCos(&spC, &sp8, (short)(RAD_TO_FIXED16 * pitch));
    m.m[2][3] = 0.0f;  // unk2C
    m.m[1][3] = 0.0f;  // unk1C
    m.m[0][3] = 0.0f;  // unkC
    m.m[3][2] = 0.0f;  // unk38
    m.m[3][1] = 0.0f;  // unk34
    m.m[3][0] = 0.0f;  // unk30
    m.m[3][3] = 1.0f;  // unk3C
    m.m[0][0] = sp10 * sp18;  // unk0
    m.m[0][1] = sp10 * sp1C;  // unk4
    m.m[0][2] = -sp14;        // unk8
    m.m[1][0] = (sp18 * (spC * sp14)) - (sp8 * sp1C);  // unk10
    m.m[1][1] = (sp1C * (spC * sp14)) + (sp8 * sp18);  // unk14
    m.m[1][2] = sp10 * spC;   // unk18
    m.m[2][0] = (sp18 * (sp8 * sp14)) + (spC * sp1C);  // unk20
    m.m[2][1] = (sp1C * (sp8 * sp14)) - (spC * sp18);  // unk24
    m.m[2][2] = sp10 * sp8;   // unk28
}

/**
 * Offset/Address/Size: 0x1DC | 0x801C3D58 | size: 0x9C
 */
void nlMakeRotationMatrixZ(nlMatrix3& m, float angle)
{
    f32 spC;
    f32 sp8;

    nlSinCos(&spC, &sp8, (short)(RAD_TO_FIXED16 * angle));
    m.m[7] = 0.0f;  // unk1C
    m.m[6] = 0.0f;  // unk18
    m.m[5] = 0.0f;  // unk14
    m.m[3] = 0.0f;  // unkC
    m.m[2] = 0.0f;  // unk8
    m.m[1] = 0.0f;  // unk4
    m.m[8] = 1.0f;  // unk20
    m.m[4] = 1.0f;  // unk10
    m.m[0] = 1.0f;  // unk0
    m.m[0] = sp8;   // unk0 = cos(θ)
    m.m[1] = spC;   // unk4 = sin(θ)
    m.m[3] = -m.m[1]; // unkC = -sin(θ)
    m.m[4] = m.m[0];  // unk10 = cos(θ)
}

/**
 * Offset/Address/Size: 0x278 | 0x801C3DF4 | size: 0x78
 */
void nlMakeRotationMatrixZ(nlMatrix4& m, float angle)
{
    f32 spC;
    f32 sp8;

    nlSinCos(&spC, &sp8, (short)(RAD_TO_FIXED16 * angle));
    PSMTX44Identity(m.m);
    
    m.m[0][0] = sp8;   // cos(θ) at offset 0x00
    m.m[0][1] = spC;   // sin(θ) at offset 0x04  
    m.m[1][0] = -m.m[0][1];  // -sin(θ) at offset 0x10
    m.m[1][1] = m.m[0][0];   // cos(θ) at offset 0x14
}

/**
 * Offset/Address/Size: 0x2F0 | 0x801C3E6C | size: 0x7C
 */
void nlMakeRotationMatrixY(nlMatrix4& m, float angle)
{
    f32 spC;
    f32 sp8;

    nlSinCos(&spC, &sp8, (short)(RAD_TO_FIXED16 * angle));
    PSMTX44Identity(m.m);
    m.m[0][0] = sp8;   // cos(θ) at offset 0x00
    m.m[0][2] = -spC;  // sin(θ) at offset 0x08
    m.m[2][0] = -m.m[0][2];  // -sin(θ) at offset 0x18
    m.m[2][2] = m.m[0][0];   // cos(θ) at offset 0x20
}

/**
 * Offset/Address/Size: 0x36C | 0x801C3EE8 | size: 0x78
 */
void nlMakeRotationMatrixX(nlMatrix4& m, float angle)
{
    f32 spC;
    f32 sp8;

    nlSinCos(&spC, &sp8, (short)(RAD_TO_FIXED16 * angle));
    PSMTX44Identity(m.m);
    m.m[1][1] = sp8;   // cos(θ) at offset 0x14
    m.m[1][2] = spC;   // sin(θ) at offset 0x18
    m.m[2][1] = -m.m[1][2];  // -sin(θ) at offset 0x24
    m.m[2][2] = m.m[1][1];   // cos(θ) at offset 0x28
}

/**
 * Offset/Address/Size: 0x3E4 | 0x801C3F60 | size: 0x44
 */
void nlMultDirVectorMatrix(nlVector3&, const nlVector3&, const nlMatrix4&)
{
}

/**
 * Offset/Address/Size: 0x428 | 0x801C3FA4 | size: 0xCC
 */
void nlMultVectorMatrix(nlVector4& v_out, const nlVector4& v_in, const nlMatrix4& m)
{
    // nlVector4 t = arg2 * arg1;
    v_out = m * v_in;
}

/**
 * Offset/Address/Size: 0x4F4 | 0x801C4070 | size: 0x54
 */
void nlMultPosVectorMatrix(nlVector3& v_out, const nlVector3& v_in, const nlMatrix4& m)
{
}

/**
 * Offset/Address/Size: 0x548 | 0x801C40C4 | size: 0x5C
 */
void nlMultVectorMatrix(nlVector2& v_out, const nlVector2& v_in, const nlMatrix3& m)
{
    // nlVector2 t = m * v_in;
    v_out = m * v_in;
}

/**
 * Offset/Address/Size: 0x5A4 | 0x801C4120 | size: 0xB4
 */
void nlInvertMatrix(nlMatrix4& out, const nlMatrix4& in)
{
    nlMatrix4 tmp;
    C_MTX44Inverse(in.m, tmp.m);
    out = tmp;
}

/**
 * Offset/Address/Size: 0x658 | 0x801C41D4 | size: 0xCC
 */
void nlTransposeMatrix(nlMatrix4& out, const nlMatrix4& in)
{
    if (out.m == in.m) 
    {
        nlMatrix4 tmp;
        PSMTX44Transpose(in.m, tmp.m);
        out = tmp;
        return;
    }
    PSMTX44Transpose(in.m, out.m);  
}

/**
 * Offset/Address/Size: 0x724 | 0x801C42A0 | size: 0xDC
 */
void nlMultMatrices(nlMatrix4& out, const nlMatrix4& a, const nlMatrix4& b)
{
    nlMatrix4 sp8;

    if ((out.m == a.m) || (out.m == b.m)) 
    {
        nlMatrix4 tmp;
        PSMTX44Concat(a.m, b.m, tmp.m);
        out = tmp;
        return;
    }
    PSMTX44Concat(a.m, b.m, out.m);    
}

/**
 * Offset/Address/Size: 0x800 | 0x801C437C | size: 0x20
 */
void nlMatrix4::SetIdentity()
{
    PSMTX44Identity(m);
}
