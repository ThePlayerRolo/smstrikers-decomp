#ifndef _DFINITEPLANE_H_
#define _DFINITEPLANE_H_

// #include "ode/objects.h"
#include "ode/collision.h"

dGeomID dCreateFinitePlane(dSpaceID space, dReal a, dReal b, dReal c, dReal d, bool flag, float param);
dColliderFn*  dFinitePlaneColliderFn(int);
int dCollideFinitePlaneSphere(dxGeom*, dxGeom*, int, dContactGeom*, int);
void dFinitePlaneAABB(dxGeom*, float*);

#endif // _DFINITEPLANE_H_
