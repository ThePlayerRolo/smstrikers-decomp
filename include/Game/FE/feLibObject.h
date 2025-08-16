#ifndef _FELIBOBJECT_H_
#define _FELIBOBJECT_H_

#include "types.h"

#include "NL/nlColour.h"
#include "NL/nlMath.h"

class FELibObject
{
public:
    const nlVector3* GetScale() const;
    const nlVector3* GetRotation() const;
    const nlVector3* GetPosition() const;
    const nlColour* GetColour() const;

    /* 0x00 */ u8 pad00[0x08];
    /* 0x08 */ nlVector3 m_position;
    /* 0x14 */ nlVector3 m_rotation;
    /* 0x20 */ nlVector3 m_scale;
    /* 0x2C */ u8 pad2C[0x0D];
    /* 0x39 */ nlColour m_colour;
};

#endif // _FELIBOBJECT_H_
