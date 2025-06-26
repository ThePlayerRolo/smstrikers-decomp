#ifndef _DCOLUMN_H_
#define _DCOLUMN_H_

#include "ode/objects.h"
#include "ode/collision.h"

dGeomID dCreateColumn(dxSpace*, float);
dColliderFn* dColumnColliderFn(int);
int dCollideColumnPlane(dxGeom*, dxGeom*, int, dContactGeom*, int);
int dCollideColumnColumn(dxGeom*, dxGeom*, int, dContactGeom*, int);
void dColumnAABB(dxGeom*, float*);
void dGeomColumnGetParams(dxGeom*, float*);

#endif // _DCOLUMN_H_
