#ifndef _SHIERARCHY_H_
#define _SHIERARCHY_H_

class nlChunk;

class cSHierarchy
{
public:
    void PreserveBoneLength(int) const;
    void GetTranslationOffset(int) const;
    void GetParent(int) const;
    void GetPushPop(int) const;
    void GetMirroredNode(int) const;
    void GetNumChildren(int) const;
    void GetNodeID(int) const;
    void GetNodeIndexByID(unsigned int) const;
    void GetChild(int, int) const;
    void BuildPushPopFlags(int, int, int&);
    void Initialize(nlChunk*);
};

#endif // _SHIERARCHY_H_
