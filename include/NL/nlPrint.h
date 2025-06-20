#ifndef _NLPRINT_H_
#define _NLPRINT_H_

#include <stdarg.h>

int nlVSNPrintf(char*, unsigned long, const char*, va_list arg);
void nlSNPrintf(char*, unsigned long, const char*, ...);

#endif // _NLPRINT_H_
