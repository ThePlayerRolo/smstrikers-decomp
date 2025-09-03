#ifndef _OVERLAYHANDLERHUD_H_
#define _OVERLAYHANDLERHUD_H_

#include "Game/FE/feAsyncImage.h"
#include "Game/FE/feTextureResource.h"
#include "Game/FE/feNSNMessenger.h"
#include "Game/FE/feRender.h"
#include "Game/FE/tlTextInstance.h"


class HUDOverlay : public BaseOverlayHandler
{
public:
    HUDOverlay();
    virtual ~HUDOverlay();
    virtual void Update(float);
    virtual void SceneCreated();
    void SetSlideIn();
    void SetSlideOut();
    void LoadHUDTextures();
    void DisplayPowerUps();
    void SetTeamIcons();
    void UpdateScore();
    void DisplayNewScore();
    void ResetScores();
    void SwapPowerUps(int);

    TLImageInstance* m_pImagePowerUps[2][2][2]; // offset 0x28, size 0x20
    TLImageInstance* m_pImageFlares[2][2][2]; // offset 0x48, size 0x20
    TLComponentInstance* m_pComponentFlares[2][2]; // offset 0x68, size 0x10
    TLComponentInstance* mSuddenDeath[2]; // offset 0x78, size 0x8
    TLComponentInstance* m_pPowerupTextComponents[2][2][2]; // offset 0x80, size 0x20
    int mNumFlareCycles[2][2]; // offset 0xA0, size 0x10
    FETextureResource* m_pStar; // offset 0xB0, size 0x4
    FETextureResource* m_pShellGreen; // offset 0xB4, size 0x4
    FETextureResource* m_pShellRed; // offset 0xB8, size 0x4
    FETextureResource* m_pBanana; // offset 0xBC, size 0x4
    FETextureResource* m_pMushroom; // offset 0xC0, size 0x4
    FETextureResource* m_pShellBlue; // offset 0xC4, size 0x4
    FETextureResource* m_pBobomb; // offset 0xC8, size 0x4
    FETextureResource* m_pShellSpike; // offset 0xCC, size 0x4
    FETextureResource* m_pChomp; // offset 0xD0, size 0x4
    u32 mSeconds; // offset 0xD4, size 0x4
    u32 mMinutes; // offset 0xD8, size 0x4
    u32 mTenths; // offset 0xDC, size 0x4
    TLTextInstance* m_pTextInstanceClock[2]; // offset 0xE0, size 0x8
    u16 mClockBuffer[32]; // offset 0xE8, size 0x40
    bool mClockColourChanged; // offset 0x128, size 0x1
    bool mOvertimeSFXPlayed; // offset 0x129, size 0x1
    bool mIsHUDSlideIn; // offset 0x12A, size 0x1
    bool mStartScoreAnimation; // offset 0x12B, size 0x1
    nlColour mOriginalClockColour; // offset 0x12C, size 0x4
    int mScore[2]; // offset 0x130, size 0x8
    int mNewScore[2]; // offset 0x138, size 0x8
    u16 mScoreBuffer[2][32]; // offset 0x140, size 0x80
    TLTextInstance* m_pTextInstanceScore[2][2]; // offset 0x1C0, size 0x10
    AsyncImage* mAsyncImage[2]; // offset 0x1D0, size 0x8
    float mScoreUpdateDelay[2]; // offset 0x1D8, size 0x8
};


/*class FEFinder<TLImageInstance, 2>
{
public:
    void _Find<FEPresentation>(FEPresentation*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
    void Find<FEPresentation>(FEPresentation*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
    void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
    void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
    void Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
};


class FEFinder<TLComponentInstance, 4>
{
public:
    void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
    void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
    void _Find<FEPresentation>(FEPresentation*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
    void Find<FEPresentation>(FEPresentation*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
};


class FEFinder<TLTextInstance, 3>
{
public:
    void _Find<FEPresentation>(FEPresentation*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
    void Find<FEPresentation>(FEPresentation*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
    void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
    void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
    void Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
};
*/

/*
class PowerupAcquireEventData
{
public:
    void GetID();
};*/

/*
class Format<BasicString<unsigned short, Detail
{
public:
    void TempStringAllocator>, unsigned short[8], unsigned short[8]>(const BasicString<unsigned short, Detail::TempStringAllocator>&, const unsigned short(&)[8], const unsigned short(&)[8]);
};


class FormatImpl<BasicString<unsigned short, Detail
{
public:
    void TempStringAllocator>>::operator%<const unsigned short*>(const unsigned short* const&);
};
*/

#endif // _OVERLAYHANDLERHUD_H_
