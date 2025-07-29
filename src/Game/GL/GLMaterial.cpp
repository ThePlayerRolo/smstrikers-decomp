#include "GLMaterial.h"
#include "NL/nlMemory.h"

/**
 * Offset/Address/Size: 0x0 | 0x801E7E70 | size: 0x48
 */
 GLMaterialEntry* GLMaterialList::FindMaterial(unsigned long arg0) const
{
    s8* start = (s8*)m_materialEntries;
    s8* end = start + (m_numEntries * 0xC);    
    // u32 var_ctr = ((end + 0xB) - start) / 12;
    s32 var_ctr = m_numEntries;

    if (start != end) 
    {
        for (;var_ctr > 0;var_ctr--)
        {
            if (((GLMaterialEntry*)start)->m_id == arg0)
            {
                return (GLMaterialEntry*)start;
            }
            start = start + 0xC;
        }
    }
    return NULL;  
}

/**
 * Offset/Address/Size: 0x48 | 0x801E7EB8 | size: 0x84
 */
void GLMaterialList::SetMaterials(int arg0, const GLMaterialEntry* arg1)
{
    u32 size;

    if (m_materialEntries)
    {
        delete[] m_materialEntries;
    }

    size = arg0 * 0xC;
    m_numEntries = arg0;
    // m_materialEntries = (GLMaterialEntry*)nlMalloc(size, 8, 0);
    m_materialEntries = (u8*)nlMalloc(size, 8, 0);
    memcpy(m_materialEntries, arg1, size);    
}

/**
 * Offset/Address/Size: 0xCC | 0x801E7F3C | size: 0x5C
 */
GLMaterialList::~GLMaterialList()
{
    if (m_materialEntries)
    {
        delete[] m_materialEntries;
    }
}

/**
 * Offset/Address/Size: 0x128 | 0x801E7F98 | size: 0x18
 */
GLMaterialList::GLMaterialList()
{
    m_unk_0x00 = -1;
    m_numEntries = 0;
    m_materialEntries = NULL;    
}
