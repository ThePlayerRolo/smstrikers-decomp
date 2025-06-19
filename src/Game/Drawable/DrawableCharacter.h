#ifndef _DRAWABLECHARACTER_H_
#define _DRAWABLECHARACTER_H_

#include "DrawableObj.h"

// void FindBoundingSphereAccurate(nlVector3*, float*, int, const nlVector3*);
// void DrawableCharacterHeadTrackCallback(unsigned int, unsigned int, cPoseAccumulator*, unsigned int, int);
// void Replayable<1>(LoadFrame&, char, cPoseNode*&);
// void Replayable<1>(SaveFrame&, char, cPoseNode*&);
// void Replayable<0>(SaveFrame&, char, cPoseNode*&);
// void Replayable<0>(LoadFrame&, char, cPoseNode*&);
// void ReplayablePolymorphic<1, LoadFrame, cPoseNode>(LoadFrame&, cPoseNode*&);
// void Replayable<1, SaveFrame, unsigned char>(SaveFrame&, unsigned char&);
// void Replayable<1, SaveFrame, unsigned short>(SaveFrame&, unsigned short&);
// void Replayable<1, SaveFrame, unsigned long>(SaveFrame&, unsigned long&);
// void Replayable<1, LoadFrame, unsigned char>(LoadFrame&, unsigned char&);
// void Replayable<1, LoadFrame, unsigned short>(LoadFrame&, unsigned short&);
// void Replayable<1, LoadFrame, unsigned long>(LoadFrame&, unsigned long&);
// void ReplayablePolymorphic<1, SaveFrame, cPoseNode>(SaveFrame&, cPoseNode*&);
// void Replayable<1, SaveFrame, FloatCompressor<-128, 128, 8>>(SaveFrame&, const FloatCompressor<-128, 128, 8>&);
// void Replayable<1, SaveFrame, FloatCompressor<-512, 512, 8>>(SaveFrame&, const FloatCompressor<-512, 512, 8>&);
// void Replayable<1, LoadFrame, FloatCompressor<-128, 128, 8>>(LoadFrame&, const FloatCompressor<-128, 128, 8>&);
// void Replayable<1, LoadFrame, FloatCompressor<-512, 512, 8>>(LoadFrame&, const FloatCompressor<-512, 512, 8>&);
// void Replayable<0, LoadFrame, cPoseNode>(LoadFrame&, cPoseNode&);
// void Replayable<0, LoadFrame, unsigned int>(LoadFrame&, unsigned int&);
// void Replayable<0, SaveFrame, cPoseNode>(SaveFrame&, cPoseNode&);
// void Replayable<0, SaveFrame, unsigned int>(SaveFrame&, unsigned int&);
// void Replayable<0, LoadFrame, FloatCompressor<0, 1, 7>>(LoadFrame&, const FloatCompressor<0, 1, 7>&);
// void Replayable<0, LoadFrame, FloatCompressor<0, 1, 15>>(LoadFrame&, const FloatCompressor<0, 1, 15>&);
// void Replayable<0, SaveFrame, FloatCompressor<0, 1, 7>>(SaveFrame&, const FloatCompressor<0, 1, 7>&);
// void Replayable<0, SaveFrame, FloatCompressor<0, 1, 15>>(SaveFrame&, const FloatCompressor<0, 1, 15>&);
// void ReplayablePolymorphic<0, LoadFrame, cPoseNode>(LoadFrame&, cPoseNode*&);
// void Replayable<0, LoadFrame, int>(LoadFrame&, int&);
// void Replayable<0, SaveFrame, int>(SaveFrame&, int&);
// void ReplayablePolymorphic<0, SaveFrame, cPoseNode>(SaveFrame&, cPoseNode*&);
// void 0x8028D2C0..0x8028D2C4 | size: 0x4;

class cCharacter;
class cPoseNode;
class SkinAnimatedMovableNPC;
class SkinAnimatedMovableNPC;
class cPoseAccumulator;

class LoadFrame;
class LoadFrame;

class DrawableCharacter
{
public:
    void OnlyRenderingOneCharacter();
    void RenderAllCharacters();
    void RenderOnlyOneCharacter(const cCharacter&, bool);
    void GetBallOrientation() const;
    void GetBallPosition() const;
    void EvaluateFrom(const cPoseNode&, const nlVector3&, unsigned short);
    void Blend(const float*, const DrawableCharacter&, const DrawableCharacter&);
    void Render(SkinAnimatedMovableNPC&) const;
    void Grab(SkinAnimatedMovableNPC&);
    void SendToGl(const cCharacter&) const;
    void Render(cCharacter&) const;
    void BuildNodeMatrices();
    void DrawableBowserHeadTrackCallback(unsigned int, unsigned int, cPoseAccumulator*, unsigned int, int);
    void Grab(cCharacter&);
    void GetAnimController() const;
    void Free();
    ~DrawableCharacter();
    DrawableCharacter();
    // void Replay<LoadFrame>(LoadFrame&);
    // void Replay<SaveFrame>(SaveFrame&);
};


// class cPoseAccumulator
// {
// public:
//     void operator=(const cPoseAccumulator&);
//     cPoseAccumulator(const cPoseAccumulator&);
// };


// class cBuildNodeMatrixCallbackInfo
// {
// public:
//     cBuildNodeMatrixCallbackInfo();
// };


// class SkinAnimatedMovableNPC
// {
// public:
//     void GetHeadTilt() const;
//     void GetHeadSpin() const;
// };


// class SkinAnimatedNPC
// {
// public:
//     void GetSkinAnimatedNPC_Type() const;
// };


// class LoadFrame
// {
// public:
//     void ReplayablePolymorphicPtr<1, cPoseNode>(cPoseNode*&);
//     void ReplayablePolymorphicPtr<0, cPoseNode>(cPoseNode*&);
// };


// class cPN_SingleAxisBlender
// {
// public:
//     void Replay<LoadFrame>(LoadFrame&);
//     void Replay<SaveFrame>(SaveFrame&);
// };


// class cPN_SAnimController
// {
// public:
//     void Replay<LoadFrame>(LoadFrame&);
//     void Replay<SaveFrame>(SaveFrame&);
// };


// class cPN_Feather
// {
// public:
//     void Replay<LoadFrame>(LoadFrame&);
//     void Replay<SaveFrame>(SaveFrame&);
// };


// class cPN_Blender
// {
// public:
//     void Replay<LoadFrame>(LoadFrame&);
//     void Replay<SaveFrame>(SaveFrame&);
// };


// class FloatCompressor<0, 1, 15>
// {
// public:
//     void FloatCompressor(float&);
// };


// class FloatCompressor<0, 1, 7>
// {
// public:
//     void FloatCompressor(float&);
// };

#endif // _DRAWABLECHARACTER_H_
