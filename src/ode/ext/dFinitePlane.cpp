#include "ode/ext/dFinitePlane.h"

s32 dFinitePlaneClassUser = -1;

struct FinitePlane
{
    float a; 
    float b; 
    float c; 
    float d; 
    bool flag;
    float param;
};

/**
 * Offset/Address/Size: 0x0 | 0x8021D404 | size: 0xE8
 */
dGeomID dCreateFinitePlane(dSpaceID space, dReal a, dReal b, dReal c, dReal d, bool flag, float param)
{
    FinitePlane *planeData;
    dGeomClass geomClass;
    dGeomID geomID;

    if ((s32) dFinitePlaneClassUser == -1) {
        geomClass.bytes = 0x18;
        geomClass.collider = &dFinitePlaneColliderFn;
        geomClass.aabb = &dFinitePlaneAABB;
        geomClass.aabb_test = 0;
        geomClass.dtor = 0;
        dFinitePlaneClassUser = dCreateGeomClass(&geomClass);
    }
    
    geomID = dCreateGeom(dFinitePlaneClassUser);
    if (space != 0U) {
        dSpaceAdd(space, geomID);
    }

    planeData = (FinitePlane*)dGeomGetClassData(geomID);
    planeData->a = a;
    planeData->b = b;
    planeData->c = c;
    planeData->d = d;
    planeData->flag = flag;
    planeData->param = param;

    return geomID;
}

/**
 * Offset/Address/Size: 0xE8 | 0x8021D4EC | size: 0x18
 */
dColliderFn* dFinitePlaneColliderFn(int num)
{
    if (num == 0) 
    {
        return &dCollideFinitePlaneSphere;
    }
    return NULL;    
}

/**
 * Offset/Address/Size: 0x100 | 0x8021D504 | size: 0x214
 */
int dCollideFinitePlaneSphere(dxGeom*, dxGeom*, int, dContactGeom*, int)
{
}

/**
 * Offset/Address/Size: 0x314 | 0x8021D718 | size: 0x3B0
 */
void dFinitePlaneAABB(dxGeom*, float*)
{
}
