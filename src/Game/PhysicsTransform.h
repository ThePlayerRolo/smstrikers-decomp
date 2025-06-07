#ifndef _PHYSICSTRANSFORM_H_
#define _PHYSICSTRANSFORM_H_

#include "NL/nlMath.h"

#include "ode/objects.h"
#include "ode/collision.h"

#include "PhysicsObject.h"

class PhysicsTransform
{
public:
    void SetSubObjectTransform(const nlMatrix4&, PhysicsObject::CoordinateType);
    void SetSubObjectPosition(const nlVector3&, PhysicsObject::CoordinateType);
    void Release();
    void Attach(PhysicsObject*, PhysicsObject*);
    void GetObjectType() const;

    ~PhysicsTransform();
    PhysicsTransform();
};

#endif // _PHYSICSTRANSFORM_H_
