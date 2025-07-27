#ifndef _SHIERARCHY_H_
#define _SHIERARCHY_H_

#include "../../include/types.h"

class nlChunk;

class cSHierarchy
{
private:
    /* 0x00 */ void *m_unk_0x00;                    /* inferred */
    /* 0x04 */ char m_pad_0x04[4];
    /* 0x08 */ s32 m_unk_0x08;                      /* inferred */
    /* 0x0C */ u32 *m_unk_0x0C;                     /* inferred */
    /* 0x10 */ void *m_unk_0x10;                    /* inferred */
    /* 0x14 */ void *m_unk_0x14;                    /* inferred */
    /* 0x18 */ void *m_unk_0x18;                    /* inferred */
    /* 0x1C */ void *m_unk_0x1C;                    /* inferred */
    /* 0x20 */ void *m_unk_0x20;                    /* inferred */
    /* 0x24 */ char m_pad_0x24[8];                  /* maybe part of unk20[3]? */
    /* 0x2C */ void *m_unk_0x2C;                    /* inferred */
    /* 0x30 */ void *m_unk_0x30;                    /* inferred */

public:
    u32 PreserveBoneLength(int) const;
    void* GetTranslationOffset(int) const;
    s32 GetParent(int) const;
    s32 GetPushPop(int) const;
    s32 GetMirroredNode(int) const;
    s32 GetNumChildren(int) const;
    u32 GetNodeID(int) const;
    s32 GetNodeIndexByID(unsigned int) const;
    s32 GetChild(int, int) const;
    void BuildPushPopFlags(int, int, int&);
    cSHierarchy* Initialize(nlChunk*);
};

#endif // _SHIERARCHY_H_
