#include "GLInventory.h"

// Helper class for finding material lists by key
class MaterialListFinder
{
public:
    MaterialListFinder(unsigned long searchKey) : m_searchKey(searchKey), m_foundMaterialList(nullptr) {}
    
    void FindCallback(const unsigned long& key, GLMaterialList** materialList)
    {
        if (key == m_searchKey) {
            m_foundMaterialList = *materialList;
        }
    }
    
    GLMaterialList* GetFoundMaterialList() const { return m_foundMaterialList; }
    
private:
    unsigned long m_searchKey;
    GLMaterialList* m_foundMaterialList;
};

/**
 * Offset/Address/Size: 0x0 | 0x801E2298 | size: 0x334
 */
void GLInventory::Update(float)
{
}

/**
 * Offset/Address/Size: 0x334 | 0x801E25CC | size: 0x1A0
 */
void GLInventory::MakeSkinMesh(unsigned long)
{
}

/**
 * Offset/Address/Size: 0x4D4 | 0x801E276C | size: 0x74
 */
void GLInventory::AddSkinData(unsigned long, nlChunk*)
{
}

/**
 * Offset/Address/Size: 0x548 | 0x801E27E0 | size: 0xC8
 */
GLMaterialList* GLInventory::GetMaterialList(unsigned long key)
{
    // Use the Walk method with a callback to find the material list
    MaterialListFinder finder(key);
    // m_materialListTree.Walk(&finder, &MaterialListFinder::FindCallback);
    
    // Return the found material list
    return finder.GetFoundMaterialList();
}

/**
 * Offset/Address/Size: 0x610 | 0x801E28A8 | size: 0x74
 */
void GLInventory::AddMaterialList(unsigned long key, GLMaterialList* materialList)
{
    m_materialListTree.AllocateEntry(&key, &materialList);
}

/**
 * Offset/Address/Size: 0x684 | 0x801E291C | size: 0xC8
 */
GLVertexAnim* GLInventory::GetVertexAnim(unsigned long)
{
    return nullptr; // TODO: Implement actual lookup
}

/**
 * Offset/Address/Size: 0x74C | 0x801E29E4 | size: 0x74
 */
void GLInventory::AddVertexAnim(unsigned long, GLVertexAnim*)
{
}

/**
 * Offset/Address/Size: 0x7C0 | 0x801E2A58 | size: 0xC8
 */
GLTextureAnim* GLInventory::GetTextureAnim(unsigned long)
{
    return nullptr; // TODO: Implement actual lookup
}

/**
 * Offset/Address/Size: 0x888 | 0x801E2B20 | size: 0x74
 */
void GLInventory::AddTextureAnim(unsigned long, GLTextureAnim*)
{
}

/**
 * Offset/Address/Size: 0x8FC | 0x801E2B94 | size: 0xC8
 */
void GLInventory::GetShadowVolume(unsigned long)
{
}

/**
 * Offset/Address/Size: 0x9C4 | 0x801E2C5C | size: 0xC8
 */
glModel* GLInventory::GetModel(unsigned long)
{
    return nullptr; // TODO: Implement actual lookup
}

/**
 * Offset/Address/Size: 0xA8C | 0x801E2D24 | size: 0x74
 */
void GLInventory::AddModel(unsigned long, glModel*)
{
}

/**
 * Offset/Address/Size: 0xB00 | 0x801E2D98 | size: 0x58
 */
void GLInventory::ResourceRelease(int)
{
}

/**
 * Offset/Address/Size: 0xB58 | 0x801E2DF0 | size: 0x10
 */
void GLInventory::ResourceMark()
{
}

/**
 * Offset/Address/Size: 0xB68 | 0x801E2E00 | size: 0xE4
 */
void GLInventory::ReleaseLevel(int)
{
}

/**
 * Offset/Address/Size: 0xC4C | 0x801E2EE4 | size: 0x108
 */
void GLInventory::Delete()
{
    m_materialListTree.Clear();
}

/**
 * Offset/Address/Size: 0xD54 | 0x801E2FEC | size: 0x304
 */
void GLInventory::Create()
{
    // Initialize the AVLTreeBase for storing GLMaterialList objects
    // The AVLTreeBase constructor will initialize the tree properly
}

