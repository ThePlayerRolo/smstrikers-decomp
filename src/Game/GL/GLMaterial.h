#ifndef _GLMATERIAL_H_
#define _GLMATERIAL_H_

#include "types.h"

struct GLMaterialEntry // size = 0xC
{
    /* 0x00 */ u32 m_id;
    /* 0x04 */ u32 m_unk_0x04;
    /* 0x08 */ u32 m_unk_0x08;
};

class GLMaterialList
{
public:
    GLMaterialEntry* FindMaterial(unsigned long) const;
    void SetMaterials(int, const GLMaterialEntry*);
    ~GLMaterialList();
    GLMaterialList();

    /* 0x00 */ s32 m_unk_0x00;
    /* 0x04 */ s32 m_numEntries;
    /* 0x08 */ GLMaterialEntry *m_materialEntries;   
};

#endif // _GLMATERIAL_H_
