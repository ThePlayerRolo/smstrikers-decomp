#ifndef _PLATAUDIO_H_
#define _PLATAUDIO_H_

#include "musyx/musyx.h"

// void AddAuxEffect(MusyXEffectType, void*, bool, unsigned char);
// void PrintSoundStackInfo();
// void PrintAvailableARAMMemory();
void musyXFree(void*);
void *musyXAlloc(u32);
// void 0x8028D524..0x8028D528 | size: 0x4;

#include "types.h"
#include "NL/nlMath.h"

enum MusyXEffectType
{
    MusyXEffectType_0 = 0,
    // todo: implement
};

enum MusyXOutputType
{
    MusyXOutputType_0 = 0,
    // todo: implement
};

class AudioFileData;
class nlFile;

// class MusyXEffectType;
// class MusyXOutputType;
class SFXStartInfo;

struct SFXEmitter__
{
    /* 0x00 */ SND_EMITTER *m_sndEmitter;      // Possibly a pointer to a sound instance or data block
    /* 0x04 */ s32       m_unk_0x04;      // Sound ID or index (-1 = unused)
    /* 0x08 */ u32       m_unk_0x08;
    /* 0x0C */ f32       m_unk_0x0C;
    /* 0x10 */ f32       m_unk_0x10;
    /* 0x14 */ f32       m_unk_0x14;
    /* 0x18 */ f32       m_unk_0x18;
    /* 0x1C */ f32       m_unk_0x1C;
    /* 0x20 */ f32       m_unk_0x20;
    /* 0x24 */ f32       m_unk_0x24;
    /* 0x28 */ u32       m_unk_0x28;      // Frequently checked/cleared
    /* 0x2C */ u32       m_unk_0x2C;
    /* 0x30 */ u32       m_unk_0x30;
    /* 0x34 */ u32       m_unk_0x34;
    /* 0x38 */ u32       m_unk_0x38;
    /* 0x3C */ u32       m_unk_0x3C;
    /* 0x40 */ u32       m_unk_0x40;
    /* 0x44 */ u32       m_unk_0x44;
    /* 0x48 */ u32       m_unk_0x48;
    /* 0x4C */ u32       m_unk_0x4C;
    /* 0x50 */ u32       m_unk_0x50;
    /* 0x54 */ u8        m_padding[0x34];
};

struct SFXEmitter
{
    // /* 0x00 */ char pad0[0x50];
    SND_EMITTER m_sndEmitter;
    /* 0x50 */ s8 unk50;                            /* inferred */
    // /* 0x51 */ char pad51[3];                       /* maybe part of unk50[4]? */
    /* 0x54 */ s32 unk54;                           /* inferred */
    /* 0x58 */ f32 unk58;                           /* inferred */
    /* 0x5C */ u8 unk5C;                            /* inferred */
    /* 0x5D */ u8 unk5D;                            /* inferred */
    /* 0x5E */ s8 unk5E;                            /* inferred */
    /* 0x5F */ s8 unk5F;                            /* inferred */
    /* 0x60 */ s32 unk60;                           /* inferred */
    /* 0x64 */ s32 unk64;                           /* inferred */
    /* 0x68 */ f32 unk68;                           /* inferred */
    /* 0x6C */ f32 unk6C;                           /* inferred */
    /* 0x70 */ f32 unk70;                           /* inferred */
    /* 0x74 */ f32 unk74;                           /* inferred */
    /* 0x78 */ f32 unk78;                           /* inferred */
    /* 0x7C */ f32 unk7C;                           /* inferred */
    /* 0x80 */ s32 unk80;                           /* inferred */
    /* 0x84 */ void *unk84;                         /* inferred */
}; 

struct EmitterStartInfo
{
    // todo: implement
};

namespace PlatAudio
{

    // public:
    u32 GetSndIDError();
    bool IsSFXPlaying(unsigned long);
    void InitEmitter(unsigned long);
    void RemoveEmitter(SFXEmitter*);
    void RemoveEmitter(unsigned long);
    SFXEmitter* GetSFXEmitter(unsigned long);
    void GetFreeEmitter(unsigned long&);
    SND_VOICEID GetEmitterVoiceID(SFXEmitter*);
    bool IsEmitterActive(SFXEmitter*);
    void Update3DSFXEmitter(SFXEmitter*, const nlVector3&, const nlVector3&, float);
    void Add3DSFXEmitter(const EmitterStartInfo&);
    void Remove3DSFXListener(SND_LISTENER*);
    void Update3DSFXListener(SND_LISTENER*, const nlVector3&, const nlVector3&, const nlVector3&, const nlVector3&, float);
    void Add3DSFXListener(SND_LISTENER*, const nlVector3&, const nlVector3&, const nlVector3&, const nlVector3&, float, float, float, float, bool, float);
    bool SetPitchBendOnSFX(SND_VOICEID vid, u16 value);
    bool SetFilterFreqOnSFX(SND_VOICEID vid, u16 value);
    bool SetMIDIControllerVal14Bit(SND_VOICEID vid, u8 ctrl, u16 value);
    void SetVolGroupVolume(u8 volGroup, float volume, u16 time);
    bool SetSFXVolumeGroup(u32 fid, u8 vGroup);
    bool SetSFXReverbVol(unsigned long, float);
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