/**
 * Offset/Address/Size: 0x1058 | 0x801E32F0 | size: 0x50
 */
GLInventory::~GLInventory()
{
    Delete();
}

// /**
//  * Offset/Address/Size: 0x0 | 0x801E3340 | size: 0x24
//  */
// void AVLTreeBase<unsigned long, nlChunk*, NewAdapter<AVLTreeEntry<unsigned long, nlChunk*>>, DefaultKeyCompare<unsigned long>>::DeleteEntry(AVLTreeEntry<unsigned long, nlChunk*>*)
// {
// }

// /**
//  * Offset/Address/Size: 0x24 | 0x801E3364 | size: 0x24
//  */
// void AVLTreeBase<unsigned long, glModel*, NewAdapter<AVLTreeEntry<unsigned long, glModel*>>, DefaultKeyCompare<unsigned long>>::DeleteEntry(AVLTreeEntry<unsigned long, glModel*>*)
// {
// }

// /**
//  * Offset/Address/Size: 0x48 | 0x801E3388 | size: 0x24
//  */
// void AVLTreeBase<unsigned long, GLShadowVolume*, NewAdapter<AVLTreeEntry<unsigned long, GLShadowVolume*>>, DefaultKeyCompare<unsigned long>>::DeleteEntry(AVLTreeEntry<unsigned long, GLShadowVolume*>*)
// {
// }

// /**
//  * Offset/Address/Size: 0x6C | 0x801E33AC | size: 0x24
//  */
// void AVLTreeBase<unsigned long, GLTextureAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLTextureAnim*>>, DefaultKeyCompare<unsigned long>>::DeleteEntry(AVLTreeEntry<unsigned long, GLTextureAnim*>*)
// {
// }

// /**
//  * Offset/Address/Size: 0x90 | 0x801E33D0 | size: 0x24
//  */
// void AVLTreeBase<unsigned long, GLVertexAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLVertexAnim*>>, DefaultKeyCompare<unsigned long>>::DeleteEntry(AVLTreeEntry<unsigned long, GLVertexAnim*>*)
// {
// }

// /**
//  * Offset/Address/Size: 0xB4 | 0x801E33F4 | size: 0x24
//  */
// void AVLTreeBase<unsigned long, GLMaterialList*, NewAdapter<AVLTreeEntry<unsigned long, GLMaterialList*>>, DefaultKeyCompare<unsigned long>>::DeleteEntry(AVLTreeEntry<unsigned long, GLMaterialList*>*)
// {
// }

// /**
//  * Offset/Address/Size: 0xD8 | 0x801E3418 | size: 0x58
//  */
// void AVLTreeBase<unsigned long, GLMaterialList*, NewAdapter<AVLTreeEntry<unsigned long, GLMaterialList*>>, DefaultKeyCompare<unsigned long>>::Clear()
// {
// }

// /**
//  * Offset/Address/Size: 0x130 | 0x801E3470 | size: 0x64
//  */
// void AVLTreeBase<unsigned long, GLMaterialList*, NewAdapter<AVLTreeEntry<unsigned long, GLMaterialList*>>, DefaultKeyCompare<unsigned long>>::DestroyTree(void (AVLTreeBase<unsigned long, GLMaterialList*, NewAdapter<AVLTreeEntry<unsigned long, GLMaterialList*>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long, GLMaterialList*>*))
// {
// }

// /**
//  * Offset/Address/Size: 0x194 | 0x801E34D4 | size: 0x758
//  */
// void AVLTreeBase<unsigned long, GLMaterialList*, NewAdapter<AVLTreeEntry<unsigned long, GLMaterialList*>>, DefaultKeyCompare<unsigned long>>::PostorderTraversal(AVLTreeEntry<unsigned long, GLMaterialList*>*, void (AVLTreeBase<unsigned long, GLMaterialList*, NewAdapter<AVLTreeEntry<unsigned long, GLMaterialList*>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long, GLMaterialList*>*))
// {
// }

// /**
//  * Offset/Address/Size: 0x8EC | 0x801E3C2C | size: 0x8
//  */
// void AVLTreeBase<unsigned long, GLMaterialList*, NewAdapter<AVLTreeEntry<unsigned long, GLMaterialList*>>, DefaultKeyCompare<unsigned long>>::CastUp(AVLTreeNode*) const
// {
// }

