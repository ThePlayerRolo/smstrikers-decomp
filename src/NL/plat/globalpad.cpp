#include "NL/globalpad.h"
#include "NL/nlMath.h"

cGlobalPad* cPadManager::m_aPads[PAD_MAX_CONTROLLERS];
s32* cPadManager::m_pRemapArray = nullptr;
float cPadManager::m_DeltaT = 0.0f;

/**
 * Offset/Address/Size: 0xDC | 0x801F01C0 | size: 0x13C
 */
void cGlobalPad::Update(float)
{
    float x;
    float y;

    x = this->AnalogLeftX();
    y = this->AnalogLeftY();
    m_leftStickMagnitude = nlSqrt((x * x) + (y * y), 1);

    if ((0.f != x) || (0.f != y))
    {
        m_leftStickAngle = (s16)(10430.378f * nlATan2f(y, x));
    }

    x = this->AnalogRightX();
    y = this->AnalogRightY();
    m_rightStickMagnitude = nlSqrt((x * x) + (y * y), 1);
    if ((0.f != x) || (0.f != y))
    {
        m_rightStickAngle = (s16)(10430.378f * nlATan2f(y, x));
    }
}

/**
 * Offset/Address/Size: 0xB0 | 0x801F0194 | size: 0x2C
 */
void cGlobalPad::JustPressed(int button, bool remap)
{
    this->PlatJustPressed(button, remap);
}

/**
 * Offset/Address/Size: 0x84 | 0x801F0168 | size: 0x2C
 */
void cGlobalPad::JustReleased(int button, bool remap)
{
    this->PlatJustReleased(button, remap);
}

/**
 * Offset/Address/Size: 0x70 | 0x801F0154 | size: 0x14
 */
cGlobalPad* cPadManager::GetPad(int idx)
{
    return m_aPads[idx];
}

/**
 * Offset/Address/Size: 0x0 | 0x801F00E4 | size: 0x70
 */
void cPadManager::Update(float deltaTime)
{
    for (int i = 0; i < PAD_MAX_CONTROLLERS; i++)
    {
        m_aPads[i]->Update(deltaTime);
    }
    m_DeltaT = deltaTime;
}
