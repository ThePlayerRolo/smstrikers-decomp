#include "DrawableObj.h"

nlMatrix4 m3Ident = { 1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f };

/**
 * Offset/Address/Size: 0x0 | 0x8011FC70 | size: 0x2C
 */
void DrawableObject::GetAABBDimensions(AABBDimensions& dim, bool param) const
{
    dim.unk0 = 0.f;
    dim.unk4 = 0.f;
    dim.unk8 = 0.f;
    dim.unkC = 0.f;
    dim.unk10 = 0.f;
    dim.unk14 = 0.f;
    dim.unk18 = 0.f;
    dim.unk1C = 0.f;
    dim.unk20 = 0.f;
}

/**
 * Offset/Address/Size: 0x2C | 0x8011FC9C | size: 0x90
 */
nlMatrix4* DrawableObject::GetWorldMatrix() const
{
    // f32 sp84;
    // f32 sp80;
    // f32 sp7C;
    // f32 sp78;
    // ? sp48;
    // ? sp8;
    // f32 temp_f1;

    // if ((u8) arg0->unk44 == 0) {
    //     nlQuatToMatrix__FR9nlMatrix4RC12nlQuaternion(&sp48, arg0 + 0x48);
    //     sp78 = arg0->unk58;
    //     sp7C = arg0->unk5C;
    //     sp80 = arg0->unk60;
    //     sp84 = @198;
    //     temp_f1 = arg0->unk64;
    //     nlMakeScaleMatrix__FR9nlMatrix4fff(&sp8, temp_f1, temp_f1, temp_f1);
    //     nlMultMatrices__FR9nlMatrix4RC9nlMatrix4RC9nlMatrix4(arg0 + 4, &sp8, &sp48);
    //     arg0->unk44 = 1U;
    // }
    // return arg0 + 4;

    return &m3Ident;
}

/**
 * Offset/Address/Size: 0xBC | 0x8011FD2C | size: 0x68
 */
DrawableObject::~DrawableObject()
{
    if (m_unk_0x6C != 0)
    {
        delete m_unk_0x6C;
    }
}

/**
 * Offset/Address/Size: 0x124 | 0x8011FD94 | size: 0x6C
 */
DrawableObject::DrawableObject()
{
    // arg0->unk44 = 1;
    // arg0->unk64 = (f32) @198;
    // arg0->unk6C = 0;
    // arg0->unk78 = 0;
    // arg0->unk88 = 0;
    // arg0->unk8C = 0;
    // arg0->unk94 = 0;
    // arg0->unk50 = (f32) @191;
    // arg0->unk4C = (f32) @191;
    // arg0->unk48 = (f32) @191;
    // arg0->unk54 = (f32) @198;
    // arg0->unk58 = (f32) @191;
    // arg0->unk5C = (f32) @191;
    // arg0->unk60 = (f32) @191;
    // arg0->unk68 = (f32) @198;
    // arg0->unk98 = 0;
    m_visibility = (m_visibility | 1);
}

/**
 * Offset/Address/Size: 0x0 | 0x8011FE00 | size: 0x4
 */
void DrawableObject::DrawPlanarShadow()
{
}

/**
 * Offset/Address/Size: 0x4 | 0x8011FE04 | size: 0x8
 */
bool DrawableObject::IsDrawableModel()
{
    return false;
}