// /**
//  * Offset/Address/Size: 0x8F4 | 0x801E3C34 | size: 0x58
//  */
// void AVLTreeBase<unsigned long, GLVertexAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLVertexAnim*>>, DefaultKeyCompare<unsigned long>>::Clear()
// {
// }

// /**
//  * Offset/Address/Size: 0x94C | 0x801E3C8C | size: 0x64
//  */
// void AVLTreeBase<unsigned long, GLVertexAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLVertexAnim*>>, DefaultKeyCompare<unsigned long>>::DestroyTree(void (AVLTreeBase<unsigned long, GLVertexAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLVertexAnim*>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long, GLVertexAnim*>*))
// {
// }

// /**
//  * Offset/Address/Size: 0x9B0 | 0x801E3CF0 | size: 0x758
//  */
// void AVLTreeBase<unsigned long, GLVertexAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLVertexAnim*>>, DefaultKeyCompare<unsigned long>>::PostorderTraversal(AVLTreeEntry<unsigned long, GLVertexAnim*>*, void (AVLTreeBase<unsigned long, GLVertexAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLVertexAnim*>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long, GLVertexAnim*>*))
// {
// }

// /**
//  * Offset/Address/Size: 0x1108 | 0x801E4448 | size: 0x8
//  */
// void AVLTreeBase<unsigned long, GLVertexAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLVertexAnim*>>, DefaultKeyCompare<unsigned long>>::CastUp(AVLTreeNode*) const
// {
// }

// /**
//  * Offset/Address/Size: 0x1110 | 0x801E4450 | size: 0x58
//  */
// void AVLTreeBase<unsigned long, GLTextureAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLTextureAnim*>>, DefaultKeyCompare<unsigned long>>::Clear()
// {
// }

// /**
//  * Offset/Address/Size: 0x1168 | 0x801E44A8 | size: 0x64
//  */
// void AVLTreeBase<unsigned long, GLTextureAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLTextureAnim*>>, DefaultKeyCompare<unsigned long>>::DestroyTree(void (AVLTreeBase<unsigned long, GLTextureAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLTextureAnim*>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long, GLTextureAnim*>*))
// {
// }

// /**
//  * Offset/Address/Size: 0x11CC | 0x801E450C | size: 0x758
//  */
// void AVLTreeBase<unsigned long, GLTextureAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLTextureAnim*>>, DefaultKeyCompare<unsigned long>>::PostorderTraversal(AVLTreeEntry<unsigned long, GLTextureAnim*>*, void (AVLTreeBase<unsigned long, GLTextureAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLTextureAnim*>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long, GLTextureAnim*>*))
// {
// }

// /**
//  * Offset/Address/Size: 0x1924 | 0x801E4C64 | size: 0x8
//  */
// void AVLTreeBase<unsigned long, GLTextureAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLTextureAnim*>>, DefaultKeyCompare<unsigned long>>::CastUp(AVLTreeNode*) const
// {
// }

// /**
//  * Offset/Address/Size: 0x192C | 0x801E4C6C | size: 0x58
//  */
// void AVLTreeBase<unsigned long, GLShadowVolume*, NewAdapter<AVLTreeEntry<unsigned long, GLShadowVolume*>>, DefaultKeyCompare<unsigned long>>::Clear()
// {
// }

// /**
//  * Offset/Address/Size: 0x1984 | 0x801E4CC4 | size: 0x64
//  */
// void AVLTreeBase<unsigned long, GLShadowVolume*, NewAdapter<AVLTreeEntry<unsigned long, GLShadowVolume*>>, DefaultKeyCompare<unsigned long>>::DestroyTree(void (AVLTreeBase<unsigned long, GLShadowVolume*, NewAdapter<AVLTreeEntry<unsigned long, GLShadowVolume*>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long, GLShadowVolume*>*))
// {
// }

// /**
//  * Offset/Address/Size: 0x19E8 | 0x801E4D28 | size: 0x758
//  */
// void AVLTreeBase<unsigned long, GLShadowVolume*, NewAdapter<AVLTreeEntry<unsigned long, GLShadowVolume*>>, DefaultKeyCompare<unsigned long>>::PostorderTraversal(AVLTreeEntry<unsigned long, GLShadowVolume*>*, void (AVLTreeBase<unsigned long, GLShadowVolume*, NewAdapter<AVLTreeEntry<unsigned long, GLShadowVolume*>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long, GLShadowVolume*>*))
// {
// }

