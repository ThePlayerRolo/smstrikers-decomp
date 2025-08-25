#ifndef _GAMEINFO_H_
#define _GAMEINFO_H_

#include "types.h"

#include "NL/nlSingleton.h"

class Spoil
{
public:
};

enum eTrophyType
{
    eTrophyType_None = 0,
    eTrophyType_Bronze = 1,
    eTrophyType_Silver = 2,
    eTrophyType_Gold = 3,
};

enum eTeamID
{
    eTeamID_None = 0,
    eTeamID_Team1 = 1,
    eTeamID_Team2 = 2,
};

enum eSidekickID
{
    eSidekickID_None = 0,
    eSidekickID_Sidekick1 = 1,
    eSidekickID_Sidekick2 = 2,
};

enum eStadiumID
{
    eStadiumID_None = 0,
    eStadiumID_Stadium1 = 1,
    eStadiumID_Stadium2 = 2,
};

enum eUserGameResult
{
    eUserGameResult_None = 0,
    eUserGameResult_Win = 1,
    eUserGameResult_Loss = 2,
};

class GameInfoManager
{
public:
    enum eGameModes
    {
        eGameModes_None = 0,
        eGameModes_Cup = 1,
        eGameModes_Tournament = 2,
    };

    void GetCustomPowerups() const;
    void GetSkillLevelAsDifficultyID();
    void GetSkillLevel();
    void IsBowserAttackEnabled() const;
    void IsPerfectStrikesOn() const;
    void IsTiltingFieldOn() const;
    void IsInfinitePowerupsOn() const;
    void IsStunnedGoaliesOn() const;
    void SetRoundResult(bool, int);
    void HasHumanGameBeenPlayed() const;
    void IsCustomFreezingUnlocked() const;
    void IsCustomExplosiveUnlocked() const;
    void IsCustomGiantUnlocked() const;
    void IsCustomEnhanceUnlocked() const;
    void IsCustomShellsUnlocked() const;
    void IsUnlimtedPowerupsUnlocked() const;
    void IsGlassJawGoalieUnlocked() const;
    void IsTiltCheatUnlocked() const;
    void IsAllSTSCheatUnlocked() const;
    void IsLegendSkillUnlocked() const;
    void IsSuperCupModeUnlocked() const;
    void IsSuperTeamUnlocked() const;
    void IsSuperStadiumUnlocked() const;
    void IsForbiddenUnlocked() const;
    void IsYoshiUnlocked() const;
    void IsKongaUnlocked() const;
    void FindWinningTeam();
    void TimeStampCupEnd();
    void DetermineUserPlacement(Spoil*);
    void DetermineNextCupScreen();
    void OnPostCupGameState();
    void OnPreCupGameState();
    void IsPossibleCupMatch() const;
    void GetTrophyTypeByCurrentMode() const;
    void ApplyDifficultySettings();
    void OnPostGameState();
    void OnPreGameState();
    void GetPowerupOptions() const;
    void GetGameplayOptions() const;
    void GetAudioOptions();
    void IsInTournamentMode() const;
    void IsInFriendlyMode() const;
    void IsInDemoMode() const;
    void IsInCupOrTournamentMode() const;
    void IsInCupMode() const;
    void IsInSuperCupMode() const;
    void IsInRegularCupMode() const;
    void GetMilestoneLevel(eTrophyType) const;
    void HasTrophy(eTrophyType) const;
    void CheckSaveIDChanged(void*);
    void SetMemoryCardData(void*);
    void GetMemoryCardData(void*);
    void GetMemoryCardDataSize() const;
    void SetMode(GameInfoManager::eGameModes);
    void IsUserQualified(GameInfoManager::eGameModes) const;
    void GetCup(GameInfoManager::eGameModes);
    void GetNumHumanTeams();
    void IncreaseGameNumber(bool);
    void IncreaseRoundNumber();
    void DetermineNextMatchups(int);
    void SetupKnockoutRound(short);
    void SetupTournamentKnockout(eTeamID*, eSidekickID*);
    void SetupBowserKnockout();
    void SetupRoundRobinSchedule(eTeamID*, eSidekickID*);
    void ResetPlayingSides();
    void GetNumPlayers() const;
    void SetPlayingSide(unsigned short, short);
    void GetPlayingSide(unsigned short) const;
    void PickStadium(bool, eStadiumID) const;
    void SetStadium(eStadiumID);
    void GetUserSelectedCupTeam() const;
    void GetNumGamesPerRound(int) const;
    void GetFirstRoundNumber() const;
    void GetPreviousRoundNumber(short) const;
    void GetNextRoundNumber(short) const;
    void GetCurrentRoundNumber() const;
    void SetResultsOfLastUserGame(eUserGameResult);
    void GetResultsOfLastUserGame() const;
    void SetUserSelectedCupSidekick(eSidekickID);
    void SetUserSelectedCupTeam(eTeamID);
    void GetMatchupInfo(short, unsigned short) const;
    void GetStadium() const;
    void SetPreviousTeamStats();
    void pGetTeamStatsByIndex(unsigned short);
    void GetTeamStatsByIndex(unsigned short);
    void GetNumRounds() const;
    void GetNumPlayingTeams() const;
    void SetSidekick(short, eSidekickID);
    void GetSidekick(short) const;
    void SetTeam(short, eTeamID);
    void GetTeam(short) const;
    ~GameInfoManager();
    GameInfoManager();

