#ifndef _NLTEXTBOX_H_
#define _NLTEXTBOX_H_

#include "NL/nlMath.h"
#include "NL/nlFont.h"
// #include "NL/nlColour.h"
#include "NL/gl/gl.h"

struct nlColour;
class FontCharString;

class nlTextBox
{
public:
    typedef struct {
        // todo..
    } StringDrawInfo;

    typedef struct {
        // todo..
    } FontCharString;

    void DrawString(const nlTextBox::StringDrawInfo&, const nlVector2&, const nlColour&, eGLView view);
    void ProcessString(const FontCharString*, const nlFont*, const nlVector2&, unsigned long, const nlMatrix4*, nlTextBox::StringDrawInfo&);
};

#endif // _NLTEXTBOX_H_