// /**
//  * Offset/Address/Size: 0x2140 | 0x801E5480 | size: 0x8
//  */
// void AVLTreeBase<unsigned long, GLShadowVolume*, NewAdapter<AVLTreeEntry<unsigned long, GLShadowVolume*>>, DefaultKeyCompare<unsigned long>>::CastUp(AVLTreeNode*) const
// {
// }

// /**
//  * Offset/Address/Size: 0x2148 | 0x801E5488 | size: 0x58
//  */
// void AVLTreeBase<unsigned long, glModel*, NewAdapter<AVLTreeEntry<unsigned long, glModel*>>, DefaultKeyCompare<unsigned long>>::Clear()
// {
// }

// /**
//  * Offset/Address/Size: 0x21A0 | 0x801E54E0 | size: 0x64
//  */
// void AVLTreeBase<unsigned long, glModel*, NewAdapter<AVLTreeEntry<unsigned long, glModel*>>, DefaultKeyCompare<unsigned long>>::DestroyTree(void (AVLTreeBase<unsigned long, glModel*, NewAdapter<AVLTreeEntry<unsigned long, glModel*>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long, glModel*>*))
// {
// }

// /**
//  * Offset/Address/Size: 0x2204 | 0x801E5544 | size: 0x758
//  */
// void AVLTreeBase<unsigned long, glModel*, NewAdapter<AVLTreeEntry<unsigned long, glModel*>>, DefaultKeyCompare<unsigned long>>::PostorderTraversal(AVLTreeEntry<unsigned long, glModel*>*, void (AVLTreeBase<unsigned long, glModel*, NewAdapter<AVLTreeEntry<unsigned long, glModel*>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long, glModel*>*))
// {
// }

// /**
//  * Offset/Address/Size: 0x295C | 0x801E5C9C | size: 0x8
//  */
// void AVLTreeBase<unsigned long, glModel*, NewAdapter<AVLTreeEntry<unsigned long, glModel*>>, DefaultKeyCompare<unsigned long>>::CastUp(AVLTreeNode*) const
// {
// }

// /**
//  * Offset/Address/Size: 0x2964 | 0x801E5CA4 | size: 0x58
//  */
// void AVLTreeBase<unsigned long, nlChunk*, NewAdapter<AVLTreeEntry<unsigned long, nlChunk*>>, DefaultKeyCompare<unsigned long>>::Clear()
// {
// }

// /**
//  * Offset/Address/Size: 0x29BC | 0x801E5CFC | size: 0x64
//  */
// void AVLTreeBase<unsigned long, nlChunk*, NewAdapter<AVLTreeEntry<unsigned long, nlChunk*>>, DefaultKeyCompare<unsigned long>>::DestroyTree(void (AVLTreeBase<unsigned long, nlChunk*, NewAdapter<AVLTreeEntry<unsigned long, nlChunk*>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long, nlChunk*>*))
// {
// }

// /**
//  * Offset/Address/Size: 0x2A20 | 0x801E5D60 | size: 0x758
//  */
// void AVLTreeBase<unsigned long, nlChunk*, NewAdapter<AVLTreeEntry<unsigned long, nlChunk*>>, DefaultKeyCompare<unsigned long>>::PostorderTraversal(AVLTreeEntry<unsigned long, nlChunk*>*, void (AVLTreeBase<unsigned long, nlChunk*, NewAdapter<AVLTreeEntry<unsigned long, nlChunk*>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long, nlChunk*>*))
// {
// }

// /**
//  * Offset/Address/Size: 0x3178 | 0x801E64B8 | size: 0x8
//  */
// void AVLTreeBase<unsigned long, nlChunk*, NewAdapter<AVLTreeEntry<unsigned long, nlChunk*>>, DefaultKeyCompare<unsigned long>>::CastUp(AVLTreeNode*) const
// {
// }

// /**
//  * Offset/Address/Size: 0x3180 | 0x801E64C0 | size: 0x5C
//  */
// void AVLTreeBase<unsigned long, GLMaterialList*, NewAdapter<AVLTreeEntry<unsigned long, GLMaterialList*>>, DefaultKeyCompare<unsigned long>>::~AVLTreeBase()
// {
// }