    static nlSingleton<GameInfoManager> s_pInstance;
};

// class Cup<8, 14>
// {
// public:
//     void GetTeamStats(int);
//     void GetSaveDataSize() const;
//     void DeserializeData(void*);
//     void SerializeData(void*) const;
//     void GetGameInfo(int, int);
//     void GetNumTeams();
//     void GetNumRounds();
//     void GetRoundResults(int);
// };

// class Cup<8, 7>
// {
// public:
//     void GetTeamStats(int);
//     void GetSaveDataSize() const;
//     void DeserializeData(void*);
//     void SerializeData(void*) const;
//     void GetGameInfo(int, int);
//     void GetNumTeams();
//     void GetNumRounds();
//     void GetRoundResults(int);
// };

// class Cup<6, 10>
// {
// public:
//     void GetSaveDataSize() const;
//     void DeserializeData(void*);
//     void SerializeData(void*) const;
//     void GetGameInfo(int, int);
//     void GetTeamStats(int);
//     void GetNumTeams();
//     void GetNumRounds();
//     void GetRoundResults(int);
// };

// class Cup<4, 6>
// {
// public:
//     void GetSaveDataSize() const;
//     void DeserializeData(void*);
//     void SerializeData(void*) const;
//     void GetGameInfo(int, int);
//     void GetTeamStats(int);
//     void GetNumTeams();
//     void GetNumRounds();
//     void GetRoundResults(int);
// };

// class Knockout<4>
// {
// public:
//     void GetSaveDataSize() const;
//     void DeserializeData(void*);
//     void SerializeData(void*) const;
//     void GetGameInfo(int, int);
//     void GetTeamStats(int);
//     void GetNumTeams();
//     void GetNumRounds();
//     void GetRoundResults(int);
// };

// class Cup<6, 5>
// {
// public:
//     void GetSaveDataSize() const;
//     void DeserializeData(void*);
//     void SerializeData(void*) const;
//     void GetGameInfo(int, int);
//     void GetTeamStats(int);
//     void GetNumTeams();
//     void GetNumRounds();
//     void GetRoundResults(int);
// };

// class Cup<4, 3>
// {
// public:
//     void GetSaveDataSize() const;
//     void DeserializeData(void*);
//     void SerializeData(void*) const;
//     void GetGameInfo(int, int);
//     void GetTeamStats(int);
//     void GetNumTeams();
//     void GetNumRounds();
//     void GetRoundResults(int);
// };

// class Spoil
// {
// public:
//     Spoil();
// };

// class CupRecord
// {
// public:
//     CupRecord();
// };

// class BaseCup
// {
// public:
//     void SerializeData(void*) const;
//     void DeserializeData(void*);
//     void GetSaveDataSize() const;
// };

// class Config
// {
// public:
//     void Get<BasicString<char, Detail::TempStringAllocator>>(const char*, BasicString<char, Detail::TempStringAllocator>);
//     void TagValuePair::Get<BasicString<char, Detail::TempStringAllocator>>() const;
// };

// class BasicGameInfo
// {
// public:
//     BasicGameInfo();
// };

#endif // _GAMEINFO_H_
