#ifndef _DCOLUMN_H_
#define _DCOLUMN_H_

dGeomID dCreateColumn(dxSpace*, float);
void dColumnColliderFn(int);
void dCollideColumnPlane(dxGeom*, dxGeom*, int, dContactGeom*, int);
void dCollideColumnColumn(dxGeom*, dxGeom*, int, dContactGeom*, int);
void dColumnAABB(dxGeom*, float*);
void dGeomColumnGetParams(dxGeom*, float*);

#endif // _DCOLUMN_H_