// /**
//  * Offset/Address/Size: 0x31DC | 0x801E651C | size: 0x5C
//  */
// void AVLTreeBase<unsigned long, GLVertexAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLVertexAnim*>>, DefaultKeyCompare<unsigned long>>::~AVLTreeBase()
// {
// }

// /**
//  * Offset/Address/Size: 0x3238 | 0x801E6578 | size: 0x5C
//  */
// void AVLTreeBase<unsigned long, GLTextureAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLTextureAnim*>>, DefaultKeyCompare<unsigned long>>::~AVLTreeBase()
// {
// }

// /**
//  * Offset/Address/Size: 0x3294 | 0x801E65D4 | size: 0x5C
//  */
// void AVLTreeBase<unsigned long, GLShadowVolume*, NewAdapter<AVLTreeEntry<unsigned long, GLShadowVolume*>>, DefaultKeyCompare<unsigned long>>::~AVLTreeBase()
// {
// }

// /**
//  * Offset/Address/Size: 0x32F0 | 0x801E6630 | size: 0x5C
//  */
// void AVLTreeBase<unsigned long, glModel*, NewAdapter<AVLTreeEntry<unsigned long, glModel*>>, DefaultKeyCompare<unsigned long>>::~AVLTreeBase()
// {
// }

// /**
//  * Offset/Address/Size: 0x334C | 0x801E668C | size: 0x5C
//  */
// void AVLTreeBase<unsigned long, nlChunk*, NewAdapter<AVLTreeEntry<unsigned long, nlChunk*>>, DefaultKeyCompare<unsigned long>>::~AVLTreeBase()
// {
// }

// /**
//  * Offset/Address/Size: 0x33A8 | 0x801E66E8 | size: 0x2C
//  */
// void AVLTreeBase<unsigned long, GLMaterialList*, NewAdapter<AVLTreeEntry<unsigned long, GLMaterialList*>>, DefaultKeyCompare<unsigned long>>::CompareNodes(AVLTreeNode*, AVLTreeNode*)
// {
// }

// /**
//  * Offset/Address/Size: 0x33D4 | 0x801E6714 | size: 0x2C
//  */
// void AVLTreeBase<unsigned long, GLMaterialList*, NewAdapter<AVLTreeEntry<unsigned long, GLMaterialList*>>, DefaultKeyCompare<unsigned long>>::CompareKey(void*, AVLTreeNode*)
// {
// }

// /**
//  * Offset/Address/Size: 0x3400 | 0x801E6740 | size: 0x2C
//  */
// void AVLTreeBase<unsigned long, GLVertexAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLVertexAnim*>>, DefaultKeyCompare<unsigned long>>::CompareNodes(AVLTreeNode*, AVLTreeNode*)
// {
// }

// /**
//  * Offset/Address/Size: 0x342C | 0x801E676C | size: 0x2C
//  */
// void AVLTreeBase<unsigned long, GLVertexAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLVertexAnim*>>, DefaultKeyCompare<unsigned long>>::CompareKey(void*, AVLTreeNode*)
// {
// }

// /**
//  * Offset/Address/Size: 0x3458 | 0x801E6798 | size: 0x2C
//  */
// void AVLTreeBase<unsigned long, GLTextureAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLTextureAnim*>>, DefaultKeyCompare<unsigned long>>::CompareNodes(AVLTreeNode*, AVLTreeNode*)
// {
// }

// /**
//  * Offset/Address/Size: 0x3484 | 0x801E67C4 | size: 0x2C
//  */
// void AVLTreeBase<unsigned long, GLTextureAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLTextureAnim*>>, DefaultKeyCompare<unsigned long>>::CompareKey(void*, AVLTreeNode*)
// {
// }

// /**
//  * Offset/Address/Size: 0x34B0 | 0x801E67F0 | size: 0x2C
//  */
// void AVLTreeBase<unsigned long, GLShadowVolume*, NewAdapter<AVLTreeEntry<unsigned long, GLShadowVolume*>>, DefaultKeyCompare<unsigned long>>::CompareNodes(AVLTreeNode*, AVLTreeNode*)
// {
// }

