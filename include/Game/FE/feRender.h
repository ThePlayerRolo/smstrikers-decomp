#ifndef _FERENDER_H_
#define _FERENDER_H_

// void ConvertColour(nlColour&, const nlFloatColour&);
// void 0x8028D570..0x8028D574 | size: 0x4;

class TLImageInstance;
class TLTextInstance;
class FEScene;
class FEPresentation;
class TLComponentInstance;
class TLSlide;
class TLInstance;

class FERender
{
public:
    void RenderImageInstance(const TLImageInstance*);
    void RenderTextInstance(TLTextInstance*);
    void RenderScene(FEScene*);
    void RenderPresentation(const FEPresentation*);
    void RenderComponentInstance(TLComponentInstance*);
    void RenderSlide(const TLSlide*);
    void RenderTimeLineAsset(TLInstance*, float);
    void PopTransformMatrix();
    void PushTransformMatrix(const TLInstance*);
    void Initialize();
    void Cleanup();
    void CalculateCurrentAssetColour(const TLInstance*);
};

// class nlFloatColour
// {
// public:
//     void operator=(const nlFloatColour&);
// };

// class TLInstance
// {
// public:
//     void GetType() const;
//     void IsVisible() const;
//     void GetLibRefObject() const;
// };

// class TLComponent
// {
// public:
//     void GetActiveSlide();
// };

// class FEScene
// {
// public:
//     void GetRenderView() const;
//     void GetCameraMatrix() const;
// };

// class TLTextInstance
// {
// public:
//     void SetMatrix(nlMatrix4*);
// };

// class nlMatrix4
// {
// public:
//     void SetTranslation(const nlVector3&);
// };

// class feVector3
// {
// public:
//     void GetNLVector3(nlVector3&) const;
// };

// class TLSlide
// {
// public:
//     void GetCurrentTime() const;
// };

#endif // _FERENDER_H_
