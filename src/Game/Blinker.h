#ifndef _BLINKER_H_
#define _BLINKER_H_

class glModel;
class GLMaterialList;

class Blinker
{
public:
    void Blink(glModel*);
    void Update(float);
    Blinker(const char*, unsigned long, GLMaterialList*, GLMaterialList*, unsigned long);
};

#endif // _BLINKER_H_
