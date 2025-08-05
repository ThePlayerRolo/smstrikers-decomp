#include "plataudio.h"

/**
 * Offset/Address/Size: 0x0 | 0x801C47FC | size: 0x8
 */
 u32 PlatAudio::GetSndIDError()
{
}

/**
 * Offset/Address/Size: 0x8 | 0x801C4804 | size: 0x30
 */
void PlatAudio::IsSFXPlaying(unsigned long)
{
}

/**
 * Offset/Address/Size: 0x38 | 0x801C4834 | size: 0xC0
 */
void PlatAudio::InitEmitter(unsigned long)
{
}

/**
 * Offset/Address/Size: 0xF8 | 0x801C48F4 | size: 0x20
 */
void PlatAudio::RemoveEmitter(SFXEmitter*)
{
}

/**
 * Offset/Address/Size: 0x118 | 0x801C4914 | size: 0x30
 */
void PlatAudio::RemoveEmitter(unsigned long)
{
}

/**
 * Offset/Address/Size: 0x148 | 0x801C4944 | size: 0x14
 */
void PlatAudio::GetSFXEmitter(unsigned long)
{
}

/**
 * Offset/Address/Size: 0x15C | 0x801C4958 | size: 0x35C
 */
void PlatAudio::GetFreeEmitter(unsigned long&)
{
}

/**
 * Offset/Address/Size: 0x4B8 | 0x801C4CB4 | size: 0x20
 */
void PlatAudio::GetEmitterVoiceID(SFXEmitter*)
{
}

/**
 * Offset/Address/Size: 0x4D8 | 0x801C4CD4 | size: 0x20
 */
void PlatAudio::IsEmitterActive(SFXEmitter*)
{
}

/**
 * Offset/Address/Size: 0x4F8 | 0x801C4CF4 | size: 0x90
 */
void PlatAudio::Update3DSFXEmitter(SFXEmitter*, const nlVector3&, const nlVector3&, float)
{
}

/**
 * Offset/Address/Size: 0x588 | 0x801C4D84 | size: 0x2E4
 */
void PlatAudio::Add3DSFXEmitter(const EmitterStartInfo&)
{
}

/**
 * Offset/Address/Size: 0x86C | 0x801C5068 | size: 0x20
 */
void PlatAudio::Remove3DSFXListener(SND_LISTENER*)
{
}

/**
 * Offset/Address/Size: 0x88C | 0x801C5088 | size: 0xC8
 */
void PlatAudio::Update3DSFXListener(SND_LISTENER*, const nlVector3&, const nlVector3&, const nlVector3&, const nlVector3&, float)
{
}

/**
 * Offset/Address/Size: 0x954 | 0x801C5150 | size: 0x10C
 */
void PlatAudio::Add3DSFXListener(SND_LISTENER*, const nlVector3&, const nlVector3&, const nlVector3&, const nlVector3&, float, float, float, float, bool, float)
{
}

/**
 * Offset/Address/Size: 0xA60 | 0x801C525C | size: 0x68
 */
void PlatAudio::SetPitchBendOnSFX(unsigned long, unsigned short)
{
}

/**
 * Offset/Address/Size: 0xAC8 | 0x801C52C4 | size: 0x7C
 */
void PlatAudio::SetFilterFreqOnSFX(unsigned long, unsigned short)
{
}

/**
 * Offset/Address/Size: 0xB44 | 0x801C5340 | size: 0x20
 */
void PlatAudio::SetMIDIControllerVal14Bit(unsigned long, unsigned char, unsigned short)
{
}

/**
 * Offset/Address/Size: 0xB64 | 0x801C5360 | size: 0x58
 */
void PlatAudio::SetVolGroupVolume(unsigned char, float, unsigned short)
{
}

/**
 * Offset/Address/Size: 0xBBC | 0x801C53B8 | size: 0x24
 */
void PlatAudio::SetSFXVolumeGroup(unsigned long, unsigned char)
{
}

/**
 * Offset/Address/Size: 0xBE0 | 0x801C53DC | size: 0x68
 */
void PlatAudio::SetSFXReverbVol(unsigned long, float)
{
}

/**
 * Offset/Address/Size: 0xC48 | 0x801C5444 | size: 0x88
 */
void PlatAudio::SetSFXVolume(unsigned long, float)
{
}

/**
 * Offset/Address/Size: 0xCD0 | 0x801C54CC | size: 0x48
 */
void PlatAudio::StopSFX(unsigned long)
{
}

/**
 * Offset/Address/Size: 0xD18 | 0x801C5514 | size: 0x244
 */
void PlatAudio::PlaySFX(const SFXStartInfo&)
{
}

