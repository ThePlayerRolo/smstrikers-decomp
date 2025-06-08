#ifndef _PHYSICSTRANSFORM_H_
#define _PHYSICSTRANSFORM_H_

#include "NL/nlMath.h"

#include "ode/objects.h"
#include "ode/collision.h"

#include "PhysicsObject.h"

class PhysicsTransform //: public PhysicsObject
{
public:
    void SetSubObjectTransform(const nlMatrix4&, PhysicsObject::CoordinateType);
    void SetSubObjectPosition(const nlVector3&, PhysicsObject::CoordinateType);
    void Release();
    void Attach(PhysicsObject*, PhysicsObject*);
    void GetObjectType() const;

    ~PhysicsTransform();
    PhysicsTransform();

    u8 _padding[4];
    /* 0x04 */ dBodyID _bodyID;
    /* 0x08 */ dGeomID _geomID;
    u8 _padding2[29];
    /* 0x2c */ PhysicsObject *_unk_2c;
};

#endif // _PHYSICSTRANSFORM_H_
