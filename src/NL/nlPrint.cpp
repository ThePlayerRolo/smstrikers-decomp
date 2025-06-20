#include "NL/nlPrint.h"

#include "printf.h"

/**
 * Offset/Address/Size: 0x0 | 0x801D22F8 | size: 0x48
 */
int nlVSNPrintf(char* s, unsigned long n, const char* format, va_list arg)
{
    return vsnprintf(s, n, format, arg);
}

/**
 * Offset/Address/Size: 0x48 | 0x801D2340 | size: 0xB8
 */
void nlSNPrintf(char*, unsigned long, const char*, ...)
{
}
