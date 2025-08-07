#ifndef _INTERPRETERCORE_H_
#define _INTERPRETERCORE_H_

#include "types.h"
#include "NL/nlBSearch.h"

struct FunctionEntryPoint {
    /* 0x00 */ u32 key;      // 0x00
    /* 0x04 */ u32 size;    // 0x04
    /* 0x08 */ u8 pad[0x0c];   
    /* 0x14 */ FunctionEntryPoint *next;
};

class InterpreterCore
{
public:
    InterpreterCore(unsigned int stackSize);
    virtual ~InterpreterCore();

    void LoadByteCode(void* byteCode);
    void CallFunction(unsigned long id);
    void CallFunctionAt(unsigned long address);
    bool FunctionExists(unsigned long id);
    virtual void Run();
    void StopWithUndo();
    void Step();
    bool IsFinished() const;

    /* 0x04 */ char      m_pad_0x04[4];
    /* 0x08 */ void*     m_unk_0x08;
    /* 0x0C */ s32*      m_unk_0x0C;
    /* 0x10 */ u8*       m_unk_0x10;
    /* 0x14 */ s32*      m_unk_0x14;
    /* 0x18 */ s32*      m_unk_0x18;
    /* 0x1C */ s32*      m_unk_0x1C;
    /* 0x20 */ u8        m_unk_0x20;
};

#endif // _INTERPRETERCORE_H_
