#ifndef _FIELD_H_
#define _FIELD_H_

#include "NL/nlMath.h"
#include "Net.h"

class cField
{
public:
    void Init(cNet*, cNet*);
    static void GetGoalLineX(float);
    static void GetGoalLineX(unsigned int);
    void GetSidelineY(unsigned int);
    void GetCornerRadius();
    void GetPenaltyBoxX(unsigned int);
    void GetPenaltyBoxY();
    void GetNet(float);
    void IsOnField(const nlVector3&);
    void FixOutOfBoundsPosition(nlVector3&, float);
    void SetFieldDimensions(float, float, float);

    /* 0x00 */ f32 m_unk_0x00;
    /* 0x04 */ cNet* m_unk_0x04;
    /* 0x08 */ f32 m_unk_0x08;
    /* 0x0C */ char padC[4];
    /* 0x10 */ f32 m_unk_0x10;
    /* 0x14 */ f32 m_unk_0x14;
    /* 0x18 */ char pad18[8]; /* maybe part of unk14[3]? */
    /* 0x20 */ f32 m_unk_0x20;
    /* 0x24 */ f32 m_unk_0x24;
    /* 0x28 */ char pad28[4];
    /* 0x2C */ f32 m_unk_0x2C;
    /* 0x30 */ f32 m_unk_0x30;
    /* 0x34 */ f32 m_unk_0x34;
};

#endif // _FIELD_H_
