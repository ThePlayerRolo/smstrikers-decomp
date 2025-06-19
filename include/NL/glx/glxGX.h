#ifndef _GLXGX_H_
#define _GLXGX_H_

#include "Dolphin/gx/GXEnum.h"
#include "NL/nlColour.h"

void gxSetCoPlanar(bool);
void gxSetChanAmbColour(int, const nlColour&);
void gxSetChanMatColour(int, const nlColour&);
void gxSetTexCoordGen(int, _GXTexGenType, _GXTexGenSrc, unsigned long);
void gxSetTevAlphaOp(int, _GXTevOp, _GXTevBias, _GXTevScale, bool, _GXTevRegID);
void gxSetTevColourOp(int, _GXTevOp, _GXTevBias, _GXTevScale, bool, _GXTevRegID);
void gxSetNumTexGens(unsigned long);
void gxSetNumTevStages(unsigned long);
void gxSetNumChans(unsigned long);
void gxSetCullMode(_GXCullMode);
void gxSetBlendMode(bool, _GXBlendFactor, _GXBlendFactor, bool);
void gxSetAlphaCompare(_GXCompare, unsigned char);
void gxRestoreZMode();
void gxSaveZMode();
void gxSetZMode(bool, _GXCompare, bool);
void gxSetZCompLoc(bool);
void gxSetAlphaUpdate(bool);
void gxSetColourUpdate(bool);
void gxSetDither(bool);
void gxSetTevAlphaIn(int, int, _GXTevAlphaArg);
void gxSetTevAlphaIn(int, _GXTevAlphaArg, _GXTevAlphaArg, _GXTevAlphaArg, _GXTevAlphaArg);
void gxInit();

#endif // _GLXGX_H_
