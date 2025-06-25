#include "ode/ext/dFinitePlane.h"

/**
 * Offset/Address/Size: 0x0 | 0x8021D404 | size: 0xE8
 */
dGeomID dCreateFinitePlane(dSpaceID space, dReal a, dReal b, dReal c, dReal d, bool flag, float param)
{
    return NULL;
}

/**
 * Offset/Address/Size: 0xE8 | 0x8021D4EC | size: 0x18
 */
void dFinitePlaneColliderFn(int)
{
}

/**
 * Offset/Address/Size: 0x100 | 0x8021D504 | size: 0x214
 */
void dCollideFinitePlaneSphere(dxGeom*, dxGeom*, int, dContactGeom*, int)
{
}

/**
 * Offset/Address/Size: 0x314 | 0x8021D718 | size: 0x3B0
 */
void dFinitePlaneAABB(dxGeom*, float*)
{
}
