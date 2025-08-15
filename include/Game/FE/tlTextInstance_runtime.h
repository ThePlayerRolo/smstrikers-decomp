#ifndef _TLTEXTINSTANCE_RUNTIME_H_
#define _TLTEXTINSTANCE_RUNTIME_H_

#include "types.h"

#include "NL/nlColour.h"
#include "NL/gl/gl.h"

class TLTextInstance
{
public:
    void SetScissorBox(unsigned short, unsigned short, unsigned short, unsigned short);
    void SetString(const unsigned short*);
    void Render(eGLView, const nlColour&) const;
    void GetString() const;
};

#endif // _TLTEXTINSTANCE_RUNTIME_H_
