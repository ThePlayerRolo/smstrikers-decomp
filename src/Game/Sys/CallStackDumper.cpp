#include "Game/Sys/CallStackDumper.h"

#include "Dolphin/os/OSError.h"

/**
 * Offset/Address/Size: 0x2C | 0x801ACE90 | size: 0xB08
 */
// void ErrorHandler(unsigned short error, OSContext* context, ...)
void ErrorHandler(unsigned short, OSContext*, unsigned long, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x0 | 0x801ACE64 | size: 0x2C
 */
void InstallCallStackDumper()
{
    OSSetErrorHandler((unsigned short)OS_ERROR_DSI, (OSErrorHandler)ErrorHandler);
}
