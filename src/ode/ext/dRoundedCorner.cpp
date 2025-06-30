#include "ode/ext/dRoundedCorner.h"

s32 dRoundedCornerClassUser = -1;
extern s32 dColumnClassUser;

struct RoundedCornerData
{
    float param;
    bool flag1;
    bool flag2;
};

struct AABBDimensions
{
    float minX;
    float maxX;
    float minY;
    float maxY;
    float minZ;
    float maxZ;
};

/**
 * Offset/Address/Size: 0x0 | 0x8021DAC8 | size: 0xD0
 */
dGeomID dCreateRoundedCorner(dxSpace* space, float param, bool flag1, bool flag2)
{
    RoundedCornerData* data;
    dGeomClass geomClass;
    dGeomID geomID;

    if ((s32)dRoundedCornerClassUser == -1)
    {
        geomClass.bytes = 8;
        geomClass.collider = &dRoundedCornerColliderFn;
        geomClass.aabb = &dRoundedCornerAABB;
        geomClass.aabb_test = 0;
        geomClass.dtor = 0;
        dRoundedCornerClassUser = dCreateGeomClass(&geomClass);
    }

    geomID = dCreateGeom(dRoundedCornerClassUser);
    if (space != 0U)
    {
        dSpaceAdd(space, geomID);
    }

    data = (RoundedCornerData*)dGeomGetClassData(geomID);
    data->param = param;
    data->flag1 = flag1;
    data->flag2 = flag2;

    return geomID;
}

/**
 * Offset/Address/Size: 0xD0 | 0x8021DB98 | size: 0x34
 */
dColliderFn* dRoundedCornerColliderFn(int num)
{
    if (num == 0)
    {
        return &dCollideRoundedCornerSphere;
    }

    if (num == dColumnClassUser)
    {
        return &dCollideRoundedCornerColumn;
    }

    return NULL;
}

/**
 * Offset/Address/Size: 0x104 | 0x8021DBCC | size: 0x208
 */
int dCollideRoundedCornerColumn(dxGeom*, dxGeom*, int, dContactGeom*, int)
{
}

/**
 * Offset/Address/Size: 0x30C | 0x8021DDD4 | size: 0x214
 */
int dCollideRoundedCornerSphere(dxGeom*, dxGeom*, int, dContactGeom*, int)
{
}

/**
 * Offset/Address/Size: 0x520 | 0x8021DFE8 | size: 0xD4
 */
void dRoundedCornerAABB(dxGeom* geomID, float* aabb)
{
    float temp_f31;
    float p_x;
    float p_y;
    float var_f2;
    float var_f3;
    u32 temp_r31;
    u32 temp_r30;
    RoundedCornerData* data;
    float* position;

    data = (RoundedCornerData*)dGeomGetClassData(geomID);
    temp_f31 = data->param;
    temp_r31 = data->flag1;
    temp_r30 = data->flag2;
    position = (float*)dGeomGetPosition(geomID);
    p_x = position[0];
    p_y = position[1];
    var_f2 = p_x;
    var_f3 = p_y;
    if (temp_r31 != 0)
    {
        var_f2 = p_x + temp_f31;
    }
    if (temp_r31 == 0)
    {
        p_x -= temp_f31;
    }
    if (temp_r30 != 0)
    {
        var_f3 += temp_f31;
    }
    if (temp_r30 == 0)
    {
        p_y -= temp_f31;
    }

    aabb[0] = p_x;
    aabb[1] = var_f2;
    aabb[2] = p_y;
    aabb[3] = var_f3;
    aabb[4] = -*(float*)&__float_max;
    aabb[5] = *(float*)&__float_max;
}
