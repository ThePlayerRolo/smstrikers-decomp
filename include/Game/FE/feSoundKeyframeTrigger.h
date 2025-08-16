#ifndef _FESOUNDKEYFRAMETRIGGER_H_
#define _FESOUNDKEYFRAMETRIGGER_H_

class TLSlide;

class SoundKeyframeTrigger
{
public:
    void Update(float, float);

    /*0x00*/ TLSlide* m_slide; // first word is the slide pointer
};

#endif // _FESOUNDKEYFRAMETRIGGER_H_
