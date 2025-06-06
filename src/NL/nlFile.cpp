#include "NL/nlFile.h"

/**
 * Offset/Address/Size: 0x0 | 0x801CEA30 | size: 0xF8
 */
void nlLoadEntireFileAsync(const char*, LoadAsyncCallback, void*, unsigned int, eAllocType type)
{
}

/**
 * Offset/Address/Size: 0xF8 | 0x801CEB28 | size: 0x68
 */
void nlLoadEntireFileAsyncCallback(nlFile*, void*, unsigned int, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x160 | 0x801CEB90 | size: 0xDC
 */
void nlLoadEntireFile(const char*, unsigned long*, unsigned int, eAllocType type)
{
}

/**
 * Offset/Address/Size: 0x23C | 0x801CEC6C | size: 0x38
 */
void nlClose(nlFile*)
{
}

/**
 * Offset/Address/Size: 0x274 | 0x801CECA4 | size: 0x2C
 */
void nlRead(nlFile*, void*, unsigned int)
{
}

/**
 * Offset/Address/Size: 0x2A0 | 0x801CECD0 | size: 0x2C
 */
void nlFileSize(nlFile*, unsigned int*)
{
}

/**
 * Offset/Address/Size: 0x2CC | 0x801CECFC | size: 0x48
 */
nlFile::~nlFile()
{
}

/**
 * Offset/Address/Size: 0x314 | 0x801CED44 | size: 0x10
 */
nlFile::nlFile()
{
}
