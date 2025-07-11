#ifndef _GLXTEXTURE_H_
#define _GLXTEXTURE_H_

#include "Dolphin/gx/GXEnum.h"

enum eGXTextureFormat
{
    eGXTextureFormat_0,
};

enum eGLTextureType
{
    eGLTextureType_0,
};

enum eGLTextureState
{
    eGLTextureState_0 = 0,
};

enum eGLTextureFormatType
{
    eGLTextureFormatType_0,
};

class glTexBundleDict;
class GXTextureHeader;
class PlatTexture;

void glplatTextureReplace(unsigned long, const void*, unsigned long);
void glplatTextureAdd(unsigned long, const void*, unsigned long);
void glx_CreatePlatTexture();
void glplatTextureGetNumBits(int);
u32 glplatTextureGetHeight();
u32 glplatTextureGetWidth();
void glplatTextureLoad(unsigned long);
void glplatEndLoadTextureBundle(void*, unsigned long);
void glplatBeginLoadTextureBundle(const char*, void (*)(void*, unsigned long, void*), void*);
void glxParseTextureBundle(const char*);
void glplatLoadTextureBundle(const char*);
void BundleSortProc(const glTexBundleDict*, const glTexBundleDict*);
void glx_MakeTexture(GXTextureHeader*, unsigned long);
void glx_AddTex(unsigned long, PlatTexture*);
void* glx_GetTex(unsigned long, bool, bool);
void glx_GetGridTexture(int, int);
void glx_MakeGridTexture(int, int);
void glx_SetGridMode(bool);
void glxInitTex();
void glx_BackupTexMarkerLevel(int);
void glx_AdvanceTexMarkerLevel();
void glx_GetTexMarkerLevel();
void glx_SetLoadCallback(unsigned long (*)(unsigned long));
// void nlQSort<glTexBundleDict>(glTexBundleDict*, int, int (*)(const glTexBundleDict*, const glTexBundleDict*));
// void nlListAddStart<ListEntry<PlatTexture*>>(ListEntry<PlatTexture*>**, ListEntry<PlatTexture*>*, ListEntry<PlatTexture*>**);

class PlatTexture
{
public:
    void Prepare();
    void Swizzle(bool);
    void Create(int, int, eGXTextureFormat, int, bool, bool);
    void CreateWithMemory(int, int, eGXTextureFormat, int, const void*);
    ~PlatTexture();
};


class TexDestructor
{
public:
    void CallDestructor(const unsigned long&, PlatTexture**);
};


// class AVLTreeBase<unsigned long, PlatTexture*, NewAdapter<AVLTreeEntry<unsigned long, PlatTexture*>>, DefaultKeyCompare<unsigned long>>
// {
// public:
//     void DeleteEntry(AVLTreeEntry<unsigned long, PlatTexture*>*);
//     void Clear();
//     void DestroyTree(void (AVLTreeBase<unsigned long, PlatTexture*, NewAdapter<AVLTreeEntry<unsigned long, PlatTexture*>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long, PlatTexture*>*));
//     void PostorderTraversal(AVLTreeEntry<unsigned long, PlatTexture*>*, void (AVLTreeBase<unsigned long, PlatTexture*, NewAdapter<AVLTreeEntry<unsigned long, PlatTexture*>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long, PlatTexture*>*));
//     void CastUp(AVLTreeNode*) const;
//     void Walk<TexDestructor>(TexDestructor*, void (TexDestructor::*)(const unsigned long&, PlatTexture**));
//     void InorderWalk<TexDestructor>(AVLTreeEntry<unsigned long, PlatTexture*>*, TexDestructor*, void (TexDestructor::*)(const unsigned long&, PlatTexture**));
//     void CompareNodes(AVLTreeNode*, AVLTreeNode*);
//     void CompareKey(void*, AVLTreeNode*);
//     void AllocateEntry(void*, void*);
// };


// class nlWalkList<ListEntry<PlatTexture*>, ListContainerBase<PlatTexture*, NewAdapter<ListEntry<PlatTexture*>>>>(ListEntry<PlatTexture*>*, ListContainerBase<PlatTexture*, NewAdapter<ListEntry<PlatTexture*>>>*, void (ListContainerBase<PlatTexture*, NewAdapter<ListEntry<PlatTexture*>>>
// {
// public:
//     void *)(ListEntry<PlatTexture*>*));
// };


// class ListContainerBase<PlatTexture*, NewAdapter<ListEntry<PlatTexture*>>>
// {
// public:
//     void DeleteEntry(ListEntry<PlatTexture*>*);
// };


// class nlListContainer<PlatTexture*>
// {
// public:
//     void ~nlListContainer();
// };

#endif // _GLXTEXTURE_H_