/**
 * Offset/Address/Size: 0xF5C | 0x801C5758 | size: 0x120
 */
void PlatAudio::UnloadAllSoundGroupsOnStack(AudioFileData&, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x107C | 0x801C5878 | size: 0x150
 */
void PlatAudio::UnloadAllSoundGroups(AudioFileData&)
{
}

/**
 * Offset/Address/Size: 0x11CC | 0x801C59C8 | size: 0x184
 */
void PlatAudio::UnloadSoundGroup(AudioFileData&, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x1350 | 0x801C5B4C | size: 0x328
 */
void PlatAudio::LoadSoundGroup(AudioFileData&, unsigned long, unsigned long, bool)
{
}

/**
 * Offset/Address/Size: 0x1678 | 0x801C5E74 | size: 0x16C
 */
void PlatAudio::SetupSoundBuffers(AudioFileData&, bool)
{
}

/**
 * Offset/Address/Size: 0x17E4 | 0x801C5FE0 | size: 0x20
 */
void PlatAudio::StopAllSound()
{
}

/**
 * Offset/Address/Size: 0x1804 | 0x801C6000 | size: 0x78
 */
void PlatAudio::Shutdown()
{
}

/**
 * Offset/Address/Size: 0x187C | 0x801C6078 | size: 0x11C
 */
void PlatAudio::Initialize(bool)
{
}

/**
 * Offset/Address/Size: 0x1998 | 0x801C6194 | size: 0x74
 */
void PlatAudio::PurgeSampleFileBuffer()
{
}

/**
 * Offset/Address/Size: 0x1A0C | 0x801C6208 | size: 0x14
 */
void PlatAudio::IsEntireSampleFileInMem()
{
}

/**
 * Offset/Address/Size: 0x1A20 | 0x801C621C | size: 0x124
 */
void PlatAudio::ReadEntireSampleFileIntoMemSync(const char*)
{
}

/**
 * Offset/Address/Size: 0x1B44 | 0x801C6340 | size: 0x100
 */
void PlatAudio::ReadEntireSampleFileIntoMem(const char*)
{
}

/**
 * Offset/Address/Size: 0x1C44 | 0x801C6440 | size: 0x54
 */
void ARAMTransferHelperLoadEntireFile::LoadEntireFileCallback(nlFile*, void*, unsigned int, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x1C98 | 0x801C6494 | size: 0x13C
 */
void ARAMTransferHelperLoadEntireFile::sndPushGroupCallback(unsigned long, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x1DD4 | 0x801C65D0 | size: 0x148
 */
void ARAMTransferHelper::sndPushGroupCallback(unsigned long, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x1F1C | 0x801C6718 | size: 0x10C
 */
void PlatAudio::UpdateAuxEffectA(MusyXEffectType, void*)
{
}

/**
 * Offset/Address/Size: 0x2028 | 0x801C6824 | size: 0x244
 */
void AddAuxEffect(MusyXEffectType, void*, bool, unsigned char)
{
}

/**
 * Offset/Address/Size: 0x226C | 0x801C6A68 | size: 0x28
 */
void PlatAudio::AddAuxEffectA(MusyXEffectType, void*, unsigned char)
{
}

/**
 * Offset/Address/Size: 0x2294 | 0x801C6A90 | size: 0x21C
 */
void PlatAudio::ShutdownAuxEffectA()
{
}

/**
 * Offset/Address/Size: 0x24B0 | 0x801C6CAC | size: 0x24
 */
void PlatAudio::DeactivateDPL2()
{
}

/**
 * Offset/Address/Size: 0x24D4 | 0x801C6CD0 | size: 0x24
 */
void PlatAudio::ActivateDPL2()
{
}

/**
 * Offset/Address/Size: 0x24F8 | 0x801C6CF4 | size: 0x60
 */
void PlatAudio::SetOutputMode(MusyXOutputType)
{
}

/**
 * Offset/Address/Size: 0x2558 | 0x801C6D54 | size: 0x278
 */
void PrintSoundStackInfo()
{
}

/**
 * Offset/Address/Size: 0x27D0 | 0x801C6FCC | size: 0x74
 */
void PrintAvailableARAMMemory()
{
}

/**
 * Offset/Address/Size: 0x2844 | 0x801C7040 | size: 0x20
 */
void musyXFree(void*)
{
}

/**
 * Offset/Address/Size: 0x2864 | 0x801C7060 | size: 0x28
 */
void musyXAlloc(unsigned long)
{
}

/**
 * Offset/Address/Size: 0x288C | 0x801C7088 | size: 0x3C
 */
void 0x8028D524..0x8028D528 | size: 0x4
{
}
