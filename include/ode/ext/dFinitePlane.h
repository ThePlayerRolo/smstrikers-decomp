#ifndef _DFINITEPLANE_H_
#define _DFINITEPLANE_H_

#include "ode/objects.h"
#include "ode/collision.h"

dGeomID dCreateFinitePlane(dSpaceID space, dReal a, dReal b, dReal c, dReal d, bool flag, float param); // added
// void dCreateFinitePlane(dxSpace*, float, float, float, float, bool, float);
void dFinitePlaneColliderFn(int);
void dCollideFinitePlaneSphere(dxGeom*, dxGeom*, int, dContactGeom*, int);
void dFinitePlaneAABB(dxGeom*, float*);

#endif // _DFINITEPLANE_H_
