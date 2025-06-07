#include "CollisionSpace.h"

#include "PhysicsWorld.h"
#include "PhysicsObject.h"

/**
 * Offset/Address/Size: 0x0 | 0x801FE3E8 | size: 0x60
 */
SimpleCollisionSpace::SimpleCollisionSpace(PhysicsWorld*)
{
}

/**
 * Offset/Address/Size: 0x60 | 0x801FE448 | size: 0x4
 */
void CollisionSpace::PreUpdate()
{
}

/**
 * Offset/Address/Size: 0x64 | 0x801FE44C | size: 0xB8
 */
void CollisionSpace::PreCollide()
{
}

/**
 * Offset/Address/Size: 0x11C | 0x801FE504 | size: 0x30
 */
void CollisionSpace::CallPreCollide(PhysicsObject*)
{
}

/**
 * Offset/Address/Size: 0x14C | 0x801FE534 | size: 0x24
 */
void CollisionSpace::DoCollide(void*, void (*)(void*, dxGeom*, dxGeom*))
{
}

/**
 * Offset/Address/Size: 0x170 | 0x801FE558 | size: 0x60
 */
CollisionSpace::~CollisionSpace()
{
}

/**
 * Offset/Address/Size: 0x1D0 | 0x801FE5B8 | size: 0x70
 */
SimpleCollisionSpace::~SimpleCollisionSpace()
{
}
