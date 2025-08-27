#include "Game/Sys/FloatingPointExceptions.h"

/**
 * Offset/Address/Size: 0x38 | 0x801ACCCC | size: 0x198
 */
void FloatingPointErrorHandler(unsigned short, OSContext*, unsigned long, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x0 | 0x801ACC94 | size: 0x38
 */
void InstallFloatingPointExceptionHandler()
{
}
