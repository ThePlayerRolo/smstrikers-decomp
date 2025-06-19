#include "NL/globalpad.h"
#include "NL/nlMath.h"


// s32 cPadManager::m_pRemapArray[] = {1<<0, 1<<1, 1<<2, 1<<3, 1<<4, 1<<5, 1<<6, 1<<7, 1<<8, 1<<9, 1<<10, 1<<11};

s32* cPadManager::m_pRemapArray = nullptr;

/**
 * Offset/Address/Size: 0x0 | 0x801F00E4 | size: 0x70
 */
void cPadManager::Update(float deltaTime)
{
    for (int i=0; i<PAD_MAX_CONTROLLERS; i++)
    {
        m_aPads[i]->Update(deltaTime);
    }
    m_DeltaT = deltaTime;    
}

/**
 * Offset/Address/Size: 0x70 | 0x801F0154 | size: 0x14
 */
cGlobalPad* cPadManager::GetPad(int i)
{
    return (cGlobalPad*)&(m_aPads[i]);
}

/**
 * Offset/Address/Size: 0x84 | 0x801F0168 | size: 0x2C
 */
void cGlobalPad::JustReleased(int button, bool remap)
{
    this->PlatJustReleased(button, remap);
}

/**
 * Offset/Address/Size: 0xB0 | 0x801F0194 | size: 0x2C
 */
void cGlobalPad::JustPressed(int button, bool remap)
{
    this->PlatJustPressed(button, remap);
}

/**
 * Offset/Address/Size: 0xDC | 0x801F01C0 | size: 0x13C
 */
void cGlobalPad::Update(float)
{
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f30;
    f32 temp_f31;

    temp_f30 = this->AnalogLeftX();
    temp_f1 = this->AnalogLeftY();
    m_unk_0x0C = nlSqrt((temp_f30 * temp_f30) + (temp_f1 * temp_f1), 1);

    if ((0.f != temp_f30) || (0.f != temp_f1)) {
        m_unk_0x08 = (s16) (10430.378f * nlATan2f(temp_f1, temp_f30));
    }

    temp_f31 = this->AnalogRightX();
    temp_f1_2 = this->AnalogRightY();
    m_unk_0x14 = nlSqrt((temp_f31 * temp_f31) + (temp_f1_2 * temp_f1_2), 1);
    if ((0.f != temp_f31) || (0.f != temp_f1_2)) {
        m_unk_0x10 = (s16) (10430.378f* nlATan2f(temp_f1_2, temp_f31));
    }    
}
