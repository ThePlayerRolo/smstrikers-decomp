#ifndef _NLSTRING_H_
#define _NLSTRING_H_

void nlStrToWcs(const char*, unsigned short*, unsigned long);
void nlZeroMemory(void*, unsigned long);
void nlStringLowerHash(const char*);
void nlStringHash(const char*);
// nlToLower<unsigned char>(unsigned char);
void nlToLower(unsigned char);

#endif // _NLSTRING_H_
