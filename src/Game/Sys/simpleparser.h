#ifndef _SIMPLEPARSER_H_
#define _SIMPLEPARSER_H_

#include "types.h"

class SimpleParser
{
public:
    void AdvanceLine();
    char* NextTokenOnLine(bool);
    char* NextToken(bool);
    bool StartParsing(char*, int, bool);
    SimpleParser();
};

#endif // _SIMPLEPARSER_H_
