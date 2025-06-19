#ifndef _GLCONSTANT_H_
#define _GLCONSTANT_H_

#include "NL/nlMath.h"

void glConstantGet(const char*);
void glConstantGet(const char*, nlVector4&);
void glConstantSet(const char*, const nlVector4&);
void gl_ConstantMarkerBackup(int);
void gl_ConstantMarkerAdvance();
void gl_ConstantStartup();

// class AVLTreeBase<unsigned long, nlVector4, NewAdapter<AVLTreeEntry<unsigned long, nlVector4>>, DefaultKeyCompare<unsigned long>>
// {
// public:
//     void DeleteEntry(AVLTreeEntry<unsigned long, nlVector4>*);
//     void Clear();
//     void DestroyTree(void (AVLTreeBase<unsigned long, nlVector4, NewAdapter<AVLTreeEntry<unsigned long, nlVector4>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long, nlVector4>*));
//     void PostorderTraversal(AVLTreeEntry<unsigned long, nlVector4>*, void (AVLTreeBase<unsigned long, nlVector4, NewAdapter<AVLTreeEntry<unsigned long, nlVector4>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long, nlVector4>*));
//     void CastUp(AVLTreeNode*) const;
//     void CompareNodes(AVLTreeNode*, AVLTreeNode*);
//     void CompareKey(void*, AVLTreeNode*);
//     void AllocateEntry(void*, void*);
// };

#endif // _GLCONSTANT_H_
