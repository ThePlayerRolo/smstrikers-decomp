#ifndef _NLCONFIG_H_
#define _NLCONFIG_H_

#include "types.h"

class SetTagValuePair
{
public:
    /* 0x00 */ char* m_unk_0x00; // tag
    /* 0x04 */ u32 m_unk_0x04; // type
    /* 0x08 */ char* m_unk_0x08; // value
};


class Config
{
public:
    enum AllocateWhere
    {
        AllocateWhere_0 = 0,
        AllocateWhere_1 = 1,
    };

    // void Parse(const char*, Config::Parser&);
    void LoadFileAsString(const char*);
    // void Set(const char*, const BasicString<char, Detail::TempStringAllocator>&);
    void Set(const char*, const char*);
    void Set(const char*, float);
    void Set(const char*, bool);
    void Set(const char*, int);
    SetTagValuePair *FindTvp(const char*);
    void IsBool(const char*, bool&) const;
    void Exists(const char*) const;
    void LoadFromFile(const char*);
    static void Global();
    
    ~Config();
    Config(AllocateWhere);

    // Parser::TagValuePair(const BasicString<char, Detail::TempStringAllocator>&, const BasicString<char, Detail::TempStringAllocator>&);
    // Parser::Section(const BasicString<char, Detail::TempStringAllocator>&);
    // Parser::Comment(const BasicString<char, Detail::TempStringAllocator>&);
    // Parser::EmptyLine();
    // TagValuePair::TagValuePair();
    // Set<BasicString<char, Detail::TempStringAllocator>>(const char*, BasicString<char, Detail::TempStringAllocator>);
};


// class SetTagValuePair
// {
// public:
//     SetTagValuePair::Comment(const BasicString<char, Detail::TempStringAllocator>&);
//     SetTagValuePair::Section(const BasicString<char, Detail::TempStringAllocator>&);
//     SetTagValuePair::TagValuePair(const BasicString<char, Detail::TempStringAllocator>&, const BasicString<char, Detail::TempStringAllocator>&);
// };


// class BasicString<char, Detail
// {
// public:
//     BasicString<char, Detail::TempStringAllocator>::Trim(const char*) const;
//     BasicString<char, Detail::TempStringAllocator>::TrimInPlace(const char*);
//     BasicString<char, Detail::TempStringAllocator>::Append<Detail::TempStringAllocator>(const BasicString<char, Detail::TempStringAllocator>&) const;
//     BasicString<char, Detail::TempStringAllocator>::AppendInPlace<Detail::TempStringAllocator>(const BasicString<char, Detail::TempStringAllocator>&);
// };

#endif // _NLCONFIG_H_
