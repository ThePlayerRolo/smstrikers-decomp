#include "Game/NetMeshEdge.h"

/**
 * Offset/Address/Size: 0x114 | 0x80130138 | size: 0x20
 * NetMeshModelLoader::NetMeshVertex::GetPosition() const
 */
const nlVector3* NetMeshModelLoader::NetMeshVertex::GetPosition() const
{
    u8* layout = *(u8**)((char*)m_owner + 0x0C);
    u8 stride = *(u8*)(layout + 0x05);
    s8* base = *(s8**)(layout + 0x00);

    return (const nlVector3*)(base + stride * m_index);
}

/**
 * Offset/Address/Size: 0x74 | 0x80130098 | size: 0xA0
 * NetMeshModelLoader::NetMeshVertex::GetNormal(nlVector3&) const
 */
void NetMeshModelLoader::NetMeshVertex::GetNormal(nlVector3& normal) const
{
    float f = 0.015625f;

    u8* layout = *(u8**)((u8*)m_owner + 0x0C);
    u8 stride = *(u8*)(layout + 0x0B);
    s8* base = *(s8**)(layout + 0x06);

    s8 normalX = (base + stride * m_index)[0];
    s8 normalY = (base + stride * m_index)[1];
    s8 normalZ = (base + stride * m_index)[2];

    normal.f.x = (float)normalX * f;
    normal.f.y = (float)normalY * f;
    normal.f.z = (float)normalZ * f;
}

/**
 * Offset/Address/Size: 0x0 | 0x80130024 | size: 0x74
 * NetMeshModelLoader::NetMeshVertex::GetTextureCoord(nlVector2&) const
 */
void NetMeshModelLoader::NetMeshVertex::GetTextureCoord(nlVector2& txtCoord) const
{
    u8* layout = *(u8**)((u8*)m_owner + 0x0C);
    u8 stride = *(u8*)(layout + 0x17);
    s8* base = *(s8**)(layout + 0x12);

    s16* offset = (s16*)(base + stride * m_index);

    s16 texCoordX = offset[0];
    s16 texCoordY = offset[1];

    float f = 0.0009765625f;

    txtCoord.x = (float)texCoordX * f;
    txtCoord.y = (float)texCoordY * f;
}
