#ifndef _DROUNDEDCORNER_H_
#define _DROUNDEDCORNER_H_

#include "ode/objects.h"
#include "ode/collision.h"

void dCreateRoundedCorner(dxSpace*, float, bool, bool);
void dRoundedCornerColliderFn(int);
void dCollideRoundedCornerColumn(dxGeom*, dxGeom*, int, dContactGeom*, int);
void dCollideRoundedCornerSphere(dxGeom*, dxGeom*, int, dContactGeom*, int);
void dRoundedCornerAABB(dxGeom*, float*);
#endif // _DROUNDEDCORNER_H_
