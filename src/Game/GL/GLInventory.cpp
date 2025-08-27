#include "Game/GL/GLInventory.h"

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
    //     u32 *sp8;
    //     s32 temp_r6;
    //     s32 var_ctr;
    //     s32 var_r0_2;
    //     s8 var_r0;
    //     u32 temp_r0;
    //     u32 var_r3;
    //     void *var_r3_2;
    //     void *var_r5;

    //     temp_r6 = arg0->unk1C0;
    //     var_r5 = arg0 + (temp_r6 * 4);
    //     var_ctr = temp_r6 + 1;
    //     if (temp_r6 >= 0) {
    // loop_1:
    //         var_r3_2 = (*var_r5->unk180)->unk8;
    // loop_14:
    //         if (var_r3_2 == NULL) {
    //             var_r0 = 0;
    //         } else {
    //             temp_r0 = var_r3_2->unkC;
    //             if (arg1 == temp_r0) {
    //                 var_r0_2 = 0;
    //             } else if (arg1 < temp_r0) {
    //                 var_r0_2 = -1;
    //             } else {
    //                 var_r0_2 = 1;
    //             }
    //             if (var_r0_2 == 0) {
    //                 if (&sp8 != NULL) {
    //                     sp8 = var_r3_2 + 0x10;
    //                 }
    //                 var_r0 = 1;
    //             } else {
    //                 if (var_r0_2 < 0) {
    //                     var_r3_2 = var_r3_2->unk0;
    //                 } else {
    //                     var_r3_2 = var_r3_2->unk4;
    //                 }
    //                 goto loop_14;
    //             }
    //         }
    //         if (var_r0 != 0) {
    //             var_r3 = *sp8;
    //         } else {
    //             var_r3 = 0U;
    //         }
    //         if (var_r3 != 0U) {
    //             return var_r3;
    //         }
    //         var_r5 -= 4;
    //         var_ctr -= 1;
    //         if (var_ctr == 0) {
    //             goto block_22;
    //         }
    //         goto loop_1;
    //     }
    // block_22:
    return NULL;
}

/**
 * Offset/Address/Size: 0x610 | 0x801E28A8 | size: 0x74
 */
void GLInventory::AddMaterialList(unsigned long key, GLMaterialList* materialList)
{
    // m_materialListTree.AllocateEntry(&key, &materialList);
    AVLTreeNode* node;
    m_materialListTree.AddAVLNode(&m_materialListTree.m_root_node_0x10, &materialList, &key, &node, 0);
    if (node == nullptr)
    {
        m_materialListTree.m_root_node_0x10 += 1;
        // m_materialListTree.AllocateEntry(&key, materialList);
    }
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
void GLInventory::AddVertexAnim(unsigned long key, GLVertexAnim* vertexAnim)
{
    // m_materialListTree.AllocateEntry(&key, &materialList);
    AVLTreeNode* node;
    m_vertexAnimTree.AddAVLNode(&m_materialListTree.m_root_node_0x10, &vertexAnim, &key, &node, 0);
    if (node == nullptr)
    {
        m_vertexAnimTree.m_root_node_0x10 += 1;
    }
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
    m_vertexAnimTree.Clear();
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
