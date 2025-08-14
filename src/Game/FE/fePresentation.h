#ifndef _FEPRESENTATION_H_
#define _FEPRESENTATION_H_

class TLSlide;

class FEPresentation
{
public:
    void Update(float);
    void SetActiveSlide(TLSlide*);
    void SetActiveSlide(unsigned long);
    void SetActiveSlide(const char*);
};

#endif // _FEPRESENTATION_H_
