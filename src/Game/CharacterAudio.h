#ifndef _CHARACTERAUDIO_H_
#define _CHARACTERAUDIO_H_

#include "types.h"
#include "NL/nlMath.h"

#include "GameAudio.h"
#include "PhysicsCharacter.h"

namespace Audio 
{
    enum eCharSFX
    {
        eCharSFX_0 = 0
    };

    class cCharacterSFX : public cGameSFX
    {
    public:
         cCharacterSFX();
        virtual ~cCharacterSFX();

        virtual void Init();
        virtual int Play(Audio::SoundAttributes&);
        void Stop(Audio::eCharSFX, cGameSFX::StopFlag);
        // void PlayRandomCharDialogue(CharDialogueType, PosUpdateMethod, float, float, bool);
        // void PlayRandomCharDialogue(CharDialogueType, Audio::SoundAttributes&, bool, unsigned long*);
        // void IsPlayingRandomCharDialogue(CharDialogueType);
        // void StopPlayingRandomCharDialogue(CharDialogueType);
        // void StopPlayingAllRandomCharDialogue();
        // void PlayRandomWalkFootstep(float, bool);
        // void PlayNISRandomCharDialogue(CharDialogueType, NisCharacterClass, float, float, bool, const nlVector3*, const nlVector3*, unsigned long*);
        // void GetCharacterFromNisCharClass(NisCharacterClass);
        void StartMovementLoop();
        void StopMovementLoop();
        void IsMovementLoopPlaying();
        void IsMovementLoopStarted();

        /* 0x04 */ u8 m_padding_0x04[0x3390];
        /* 0x3394 */ PhysicsCharacter* m_physicsCharacter;
    };

}

#endif // _CHARACTERAUDIO_H_
