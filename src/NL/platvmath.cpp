#include "NL/platvmath.h"

/**
 * Offset/Address/Size: 0x0 | 0x801C3B7C | size: 0x20
 */
void nlMakeScaleMatrix(nlMatrix4&, float, float, float)
{
}

/**
 * Offset/Address/Size: 0x20 | 0x801C3B9C | size: 0x1BC
 */
void nlMakeRotationMatrixEulerAngles(nlMatrix4&, float, float, float)
{
}

/**
 * Offset/Address/Size: 0x1DC | 0x801C3D58 | size: 0x9C
 */
void nlMakeRotationMatrixZ(nlMatrix3&, float)
{
}

/**
 * Offset/Address/Size: 0x278 | 0x801C3DF4 | size: 0x78
 */
void nlMakeRotationMatrixZ(nlMatrix4&, float)
{
}

/**
 * Offset/Address/Size: 0x2F0 | 0x801C3E6C | size: 0x7C
 */
void nlMakeRotationMatrixY(nlMatrix4&, float)
{
}

/**
 * Offset/Address/Size: 0x36C | 0x801C3EE8 | size: 0x78
 */
void nlMakeRotationMatrixX(nlMatrix4&, float)
{
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
void nlMultVectorMatrix(nlVector4&, const nlVector4&, const nlMatrix4&)
{
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
void nlMultVectorMatrix(nlVector2&, const nlVector2&, const nlMatrix3&)
{
}

/**
 * Offset/Address/Size: 0x5A4 | 0x801C4120 | size: 0xB4
 */
void nlInvertMatrix(nlMatrix4& out, const nlMatrix4& in)
{
    //   undefined4 local_48;
    //   undefined4 local_44;
    //   undefined4 local_40;
    //   undefined4 local_3c;
    //   undefined4 local_38;
    //   undefined4 local_34;
    //   undefined4 local_30;
    //   undefined4 local_2c;
    //   undefined4 local_28;
    //   undefined4 local_24;
    //   undefined4 local_20;
    //   undefined4 local_1c;
    //   undefined4 local_18;
    //   undefined4 local_14;
    //   undefined4 local_10;
    //   undefined4 local_c;

    C_MTX44Inverse(in.m, out.m);
    //   *param_1 = local_48;
    //   param_1[1] = local_44;
    //   param_1[2] = local_40;
    //   param_1[3] = local_3c;
    //   param_1[4] = local_38;
    //   param_1[5] = local_34;
    //   param_1[6] = local_30;
    //   param_1[7] = local_2c;
    //   param_1[8] = local_28;
    //   param_1[9] = local_24;
    //   param_1[10] = local_20;
    //   param_1[0xb] = local_1c;
    //   param_1[0xc] = local_18;
    //   param_1[0xd] = local_14;
    //   param_1[0xe] = local_10;
    //   param_1[0xf] = local_c;
}

/**
 * Offset/Address/Size: 0x658 | 0x801C41D4 | size: 0xCC
 */
void nlTransposeMatrix(nlMatrix4&, const nlMatrix4&)
{
}

/**
 * Offset/Address/Size: 0x724 | 0x801C42A0 | size: 0xDC
 */
void nlMultMatrices(nlMatrix4& out, const nlMatrix4& a, const nlMatrix4& b)
{
}

/**
 * Offset/Address/Size: 0x800 | 0x801C437C | size: 0x20
 */
void nlMatrix4::SetIdentity()
{
    PSMTX44Identity(m);
}
