#ifndef _NLPRINT_H_
#define _NLPRINT_H_

#include <stdarg.h>

void nlVSNPrintf(char*, unsigned long, const char*, __va_list*);
void nlSNPrintf(char*, unsigned long, const char*, ...);

#endif // _NLPRINT_H_
