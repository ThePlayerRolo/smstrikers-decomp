#include "Game/NetMeshModelLoader.h"

// /**
//  * Offset/Address/Size: 0x1554 | 0x80132B00 | size: 0x10
//  */
// void AVLTreeBase<NetMeshModelLoader::NetMeshVertex, int, BasicSlotPool<AVLTreeEntry<NetMeshModelLoader::NetMeshVertex, int>>, DefaultKeyCompare<NetMeshModelLoader::NetMeshVertex>>::DeleteEntry(AVLTreeEntry<NetMeshModelLoader::NetMeshVertex, int>*)
// {
// }

// /**
//  * Offset/Address/Size: 0x149C | 0x80132A48 | size: 0xB8
//  */
// void AVLTreeBase<NetMeshModelLoader::NetMeshVertex, int, BasicSlotPool<AVLTreeEntry<NetMeshModelLoader::NetMeshVertex, int>>, DefaultKeyCompare<NetMeshModelLoader::NetMeshVertex>>::AllocateEntry(void*, void*)
// {
// }

// /**
//  * Offset/Address/Size: 0x148C | 0x80132A38 | size: 0x10
//  */
// void AVLTreeBase<NetMeshModelLoader::NetMeshEdge, int, BasicSlotPool<AVLTreeEntry<NetMeshModelLoader::NetMeshEdge, int>>, DefaultKeyCompare<NetMeshModelLoader::NetMeshEdge>>::DeleteEntry(AVLTreeEntry<NetMeshModelLoader::NetMeshEdge, int>*)
// {
// }

// /**
//  * Offset/Address/Size: 0x13B8 | 0x80132964 | size: 0xD4
//  */
// void AVLTreeBase<NetMeshModelLoader::NetMeshEdge, int, BasicSlotPool<AVLTreeEntry<NetMeshModelLoader::NetMeshEdge, int>>, DefaultKeyCompare<NetMeshModelLoader::NetMeshEdge>>::CompareNodes(AVLTreeNode*, AVLTreeNode*)
// {
// }

// /**
//  * Offset/Address/Size: 0x12E4 | 0x80132890 | size: 0xD4
//  */
// void AVLTreeBase<NetMeshModelLoader::NetMeshEdge, int, BasicSlotPool<AVLTreeEntry<NetMeshModelLoader::NetMeshEdge, int>>, DefaultKeyCompare<NetMeshModelLoader::NetMeshEdge>>::CompareKey(void*, AVLTreeNode*)
// {
// }

// /**
//  * Offset/Address/Size: 0x1218 | 0x801327C4 | size: 0xCC
//  */
// void AVLTreeBase<NetMeshModelLoader::NetMeshEdge, int, BasicSlotPool<AVLTreeEntry<NetMeshModelLoader::NetMeshEdge, int>>, DefaultKeyCompare<NetMeshModelLoader::NetMeshEdge>>::AllocateEntry(void*, void*)
// {
// }

// /**
//  * Offset/Address/Size: 0x11A4 | 0x80132750 | size: 0x74
//  */
// void AVLTreeBase<NetMeshModelLoader::NetMeshVertex, int, BasicSlotPool<AVLTreeEntry<NetMeshModelLoader::NetMeshVertex, int>>, DefaultKeyCompare<NetMeshModelLoader::NetMeshVertex>>::CompareKey(void*, AVLTreeNode*)
// {
// }

// /**
//  * Offset/Address/Size: 0x1130 | 0x801326DC | size: 0x74
//  */
// void AVLTreeBase<NetMeshModelLoader::NetMeshVertex, int, BasicSlotPool<AVLTreeEntry<NetMeshModelLoader::NetMeshVertex, int>>, DefaultKeyCompare<NetMeshModelLoader::NetMeshVertex>>::CompareNodes(AVLTreeNode*, AVLTreeNode*)
// {
// }

