#ifndef _FENSNMESSENGER_H_
#define _FENSNMESSENGER_H_

// void 0x800A1F08..0x800A1F0C | size: 0x4;
// void 0x802A9938..0x802A99C0 | size: 0x88;

class NSNMessengerScene
{
public:
    void EnableScrolling(bool);
    void IsMessengerOpen() const;
    void CloseMessengerNow();
    void CloseMessenger();
    void SetDisplayMessage(const char*);
    // void SetDisplayMessage(const BasicString<unsigned short, Detail::TempStringAllocator>&);
    void ForceMessengerVisibleNow();
    void OpenMessengerNow();
    void OpenMessenger();
    void Update(float);
    void SceneCreated();
    ~NSNMessengerScene();
    NSNMessengerScene();
    // void @4@SceneCreated();
    // void @4@Update(float);
};

// class BaseSceneHandler
// {
// public:
//     void SceneCreated();
// };

// class FEFinder<TLTextInstance, 3>
// {
// public:
//     void Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
//     void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void Find<FEPresentation>(FEPresentation*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
//     void _Find<FEPresentation>(FEPresentation*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned
//     long);
// };

// class BaseOverlayHandler
// {
// public:
//     ~BaseOverlayHandler();
// };

#endif // _FENSNMESSENGER_H_
