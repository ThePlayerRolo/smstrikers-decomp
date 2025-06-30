#include "ode/ext/dColumn.h"
// #include "ode/collision.h"
#include "math.h"
// #include "objects.h"

s32 dColumnClassUser = -1;
u8 lengthwiseAxis = 0x2;

/**
 * Offset/Address/Size: 0x0 | 0x8021CE2C | size: 0xB0
 */
dGeomID dCreateColumn(dxSpace* space, float radius)
{
    dGeomClass geomClass;
    dGeomID geomID;

    if ((s32)dColumnClassUser == -1)
    {
        geomClass.bytes = 4;
        geomClass.collider = &dColumnColliderFn;
        geomClass.aabb = &dColumnAABB;
        geomClass.aabb_test = 0;
        geomClass.dtor = 0;
        dColumnClassUser = dCreateGeomClass(&geomClass);
    }
    geomID = dCreateGeom(dColumnClassUser);
    if (space != NULL)
    {
        dSpaceAdd(space, geomID);
    }
    *(float*)dGeomGetClassData(geomID) = radius;
    return geomID;
}

/**
 * Offset/Address/Size: 0xB0 | 0x8021CEDC | size: 0x30
 */
dColliderFn* dColumnColliderFn(int num)
{
    if (num == (s32)dColumnClassUser)
    {
        return &dCollideColumnColumn;
    }
    if (num == 4)
    {
        return &dCollideColumnPlane;
    }
    return NULL;
}

/**
 * Offset/Address/Size: 0xE0 | 0x8021CF0C | size: 0x1AC
 */
int dCollideColumnPlane(dxGeom* geomID0, dxGeom* geomID1, int arg2, dContactGeom* arg3, int arg4)
{
    dVector4 sp8;
    f32 temp_f2;
    f32 temp_f31; // radius
    s32 temp_r0;
    s32 temp_r6;
    s32 var_r4;
    s32 var_r5;
    s8 var_r6;
    float* temp_r3; // pos

    temp_f31 = *(float*)dGeomGetClassData(geomID0);
    dGeomPlaneGetParams(geomID1, sp8);
    temp_r3 = (float*)dGeomGetPosition(geomID0);
    var_r4 = 0xFF;
    var_r5 = 0xFF;
    var_r6 = 0;
    if ((u8)lengthwiseAxis == 0)
    {
        var_r4 = 1;
        var_r5 = 2;
        if (sp8[0] < 0.001f)
        {
            var_r6 = 1;
        }
    }
    if ((u8)lengthwiseAxis == 1)
    {
        var_r4 = 0;
        var_r5 = 2;
        if (sp8[1] < 0.001f)
        {
            var_r6 = 1;
        }
    }
    if ((u8)lengthwiseAxis == 2)
    {
        var_r4 = 0;
        var_r5 = 1;
        if (sp8[2] < 0.001f)
        {
            var_r6 = 1;
        }
    }
    if (var_r6 == 0)
    {
        return 0;
    }
    temp_r6 = (var_r4 * 4) & 0x3FC;
    temp_r0 = (var_r5 * 4) & 0x3FC;
    temp_f2 = ((*(&sp8[0] + temp_r6) * *(temp_r3 + temp_r6)) + (*(&sp8[0] + temp_r0) * *(temp_r3 + temp_r0))) - sp8[3];
    if (temp_f2 < temp_f31)
    {

        // typedef struct dContactGeom {
        //   dVector3 pos; 0 4 8 C
        //   dVector3 normal; 10 14 18 1C
        //   dReal depth; 20
        //   dGeomID g1,g2; 24 28
        // } dContactGeom;

        arg3->normal[0] = sp8[0];
        arg3->normal[1] = sp8[1];
        arg3->normal[2] = sp8[2];
        *(float*)(arg3 + temp_r6) = -((*(float*)((u8*)(arg3 + temp_r6 + 0x10)) * temp_f31) - *(temp_r3 + temp_r6));
        *(float*)(arg3 + temp_r0) = -((*(float*)((u8*)(arg3 + temp_r0 + 0x10)) * temp_f31) - *(temp_r3 + temp_r0));
        *(float*)(arg3 + (lengthwiseAxis * 4)) = 0.0f;
        arg3->depth = (f32)(temp_f2 - temp_f31);
        arg3->g1 = geomID0;
        arg3->g2 = geomID1;
        return 1;
    }
    return 0;
}

/**
 * Offset/Address/Size: 0x28C | 0x8021D0B8 | size: 0x288
 */