// /**
//  * Offset/Address/Size: 0x34DC | 0x801E681C | size: 0x2C
//  */
// void AVLTreeBase<unsigned long, GLShadowVolume*, NewAdapter<AVLTreeEntry<unsigned long, GLShadowVolume*>>, DefaultKeyCompare<unsigned long>>::CompareKey(void*, AVLTreeNode*)
// {
// }

// /**
//  * Offset/Address/Size: 0x3508 | 0x801E6848 | size: 0x2C
//  */
// void AVLTreeBase<unsigned long, glModel*, NewAdapter<AVLTreeEntry<unsigned long, glModel*>>, DefaultKeyCompare<unsigned long>>::CompareNodes(AVLTreeNode*, AVLTreeNode*)
// {
// }

// /**
//  * Offset/Address/Size: 0x3534 | 0x801E6874 | size: 0x2C
//  */
// void AVLTreeBase<unsigned long, glModel*, NewAdapter<AVLTreeEntry<unsigned long, glModel*>>, DefaultKeyCompare<unsigned long>>::CompareKey(void*, AVLTreeNode*)
// {
// }

// /**
//  * Offset/Address/Size: 0x3560 | 0x801E68A0 | size: 0x2C
//  */
// void AVLTreeBase<unsigned long, nlChunk*, NewAdapter<AVLTreeEntry<unsigned long, nlChunk*>>, DefaultKeyCompare<unsigned long>>::CompareNodes(AVLTreeNode*, AVLTreeNode*)
// {
// }

// /**
//  * Offset/Address/Size: 0x358C | 0x801E68CC | size: 0x2C
//  */
// void AVLTreeBase<unsigned long, nlChunk*, NewAdapter<AVLTreeEntry<unsigned long, nlChunk*>>, DefaultKeyCompare<unsigned long>>::CompareKey(void*, AVLTreeNode*)
// {
// }

// /**
//  * Offset/Address/Size: 0x35B8 | 0x801E68F8 | size: 0x64
//  */
// void AVLTreeBase<unsigned long, nlChunk*, NewAdapter<AVLTreeEntry<unsigned long, nlChunk*>>, DefaultKeyCompare<unsigned long>>::AllocateEntry(void*, void*)
// {
// }

// /**
//  * Offset/Address/Size: 0x361C | 0x801E695C | size: 0x64
//  */
// void AVLTreeBase<unsigned long, glModel*, NewAdapter<AVLTreeEntry<unsigned long, glModel*>>, DefaultKeyCompare<unsigned long>>::AllocateEntry(void*, void*)
// {
// }

// /**
//  * Offset/Address/Size: 0x3680 | 0x801E69C0 | size: 0x64
//  */
// void AVLTreeBase<unsigned long, GLShadowVolume*, NewAdapter<AVLTreeEntry<unsigned long, GLShadowVolume*>>, DefaultKeyCompare<unsigned long>>::AllocateEntry(void*, void*)
// {
// }

// /**
//  * Offset/Address/Size: 0x36E4 | 0x801E6A24 | size: 0x64
//  */
// void AVLTreeBase<unsigned long, GLTextureAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLTextureAnim*>>, DefaultKeyCompare<unsigned long>>::AllocateEntry(void*, void*)
// {
// }

// /**
//  * Offset/Address/Size: 0x3748 | 0x801E6A88 | size: 0x64
//  */
// void AVLTreeBase<unsigned long, GLVertexAnim*, NewAdapter<AVLTreeEntry<unsigned long, GLVertexAnim*>>, DefaultKeyCompare<unsigned long>>::AllocateEntry(void*, void*)
// {
// }

// /**
//  * Offset/Address/Size: 0x37AC | 0x801E6AEC | size: 0x64
//  */
// void AVLTreeBase<unsigned long, GLMaterialList*, NewAdapter<AVLTreeEntry<unsigned long, GLMaterialList*>>, DefaultKeyCompare<unsigned long>>::AllocateEntry(void*, void*)
// {
// }

// /**
//  * Offset/Address/Size: 0x3810 | 0x801E6B50 | size: 0x140
//  */
// void 0x801E6C90..0x801E6CB4 | size: 0x24
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x801E6C90 | size: 0x24
//  */
// void ListContainerBase<void*, NewAdapter<ListEntry<void*>>>::DeleteEntry(ListEntry<void*>*)
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x801E6CB4 | size: 0x190
//  */
// void deleting_GLInventory<GLMaterialList>::Release()
// {
// }

