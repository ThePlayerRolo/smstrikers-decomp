#ifndef _GLUSKINMESH_H_
#define _GLUSKINMESH_H_

#include "NL/nlMath.h"
#include "NL/nlDLRing.h"

// void nlRingIsEnd<SkinPairList>(SkinPairList*, SkinPairList*);
// void nlRingGetStart<SkinPairList>(SkinPairList*);
// void nlRingGetStart<BoneMapList>(BoneMapList*);

class ShaderSkinMesh
{
public:
    void StitchModel();
    void AttachSkinData(unsigned long, const nlMatrix4*);
};

class TempMatrixCopier
{
public:
    void CopyMatrix(const unsigned long&, unsigned long*);
};

// class AVLTreeBase<unsigned long, unsigned long, NewAdapter<AVLTreeEntry<unsigned long, unsigned long>>, DefaultKeyCompare<unsigned long>>
// {
// public:
//     void CastUp(AVLTreeNode*) const;
//     void InorderWalk<TempMatrixCopier>(AVLTreeEntry<unsigned long, unsigned long>*, TempMatrixCopier*, void (TempMatrixCopier::*)(const
//     unsigned long&, unsigned long*)); void Walk<TempMatrixCopier>(TempMatrixCopier*, void (TempMatrixCopier::*)(const unsigned long&,
//     unsigned long*));
// };

#endif // _GLUSKINMESH_H_
