#ifndef _GLVIEW_H_
#define _GLVIEW_H_

#include "NL/nlMath.h"
#include "NL/gl/gl.h"

#include "NL/gl/glModel.h"

struct glRenderList
{
    /* 0x00 */ u32 m_unk_0x00;
    /* 0x00 */ eGLViewSort m_unk_0x04;
};

struct glView
{
    /* 0x00 */ u32 m_unk_0x00;
    /* 0x04 */ u8 m_padding_0x04[0x10];
    /* 0x14 */ nlMatrix4* m_unk_0x14;
    /* 0x18 */ nlMatrix4* m_unk_0x18;
    /* 0x1C */ eGLTarget m_target;
    /* 0x20 */ nlMatrix4 m_viewMatrix;
    /* 0x60 */ nlMatrix4 m_projectionMatrix;
    /* 0xA0 */ u8 m_padding_0xA0[0x40];
    /* 0xE0 */ bool m_unk_0xE0;
    // /* 0xE1 */ bool m_unk_0xE1; // unused, because of alignment?
    // /* 0xE2 */ bool m_unk_0xE2; // unused, because of alignment?
    // /* 0xE3 */ bool m_unk_0xE3; // unused, because of alignment?
    /* 0xE4 */ eGLFilter m_filter;
    /* 0xE8 */ eGLTarget m_filterSource;
    /* 0xEC */ bool m_unk_0xEC;
    /* 0xED */ bool m_depthClear;
    /* 0xEE */ bool m_unk_0xEE;
    /* 0xEF */ bool m_unk_0xEF;
    /* 0xF0 */ glRenderList* renderList;
};

bool glViewSetEnable(eGLView, bool);
bool glViewGetEnable(eGLView);
eGLTarget glViewSetFilterSource(eGLView, eGLTarget);
eGLFilter glViewGetFilter(eGLView);
eGLFilter glViewSetFilter(eGLView, eGLFilter);
eGLTarget glViewSetTarget(eGLView, eGLTarget);
void glViewProjectPoint(eGLView, const nlVector3&, nlVector3&);
void glViewGetProjectionMatrix(eGLView, nlMatrix4&);
void glViewGetViewMatrix(eGLView, nlMatrix4&);
nlMatrix4* glViewSetProjectionMatrix(eGLView, unsigned long);
nlMatrix4* glViewGetProjectionMatrix(eGLView);
nlMatrix4* glViewSetViewMatrix(eGLView, unsigned long);
nlMatrix4* glViewGetViewMatrix(eGLView);
eGLViewSort glViewSetSortMode(eGLView, eGLViewSort);
bool glViewSetDepthClear(eGLView, bool);
bool glViewGetDepthClear(eGLView);
void gl_ViewStartup();
void gl_ViewIterate(eGLView, void (*)(eGLView, unsigned long, const glModelPacket*));
void glViewCompact();
void gl_ViewReset();
void glViewAttachPacket(eGLView, const glModelPacket*);
void glViewAttachModel(eGLView, const glModel*);
void glViewAttachModel(eGLView, unsigned long, const glModel*);
glRenderList* gl_ViewGetRenderList(eGLView);

#endif // _GLVIEW_H_
