#ifndef _SIMPLEPARSER_H_
#define _SIMPLEPARSER_H_

#include "types.h"

class SimpleParser
{
public:
    SimpleParser();
    bool StartParsing(char*, int, bool);
    char* NextToken(bool);
    char* NextTokenOnLine(bool);
    void AdvanceLine();

    char mTokenBuf[5][256];     // [0x000..0x4FF]
    char* mPos;                 // [0x500] current position within line (token cursor)
    char* mLineEnd;             // [0x504] current line end sentinel (points at '\n' or scan head)
    int mBytesRemain;           // [0x508] bytes left from mLineEnd to end of buffer
    int mTokIndex;              // [0x50C] rotating token buffer index 0..4
    unsigned char mSplitSpaces; // [0x510] 1 => treat ' ' as whitespace; 0 => keep spaces in tokens
};

#endif // _SIMPLEPARSER_H_
