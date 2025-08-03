#include "audio.h"

/**
 * Offset/Address/Size: 0x0 | 0x8013C514 | size: 0x10
 */
void Audio::MasterVolume::GetVoiceVolume()
{
}

/**
 * Offset/Address/Size: 0x10 | 0x8013C524 | size: 0x208
 */
void Audio::MasterVolume::SetVoiceVolume(float, int)
{
}

/**
 * Offset/Address/Size: 0x218 | 0x8013C72C | size: 0x14
 */
void Audio::MasterVolume::SetVolume(Audio::MasterVolume::VOLUME_GROUP, float)
{
}

/**
 * Offset/Address/Size: 0x22C | 0x8013C740 | size: 0x14
 */
void Audio::MasterVolume::GetVolume(Audio::MasterVolume::VOLUME_GROUP)
{
}

/**
 * Offset/Address/Size: 0x240 | 0x8013C754 | size: 0x1A0
 */
void Audio::FadeFilterFromCurrentToZero()
{
}

/**
 * Offset/Address/Size: 0x3E0 | 0x8013C8F4 | size: 0x94
 */
void Audio::FadeFilterToFullStrength()
{
}

/**
 * Offset/Address/Size: 0x474 | 0x8013C988 | size: 0x354
 */
void Audio::PitchBend(float, float, float, float)
{
}

/**
 * Offset/Address/Size: 0x7C8 | 0x8013CCDC | size: 0x510
 */
void Audio::FadeFilter(float, float, float, float)
{
}

/**
 * Offset/Address/Size: 0xCD8 | 0x8013D1EC | size: 0x2C
 */
void Audio::ClearFadeData()
{
}

/**
 * Offset/Address/Size: 0xD04 | 0x8013D218 | size: 0x20
 */
void Audio::IsEmitterActive(SFXEmitter*)
{
}

/**
 * Offset/Address/Size: 0xD24 | 0x8013D238 | size: 0x20
 */
void Audio::GetEmitterVoiceID(SFXEmitter*)
{
}

/**
 * Offset/Address/Size: 0xD44 | 0x8013D258 | size: 0x20
 */
void Audio::Remove3DSFXEmitter(SFXEmitter*)
{
}

/**
 * Offset/Address/Size: 0xD64 | 0x8013D278 | size: 0x20
 */
void Audio::Add3DSFXEmitter(const EmitterStartInfo&)
{
}

/**
 * Offset/Address/Size: 0xD84 | 0x8013D298 | size: 0x20
 */
void Audio::GetFreeEmitter(unsigned long&)
{
}

/**
 * Offset/Address/Size: 0xDA4 | 0x8013D2B8 | size: 0x20
 */
void Audio::GetEmitter(unsigned long)
{
}

/**
 * Offset/Address/Size: 0xDC4 | 0x8013D2D8 | size: 0x8
 */
void Audio::SetListenerActive(bool)
{
}

/**
 * Offset/Address/Size: 0xDCC | 0x8013D2E0 | size: 0x8
 */
void Audio::IsListenerActive()
{
}

/**
 * Offset/Address/Size: 0xDD4 | 0x8013D2E8 | size: 0x20
 */
void Audio::SetOutputMode(MusyXOutputType)
{
}

/**
 * Offset/Address/Size: 0xDF4 | 0x8013D308 | size: 0x78
 */
void Audio::SetPitchBendOnSFX(unsigned long, unsigned short)
{
}

/**
 * Offset/Address/Size: 0xE6C | 0x8013D380 | size: 0x78
 */
void Audio::SetFilterFreqOnSFX(unsigned long, unsigned short)
{
}

/**
 * Offset/Address/Size: 0xEE4 | 0x8013D3F8 | size: 0x88
 */
void Audio::ActivateFilterOnSFX(unsigned long, bool)
{
}

/**
 * Offset/Address/Size: 0xF6C | 0x8013D480 | size: 0xBC
 */
void Audio::SetPitchBendOnAllDialogueSFX(unsigned short)
{
}

/**
 * Offset/Address/Size: 0x1028 | 0x8013D53C | size: 0xE0
 */
