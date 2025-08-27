#ifndef _GLINVENTORY_H_
#define _GLINVENTORY_H_

#include "NL/nlAVLTreeBase.h"

class nlChunk;
class GLMaterialList;
class GLVertexAnim;
class GLTextureAnim;
class GLShadowVolume;
class glModel;

class GLInventory
{
public:
    ~GLInventory();
    void Create();
    void Delete();
    void ReleaseLevel(int);
    void ResourceMark();
    void ResourceRelease(int);
    void AddModel(unsigned long, glModel*);
    glModel* GetModel(unsigned long);
    void GetShadowVolume(unsigned long);
    void AddTextureAnim(unsigned long, GLTextureAnim*);
    GLTextureAnim* GetTextureAnim(unsigned long);
    void AddVertexAnim(unsigned long, GLVertexAnim*);
    GLVertexAnim* GetVertexAnim(unsigned long);
    void AddMaterialList(unsigned long, GLMaterialList*);
    GLMaterialList* GetMaterialList(unsigned long);
    void AddSkinData(unsigned long, nlChunk*);
    void MakeSkinMesh(unsigned long);
    void Update(float);

    /* 0x00 */ u8 m_unk_0x00[0x08];
    /* 0x08 */ AVLTreeBase<unsigned long, GLVertexAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLVertexAnim*> >, DefaultKeyCompare<unsigned long> > m_vertexAnimTree;
    /* 0x1C */ u8 m_unk_0x1C[0x1C0];
    /* 0x1DC */ AVLTreeBase<unsigned long, GLMaterialList*, NewAdapter<AVLTreeEntry<unsigned long, GLMaterialList*> >, DefaultKeyCompare<unsigned long> > m_materialListTree;
};

#endif // _GLINVENTORY_H_