// /**
//  * Offset/Address/Size: 0x1128 | 0x801326D4 | size: 0x8
//  */
// void AVLTreeBase<NetMeshModelLoader::NetMeshEdge, int, BasicSlotPool<AVLTreeEntry<NetMeshModelLoader::NetMeshEdge, int>>, DefaultKeyCompare<NetMeshModelLoader::NetMeshEdge>>::CastUp(AVLTreeNode*) const
// {
// }

// /**
//  * Offset/Address/Size: 0x9D0 | 0x80131F7C | size: 0x758
//  */
// void AVLTreeBase<NetMeshModelLoader::NetMeshEdge, int, BasicSlotPool<AVLTreeEntry<NetMeshModelLoader::NetMeshEdge, int>>, DefaultKeyCompare<NetMeshModelLoader::NetMeshEdge>>::PostorderTraversal(AVLTreeEntry<NetMeshModelLoader::NetMeshEdge, int>*, void (AVLTreeBase<NetMeshModelLoader::NetMeshEdge, int, BasicSlotPool<AVLTreeEntry<NetMeshModelLoader::NetMeshEdge, int>>, DefaultKeyCompare<NetMeshModelLoader::NetMeshEdge>>::*)(AVLTreeEntry<NetMeshModelLoader::NetMeshEdge, int>*))
// {
// }

// /**
//  * Offset/Address/Size: 0x96C | 0x80131F18 | size: 0x64
//  */
// void AVLTreeBase<NetMeshModelLoader::NetMeshEdge, int, BasicSlotPool<AVLTreeEntry<NetMeshModelLoader::NetMeshEdge, int>>, DefaultKeyCompare<NetMeshModelLoader::NetMeshEdge>>::DestroyTree(void (AVLTreeBase<NetMeshModelLoader::NetMeshEdge, int, BasicSlotPool<AVLTreeEntry<NetMeshModelLoader::NetMeshEdge, int>>, DefaultKeyCompare<NetMeshModelLoader::NetMeshEdge>>::*)(AVLTreeEntry<NetMeshModelLoader::NetMeshEdge, int>*))
// {
// }

// /**
//  * Offset/Address/Size: 0x914 | 0x80131EC0 | size: 0x58
//  */
// void AVLTreeBase<NetMeshModelLoader::NetMeshEdge, int, BasicSlotPool<AVLTreeEntry<NetMeshModelLoader::NetMeshEdge, int>>, DefaultKeyCompare<NetMeshModelLoader::NetMeshEdge>>::Clear()
// {
// }

// /**
//  * Offset/Address/Size: 0x898 | 0x80131E44 | size: 0x7C
//  */
// void AVLTreeBase<NetMeshModelLoader::NetMeshEdge, int, BasicSlotPool<AVLTreeEntry<NetMeshModelLoader::NetMeshEdge, int>>, DefaultKeyCompare<NetMeshModelLoader::NetMeshEdge>>::~AVLTreeBase()
// {
// }

// /**
//  * Offset/Address/Size: 0x890 | 0x80131E3C | size: 0x8
//  */
// void AVLTreeBase<NetMeshModelLoader::NetMeshVertex, int, BasicSlotPool<AVLTreeEntry<NetMeshModelLoader::NetMeshVertex, int>>, DefaultKeyCompare<NetMeshModelLoader::NetMeshVertex>>::CastUp(AVLTreeNode*) const
// {
// }

// /**
//  * Offset/Address/Size: 0x138 | 0x801316E4 | size: 0x758
//  */
// void AVLTreeBase<NetMeshModelLoader::NetMeshVertex, int, BasicSlotPool<AVLTreeEntry<NetMeshModelLoader::NetMeshVertex, int>>, DefaultKeyCompare<NetMeshModelLoader::NetMeshVertex>>::PostorderTraversal(AVLTreeEntry<NetMeshModelLoader::NetMeshVertex, int>*, void (AVLTreeBase<NetMeshModelLoader::NetMeshVertex, int, BasicSlotPool<AVLTreeEntry<NetMeshModelLoader::NetMeshVertex, int>>, DefaultKeyCompare<NetMeshModelLoader::NetMeshVertex>>::*)(AVLTreeEntry<NetMeshModelLoader::NetMeshVertex, int>*))
// {
// }