void Audio::ActivateFilterOnAllCurrentSFX(bool)
{
}

/**
 * Offset/Address/Size: 0x1108 | 0x8013D61C | size: 0x1CC
 */
void Audio::SetVolGroupVolume(int, float, int)
{
}

/**
 * Offset/Address/Size: 0x12D4 | 0x8013D7E8 | size: 0x4C
 */
void Audio::SetSFXVolumeGroup(unsigned long, int)
{
}

/**
 * Offset/Address/Size: 0x1320 | 0x8013D834 | size: 0x20
 */
void Audio::SetSFXVolume(unsigned long, float)
{
}

/**
 * Offset/Address/Size: 0x1340 | 0x8013D854 | size: 0x25C
 */
void Audio::Update3DSFXEmitters()
{
}

/**
 * Offset/Address/Size: 0x159C | 0x8013DAB0 | size: 0xA34
 */
void Audio::UpdateFades(float)
{
}

/**
 * Offset/Address/Size: 0x1FD0 | 0x8013E4E4 | size: 0x354
 */
void Audio::Update(float)
{
}

/**
 * Offset/Address/Size: 0x2324 | 0x8013E838 | size: 0x20
 */
void Audio::GetSndIDError()
{
}

/**
 * Offset/Address/Size: 0x2344 | 0x8013E858 | size: 0x34
 */
void Audio::IsSFXPlaying(unsigned long)
{
}

/**
 * Offset/Address/Size: 0x2378 | 0x8013E88C | size: 0x34
 */
void Audio::StopSFX(unsigned long)
{
}

/**
 * Offset/Address/Size: 0x23AC | 0x8013E8C0 | size: 0x214
 */
void Audio::PlaySFXEventFromScript(const SoundEventData&, const char*, float, float)
{
}

/**
 * Offset/Address/Size: 0x25C0 | 0x8013EAD4 | size: 0x68
 */
void Audio::StopCharSFXbyStr(const char*, NisCharacterClass)
{
}

/**
 * Offset/Address/Size: 0x2628 | 0x8013EB3C | size: 0xB4
 */
void Audio::StopWorldSFXbyStr(const char*)
{
}

/**
 * Offset/Address/Size: 0x26DC | 0x8013EBF0 | size: 0x104
 */
void Audio::PlayCharSFXbyStr(const char*, NisCharacterClass, float, float, bool, bool, const nlVector3*, const nlVector3*, unsigned long*)
{
}

/**
 * Offset/Address/Size: 0x27E0 | 0x8013ECF4 | size: 0x144
 */
void Audio::PlayWorldSFXbyStr(const char*, float, float, bool, bool, const nlVector3*, const nlVector3*, unsigned long*)
{
}

/**
 * Offset/Address/Size: 0x2924 | 0x8013EE38 | size: 0x30
 */
void Audio::RemoveDelayedSFX(unsigned long)
{
}

/**
 * Offset/Address/Size: 0x2954 | 0x8013EE68 | size: 0xE8
 */
void Audio::IsDelayedCharSFX(unsigned long, cGameSFX*)
{
}

/**
 * Offset/Address/Size: 0x2A3C | 0x8013EF50 | size: 0x3E4
 */
void Audio::AddDelayedSFX(const Audio::SoundAttributes&, unsigned long, float, float, cGameSFX*)
{
}

/**
 * Offset/Address/Size: 0x2E20 | 0x8013F334 | size: 0x17C
 */
void Audio::PlaySFXbyID(const Audio::SoundAttributes&, unsigned long, float, float, int)
{
}

/**
 * Offset/Address/Size: 0x2F9C | 0x8013F4B0 | size: 0x20
 */
void Audio::PlaySFX(const SFXStartInfo&)
{
}

/**
 * Offset/Address/Size: 0x2FBC | 0x8013F4D0 | size: 0x8
 */
void Audio::GetAudioTimer()
{
}

/**
 * Offset/Address/Size: 0x2FC4 | 0x8013F4D8 | size: 0x44
 */
void Audio::Shutdown()
{
}

/**
 * Offset/Address/Size: 0x3008 | 0x8013F51C | size: 0x20
 */
