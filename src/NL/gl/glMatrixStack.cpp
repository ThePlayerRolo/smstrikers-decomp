#include "NL/gl/glMatrixStack.h"
#include "NL/nlMemory.h"

/**
 * Offset/Address/Size: 0x0 | 0x801D8C00 | size: 0x84
 */
void GLMatrixStack::GetTop(nlMatrix4& result)
{
    result = m_matrix1;
}

/**
 * Offset/Address/Size: 0x84 | 0x801D8C84 | size: 0xA4
 */
void GLMatrixStack::PopMatrix()
{
    m_matrix1 = m_matrixStack[--m_unk_0x8C];
    m_stackCurPosition = 1;
}

/**
 * Offset/Address/Size: 0x128 | 0x801D8D28 | size: 0xA4
 */
void GLMatrixStack::PushMatrix()
{
    m_matrixStack[m_unk_0x8C++] = m_matrix1;
    m_stackCurPosition = 1;
}

/**
 * Offset/Address/Size: 0x1CC | 0x801D8DCC | size: 0xB8
 */
void GLMatrixStack::MultMatrix(const nlMatrix4& m)
{
    nlMatrix4 tmp = m_matrix1;
    nlMultMatrices(m_matrix1, m, tmp);
    m_stackCurPosition = 1;    
}

/**
 * Offset/Address/Size: 0x284 | 0x801D8E84 | size: 0x3C
 */
void GLMatrixStack::LoadIdentity()
{
    m_matrix1.SetIdentity();
    m_matrix2.SetIdentity();
    m_stackCurPosition = 0;
}

/**
 * Offset/Address/Size: 0x2C0 | 0x801D8EC0 | size: 0x54
 */
GLMatrixStack::~GLMatrixStack()
{
    delete [] m_matrixStack;
}

/**
 * Offset/Address/Size: 0x314 | 0x801D8F14 | size: 0xA8
 */
GLMatrixStack::GLMatrixStack(int stackSize)
{
    m_stackSize = stackSize;
    m_unk_0x8C = 0;
    m_matrixStack = (nlMatrix4*)nlMalloc(stackSize << 6, 8, 0);
    for (int i = 0; i < stackSize; i++) 
    {
        m_matrixStack[i].SetIdentity();
    }
    m_matrix1.SetIdentity();
    m_matrix2.SetIdentity();
    m_stackCurPosition = 0;
}
