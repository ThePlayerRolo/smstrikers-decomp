#ifndef _FESCROLLINGTICKER_H_
#define _FESCROLLINGTICKER_H_

// void 0x800A0DCC..0x800A1304 | size: 0x538;
// void 0x802A9880..0x802A9938 | size: 0xB8;

class ScrollingTickerScene
{
public:
    void IsMessengerOpen() const;
    void CloseMessengerNow();
    void CloseMessenger();
    void OpenMessengerNow();
    void OpenMessenger();
    void Update(float);
    // void SetDisplayMessage(const BasicString<unsigned short, Detail::TempStringAllocator>&);
    void SceneCreated();
    ~ScrollingTickerScene();
    ScrollingTickerScene();
    void tickerClosed(void*);
    void tickerOpened(void*);
    void setScaleTweenCallback(void*, const float*);
    void setSizeTweenCallback(void*, const float*);
    // void @4@SceneCreated();
    // void @4@Update(float);
};

// class FEFinder<TLInstance, 3>
// {
// public:
//     void Find<FEPresentation>(FEPresentation*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
//     void _Find<FEPresentation>(FEPresentation*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned
//     long); void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long); void
//     _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
// };

// class FEFinder<TLInstance, 2>
// {
// public:
//     void Find<FEPresentation>(FEPresentation*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
//     void _Find<FEPresentation>(FEPresentation*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned
//     long); void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long); void
//     _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
// };

#endif // _FESCROLLINGTICKER_H_