void Audio::Silence()
{
}

/**
 * Offset/Address/Size: 0x3028 | 0x8013F53C | size: 0x48
 */
void Audio::ResetForNewGame()
{
}

/**
 * Offset/Address/Size: 0x3070 | 0x8013F584 | size: 0xC
 */
void Audio::ResetPauseStatus()
{
}

/**
 * Offset/Address/Size: 0x307C | 0x8013F590 | size: 0x64
 */
void Audio::UnloadWorldSFX()
{
}

/**
 * Offset/Address/Size: 0x30E0 | 0x8013F5F4 | size: 0x8
 */
void Audio::IsWorldSFXLoaded()
{
}

/**
 * Offset/Address/Size: 0x30E8 | 0x8013F5FC | size: 0xC0
 */
void Audio::LoadWorldSFX()
{
}

/**
 * Offset/Address/Size: 0x31A8 | 0x8013F6BC | size: 0xB0
 */
void Audio::UnloadInGameSFX()
{
}

/**
 * Offset/Address/Size: 0x3258 | 0x8013F76C | size: 0x80
 */
void Audio::LoadInGameSFX()
{
}

/**
 * Offset/Address/Size: 0x32D8 | 0x8013F7EC | size: 0x8
 */
bool IsInited()
{
    return false;
}

/**
 * Offset/Address/Size: 0x32E0 | 0x8013F7F4 | size: 0x9C
 */
void Audio::ShutdownReverb()
{
}

/**
 * Offset/Address/Size: 0x337C | 0x8013F890 | size: 0x734
 */
void Audio::InitializeReverb(eStadiumID, unsigned char)
{
}

/**
 * Offset/Address/Size: 0x3AB0 | 0x8013FFC4 | size: 0xF60
 */
void ReadVolGroupSettings()
{
}

/**
 * Offset/Address/Size: 0x4A10 | 0x80140F24 | size: 0x15C
 */
void Audio::Initialize(bool)
{
}

/**
 * Offset/Address/Size: 0x4B6C | 0x80141080 | size: 0x2C
 */
void Audio::SoundAttributes::UseStationaryPosVector(const nlVector3&)
{
}

/**
 * Offset/Address/Size: 0x4B98 | 0x801410AC | size: 0x44
 */
void Audio::SoundAttributes::UseVectors(const nlVector3&, const nlVector3&)
{
}

/**
 * Offset/Address/Size: 0x4BDC | 0x801410F0 | size: 0x1C
 */
void Audio::SoundAttributes::UseVectorPtrs(const nlVector3*, const nlVector3*)
{
}

/**
 * Offset/Address/Size: 0x4BF8 | 0x8014110C | size: 0x14
 */
void Audio::SoundAttributes::UsePhysObj(PhysicsObject*)
{
}

/**
 * Offset/Address/Size: 0x4C0C | 0x80141120 | size: 0xC
 */
void Audio::SoundAttributes::SetSoundType(unsigned long, bool)
{
}

/**
 * Offset/Address/Size: 0x4C18 | 0x8014112C | size: 0x100
 */
void Audio::SoundAttributes::Init()
{
}

/**
 * Offset/Address/Size: 0x0 | 0x8014122C | size: 0x8
 */
void cGameSFX::GetClassType() const
{
}

/**
 * Offset/Address/Size: 0x0 | 0x80141234 | size: 0x8C
 */
void nlBSearch<nlSortedSlot<AudioStreamTrack::StreamTrack, 3>::EntryLookup<AudioStreamTrack::StreamTrack>, unsigned long>(const unsigned long&, nlSortedSlot<AudioStreamTrack::StreamTrack, 3>::EntryLookup<AudioStreamTrack::StreamTrack>*, int)
{
}

/**
 * Offset/Address/Size: 0x0 | 0x801412C0 | size: 0x54
 */
void nlDeleteList<FadeAudioData>(FadeAudioData**)
{
}

/**
 * Offset/Address/Size: 0x54 | 0x80141314 | size: 0x9C
 */
void nlListRemoveElement<FadeAudioData>(FadeAudioData**, FadeAudioData*, FadeAudioData**)
{
}

