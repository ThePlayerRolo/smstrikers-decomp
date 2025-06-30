#ifndef _DROUNDEDCORNER_H_
#define _DROUNDEDCORNER_H_

#include "ode/objects.h"
#include "ode/collision.h"

dGeomID dCreateRoundedCorner(dxSpace*, float, bool, bool);
dColliderFn* dRoundedCornerColliderFn(int);
int dCollideRoundedCornerColumn(dxGeom*, dxGeom*, int, dContactGeom*, int);
int dCollideRoundedCornerSphere(dxGeom*, dxGeom*, int, dContactGeom*, int);
void dRoundedCornerAABB(dxGeom*, float*);
#endif // _DROUNDEDCORNER_H_
