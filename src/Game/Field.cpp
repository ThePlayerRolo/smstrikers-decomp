#include "Field.h"

/**
 * Offset/Address/Size: 0x1CC | 0x800192B0 | size: 0x28
 */
void cField::Init(cNet*, cNet*)
{
}

/**
 * Offset/Address/Size: 0x1A4 | 0x80019288 | size: 0x28
 */
void cField::GetGoalLineX(float)
{
}

/**
 * Offset/Address/Size: 0x180 | 0x80019264 | size: 0x24
 */
void cField::GetGoalLineX(unsigned int)
{
}

/**
 * Offset/Address/Size: 0x154 | 0x80019238 | size: 0x2C
 */
void cField::GetSidelineY(unsigned int)
{
}

/**
 * Offset/Address/Size: 0x14C | 0x80019230 | size: 0x8
 */
void cField::GetCornerRadius()
{
}

/**
 * Offset/Address/Size: 0x130 | 0x80019214 | size: 0x1C
 */
void cField::GetPenaltyBoxX(unsigned int)
{
}

/**
 * Offset/Address/Size: 0x128 | 0x8001920C | size: 0x8
 */
void cField::GetPenaltyBoxY()
{
}

/**
 * Offset/Address/Size: 0x108 | 0x800191EC | size: 0x20
 */
void cField::GetNet(float)
{
}

/**
 * Offset/Address/Size: 0xBC | 0x800191A0 | size: 0x4C
 */
void cField::IsOnField(const nlVector3&)
{
}

/**
 * Offset/Address/Size: 0x2C | 0x80019110 | size: 0x90
 */
void cField::FixOutOfBoundsPosition(nlVector3&, float)
{
}

/**
 * Offset/Address/Size: 0x0 | 0x800190E4 | size: 0x2C
 */
void cField::SetFieldDimensions(float, float, float)
{
}