/**
 * Offset/Address/Size: 0xF0 | 0x801413B0 | size: 0x28
 */
void nlListAddStart<FadeAudioData>(FadeAudioData**, FadeAudioData*, FadeAudioData**)
{
}

/**
 * Offset/Address/Size: 0x0 | 0x801413D8 | size: 0x3C
 */
void nlWalkDLRing<DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>, DLListContainerBase<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, BasicSlotPool<DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>>>>(DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*, DLListContainerBase<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, BasicSlotPool<DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>>>*, void (DLListContainerBase<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, BasicSlotPool<DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>>>::*)(DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*))
{
}

/**
 * Offset/Address/Size: 0x3C | 0x80141414 | size: 0x3C
 */
void nlWalkDLRing<DLListEntry<GCAudioStreaming::StereoAudioStream*>, DLListContainerBase<GCAudioStreaming::StereoAudioStream*, BasicSlotPool<DLListEntry<GCAudioStreaming::StereoAudioStream*>>>>(DLListEntry<GCAudioStreaming::StereoAudioStream*>*, DLListContainerBase<GCAudioStreaming::StereoAudioStream*, BasicSlotPool<DLListEntry<GCAudioStreaming::StereoAudioStream*>>>*, void (DLListContainerBase<GCAudioStreaming::StereoAudioStream*, BasicSlotPool<DLListEntry<GCAudioStreaming::StereoAudioStream*>>>::*)(DLListEntry<GCAudioStreaming::StereoAudioStream*>*))
{
}

/**
 * Offset/Address/Size: 0x78 | 0x80141450 | size: 0x3C
 */
void nlWalkDLRing<DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>, DLListContainerBase<AudioStreamTrack::StreamTrack::QUEUED_STREAM, nlStaticArrayAllocator<DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>, 4>>>(DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>*, DLListContainerBase<AudioStreamTrack::StreamTrack::QUEUED_STREAM, nlStaticArrayAllocator<DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>, 4>>*, void (DLListContainerBase<AudioStreamTrack::StreamTrack::QUEUED_STREAM, nlStaticArrayAllocator<DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>, 4>>::*)(DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>*))
{
}

/**
 * Offset/Address/Size: 0xB4 | 0x8014148C | size: 0x3C
 */
void nlWalkDLRing<DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>, WalkHelper<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>, AudioStreamTrack::TrackManagerBase::FadeManager>>(DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*, WalkHelper<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>, AudioStreamTrack::TrackManagerBase::FadeManager>*, void (WalkHelper<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>, AudioStreamTrack::TrackManagerBase::FadeManager>::*)(DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*))
{
}

/**
 * Offset/Address/Size: 0xF0 | 0x801414C8 | size: 0x20
 */
void nlDLRingIsEnd<DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>>(DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*, DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*)
{
}

/**
 * Offset/Address/Size: 0x110 | 0x801414E8 | size: 0x18
 */
void nlDLRingGetStart<DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>>(DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>*)
{
}

/**
 * Offset/Address/Size: 0x128 | 0x80141500 | size: 0x18
 */
void nlDLRingGetStart<DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>>(DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*)
{
}

/**
 * Offset/Address/Size: 0x0 | 0x80141518 | size: 0x1AC
 */
void Audio::CreateTrackMgr<3>()
{
}

/**
 * Offset/Address/Size: 0x0 | 0x801416C4 | size: 0x1F4
 */
void AudioStreamTrack::TrackManagerBase::~TrackManagerBase()
{
}

/**
 * Offset/Address/Size: 0x1F4 | 0x801418B8 | size: 0x204
 */
void AudioStreamTrack::TrackManager<3>::~TrackManager()
{
}

/**
 * Offset/Address/Size: 0x3F8 | 0x80141ABC | size: 0x1EC
 */
void AudioStreamTrack::TrackManager<3>::OnMasterVolumeChange(Audio::MasterVolume::VOLUME_GROUP)
{
}

/**
 * Offset/Address/Size: 0x5E4 | 0x80141CA8 | size: 0x54
 */
void AudioStreamTrack::TrackManager<3>::GetTrack(unsigned long)
{
}

