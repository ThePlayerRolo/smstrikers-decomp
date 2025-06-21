#ifndef _GLFONT_H_
#define _GLFONT_H_

#include "NL/gl/glView.h"

// Forward declaration
struct nlColour;

void glFontPrintf(eGLView, int, int, const nlColour&, const char*, ...);
void glFontPrintf(eGLView, int, int, const char*, ...);
void glFontPrint(eGLView, int, int, const nlColour&, const char*);
void glFontEnd();
void glFontBegin(bool);
void glFontVirtualPosToScreenCoordPos(float, float, float&, float&);
void gl_FontStartup();
#endif // _GLFONT_H_
