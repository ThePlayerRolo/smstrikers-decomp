#ifndef _FELIBOBJECT_H_
#define _FELIBOBJECT_H_

class FELibObject
{
public:
    void GetScale() const;
    void GetRotation() const;
    void GetPosition() const;
    void GetColour() const;

    // /* 0x00 */ char pad0[8];
    // /* 0x08 */ ? unk8;                              /* inferred */
    // /* 0x08 */ char pad8[0xC];
    // /* 0x14 */ ? unk14;                             /* inferred */
    // /* 0x14 */ char pad14[0xC];
    // /* 0x20 */ ? unk20;                             /* inferred */
    // /* 0x20 */ char pad20[0x19];
    // /* 0x39 */ ? unk39;                             /* inferred */
    // /* 0x39 */ char pad39[1];
};

#endif // _FELIBOBJECT_H_