/**
 * Offset/Address/Size: 0x638 | 0x80141CFC | size: 0x78
 */
void AudioStreamTrack::TrackManager<3>::StopAllTracks(unsigned long)
{
}

/**
 * Offset/Address/Size: 0x6B0 | 0x80141D74 | size: 0xF0
 */
void AudioStreamTrack::TrackManager<3>::Update(float)
{
}

/**
 * Offset/Address/Size: 0x7A0 | 0x80141E64 | size: 0x1D0
 */
void AudioStreamTrack::TrackManager<3>::DestroyAllTracks()
{
}

/**
 * Offset/Address/Size: 0x970 | 0x80142034 | size: 0x1AC
 */
void AudioStreamTrack::TrackManager<3>::CreateTrack(const char*, Audio::MasterVolume::VOLUME_GROUP)
{
}

/**
 * Offset/Address/Size: 0x0 | 0x801421E0 | size: 0x14
 */
void nlStaticSortedSlot<AudioStreamTrack::StreamTrack, 3>::ExpandLookup()
{
}

/**
 * Offset/Address/Size: 0x14 | 0x801421F4 | size: 0xC
 */
void nlStaticSortedSlot<AudioStreamTrack::StreamTrack, 3>::FreeLookup()
{
}

/**
 * Offset/Address/Size: 0x20 | 0x80142200 | size: 0x10
 */
void nlStaticSortedSlot<AudioStreamTrack::StreamTrack, 3>::FreeEntry(AudioStreamTrack::StreamTrack*)
{
}

/**
 * Offset/Address/Size: 0x30 | 0x80142210 | size: 0x24
 */
void nlStaticSortedSlot<AudioStreamTrack::StreamTrack, 3>::GetNewEntry()
{
}

/**
 * Offset/Address/Size: 0x0 | 0x80142234 | size: 0x60
 */
void nlWalkRing<DLListEntry<GCAudioStreaming::StereoAudioStream*>, DLListContainerBase<GCAudioStreaming::StereoAudioStream*, BasicSlotPool<DLListEntry<GCAudioStreaming::StereoAudioStream*>>>>(DLListEntry<GCAudioStreaming::StereoAudioStream*>*, DLListContainerBase<GCAudioStreaming::StereoAudioStream*, BasicSlotPool<DLListEntry<GCAudioStreaming::StereoAudioStream*>>>*, void (DLListContainerBase<GCAudioStreaming::StereoAudioStream*, BasicSlotPool<DLListEntry<GCAudioStreaming::StereoAudioStream*>>>::*)(DLListEntry<GCAudioStreaming::StereoAudioStream*>*))
{
}

/**
 * Offset/Address/Size: 0x60 | 0x80142294 | size: 0x60
 */
void nlWalkRing<DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>, DLListContainerBase<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, BasicSlotPool<DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>>>>(DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*, DLListContainerBase<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, BasicSlotPool<DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>>>*, void (DLListContainerBase<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, BasicSlotPool<DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>>>::*)(DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*))
{
}

/**
 * Offset/Address/Size: 0xC0 | 0x801422F4 | size: 0x60
 */
void nlWalkRing<DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>, WalkHelper<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>, AudioStreamTrack::TrackManagerBase::FadeManager>>(DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*, WalkHelper<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>, AudioStreamTrack::TrackManagerBase::FadeManager>*, void (WalkHelper<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL, DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>, AudioStreamTrack::TrackManagerBase::FadeManager>::*)(DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*))
{
}

/**
 * Offset/Address/Size: 0x120 | 0x80142354 | size: 0x60
 */
void nlWalkRing<DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>, DLListContainerBase<AudioStreamTrack::StreamTrack::QUEUED_STREAM, nlStaticArrayAllocator<DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>, 4>>>(DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>*, DLListContainerBase<AudioStreamTrack::StreamTrack::QUEUED_STREAM, nlStaticArrayAllocator<DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>, 4>>*, void (DLListContainerBase<AudioStreamTrack::StreamTrack::QUEUED_STREAM, nlStaticArrayAllocator<DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>, 4>>::*)(DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>*))
{
}
