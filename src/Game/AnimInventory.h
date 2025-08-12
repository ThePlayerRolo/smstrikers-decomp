#ifndef _ANIMINVENTORY_H_
#define _ANIMINVENTORY_H_

// void nlPrintf(const char*, ...);
// void nlListRemoveStart<ListEntry<char*>>(ListEntry<char*>**, ListEntry<char*>**);
// void nlListAddStart<ListEntry<cSAnim*>>(ListEntry<cSAnim*>**, ListEntry<cSAnim*>*, ListEntry<cSAnim*>**);
// void nlListAddStart<ListEntry<char*>>(ListEntry<char*>**, ListEntry<char*>*, ListEntry<char*>**);

struct AnimProperties
{
    /* 0x0 */ char* name;
    /* 0x4 */ char* name2;
    /* 0x8 */ char* name3;
};

class cAnimInventory
{
public:
    void GetMatchCharacterSpeed(int);
    void GetEndPhase(int);
    void GetBallRotationMode(int);
    void GetMirrored(int);
    void GetBlendTime(int);
    void GetPlayMode(int);
    void GetAnim(int);
    void AddAnimBundle(const char*);
    ~cAnimInventory();
    cAnimInventory(const AnimProperties*, int);
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
