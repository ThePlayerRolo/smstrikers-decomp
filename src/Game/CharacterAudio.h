#ifndef _CHARACTERAUDIO_H_
#define _CHARACTERAUDIO_H_

#include "types.h"
#include "NL/nlMath.h"

#include "GameAudio.h"

namespace Audio 
{
    enum eCharSFX
    {
        eCharSFX_0 = 0
    };

    struct SoundAttributes
    {
        // Placeholder structure
    };

    class cCharacterSFX : public cGameSFX
    {
    public:
        void IsMovementLoopStarted();
        void IsMovementLoopPlaying();
        void StopMovementLoop();
        void StartMovementLoop();
        // void GetCharacterFromNisCharClass(NisCharacterClass);
        // void PlayNISRandomCharDialogue(CharDialogueType, NisCharacterClass, float, float, bool, const nlVector3*, const nlVector3*, unsigned long*);
        // void PlayRandomWalkFootstep(float, bool);
        // void StopPlayingAllRandomCharDialogue();
        // void StopPlayingRandomCharDialogue(CharDialogueType);
        // void IsPlayingRandomCharDialogue(CharDialogueType);
        // void PlayRandomCharDialogue(CharDialogueType, Audio::SoundAttributes&, bool, unsigned long*);
        // void PlayRandomCharDialogue(CharDialogueType, PosUpdateMethod, float, float, bool);
        void Stop(Audio::eCharSFX, cGameSFX::StopFlag);
        int Play(Audio::SoundAttributes&);
        void Init();
        
        ~cCharacterSFX();
        cCharacterSFX();
    };

}

#endif // _CHARACTERAUDIO_H_
