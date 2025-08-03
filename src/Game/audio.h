#ifndef _AUDIO_H_
#define _AUDIO_H_

// void ReadVolGroupSettings();
// void nlDeleteList<FadeAudioData>(FadeAudioData**);
// void nlListRemoveElement<FadeAudioData>(FadeAudioData**, FadeAudioData*, FadeAudioData**);
// void nlListAddStart<FadeAudioData>(FadeAudioData**, FadeAudioData*, FadeAudioData**);

namespace Audio 
{
    // void MasterVolume::GetVoiceVolume();
    // void MasterVolume::SetVoiceVolume(float, int);
    // void MasterVolume::SetVolume(Audio::MasterVolume::VOLUME_GROUP, float);
    // void MasterVolume::GetVolume(Audio::MasterVolume::VOLUME_GROUP);
    // void FadeFilterFromCurrentToZero();
    // void FadeFilterToFullStrength();
    // void PitchBend(float, float, float, float);
    // void FadeFilter(float, float, float, float);
    // void ClearFadeData();
    // void IsEmitterActive(SFXEmitter*);
    // void GetEmitterVoiceID(SFXEmitter*);
    // void Remove3DSFXEmitter(SFXEmitter*);
    // void Add3DSFXEmitter(const EmitterStartInfo&);
    // void GetFreeEmitter(unsigned long&);
    // void GetEmitter(unsigned long);
    // void SetListenerActive(bool);
    // void IsListenerActive();
    // void SetOutputMode(MusyXOutputType);
    // void SetPitchBendOnSFX(unsigned long, unsigned short);
    // void SetFilterFreqOnSFX(unsigned long, unsigned short);
    // void ActivateFilterOnSFX(unsigned long, bool);
    // void SetPitchBendOnAllDialogueSFX(unsigned short);
    // void ActivateFilterOnAllCurrentSFX(bool);
    // void SetVolGroupVolume(int, float, int);
    // void SetSFXVolumeGroup(unsigned long, int);
    // void SetSFXVolume(unsigned long, float);
    // void Update3DSFXEmitters();
    // void UpdateFades(float);
    // void Update(float);
    // void GetSndIDError();
    // void IsSFXPlaying(unsigned long);
    // void StopSFX(unsigned long);
    // void PlaySFXEventFromScript(const SoundEventData&, const char*, float, float);
    // void StopCharSFXbyStr(const char*, NisCharacterClass);
    // void StopWorldSFXbyStr(const char*);
    // void PlayCharSFXbyStr(const char*, NisCharacterClass, float, float, bool, bool, const nlVector3*, const nlVector3*, unsigned long*);
    // void PlayWorldSFXbyStr(const char*, float, float, bool, bool, const nlVector3*, const nlVector3*, unsigned long*);
    // void RemoveDelayedSFX(unsigned long);
    // void IsDelayedCharSFX(unsigned long, cGameSFX*);
    // void AddDelayedSFX(const Audio::SoundAttributes&, unsigned long, float, float, cGameSFX*);
    // void PlaySFXbyID(const Audio::SoundAttributes&, unsigned long, float, float, int);
    // void PlaySFX(const SFXStartInfo&);
    // void GetAudioTimer();
    // void Shutdown();
    // void Silence();
    // void ResetForNewGame();
    // void ResetPauseStatus();
    // void UnloadWorldSFX();
    // void IsWorldSFXLoaded();
    // void LoadWorldSFX();
    // void UnloadInGameSFX();
    // void LoadInGameSFX();
    bool IsInited();
    // void ShutdownReverb();
    // void InitializeReverb(eStadiumID, unsigned char);
    // void Initialize(bool);
    // void SoundAttributes::UseStationaryPosVector(const nlVector3&);
    // void SoundAttributes::UseVectors(const nlVector3&, const nlVector3&);
    // void SoundAttributes::UseVectorPtrs(const nlVector3*, const nlVector3*);
    // void SoundAttributes::UsePhysObj(PhysicsObject*);
    // void SoundAttributes::SetSoundType(unsigned long, bool);
    // void SoundAttributes::Init();
    // void CreateTrackMgr<3>();
};


// class cGameSFX
// {
// public:
//     void GetClassType() const;
// };


// class nlBSearch<nlSortedSlot<AudioStreamTrack
// {
// public:
//     void StreamTrack, 3>::EntryLookup<AudioStreamTrack::StreamTrack>, unsigned long>(const unsigned long&, nlSortedSlot<AudioStreamTrack::StreamTrack, 3>::EntryLookup<AudioStreamTrack::StreamTrack>*, int);
// };


