#include "Field.h"

cNet* cField::mpNet = nullptr;

nlVector3_ cField::mv3FieldPosition = { 20.60211f, 12.0825f, 0.0f };
nlVector3_ cField::mSidelines[4] = { { 1.0f, 0.0f, 0.0f }, { -1.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, -1.0f, 0.0f } };
// float cField::mCorners[16] = {
//     0.0f,  0.0f, 0.000000000000000000000000000000000000000022959f, 3.0f, 0.0f, 0.0f, 2.0078125f, 3.0f, 0.0f, 0.0f, 0.0f, 3.0f, 0.0f,
//     0.0f, -2.0f, 3.0f
// };
Corner cField::mCorners = {
    0.0f,  0.0f, 0.000000000000000000000000000000000000000022959f, 3.0f, 0.0f, 0.0f, 2.0078125f, 3.0f, 0.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f,
    -2.0f, 3.0f
};
float cField::mfPenaltyBoxX = 13.5f;
float cField::mfPenaltyBoxY = 4.5f;

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
void cField::GetGoalLineX(unsigned int side)
{
    // nlVector4 v3(1.0f, 2.0f, 3.0f, 4.0f);
    // nlVector4 v4 = v3;
    // if (side == 0)
    // {
    //     v4.x -= v4.x;
    // }
    // else
    // {
    //     v4.x += v4.x;
    // }
    // mv3FieldPosition = v4;
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
void cField::IsOnField(const nlVector3& location)
{
}

/**
 * Offset/Address/Size: 0x2C | 0x80019110 | size: 0x90
 */
void cField::FixOutOfBoundsPosition(nlVector3& location, float arg0)
{
    location = *(nlVector3*)&mv3FieldPosition;
}

/**
 * Offset/Address/Size: 0x0 | 0x800190E4 | size: 0x2C
 */
void cField::SetFieldDimensions(float, float, float)
{
}
