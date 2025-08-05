#ifndef _PLATAUDIO_H_
#define _PLATAUDIO_H_

// void AddAuxEffect(MusyXEffectType, void*, bool, unsigned char);
// void PrintSoundStackInfo();
// void PrintAvailableARAMMemory();
// void musyXFree(void*);
// void musyXAlloc(unsigned long);
// void 0x8028D524..0x8028D528 | size: 0x4;

#include "types.h"
#include "NL/nlMath.h"

class SFXEmitter;
class AudioFileData;
class nlFile;
// class nlVector3;
class MusyXEffectType;
class MusyXOutputType;
class SFXStartInfo;
class SND_LISTENER;

struct EmitterStartInfo
{
    // todo: implement
};

namespace PlatAudio
{

    // public:
    u32 GetSndIDError();
    void IsSFXPlaying(unsigned long);
    void InitEmitter(unsigned long);
    void RemoveEmitter(SFXEmitter*);
    void RemoveEmitter(unsigned long);
    void GetSFXEmitter(unsigned long);
    void GetFreeEmitter(unsigned long&);
    void GetEmitterVoiceID(SFXEmitter*);
    void IsEmitterActive(SFXEmitter*);
    void Update3DSFXEmitter(SFXEmitter*, const nlVector3&, const nlVector3&, float);
    void Add3DSFXEmitter(const EmitterStartInfo&);
    void Remove3DSFXListener(SND_LISTENER*);
    void Update3DSFXListener(SND_LISTENER*, const nlVector3&, const nlVector3&, const nlVector3&, const nlVector3&, float);
    void Add3DSFXListener(SND_LISTENER*, const nlVector3&, const nlVector3&, const nlVector3&, const nlVector3&, float, float, float, float, bool, float);
    void SetPitchBendOnSFX(unsigned long, unsigned short);
    void SetFilterFreqOnSFX(unsigned long, unsigned short);
    void SetMIDIControllerVal14Bit(unsigned long, unsigned char, unsigned short);
    void SetVolGroupVolume(unsigned char, float, unsigned short);
    void SetSFXVolumeGroup(unsigned long, unsigned char);
    void SetSFXReverbVol(unsigned long, float);
    void SetSFXVolume(unsigned long, float);
    void StopSFX(unsigned long);
    void PlaySFX(const SFXStartInfo&);
    void UnloadAllSoundGroupsOnStack(AudioFileData&, unsigned long);
    void UnloadAllSoundGroups(AudioFileData&);
    void UnloadSoundGroup(AudioFileData&, unsigned long);
    void LoadSoundGroup(AudioFileData&, unsigned long, unsigned long, bool);
    void SetupSoundBuffers(AudioFileData&, bool);
    void StopAllSound();
    void Shutdown();
    void Initialize(bool);
    void PurgeSampleFileBuffer();
    void IsEntireSampleFileInMem();
    void ReadEntireSampleFileIntoMemSync(const char*);
    void ReadEntireSampleFileIntoMem(const char*);
    void UpdateAuxEffectA(MusyXEffectType, void*);
    void AddAuxEffectA(MusyXEffectType, void*, unsigned char);
    void ShutdownAuxEffectA();
    void DeactivateDPL2();
    void ActivateDPL2();
    void SetOutputMode(MusyXOutputType);

}


class ARAMTransferHelperLoadEntireFile
{
public:
    void LoadEntireFileCallback(nlFile*, void*, unsigned int, unsigned long);
    void sndPushGroupCallback(unsigned long, unsigned long);
};


class ARAMTransferHelper
{
public:
    void sndPushGroupCallback(unsigned long, unsigned long);
};

#endif // _PLATAUDIO_H_
