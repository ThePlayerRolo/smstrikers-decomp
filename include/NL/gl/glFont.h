#ifndef _GLFONT_H_
#define _GLFONT_H_

#include "NL/nlColour.h"
#include "NL/gl/glView.h"

bool glFontPrintf(eGLView, int, int, const nlColour&, const char*, ...);
bool glFontPrintf(eGLView, int, int, const char*, ...);
bool glFontPrint(eGLView, int, int, const nlColour&, const char*);
void glFontEnd();
void glFontBegin(bool);
void glFontVirtualPosToScreenCoordPos(float, float, float&, float&);
void gl_FontStartup();

#endif // _GLFONT_H_
