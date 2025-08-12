#ifndef _ANIMINVENTORY_H_
#define _ANIMINVENTORY_H_

#include "types.h"
#include "NL/nlDLRing.h"

// void nlPrintf(const char*, ...);
class cSAnim;

struct SAnimContainer
{
    /* 0x00 */ void* unused0;
    /* 0x04 */ DLListEntry<cSAnim*>* animHead;
    /* 0x08 */ DLListEntry<cSAnim*>* animTail;
    /* 0x0C */ void* unused0C;
    /* 0x10 */ DLListEntry<char*>* fileHead;
    /* 0x14 */ DLListEntry<char*>* fileTail;
    /* 0x18 */ int animCount;
};

struct AnimProperties
{
    /* 0x00 */ const char* name0;
    /* 0x04 */ const char* name;
    /* 0x08 */ int playMode;
    /* 0x0C */ float blendTime;
    /* 0x10 */ u8 mirrored;
    /* 0x11 */ u8 pad11[3];
    /* 0x14 */ int ballRotMode;
    /* 0x18 */ int endPhase;
    /* 0x1C */ u8 matchCharSpd;
    /* 0x1D */ u8 pad1d[3];
};

class cAnimInventory
{
public:
    cAnimInventory(const AnimProperties* props, int count);
    ~cAnimInventory();

    // bundle ingest and lookups
    void AddAnimBundle(const char* bundlePath);
    cSAnim* GetAnim(int i);
    int GetPlayMode(int i);
    float GetBlendTime(int i);
    bool GetMirrored(int i);
    int GetBallRotationMode(int i);
    int GetEndPhase(int i);
    u8 GetMatchCharacterSpeed(int i);

private:
    /* 0x00 */ int m_count;
    /* 0x04 */ SAnimContainer* m_cont;
    /* 0x08 */ cSAnim** m_anims;
    /* 0x0C */ const AnimProperties* m_props;
};

// class ListContainerBase<cSAnim*, NewAdapter<ListEntry<cSAnim*>>>
// {
// public:
//     void DeleteEntry(ListEntry<cSAnim*>*);
// };

// class ListContainerBase<char*, NewAdapter<ListEntry<char*>>>
// {
// public:
//     void DeleteEntry(ListEntry<char*>*);
// };

// class nlWalkList<ListEntry<char*>, ListContainerBase<char*, NewAdapter<ListEntry<char*>>>>(ListEntry<char*>*, ListContainerBase<char*,
// NewAdapter<ListEntry<char*>>>*, void (ListContainerBase<char*, NewAdapter<ListEntry<char*>>>
// {
// public:
//     void *)(ListEntry<char*>*));
// };

// class nlWalkList<ListEntry<cSAnim*>, ListContainerBase<cSAnim*, NewAdapter<ListEntry<cSAnim*>>>>(ListEntry<cSAnim*>*,
// ListContainerBase<cSAnim*, NewAdapter<ListEntry<cSAnim*>>>*, void (ListContainerBase<cSAnim*, NewAdapter<ListEntry<cSAnim*>>>
// {
// public:
//     void *)(ListEntry<cSAnim*>*));
// };

#endif // _ANIMINVENTORY_H_