int dCollideColumnColumn(dxGeom* geomID0, dxGeom* geomID1, int arg2, dContactGeom* arg3, int arg4)
{
    f32 sp8;
    f32 temp_f1;
    f32 temp_f2;
    f32 radius_1;
    f32 radius_0;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f4_3;
    f32 var_f5;
    f64 temp_f1_2;
    f64 temp_f1_3;
    f64 temp_f1_4;
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r6;
    s32 var_r0;
    s32 var_r4;
    s32 var_r5;
    float* pos_0;
    float* pos_1;
    float* temp_r7;
    float* temp_r8;

    radius_0 = *(float*)dGeomGetClassData(geomID0);
    radius_1 = *(float*)dGeomGetClassData(geomID1);
    pos_0 = (float*)dGeomGetPosition(geomID0);
    pos_1 = (float*)dGeomGetPosition(geomID1);
    var_r4 = 0xFF;
    var_r5 = 0xFF;
    if ((u8)lengthwiseAxis == 0)
    {
        var_r4 = 1;
        var_r5 = 2;
    }
    if ((u8)lengthwiseAxis == 1)
    {
        var_r4 = 0;
        var_r5 = 2;
    }
    if ((u8)lengthwiseAxis == 2)
    {
        var_r4 = 0;
        var_r5 = 1;
    }
    temp_r6 = (var_r4 * 4) & 0x3FC;
    temp_r5 = (var_r5 * 4) & 0x3FC;
    temp_f4 = radius_0 + radius_1;
    temp_f2 = *(pos_0 + temp_r6) - *(pos_1 + temp_r6);
    temp_f1 = *(pos_0 + temp_r5) - *(pos_1 + temp_r5);
    temp_f4_2 = (temp_f2 * temp_f2) + (temp_f1 * temp_f1);
    if (temp_f4_2 < (temp_f4 * temp_f4))
    {
        if (temp_f4_2 > 0.0f)
        {
            // temp_f1_2 = __frsqrte(temp_f4_2);
            temp_f1_3 = 0.5 * temp_f1_2 * -(((f64)temp_f4_2 * (temp_f1_2 * temp_f1_2)) - 3.0);
            temp_f1_4 = 0.5 * temp_f1_3 * -(((f64)temp_f4_2 * (temp_f1_3 * temp_f1_3)) - 3.0);
            var_f5 = (f32)((f64)temp_f4_2 * (0.5 * temp_f1_4 * -(((f64)temp_f4_2 * (temp_f1_4 * temp_f1_4)) - 3.0)));
            // } else if (temp_f4_2 < (bitwise f32) 0.0) {
        }
        else if (temp_f4_2 < 0.0)
        {
            var_f5 = *(float*)&__float_nan;
        }
        else
        {
            sp8 = temp_f4_2;
            temp_r4 = *(s32*)&sp8 & 0x7F800000;
            // temp_r4 = (bitwise s32) sp8 & 0x7F800000;
            switch (temp_r4)
            { /* irregular */
            case 0x7F800000:
                // if ((bitwise s32) sp8 & 0x7FFFFF) {
                if (*(s32*)&sp8 & 0x7FFFFF)
                {
                    var_r0 = 1;
                }
                else
                {
                    var_r0 = 2;
                }
                break;
            case 0x0:
                // if ((bitwise s32) sp8 & 0x7FFFFF) {
                if (*(s32*)&sp8 & 0x7FFFFF)
                {
                    var_r0 = 5;
                }
                else
                {
                    var_r0 = 3;
                }
                break;
            default:
                var_r0 = 4;
                break;
            }
            if (var_r0 == 1)
            {
                var_f5 = *(float*)&__float_nan;
            }
            else
            {
                var_f5 = temp_f4_2;
            }
        }

        temp_r7 = (float*)(arg3 + temp_r6);
        temp_r8 = (float*)(arg3 + temp_r5);

        temp_r7[4] = (f32)((*(pos_0 + temp_r6) - *(pos_1 + temp_r6)) / var_f5);
        temp_f4_3 = ((var_f5 + radius_1) - radius_0) * 0.5f;

        temp_r8[4] = (f32)((*(pos_0 + temp_r5) - *(pos_1 + temp_r5)) / var_f5);
        *(float*)(arg3 + (lengthwiseAxis * 4) + 0x10) = 0.0f;

        *(float*)(arg3 + temp_r6) = (temp_r7[4] * temp_f4_3) + *(float*)((u8*)pos_1 + temp_r6);
        *(float*)(arg3 + temp_r5) = (temp_r8[4] * temp_f4_3) + *(float*)((u8*)pos_1 + temp_r5);
        *(float*)(arg3 + (lengthwiseAxis * 4)) = 0.0f;
        arg3->depth = (f32)(radius_1 - (var_f5 - radius_1));
        arg3->g1 = geomID0;
        arg3->g2 = geomID1;
        return 1;
    }
    return 0;
}

/**
 * Offset/Address/Size: 0x514 | 0x8021D340 | size: 0x90
 */
void dColumnAABB(dxGeom* geomID, float* aabb)
{
    f32 radius;
    float* position;

    radius = *(float*)dGeomGetClassData(geomID);
    position = (float*)dGeomGetPosition(geomID);

    aabb[0] = position[0] - radius;
    aabb[1] = position[0] + radius;
    aabb[2] = position[1] - radius;
    aabb[3] = position[1] + radius;
    aabb[4] = -radius;
    aabb[5] = radius;
}

/**
 * Offset/Address/Size: 0x5A4 | 0x8021D3D0 | size: 0x34
 */
void dGeomColumnGetParams(dxGeom* geomID, float* radius)
{
    *radius = *(float*)dGeomGetClassData(geomID);
}
