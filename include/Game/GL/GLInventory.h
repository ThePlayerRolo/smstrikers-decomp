#ifndef _GLINVENTORY_H_
#define _GLINVENTORY_H_

#include "Game/AVLTreeBase.h"

class nlChunk;
class GLMaterialList;
class GLVertexAnim;
class GLTextureAnim;
class GLShadowVolume;
class glModel;

class GLInventory
{
public:
    void Update(float);
    void MakeSkinMesh(unsigned long);
    void AddSkinData(unsigned long, nlChunk*);
    GLMaterialList* GetMaterialList(unsigned long);
    void AddMaterialList(unsigned long, GLMaterialList*);
    GLVertexAnim* GetVertexAnim(unsigned long);
    void AddVertexAnim(unsigned long, GLVertexAnim*);
    GLTextureAnim* GetTextureAnim(unsigned long);
    void AddTextureAnim(unsigned long, GLTextureAnim*);
    void GetShadowVolume(unsigned long);
    glModel* GetModel(unsigned long);
    void AddModel(unsigned long, glModel*);
    void ResourceRelease(int);
    void ResourceMark();
    void ReleaseLevel(int);
    void Delete();
    void Create();
    ~GLInventory();

    // /* 0x00 */ u8 m_unk_0x00[0x08];
    /* 0x0x */ AVLTreeBase<unsigned long, GLVertexAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLVertexAnim*>>,
                           DefaultKeyCompare<unsigned long>>
        m_vertexAnimTree;
    /* 0x00 */ u8 m_unk_0x00[0x1C0];
    /* 0x1C0 */ AVLTreeBase<unsigned long, GLMaterialList*, NewAdapter<AVLTreeEntry<unsigned long, GLMaterialList*>>,
                            DefaultKeyCompare<unsigned long>>
        m_materialListTree;
};

#endif // _GLINVENTORY_H_
