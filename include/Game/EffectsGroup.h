#ifndef _EFFECTSGROUP_H_
#define _EFFECTSGROUP_H_

// #include "Game/Sys/SimpleParser.h"

class EffectsGroup;

EffectsGroup* fxGetGroup(const char*);
void fxUnloadGroups();
void fxLoadGroupBundle(void*, unsigned long);
void fxLoadGroupBundle(const char*);

// void parse_group(SimpleParser*);
// void parse_terrain_spec(SimpleParser*);
// void parse_spec(SimpleParser*, EffectsSpec&);

// void nlDLRingCountElements<DLListEntry<UserEffectSpec*>>(DLListEntry<UserEffectSpec*>*);
// void nlDLRingIsEnd<DLListEntry<UserEffectSpec*>>(DLListEntry<UserEffectSpec*>*, DLListEntry<UserEffectSpec*>*);
// void nlDLRingGetStart<DLListEntry<UserEffectSpec*>>(DLListEntry<UserEffectSpec*>*);
// void nlDLRingAddEnd<DLListEntry<UserEffectSpec*>>(DLListEntry<UserEffectSpec*>**, DLListEntry<UserEffectSpec*>*);
// void nlDLRingAddStart<DLListEntry<UserEffectSpec*>>(DLListEntry<UserEffectSpec*>**, DLListEntry<UserEffectSpec*>*);
// void nlRingCountElements<DLListEntry<UserEffectSpec*>>(DLListEntry<UserEffectSpec*>*);

// class nlAVLTree<unsigned long, EffectsTerrainSpec*, DefaultKeyCompare<unsigned long>>
// {
// public:
//     void ~nlAVLTree();
// };

// class EffectsSpec
// {
// public:
//     EffectsSpec();
// };

// class EffectsTerrainSpec
// {
// public:
//     void HasTerrain(unsigned long) const;
// };

// class AVLTreeBase<unsigned long, EffectsGroup*, NewAdapter<AVLTreeEntry<unsigned long, EffectsGroup*>>, DefaultKeyCompare<unsigned long>>
// {
// public:
//     void AllocateEntry(void*, void*);
//     void CompareKey(void*, AVLTreeNode*);
//     void CompareNodes(AVLTreeNode*, AVLTreeNode*);
//     void DeleteValues();
//     void CastUp(AVLTreeNode*) const;
//     void PostorderTraversal(AVLTreeEntry<unsigned long, EffectsGroup*>*, void (AVLTreeBase<unsigned long, EffectsGroup*,
//     NewAdapter<AVLTreeEntry<unsigned long, EffectsGroup*>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long,
//     EffectsGroup*>*)); void DestroyTree(void (AVLTreeBase<unsigned long, EffectsGroup*, NewAdapter<AVLTreeEntry<unsigned long,
//     EffectsGroup*>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long, EffectsGroup*>*)); void Clear(); void
//     ~AVLTreeBase(); void DeleteEntry(AVLTreeEntry<unsigned long, EffectsGroup*>*); void DeleteValue(AVLTreeEntry<unsigned long,
//     EffectsGroup*>*);
// };

// class AVLTreeBase<unsigned long, EffectsTerrainSpec*, NewAdapter<AVLTreeEntry<unsigned long, EffectsTerrainSpec*>>,
// DefaultKeyCompare<unsigned long>>
// {
// public:
//     void AllocateEntry(void*, void*);
//     void CompareKey(void*, AVLTreeNode*);
//     void CompareNodes(AVLTreeNode*, AVLTreeNode*);
//     void DeleteValues();
//     void CastUp(AVLTreeNode*) const;
//     void PostorderTraversal(AVLTreeEntry<unsigned long, EffectsTerrainSpec*>*, void (AVLTreeBase<unsigned long, EffectsTerrainSpec*,
//     NewAdapter<AVLTreeEntry<unsigned long, EffectsTerrainSpec*>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long,
//     EffectsTerrainSpec*>*)); void DestroyTree(void (AVLTreeBase<unsigned long, EffectsTerrainSpec*, NewAdapter<AVLTreeEntry<unsigned
//     long, EffectsTerrainSpec*>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long, EffectsTerrainSpec*>*)); void Clear();
//     void ~AVLTreeBase();
//     void DeleteEntry(AVLTreeEntry<unsigned long, EffectsTerrainSpec*>*);
//     void DeleteValue(AVLTreeEntry<unsigned long, EffectsTerrainSpec*>*);
// };

// class nlAVLTree<unsigned long, EffectsGroup*, DefaultKeyCompare<unsigned long>>
// {
// public:
//     void ~nlAVLTree();
// };

// class NewAdapter<AVLTreeEntry<unsigned long, EffectsGroup*>>
// {
// public:
//     void Delete(AVLTreeEntry<unsigned long, EffectsGroup*>*);
// };

// class NewAdapter<AVLTreeEntry<unsigned long, EffectsTerrainSpec*>>
// {
// public:
//     void Delete(AVLTreeEntry<unsigned long, EffectsTerrainSpec*>*);
// };

// class DLListContainerBase<UserEffectSpec*, NewAdapter<DLListEntry<UserEffectSpec*>>>
// {
// public:
//     void DeleteEntry(DLListEntry<UserEffectSpec*>*);
// };

// class nlWalkDLRing<DLListEntry<UserEffectSpec*>, DLListContainerBase<UserEffectSpec*,
// NewAdapter<DLListEntry<UserEffectSpec*>>>>(DLListEntry<UserEffectSpec*>*, DLListContainerBase<UserEffectSpec*,
// NewAdapter<DLListEntry<UserEffectSpec*>>>*, void (DLListContainerBase<UserEffectSpec*, NewAdapter<DLListEntry<UserEffectSpec*>>>
// {
// public:
//     void *)(DLListEntry<UserEffectSpec*>*));
// };

// class nlWalkRing<DLListEntry<UserEffectSpec*>, DLListContainerBase<UserEffectSpec*,
// NewAdapter<DLListEntry<UserEffectSpec*>>>>(DLListEntry<UserEffectSpec*>*, DLListContainerBase<UserEffectSpec*,
// NewAdapter<DLListEntry<UserEffectSpec*>>>*, void (DLListContainerBase<UserEffectSpec*, NewAdapter<DLListEntry<UserEffectSpec*>>>
// {
// public:
//     void *)(DLListEntry<UserEffectSpec*>*));
// };

#endif // _EFFECTSGROUP_H_
