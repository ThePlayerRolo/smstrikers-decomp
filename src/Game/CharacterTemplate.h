#ifndef _CHARACTERTEMPLATE_H_
#define _CHARACTERTEMPLATE_H_

void GetGoalieIndex(int);
void GetCharacterIndex(const cCharacter*);
void DestroyCharacters();
void CreateCharacters();
void CreateGoalie(eCharacterClass, bool);
void CreateSidekick(int, int, eCharacterClass, eCharacterClass, bool);
void SidekickTexture_cb(unsigned long);
void CreateCharacter(int, int, eCharacterClass, bool);
void CharacterLoadingGuts(tCharacterTemplate*, const tCharacterTemplateInfo&, eCharacterClass, bool);
void IsCaptain(eCharacterClass);
void GetCharacterName(eCharacterClass);
void LexicalCast<bool, const char*>(const char* const&);
void LexicalCast<bool, float>(const float&);
void LexicalCast<bool, int>(const int&);
void LexicalCast<bool, bool>(const bool&);
void 0x800148D0..0x800149F0 | size: 0x120;
void nlListAddStart<ListEntry<AnimRetargetList*>>(ListEntry<AnimRetargetList*>**, ListEntry<AnimRetargetList*>*, ListEntry<AnimRetargetList*>**);
void nlListAddStart<ListEntry<cSHierarchy*>>(ListEntry<cSHierarchy*>**, ListEntry<cSHierarchy*>*, ListEntry<cSHierarchy*>**);

class DLListContainerBase<GCAudioStreaming
{
public:
    void StereoAudioStream*, BasicSlotPool<DLListEntry<GCAudioStreaming::StereoAudioStream*>>>::DeleteEntry(DLListEntry<GCAudioStreaming::StereoAudioStream*>*);
};


class DLListContainerBase<AudioStreamTrack
{
public:
    void TrackManagerBase::FadeManager::STREAM_FADE_CTRL, BasicSlotPool<DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>>>::DeleteEntry(DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*);
    void StreamTrack::QUEUED_STREAM, nlStaticArrayAllocator<DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>, 4>>::DeleteEntry(DLListEntry<AudioStreamTrack::StreamTrack::QUEUED_STREAM>*);
};


class WalkHelper<AudioStreamTrack
{
public:
    void TrackManagerBase::FadeManager::STREAM_FADE_CTRL, DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>, AudioStreamTrack::TrackManagerBase::FadeManager>::Callback(DLListEntry<AudioStreamTrack::TrackManagerBase::FadeManager::STREAM_FADE_CTRL>*);
};


class ListContainerBase<cSHierarchy*, NewAdapter<ListEntry<cSHierarchy*>>>
{
public:
    void DeleteEntry(ListEntry<cSHierarchy*>*);
};


class ListContainerBase<AnimRetargetList*, NewAdapter<ListEntry<AnimRetargetList*>>>
{
public:
    void DeleteEntry(ListEntry<AnimRetargetList*>*);
};


class Function0<void>
{
public:
    void FunctorBase::~FunctorBase();
};


class CharacterPhysicsData
{
public:
    ~CharacterPhysicsData();
};


class SebringAnimTagScriptInterpreter
{
public:
    ~SebringAnimTagScriptInterpreter();
};


class AnimTagScriptInterpreter
{
public:
    ~AnimTagScriptInterpreter();
    void TriggerFired(unsigned long);
};


class nlWalkList<ListEntry<AnimRetargetList*>, ListContainerBase<AnimRetargetList*, NewAdapter<ListEntry<AnimRetargetList*>>>>(ListEntry<AnimRetargetList*>*, ListContainerBase<AnimRetargetList*, NewAdapter<ListEntry<AnimRetargetList*>>>*, void (ListContainerBase<AnimRetargetList*, NewAdapter<ListEntry<AnimRetargetList*>>>
{
public:
    void *)(ListEntry<AnimRetargetList*>*));
};


class nlWalkList<ListEntry<cSHierarchy*>, ListContainerBase<cSHierarchy*, NewAdapter<ListEntry<cSHierarchy*>>>>(ListEntry<cSHierarchy*>*, ListContainerBase<cSHierarchy*, NewAdapter<ListEntry<cSHierarchy*>>>*, void (ListContainerBase<cSHierarchy*, NewAdapter<ListEntry<cSHierarchy*>>>
{
public:
    void *)(ListEntry<cSHierarchy*>*));
};

#endif // _CHARACTERTEMPLATE_H_