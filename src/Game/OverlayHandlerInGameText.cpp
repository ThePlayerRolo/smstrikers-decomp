#include "Game/OverlayHandlerInGameText.h"
#include "Game/BaseSceneHandler.h"
#include "Game/FE/FEPresentation.h"
#include "Game/FE/tlSlide.h"
#include "Game/OverlayManager.h"
#include "NL/nlSingleton.h"
#include "NL/nlTask.h"
#include "Game/FE/feInput.h"


/**
 * Offset/Address/Size: 0xBC | 0x800FC998 | size: 0x208
 */
/*
void BasicString<unsigned short, Detail::TempStringAllocator>::AppendInPlace<Detail::TempStringAllocator>(const BasicString<unsigned short, Detail::TempStringAllocator>&)
{
}
*/
/**
 * Offset/Address/Size: 0x0 | 0x800FC8DC | size: 0xBC
 */
//void BasicString<unsigned short, Detail::TempStringAllocator>::Append<Detail::TempStringAllocator>(const BasicString<unsigned short, Detail::TempStringAllocator>&) const
//{
//}

/**
 * Offset/Address/Size: 0x678 | 0x800FC780 | size: 0x15C
 */
//void FEFinder<TLTextInstance, 3>::_Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long)
//{
//}

/**
 * Offset/Address/Size: 0x5F4 | 0x800FC6FC | size: 0x84
 */
//void FEFinder<TLTextInstance, 3>::_Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long)
//{
//}

/**
 * Offset/Address/Size: 0x570 | 0x800FC678 | size: 0x84
 */
//void FEFinder<TLTextInstance, 3>::_Find<FEPresentation>(FEPresentation*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long)
//{
//}

/**
 * Offset/Address/Size: 0x538 | 0x800FC640 | size: 0x38
 */
//void FEFinder<TLTextInstance, 3>::Find<FEPresentation>(FEPresentation*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher)
//{
//}

/**
 * Offset/Address/Size: 0x3DC | 0x800FC4E4 | size: 0x15C
 */
//void FEFinder<TLInstance, 3>::_Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long)
//{
//}

/**
 * Offset/Address/Size: 0x358 | 0x800FC460 | size: 0x84
 */
//void FEFinder<TLInstance, 3>::_Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long)
//{
//}

/**
 * Offset/Address/Size: 0x2D4 | 0x800FC3DC | size: 0x84
 */
//void FEFinder<TLInstance, 3>::_Find<FEPresentation>(FEPresentation*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long)
//{
//}

/**
 * Offset/Address/Size: 0x29C | 0x800FC3A4 | size: 0x38
 */
//void FEFinder<TLInstance, 3>::Find<FEPresentation>(FEPresentation*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher)
//{
//}

/**
 * Offset/Address/Size: 0x140 | 0x800FC248 | size: 0x15C
 */
//void FEFinder<TLComponentInstance, 4>::_Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long)
//{
//}

/**
 * Offset/Address/Size: 0xBC | 0x800FC1C4 | size: 0x84
 */
//void FEFinder<TLComponentInstance, 4>::_Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long)
//{
//}

/**
 * Offset/Address/Size: 0x38 | 0x800FC140 | size: 0x84
 */
//void FEFinder<TLComponentInstance, 4>::_Find<FEPresentation>(FEPresentation*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long)
//{
//}

/**
 * Offset/Address/Size: 0x0 | 0x800FC108 | size: 0x38
 */
//void FEFinder<TLComponentInstance, 4>::Find<FEPresentation>(FEPresentation*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher)
//{
//}

/**
 * Offset/Address/Size: 0x0 | 0x800FC098 | size: 0x70
 */
 /*
void StatsTracker::Track(ePlayerStats, int, int, int, int, int, int)
{
}*/

/**
 * Offset/Address/Size: 0xF44 | 0x800FBFF0 | size: 0xA8
 */
InGameTextOverlay::InGameTextOverlay()
{
    mCurrentSlideName = SLIDE_NAME_INVALID;
    mPendingSlideName = SLIDE_NAME_INVALID;
    this->SetVisible(true);
}

/**
 * Offset/Address/Size: 0xED8 | 0x800FBF84 | size: 0x6C
 */
InGameTextOverlay::~InGameTextOverlay()
{
}

/**
 * Offset/Address/Size: 0xE1C | 0x800FBEC8 | size: 0xBC
 */
void InGameTextOverlay::SetSlide(OverlaySlideName slideName)
{
    this->mPendingSlideName = slideName;
    if (this->mCurrentSlideName != this->mPendingSlideName) {
        this->m_pFEScene->m_package->GetPresentation()->SetActiveSlide(IGTTable[this->mPendingSlideName].mSlideName);
        TLSlide* CurrentSlide = this->m_pFEScene->m_package->GetPresentation()->m_currentSlide;
        if (CurrentSlide != NULL) {
            CurrentSlide->m_time = 0.0f;
            CurrentSlide->m_start = 0.0f;
            CurrentSlide->Update(0.0f);
        }
        if (mCurrentSlideName != SLIDE_NAME_INVALID) {
            this->m_pFEScene->m_package->GetPresentation()->SetActiveSlide(IGTTable[mCurrentSlideName].mSlideName);
        }
    }
}

/**
 * Offset/Address/Size: 0xCB0 | 0x800FBD5C | size: 0x16C
 */
void InGameTextOverlay::Update(float fDeltaT)
{
    BaseSceneHandler::Update(fDeltaT);
    if (this->mCurrentSlideName != this->mPendingSlideName) {
        this->mCurrentSlideName = this->mPendingSlideName;
        this->m_pFEScene->m_package->GetPresentation()->SetActiveSlide(IGTTable[this->mCurrentSlideName].mSlideName);
        this->mVisibilityMask = IGTTable[this->mCurrentSlideName].mTaskVisibility;
        if (this->mVisibilityMask & nlTaskManager::m_pInstance->m_unk_0x08) {
            if (mWasLastVisible) {
                this->SetVisible(true);
            }
        }
        else {
            mWasLastVisible = m_bVisible;
            this->SetVisible(false);
        }

        switch (this->mCurrentSlideName) {
            case SLIDE_NAME_TEXT_WINNER:
                DisplayFinalScore();
                break;
        } //TODO: Fill in DisplayFinalScore();
    }
    if (this->mCurrentSlideName == SLIDE_NAME_TEXT_WINNER && g_pFEInput->JustPressed(FE_ALL_PADS, 0x100, false, NULL) && m_bVisible) {
        nlSingleton<OverlayManager>::s_pInstance->SetVisible(OVERLAY_TEXT, false, false);
        BaseSceneHandler* handler = nlSingleton<OverlayManager>::s_pInstance->Push(OVERLAY_SUMMARY, SCREEN_NOTHING, false);
        handler->m_bVisible = true;  //TODO: Big Offset      
    }
}

/**
 * Offset/Address/Size: 0xCAC | 0x800FBD58 | size: 0x4
 */
void InGameTextOverlay::SceneCreated()
{
}

/**
 * Offset/Address/Size: 0x0 | 0x800FB0AC | size: 0xCAC
 */
void InGameTextOverlay::DisplayFinalScore()
{
    
}
