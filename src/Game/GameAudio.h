#ifndef _GAMEAUDIO_H_
#define _GAMEAUDIO_H_

// void TrackedSFXPriorityCallback(SFXPlaySet*, unsigned long, cGameSFX*);
// void TrackedSFXFilterFreqTypeCheckCallback(unsigned long, cGameSFX*);
// void TrackedSFXPitchFreqTypeCheckCallback(unsigned long, cGameSFX*);
// void nlDLRingIsEnd<DLListEntry<SFXPlaySet*>>(DLListEntry<SFXPlaySet*>*, DLListEntry<SFXPlaySet*>*);
// void nlDLRingGetStart<DLListEntry<SFXPlaySet*>>(DLListEntry<SFXPlaySet*>*);
// void nlDLRingRemove<DLListEntry<SFXPlaySet*>>(DLListEntry<SFXPlaySet*>**, DLListEntry<SFXPlaySet*>*);
// void nlDLRingAddStart<DLListEntry<SFXPlaySet*>>(DLListEntry<SFXPlaySet*>**, DLListEntry<SFXPlaySet*>*);

class cGameSFX
{
public:
    enum StopFlag
    {
        StopFlag_0 = 0,
        StopFlag_1, // Immediate?
    };

    // void UpdateAllTrackedSFX(float);
    void StopPlayingAllTrackedSFX();
    // void StopTrackedSFX(nlDLListIterator<SFXPlaySet*>*);
    // void StopTrackedSFX(SFXPlaySet*);
    // void StopEmitter(SFXEmitter*, unsigned long);
    // void Stop(unsigned long, cGameSFX::StopFlag);
    // void KeepTrack(SFXEmitter*, const Audio::SoundAttributes&, unsigned long);
    // void Play(Audio::SoundAttributes&);
    // void SetPitchBendOnAllDialogueSFX(unsigned short);
    // void SetFilterFreqOnAllTrackedSFX(unsigned short);
    // void ActivateFilterOnAllTrackedSFX(bool);
    // void IsKeepingTrackOf(unsigned long, SFXPlaySet**);
    // void GetSFXVolReverb(unsigned long) const;
    // void GetSFXVol(unsigned long) const;
    // void SetSFX(SoundPropAccessor*);
    void ShutdownPlaySet();
    void DeInit();
    void Init();
    ~cGameSFX();
    cGameSFX();
};


// class DLListContainerBase<SFXPlaySet*, NewAdapter<DLListEntry<SFXPlaySet*>>>
// {
// public:
//     void DeleteEntry(DLListEntry<SFXPlaySet*>*);
// };


// class nlWalkDLRing<DLListEntry<SFXPlaySet*>, DLListContainerBase<SFXPlaySet*, NewAdapter<DLListEntry<SFXPlaySet*>>>>(DLListEntry<SFXPlaySet*>*, DLListContainerBase<SFXPlaySet*, NewAdapter<DLListEntry<SFXPlaySet*>>>*, void (DLListContainerBase<SFXPlaySet*, NewAdapter<DLListEntry<SFXPlaySet*>>>
// {
// public:
//     void *)(DLListEntry<SFXPlaySet*>*));
// };


// class nlWalkRing<DLListEntry<SFXPlaySet*>, DLListContainerBase<SFXPlaySet*, NewAdapter<DLListEntry<SFXPlaySet*>>>>(DLListEntry<SFXPlaySet*>*, DLListContainerBase<SFXPlaySet*, NewAdapter<DLListEntry<SFXPlaySet*>>>*, void (DLListContainerBase<SFXPlaySet*, NewAdapter<DLListEntry<SFXPlaySet*>>>
// {
// public:
//     void *)(DLListEntry<SFXPlaySet*>*));
// };


// class SlotPool<SFXPlaySet>
// {
// public:
//     void ~SlotPool();
// };

#endif // _GAMEAUDIO_H_