// /**
//  * Offset/Address/Size: 0x190 | 0x801E6E44 | size: 0x18C
//  */
// void deleting_GLInventory<GLVertexAnim>::Release()
// {
// }

// /**
//  * Offset/Address/Size: 0x31C | 0x801E6FD0 | size: 0x190
//  */
// void deleting_GLInventory<GLTextureAnim>::Release()
// {
// }

// /**
//  * Offset/Address/Size: 0x4AC | 0x801E7160 | size: 0x1A4
//  */
// void deleting_GLInventory<GLShadowVolume>::Release()
// {
// }

// /**
//  * Offset/Address/Size: 0x650 | 0x801E7304 | size: 0x24
//  */
// void clearing_GLInventory<glModel>::Release()
// {
// }

// /**
//  * Offset/Address/Size: 0x674 | 0x801E7328 | size: 0x18C
//  */
// void freeing_GLInventory<nlChunk>::Release()
// {
// }

// /**
//  * Offset/Address/Size: 0x800 | 0x801E74B4 | size: 0x5C
//  */
// void deleting_GLInventory<GLMaterialList>::~deleting_GLInventory()
// {
// }

// /**
//  * Offset/Address/Size: 0x85C | 0x801E7510 | size: 0x60
//  */
// void nlAVLTree<unsigned long, GLMaterialList*, DefaultKeyCompare<unsigned long>>::~nlAVLTree()
// {
// }

// /**
//  * Offset/Address/Size: 0x8BC | 0x801E7570 | size: 0x5C
//  */
// void deleting_GLInventory<GLVertexAnim>::~deleting_GLInventory()
// {
// }

// /**
//  * Offset/Address/Size: 0x918 | 0x801E75CC | size: 0x60
//  */
// void nlAVLTree<unsigned long, GLVertexAnim*, DefaultKeyCompare<unsigned long>>::~nlAVLTree()
// {
// }

// /**
//  * Offset/Address/Size: 0x978 | 0x801E762C | size: 0x5C
//  */
// void deleting_GLInventory<GLTextureAnim>::~deleting_GLInventory()
// {
// }

// /**
//  * Offset/Address/Size: 0x9D4 | 0x801E7688 | size: 0x60
//  */
// void nlAVLTree<unsigned long, GLTextureAnim*, DefaultKeyCompare<unsigned long>>::~nlAVLTree()
// {
// }

// /**
//  * Offset/Address/Size: 0xA34 | 0x801E76E8 | size: 0x5C
//  */
// void deleting_GLInventory<GLShadowVolume>::~deleting_GLInventory()
// {
// }

// /**
//  * Offset/Address/Size: 0xA90 | 0x801E7744 | size: 0x60
//  */
// void nlAVLTree<unsigned long, GLShadowVolume*, DefaultKeyCompare<unsigned long>>::~nlAVLTree()
// {
// }

// /**
//  * Offset/Address/Size: 0xAF0 | 0x801E77A4 | size: 0x60
//  */
// void clearing_GLInventory<glModel>::~clearing_GLInventory()
// {
// }

// /**
//  * Offset/Address/Size: 0xB50 | 0x801E7804 | size: 0x60
//  */
// void nlAVLTree<unsigned long, glModel*, DefaultKeyCompare<unsigned long>>::~nlAVLTree()
// {
// }

// /**
//  * Offset/Address/Size: 0xBB0 | 0x801E7864 | size: 0x5C
//  */
// void freeing_GLInventory<nlChunk>::~freeing_GLInventory()
// {
// }

// /**
//  * Offset/Address/Size: 0xC0C | 0x801E78C0 | size: 0x60
//  */
// void nlAVLTree<unsigned long, nlChunk*, DefaultKeyCompare<unsigned long>>::~nlAVLTree()
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x801E7920 | size: 0x68
//  */
// void nlWalkList<ListEntry<void*>, ListContainerBase<void*, NewAdapter<ListEntry<void*>>>>(ListEntry<void*>*, ListContainerBase<void*, NewAdapter<ListEntry<void*>>>*, void (ListContainerBase<void*, NewAdapter<ListEntry<void*>>>::*)(ListEntry<void*>*))
// {
// }