// /**
//  * Offset/Address/Size: 0xD4 | 0x80131680 | size: 0x64
//  */
// void AVLTreeBase<NetMeshModelLoader::NetMeshVertex, int, BasicSlotPool<AVLTreeEntry<NetMeshModelLoader::NetMeshVertex, int>>, DefaultKeyCompare<NetMeshModelLoader::NetMeshVertex>>::DestroyTree(void (AVLTreeBase<NetMeshModelLoader::NetMeshVertex, int, BasicSlotPool<AVLTreeEntry<NetMeshModelLoader::NetMeshVertex, int>>, DefaultKeyCompare<NetMeshModelLoader::NetMeshVertex>>::*)(AVLTreeEntry<NetMeshModelLoader::NetMeshVertex, int>*))
// {
// }

// /**
//  * Offset/Address/Size: 0x7C | 0x80131628 | size: 0x58
//  */
// void AVLTreeBase<NetMeshModelLoader::NetMeshVertex, int, BasicSlotPool<AVLTreeEntry<NetMeshModelLoader::NetMeshVertex, int>>, DefaultKeyCompare<NetMeshModelLoader::NetMeshVertex>>::Clear()
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x801315AC | size: 0x7C
//  */
// void AVLTreeBase<NetMeshModelLoader::NetMeshVertex, int, BasicSlotPool<AVLTreeEntry<NetMeshModelLoader::NetMeshVertex, int>>, DefaultKeyCompare<NetMeshModelLoader::NetMeshVertex>>::~AVLTreeBase()
// {
// }

// /**
//  * Offset/Address/Size: 0x1400 | 0x80131558 | size: 0x54
//  */
// NetMeshModelLoader::NetMeshModelLoader(NetMesh&, unsigned long)
// {
// }

// /**
//  * Offset/Address/Size: 0x13A0 | 0x801314F8 | size: 0x60
//  */
// void nlAVLTreeSlotPool<NetMeshModelLoader::NetMeshEdge, int, DefaultKeyCompare<NetMeshModelLoader::NetMeshEdge>>::~nlAVLTreeSlotPool()
// {
// }

// /**
//  * Offset/Address/Size: 0x1340 | 0x80131498 | size: 0x60
//  */
// void nlAVLTreeSlotPool<NetMeshModelLoader::NetMeshVertex, int, DefaultKeyCompare<NetMeshModelLoader::NetMeshVertex>>::~nlAVLTreeSlotPool()
// {
// }

/**
 * Offset/Address/Size: 0x12C8 | 0x80131420 | size: 0x78
 */
NetMeshModelLoader::~NetMeshModelLoader()
{
}

/**
 * Offset/Address/Size: 0xE78 | 0x80130FD0 | size: 0x450
 */
void NetMeshModelLoader::LoadGeometryFromModel()
{
}

/**
 * Offset/Address/Size: 0xC44 | 0x80130D9C | size: 0x234
 */
void NetMeshModelLoader::AddEdge(const glModelPacket&, unsigned short, unsigned short)
{
}

/**
 * Offset/Address/Size: 0xB90 | 0x80130CE8 | size: 0xB4
 */
void NetMeshModelLoader::AddTriangleFromGeometry(const glModelPacket&, unsigned short*)
{
}

/**
 * Offset/Address/Size: 0xA80 | 0x80130BD8 | size: 0x110
 */
void NetMeshModelLoader::ReadEdgesFromGeometryPacket(const glModelPacket&)
{
}

/**
 * Offset/Address/Size: 0x780 | 0x801308D8 | size: 0x300
 */
void NetMeshModelLoader::ProcessEdges(const glModelPacket&, int)
{
}

/**
 * Offset/Address/Size: 0x0 | 0x80130158 | size: 0x780
 */
void NetMeshModelLoader::CreateNetMeshFromVertexList()
{
}