// class nlWalkDLRing<DLListEntry<AudioStreamTrack
// {
// public:
//     void TrackManagerBase::FadeManager::STREAM_FADE_CTRL>, DLListContainerBase<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, BasicSlotPool<DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>>>>(DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*, DLListContainerBase<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, BasicSlotPool<DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>>>*, void (DLListContainerBase<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, BasicSlotPool<DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>>>::*)(DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*));
//     void StreamTrack::QUEUED_STREAM>, DLListContainerBase<AudioStreamTrack::StreamTrack::QUEUED_STREAM, nlStaticArrayAllocator<DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>, 4>>>(DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>*, DLListContainerBase<AudioStreamTrack::StreamTrack::QUEUED_STREAM, nlStaticArrayAllocator<DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>, 4>>*, void (DLListContainerBase<AudioStreamTrack::StreamTrack::QUEUED_STREAM, nlStaticArrayAllocator<DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>, 4>>::*)(DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>*));
//     void TrackManagerBase::FadeManager::STREAM_FADE_CTRL>, WalkHelper<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>, AudioStreamTrack::TrackManagerBase::FadeManager>>(DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*, WalkHelper<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>, AudioStreamTrack::TrackManagerBase::FadeManager>*, void (WalkHelper<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>, AudioStreamTrack::TrackManagerBase::FadeManager>::*)(DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*));
// };


// class nlWalkDLRing<DLListEntry<GCAudioStreaming
// {
// public:
//     void StereoAudioStream*>, DLListContainerBase<GCAudioStreaming::StereoAudioStream*, BasicSlotPool<DLListEntry<GCAudioStreaming::StereoAudioStream*>>>>(DLListEntry<GCAudioStreaming::StereoAudioStream*>*, DLListContainerBase<GCAudioStreaming::StereoAudioStream*, BasicSlotPool<DLListEntry<GCAudioStreaming::StereoAudioStream*>>>*, void (DLListContainerBase<GCAudioStreaming::StereoAudioStream*, BasicSlotPool<DLListEntry<GCAudioStreaming::StereoAudioStream*>>>::*)(DLListEntry<GCAudioStreaming::StereoAudioStream*>*));
// };


// class nlDLRingIsEnd<DLListEntry<AudioStreamTrack
// {
// public:
//     void TrackManagerBase::FadeManager::STREAM_FADE_CTRL>>(DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*, DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*);
// };


// class nlDLRingGetStart<DLListEntry<AudioStreamTrack
// {
// public:
//     void StreamTrack::QUEUED_STREAM>>(DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>*);
//     void TrackManagerBase::FadeManager::STREAM_FADE_CTRL>>(DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*);
// };


// class AudioStreamTrack
// {
// public:
//     void TrackManagerBase::~TrackManagerBase();
//     void TrackManager<3>::~TrackManager();
//     void TrackManager<3>::OnMasterVolumeChange(Audio::MasterVolume::VOLUME_GROUP);
//     void TrackManager<3>::GetTrack(unsigned long);
//     void TrackManager<3>::StopAllTracks(unsigned long);
//     void TrackManager<3>::Update(float);
//     void TrackManager<3>::DestroyAllTracks();
//     void TrackManager<3>::CreateTrack(const char*, Audio::MasterVolume::VOLUME_GROUP);
// };


// class nlStaticSortedSlot<AudioStreamTrack
// {
// public:
//     void StreamTrack, 3>::ExpandLookup();
//     void StreamTrack, 3>::FreeLookup();
//     void StreamTrack, 3>::FreeEntry(AudioStreamTrack::StreamTrack*);
//     void StreamTrack, 3>::GetNewEntry();
// };


// class nlWalkRing<DLListEntry<GCAudioStreaming
// {
// public:
//     void StereoAudioStream*>, DLListContainerBase<GCAudioStreaming::StereoAudioStream*, BasicSlotPool<DLListEntry<GCAudioStreaming::StereoAudioStream*>>>>(DLListEntry<GCAudioStreaming::StereoAudioStream*>*, DLListContainerBase<GCAudioStreaming::StereoAudioStream*, BasicSlotPool<DLListEntry<GCAudioStreaming::StereoAudioStream*>>>*, void (DLListContainerBase<GCAudioStreaming::StereoAudioStream*, BasicSlotPool<DLListEntry<GCAudioStreaming::StereoAudioStream*>>>::*)(DLListEntry<GCAudioStreaming::StereoAudioStream*>*));
// };


// class nlWalkRing<DLListEntry<AudioStreamTrack
// {
// public:
//     void TrackManagerBase::FadeManager::STREAM_FADE_CTRL>, DLListContainerBase<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, BasicSlotPool<DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>>>>(DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*, DLListContainerBase<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, BasicSlotPool<DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>>>*, void (DLListContainerBase<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, BasicSlotPool<DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>>>::*)(DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*));
//     void TrackManagerBase::FadeManager::STREAM_FADE_CTRL>, WalkHelper<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>, AudioStreamTrack::TrackManagerBase::FadeManager>>(DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*, WalkHelper<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>, AudioStreamTrack::TrackManagerBase::FadeManager>*, void (WalkHelper<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>, AudioStreamTrack::TrackManagerBase::FadeManager>::*)(DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*));
//     void StreamTrack::QUEUED_STREAM>, DLListContainerBase<AudioStreamTrack::StreamTrack::QUEUED_STREAM, nlStaticArrayAllocator<DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>, 4>>>(DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>*, DLListContainerBase<AudioStreamTrack::StreamTrack::QUEUED_STREAM, nlStaticArrayAllocator<DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>, 4>>*, void (DLListContainerBase<AudioStreamTrack::StreamTrack::QUEUED_STREAM, nlStaticArrayAllocator<DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>, 4>>::*)(DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>*));
// };

#endif // _AUDIO_H_
