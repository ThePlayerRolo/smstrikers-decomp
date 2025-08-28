#include "Game/NetMesh.h"

/**
 * Offset/Address/Size: 0x1178 | 0x8012FF98 | size: 0x84
 */
NetMesh::NetMesh(bool)
{
}

/**
 * Offset/Address/Size: 0xFE8 | 0x8012FE08 | size: 0x190
 */
void NetMesh::Allocate(int, int, int)
{
}

/**
 * Offset/Address/Size: 0xF54 | 0x8012FD74 | size: 0x94
 */
NetMesh::~NetMesh()
{
}

/**
 * Offset/Address/Size: 0xEF4 | 0x8012FD14 | size: 0x60
 */
void NetMesh::SetPositionConstraint(int, const nlVector3&)
{
}

/**
 * Offset/Address/Size: 0xEAC | 0x8012FCCC | size: 0x48
 */
void NetMesh::SetDistanceConstraint(int, int, float)
{
}

/**
 * Offset/Address/Size: 0xE40 | 0x8012FC60 | size: 0x6C
 */
void NetMesh::UpdateUntilRelaxed()
{
}

/**
 * Offset/Address/Size: 0xAA8 | 0x8012F8C8 | size: 0x398
 */
void NetMesh::Update(float, const nlVector3&, const nlVector3&, bool, PhysicsSphere*)
{
}

/**
 * Offset/Address/Size: 0xA60 | 0x8012F880 | size: 0x48
 */
void NetMesh::JoltNet(float)
{
}

/**
 * Offset/Address/Size: 0x550 | 0x8012F370 | size: 0x510
 */
void NetMesh::SatisfyConstraints(const nlVector3&, bool)
{
}

/**
 * Offset/Address/Size: 0x220 | 0x8012F040 | size: 0x330
 */
void NetMesh::AddForcesToBall(const nlVector3&, PhysicsSphere*)
{
}

/**
 * Offset/Address/Size: 0xBC | 0x8012EEDC | size: 0x164
 */
void NetMesh::Initialize(unsigned long)
{
}

/**
 * Offset/Address/Size: 0x54 | 0x8012EE74 | size: 0x68
 */
void NetMesh::SetTriStripIndices(int, const unsigned short*)
{
}

/**
 * Offset/Address/Size: 0x4C | 0x8012EE6C | size: 0x8
 */
void NetMesh::SetDontUseLowestNetTextureLOD(bool)
{
}

/**
 * Offset/Address/Size: 0x0 | 0x8012EE20 | size: 0x4C
 */
void NetMesh::SetTexture(unsigned long)
{
}
