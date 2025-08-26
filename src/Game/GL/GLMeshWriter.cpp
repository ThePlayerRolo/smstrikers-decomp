#include "Game/GL/GLMeshWriter.h"

/**
 * Offset/Address/Size: 0x510 | 0x801E04B0 | size: 0x58
 */
GLMeshWriterCore::GLMeshWriterCore()
{
}

/**
 * Offset/Address/Size: 0x4C8 | 0x801E0468 | size: 0x48
 */
GLMeshWriterCore::~GLMeshWriterCore()
{
}

/**
 * Offset/Address/Size: 0x134 | 0x801E00D4 | size: 0x394
 */
bool GLMeshWriterCore::Begin(int, eGLPrimitive, int, const eGLStream*, bool)
{
    return false;
}

/**
 * Offset/Address/Size: 0x11C | 0x801E00BC | size: 0x18
 */
bool GLMeshWriterCore::End()
{
    return false;
}

/**
 * Offset/Address/Size: 0x114 | 0x801E00B4 | size: 0x8
 */
glModel* GLMeshWriterCore::GetModel()
{
    return nullptr;
}

/**
 * Offset/Address/Size: 0xF0 | 0x801E0090 | size: 0x24
 */
void GLMeshWriterCore::Colour(const nlColour&)
{
}

/**
 * Offset/Address/Size: 0xD0 | 0x801E0070 | size: 0x20
 */
void GLMeshWriterCore::ColourPlat(unsigned long)
{
}

/**
 * Offset/Address/Size: 0xA0 | 0x801E0040 | size: 0x30
 */
void GLMeshWriterCore::Texcoord(const nlVector2&)
{
}

/**
 * Offset/Address/Size: 0x54 | 0x801DFFF4 | size: 0x4C
 */
void GLMeshWriterCore::Vertex(const nlVector3&)
{
}

/**
 * Offset/Address/Size: 0x0 | 0x801DFFA0 | size: 0x54
 */
void GLMeshWriterCore::Vertex(const nlVector4&)
{
}
