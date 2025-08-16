#ifndef _TLCOMPONENTINSTANCE_H_
#define _TLCOMPONENTINSTANCE_H_

#include "types.h"

// #include "Game/FE/tlComponent.h"
#include "Game/FE/tlInstance.h"
#include "Game/FE/tlSlide.h"

class TLComponentInstance : public TLInstance
{
public:
    void GetActiveSlide();
    void SetActiveSlide(TLSlide*);
    void SetActiveSlide(unsigned long);
    void SetActiveSlide(const char*);
    void Update(float);

    // /* 0x00 */ u8 pad0[0x0C];
    // /* 0x0C */ TLComponent* m_component; // owner
    // /* 0x10 */ char pad10[0x6E];
    // /* 0x7E */ u8 m_enableSoundTriggers;
    // /* 0x7F */ u8 pad7F;
    /* 0x80 */ f32 m_time; // local time
};

#endif // _TLCOMPONENTINSTANCE_H_
