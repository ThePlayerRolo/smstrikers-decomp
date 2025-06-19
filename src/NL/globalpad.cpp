#include "NL/globalpad.h"

// s32 cPadManager::m_pRemapArray[] = {1<<0, 1<<1, 1<<2, 1<<3, 1<<4, 1<<5, 1<<6, 1<<7, 1<<8, 1<<9, 1<<10, 1<<11};

s32* cPadManager::m_pRemapArray = nullptr;

/**
 * Offset/Address/Size: 0x0 | 0x801F00E4 | size: 0x70
 */
void cPadManager::Update(float)
{
}

/**
 * Offset/Address/Size: 0x70 | 0x801F0154 | size: 0x14
 */
void cPadManager::GetPad(int)
{
}

/**
 * Offset/Address/Size: 0x84 | 0x801F0168 | size: 0x2C
 */
void cGlobalPad::JustReleased(int, bool)
{
}

/**
 * Offset/Address/Size: 0xB0 | 0x801F0194 | size: 0x2C
 */
void cGlobalPad::JustPressed(int, bool)
{
}

/**
 * Offset/Address/Size: 0xDC | 0x801F01C0 | size: 0x13C
 */
void cGlobalPad::Update(float)
{
}
