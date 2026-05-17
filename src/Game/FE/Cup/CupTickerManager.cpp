#include "Game/FE/Cup/CupTickerManager.h"
#include "Game/FE/feScrollText.h"
#include "NL/nlFormat.h"

template <typename T, typename R>
Detail::MemFunImpl<R, void (T::*)()> MemFun(void (T::*)());

template <typename R, typename F, typename A>
BindExp1<R, F, A> Bind(F fn, const A& arg);

typedef Detail::MemFunImpl<void, void (CupTickerManager::*)()> MemFunImpl_CupTickerManager_v;
typedef BindExp1<void, MemFunImpl_CupTickerManager_v, CupTickerManager*> BindExp1_vfmfcp;
typedef Function0<void>::FunctorImpl<BindExp1_vfmfcp> FunctorImpl_vfmfcp;

struct gl_ScreenInfo
{
    int ScreenWidth;
};

extern gl_ScreenInfo* glGetScreenInfo();

class GameInfoManager;

template <typename T>
class nlSingleton
{
public:
    static T* s_pInstance;
};

extern "C" bool IsInTournamentMode__15GameInfoManagerCFv(void*);
extern "C" short GetCurrentRoundNumber__15GameInfoManagerCFv(void*);
extern "C" short GetFirstRoundNumber__15GameInfoManagerCFv(void*);
extern "C" short GetPreviousRoundNumber__15GameInfoManagerCFs(void*, short);
extern "C" unsigned short GetNumGamesPerRound__15GameInfoManagerCFi(void*, int);
extern "C" void* GetMatchupInfo__15GameInfoManagerCFsUs(void*, short, unsigned short);
extern "C" int GetTeam__15GameInfoManagerCFs(void*, short);
extern "C" bool IsUserQualified__15GameInfoManagerCFQ215GameInfoManager10eGameModes(void*, int);
extern "C" bool IsInCupMode__15GameInfoManagerCFv(void*);
extern "C" unsigned long GetLOCTeamName__F7eTeamID(int);

struct GameInfoAccessor_CupTicker
{
    char _pad6C[0x6C];
    unsigned char mDoingKnockout;
    char _pad4948[0x48DB];
    int mTournamentMode;
    char _pad4954[8];
    int mCurrentMode;
    char _pad4960[8];
    void* mCurrentCup;
};

struct BaseCupAccessor_CupTicker
{
    char _padA[0xA];
    short mGameNumber;
};

// /**
//  * Offset/Address/Size: 0x0 | 0x800F5EBC | size: 0x38
//  */
// void Bind<void, Detail::MemFunImpl<void, void (CupTickerManager::*)()>, CupTickerManager*>(Detail::MemFunImpl<void, void (CupTickerManager::*)()>, CupTickerManager* const&)
// {
// }

// /**
//  * Offset/Address/Size: 0x1C48 | 0x800F5D94 | size: 0x128
//  */
// void Format<BasicString<unsigned short, Detail::TempStringAllocator>, const unsigned short*, const unsigned short*>(const BasicString<unsigned short, Detail::TempStringAllocator>&, const unsigned short* const&, const unsigned short* const&)
// {
// }

// /**
//  * Offset/Address/Size: 0xF58 | 0x800F50A4 | size: 0xCF0
//  */
// void FormatImpl<BasicString<unsigned short, Detail::TempStringAllocator>>::operator%<BasicString<unsigned short, Detail::TempStringAllocator>>(const BasicString<unsigned short, Detail::TempStringAllocator>&)
// {
// }

// /**
//  * Offset/Address/Size: 0xE30 | 0x800F4F7C | size: 0x128
//  */
// void Format<BasicString<unsigned short, Detail::TempStringAllocator>, BasicString<unsigned short, Detail::TempStringAllocator>, BasicString<unsigned short, Detail::TempStringAllocator>>(const BasicString<unsigned short, Detail::TempStringAllocator>&, const BasicString<unsigned short, Detail::TempStringAllocator>&, const BasicString<unsigned short, Detail::TempStringAllocator>&)
// {
// }

// /**
//  * Offset/Address/Size: 0x140 | 0x800F428C | size: 0xCF0
//  */
// void FormatImpl<BasicString<unsigned short, Detail::TempStringAllocator>>::operator%<const unsigned short*>(const unsigned short* const&)
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x800F414C | size: 0x140
//  */
// void Format<BasicString<unsigned short, Detail::TempStringAllocator>, const unsigned short*, const unsigned short*, unsigned short[16], unsigned short[16]>(const BasicString<unsigned short, Detail::TempStringAllocator>&, const unsigned short* const&, const unsigned short* const&, const unsigned short(&)[16], const unsigned short(&)[16])
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x800F4130 | size: 0x1C
//  */
// void MemFun<CupTickerManager, void>(void (CupTickerManager::*)())
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x800F40D4 | size: 0x5C
//  */
// void Function0<void>::FunctorImpl<BindExp1<void, Detail::MemFunImpl<void, void (CupTickerManager::*)()>, CupTickerManager*>>::~FunctorImpl()
// {
// }

/**
 * Offset/Address/Size: 0x78 | 0x800F40A4 | size: 0x30
 */
template <>
void Function0<void>::FunctorImpl<BindExp1_vfmfcp>::operator()()
{
    (mBind.mArg->*(mBind.mFuncPtr.mMemFun))();
}

// /**
//  * Offset/Address/Size: 0x0 | 0x800F402C | size: 0x78
//  */
// void Function0<void>::FunctorImpl<BindExp1<void, Detail::MemFunImpl<void, void (CupTickerManager::*)()>, CupTickerManager*>>::Clone() const
// {
// }

// /**
//  * Offset/Address/Size: 0xBC | 0x800F3E24 | size: 0x208
//  */
// void BasicString<unsigned short, Detail::TempStringAllocator>::AppendInPlace<Detail::TempStringAllocator>(const BasicString<unsigned short, Detail::TempStringAllocator>&)
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x800F3D68 | size: 0xBC
//  */
// void BasicString<unsigned short, Detail::TempStringAllocator>::Append<Detail::TempStringAllocator>(const BasicString<unsigned short, Detail::TempStringAllocator>&) const
// {
// }

/**
 * Offset/Address/Size: 0x1D90 | 0x800F3D58 | size: 0x10
 */
CupTickerManager::CupTickerManager()
{
    mTicker = 0;
    mState = CUP_TICKER_STATE_0;
}

/**
 * Offset/Address/Size: 0x1C90 | 0x800F3C58 | size: 0x100
 */
CupTickerManager::~CupTickerManager()
{
    if (mTicker != 0)
    {
        delete mTicker;
    }
}

/**
 * Offset/Address/Size: 0x1968 | 0x800F3930 | size: 0x328
 * TODO: 95.99% match - mTicker load/store scheduling, string init ordering,
 * and cleanup r30/r31 register allocation differ due to -inline deferred vs -inline auto.
 */
void CupTickerManager::SetTickerTextInstance(TLTextInstance* tickerText)
{
    if (mTicker)
    {
        mTicker->ApplyNewTextInstancePointer(tickerText, 0.0f, 1.0f);
    }
    else
    {
        gl_ScreenInfo* screenInfo = glGetScreenInfo();
        mTicker = new ((FEScrollText*)nlMalloc(sizeof(FEScrollText), 0x20, true))
            FEScrollText(tickerText, 0, screenInfo->ScreenWidth + 0x32);

        {
            BindExp1_vfmfcp bind = Bind<void, MemFunImpl_CupTickerManager_v, CupTickerManager*>(
                MemFun<CupTickerManager, void>(&CupTickerManager::CreateNewMessage), this);

            Function<FnVoidVoid> callback;
            callback.mTag = FUNCTOR;

            FunctorImpl_vfmfcp* functor = new ((FunctorImpl_vfmfcp*)nlMalloc(sizeof(FunctorImpl_vfmfcp), 8, false))
                FunctorImpl_vfmfcp(bind);
            callback.mFunctor = functor;

            *(Function<FnVoidVoid>*)&mTicker->m_messageFinishedCB = callback;
        }

        this->CreateNewMessage();
    }

    BasicStringInternal* data = (BasicStringInternal*)nlMalloc(0x10, 8, true);
    if (data)
    {
        const unsigned short* src = mMessageBuffer;
        data->mData = 0;
        const unsigned short* ptr = src;
        data->mSize = 0;
        data->mCapacity = 0;

        while (*ptr++)
        {
            data->mSize++;
        }

        data->mSize++;
        data->mData = (char*)nlMalloc((data->mSize + 1) * 2, 8, true);
        data->mCapacity = data->mSize;

        int i = 0;
        int j = i;
        while (i < data->mSize)
        {
            *(unsigned short*)(data->mData + j) = *src;
            i++;
            src++;
            j += 2;
        }

        data->mRefCount = 1;
    }

    BasicStringInternal* msgData = data;
    mTicker->SetDisplayMessage(*(const BasicString<unsigned short, Detail::TempStringAllocator>*)&msgData);

    data = msgData;
    if (data)
    {
        if (--data->mRefCount == 0)
        {
            if (data)
            {
                if (data)
                {
                    delete[] data->mData;
                }
                if (data)
                {
                    nlFree(data);
                }
            }
        }
    }
}

struct LOCHeader
{
    char Thumbprint[4];
    unsigned long Version;
    unsigned long Language;
    unsigned long StringCount;
    unsigned long Flags;
};

class nlLocalization
{
public:
    struct StringLookup
    {
        unsigned long hash;
        unsigned long StringOffset;
        operator unsigned long() const { return hash; }
    };
    LOCHeader* m_pFile;
    StringLookup* m_LookupTable;
    unsigned short* m_FirstString;
};

extern nlLocalization* g_pLocalization;
extern unsigned short LocalizationTableNotFound[];
extern unsigned short MissingLocString[];

template <typename T, typename K>
T* nlBSearch(const K& key, T* table, int count);

extern "C" unsigned long GetLOCModeName__FQ215GameInfoManager10eGameModes(int);
extern "C" unsigned long GetLOCCharacterName__F7eTeamIDbb(int, bool, bool);
extern "C" int FindWinningTeam__15GameInfoManagerFv(void*);
extern "C" unsigned long nlStringLowerHash__FPCc(const char*);
extern "C" void nlStrToWcs__FPCcPUsUl(const char*, unsigned short*, unsigned long);

template <typename StringType, typename T1, typename T2, typename T3, typename T4>
StringType Format(const StringType& fmt, const T1& v1, const T2& v2, const T3& v3, const T4& v4);

#define GI_TOURNAMENT_MODE(gi) (*(int*)((char*)(gi) + 0x4948))
#define GI_CURRENT_MODE(gi)    (*(int*)((char*)(gi) + 0x4954))
#define GI_DOING_KNOCKOUT(gi)  (*(unsigned char*)((char*)(gi) + 0x6C))
#define GI_CURRENT_CUP(gi)     (*(void**)((char*)(gi) + 0x4960))

#define LOC_LOOKUP(_hashExpr, _locVar)                                                                                     \
    {                                                                                                                      \
        unsigned long _hash = (_hashExpr);                                                                                 \
        nlLocalization* _loc = g_pLocalization;                                                                            \
        if (_loc->m_LookupTable == 0)                                                                                      \
        {                                                                                                                  \
            (_locVar) = LocalizationTableNotFound;                                                                         \
        }                                                                                                                  \
        else                                                                                                               \
        {                                                                                                                  \
            nlLocalization::StringLookup* _entry = nlBSearch(_hash, _loc->m_LookupTable, (int)_loc->m_pFile->StringCount); \
            if (_entry != 0)                                                                                               \
            {                                                                                                              \
                (_locVar) = _loc->m_FirstString + _entry->StringOffset;                                                    \
            }                                                                                                              \
            else                                                                                                           \
            {                                                                                                              \
                (_locVar) = MissingLocString;                                                                              \
            }                                                                                                              \
        }                                                                                                                  \
    }

/**
 * Offset/Address/Size: 0x680 | 0x800F2648 | size: 0x12E8
 * TODO: 78.75% match - register allocation (r25/r28 vs r30/r31 for this/gameInfo),
 * extra mr r4,r0 in LOC_LOOKUP fallback paths, stack frame size 0x150 vs 0x140.
 */
void CupTickerManager::CreateNewMessage()
{
    bool tournamentLeague = false;
    GameInfoManager* gameInfo = nlSingleton<GameInfoManager>::s_pInstance;
    GameInfoAccessor_CupTicker* gameInfoMem = (GameInfoAccessor_CupTicker*)gameInfo;
    WideBasicString tickerMessage;
    bool messageDisplayed = false;
    unsigned short* locString = 0;

    if (IsInTournamentMode__15GameInfoManagerCFv(gameInfo) && gameInfoMem->mTournamentMode == 0)
    {
        tournamentLeague = true;
    }

    if (mTicker == 0)
    {
        return;
    }

    do
    {
        if (GetCurrentRoundNumber__15GameInfoManagerCFv(gameInfo) == -5)
        {
            if (mState != 5)
            {
                mState = (eCupTickerState)5;

                unsigned long modeHash = GetLOCModeName__FQ215GameInfoManager10eGameModes(GI_CURRENT_MODE(gameInfo));
                LOC_LOOKUP(modeHash, locString);
                WideBasicString modeWBS(locString);

                unsigned long charHash = GetLOCCharacterName__F7eTeamIDbb(
                    FindWinningTeam__15GameInfoManagerFv(gameInfo), false, false);
                LOC_LOOKUP(charHash, locString);
                WideBasicString charWBS(locString);

                LOC_LOOKUP(0x273CF730UL, locString);
                WideBasicString fmtWBS(locString);

                tickerMessage = Format<WideBasicString, WideBasicString, WideBasicString>(
                    fmtWBS, modeWBS, charWBS);
                break;
            }
            else
            {
                mState = (eCupTickerState)2;
                if (gameInfoMem->mTournamentMode != 0)
                {
                    continue;
                }
                BuildGoalTotalTickerMessage(tickerMessage, false);
                break;
            }
        }

        if (mState == 0)
        {
            if (gameInfoMem->mDoingKnockout)
            {
                LOC_LOOKUP(0x474DA1D4UL, locString);
                WideBasicString msg(locString);
                tickerMessage = msg;
            }
            else
            {
                LOC_LOOKUP(0x67493499UL, locString);
                WideBasicString msg(locString);
                tickerMessage = msg;
            }
            messageDisplayed = true;
        }

        if (mState == 1)
        {
            if (!tournamentLeague)
            {
                mState = (eCupTickerState)3;
            }
            else
            {
                LOC_LOOKUP(0xA81870D8UL, locString);
                WideBasicString msg(locString);
                tickerMessage = msg;
                messageDisplayed = true;
            }
        }

        if (mState == 2)
        {
            if (tournamentLeague
                && (GetCurrentRoundNumber__15GameInfoManagerCFv(gameInfo) != 0
                    || (*(short*)((char*)GI_CURRENT_CUP(gameInfo) + 0xA) != 0)))
            {
                BuildGoalTotalTickerMessage(tickerMessage, false);
                messageDisplayed = true;
            }
            else
            {
                mState = (eCupTickerState)3;
            }
        }

        if (mState == 3)
        {
            if (GetCurrentRoundNumber__15GameInfoManagerCFv(gameInfo) == -5)
            {
                mState = (eCupTickerState)4;
            }
            else
            {
                unsigned long team0LOC = GetLOCTeamName__F7eTeamID(
                    GetTeam__15GameInfoManagerCFs(gameInfo, 0));
                unsigned long team1LOC = GetLOCTeamName__F7eTeamID(
                    GetTeam__15GameInfoManagerCFs(gameInfo, 1));

                unsigned long fmtHash = nlStringLowerHash__FPCc("CUPHUB_TICKER_NEXT_MATCH");
                unsigned short* locString;
                LOC_LOOKUP(fmtHash, locString);
                WideBasicString fmtWBS(locString);
                unsigned short* team0LocString;
                unsigned short* team1LocString;
                LOC_LOOKUP(team0LOC, team0LocString);
                LOC_LOOKUP(team1LOC, team1LocString);

                tickerMessage = Format<WideBasicString, unsigned short*, unsigned short*>(
                    fmtWBS, team0LocString, team1LocString);
                messageDisplayed = true;
            }
        }

        if (mState == 4)
        {
            int mode = GI_CURRENT_MODE(gameInfo);
            if ((mode == 1
                    && !IsUserQualified__15GameInfoManagerCFQ215GameInfoManager10eGameModes(gameInfo, 2))
                || (mode == 2
                    && !IsUserQualified__15GameInfoManagerCFQ215GameInfoManager10eGameModes(gameInfo, 3)))
            {
                LOC_LOOKUP(0x751FA62FUL, locString);
                WideBasicString msg(locString);
                tickerMessage = msg;
                messageDisplayed = true;
            }
            else if (IsUserQualified__15GameInfoManagerCFQ215GameInfoManager10eGameModes(gameInfo, 2)
                     && IsUserQualified__15GameInfoManagerCFQ215GameInfoManager10eGameModes(gameInfo, 3)
                     && !IsUserQualified__15GameInfoManagerCFQ215GameInfoManager10eGameModes(gameInfo, 4)
                     && IsInCupMode__15GameInfoManagerCFv(gameInfo))
            {
                LOC_LOOKUP(0xEEC22902UL, locString);
                WideBasicString msg(locString);
                tickerMessage = msg;
                messageDisplayed = true;
            }
            else if ((mode == 4 || mode == 8) && !gameInfoMem->mDoingKnockout)
            {
                LOC_LOOKUP(0x4B50DF6AUL, locString);
                WideBasicString msg(locString);
                tickerMessage = msg;
                messageDisplayed = true;
            }
            else
            {
                mState = (eCupTickerState)5;
            }
        }

        if (mState == 5)
        {
            short firstRound = GetFirstRoundNumber__15GameInfoManagerCFv(gameInfo);
            short currentRound = GetCurrentRoundNumber__15GameInfoManagerCFv(gameInfo);
            if (currentRound == firstRound)
            {
                mState = CUP_TICKER_STATE_0;
            }
            else
            {
                short round = GetPreviousRoundNumber__15GameInfoManagerCFs(gameInfo, -7);
                unsigned short numGames = GetNumGamesPerRound__15GameInfoManagerCFi(gameInfo, round);
                int i = 0;
                while (i < (int)numGames)
                {
                    int* game;
                    if (GetCurrentRoundNumber__15GameInfoManagerCFv(gameInfo) == -1)
                    {
                        game = (int*)((char*)gameInfo + 0x3FF0);
                    }
                    else
                    {
                        game = (int*)GetMatchupInfo__15GameInfoManagerCFsUs(
                            gameInfo, round, (unsigned short)i);
                    }

                    unsigned long team0Name = GetLOCTeamName__F7eTeamID(game[0]);
                    unsigned long team1Name = GetLOCTeamName__F7eTeamID(game[1]);

                    unsigned long formatHash;
                    if (i == 0)
                    {
                        formatHash = 0x97372F0FUL;
                    }
                    else
                    {
                        formatHash = 0x3E3B44CAUL;
                    }

                    NLString score0Str = LexicalCast<NLString, int>((int)*(short*)((char*)game + 0x1C));
                    NLString score1Str = LexicalCast<NLString, int>((int)*(short*)((char*)game + 0x1E));

                    unsigned short wideScore0[16];
                    nlStrToWcs__FPCcPUsUl(score0Str.c_str(), wideScore0, 16);

                    unsigned short wideScore1[16];
                    nlStrToWcs__FPCcPUsUl(score1Str.c_str(), wideScore1, 16);

                    if (*(short*)((char*)game + 0x1C) > *(short*)((char*)game + 0x1E))
                    {
                        unsigned short* fmtLocString;
                        unsigned short* t0Str;
                        unsigned short* t1Str;
                        LOC_LOOKUP(formatHash, fmtLocString);
                        LOC_LOOKUP(team0Name, t0Str);
                        LOC_LOOKUP(team1Name, t1Str);
                        WideBasicString fmtWBS(fmtLocString);
                        tickerMessage = tickerMessage.Append(
                            Format<WideBasicString, unsigned short*, unsigned short*, unsigned short[16], unsigned short[16]>(
                                fmtWBS, t0Str, t1Str, wideScore0, wideScore1));
                    }
                    else
                    {
                        unsigned short* fmtLocString;
                        unsigned short* t1Str;
                        unsigned short* t0Str;
                        LOC_LOOKUP(formatHash, fmtLocString);
                        LOC_LOOKUP(team1Name, t1Str);
                        LOC_LOOKUP(team0Name, t0Str);
                        WideBasicString fmtWBS(fmtLocString);
                        tickerMessage = tickerMessage.Append(
                            Format<WideBasicString, unsigned short*, unsigned short*, unsigned short[16], unsigned short[16]>(
                                fmtWBS, t1Str, t0Str, wideScore1, wideScore0));
                    }

                    i++;
                }
                messageDisplayed = true;
            }
        }

        mState = (eCupTickerState)(((int)mState + 1) % 6);
    } while (!messageDisplayed);

    memcpy(mMessageBuffer, tickerMessage.c_str(), 0x400);
    WideBasicString displayMessage(mMessageBuffer);
    mTicker->SetDisplayMessage(displayMessage);
}

/**
 * Offset/Address/Size: 0x654 | 0x800F261C | size: 0x2C
 */
void CupTickerManager::Update(float dt)
{
    if (mTicker != NULL)
    {
        mTicker->Update(dt);
    }
}

// Stub to force template instantiations -- REMOVE once real callers exist.
void CupTickerManager_stub()
{
    typedef BasicString<unsigned short, Detail::TempStringAllocator> WideBasicString;
    typedef WideBasicString (*FmtFn)(const WideBasicString&, const WideBasicString&, const WideBasicString&);
    typedef WideBasicString (*FmtFnPCUs)(const WideBasicString&, const unsigned short* const&, const unsigned short* const&);

    WideBasicString s;
    volatile FmtFn fn = &Format<WideBasicString, WideBasicString, WideBasicString>;
    volatile FmtFnPCUs fn2 = &Format<WideBasicString, const unsigned short*, const unsigned short*>;
    WideBasicString s2 = fn(s, s, s);
}

union RECORDTYPE
{
    int mCharacterClass;
    int mTeamID;
    int mControllerID;
};

enum eType
{
    TYPE_INVALID = -1,
    TYPE_CHARACTER = 0,
    TYPE_TEAM = 1,
    TYPE_USER = 2,
};

struct PlayerStats
{
    unsigned short mNumShotsOnGoal;
    unsigned short mNumGoalsFor;
    unsigned short mNumGoalsAgainst;
    unsigned short mNumAssists;
    unsigned short mNumFouls;
    unsigned short mNumGamesPlayed;
    unsigned short mNumPowerupsUsed;
    unsigned short mNumPowerupsHit;
    unsigned short mNumShootToScoreGoals;
    unsigned short mNumPassesMade;
    unsigned short mNumPassesReceived;
    unsigned short mNumPassesIntercepted;
    unsigned short mNumHitsMade;
    unsigned short mNumSteals;
    unsigned short mNumGoalsOneTimers;
    unsigned short mNumSTSAttempts;
    unsigned short mNumPerfectPasses;
    unsigned long mBallPossessionTime;
    unsigned long mNumButtonPresses;
    RECORDTYPE mRecordType;
    eType mType;
};

enum eTeamID_Local
{
    TEAM_CTM_INVALID = -1
};

struct TeamStats
{
    int mTeamIndex;
    unsigned short mNumWins;
    unsigned short mNumLosses;
    unsigned short mNumOTLosses;
    unsigned short mNumPoints;
    PlayerStats mPlayerTotalStats;

    TeamStats(const TeamStats& other)
        : mTeamIndex(other.mTeamIndex)
        , mNumWins(other.mNumWins)
        , mNumLosses(other.mNumLosses)
        , mNumOTLosses(other.mNumOTLosses)
        , mNumPoints(other.mNumPoints)
        , mPlayerTotalStats(other.mPlayerTotalStats)
    {
    }
};

class GameInfoManager
{
public:
    int GetNumHumanTeams();
    unsigned short GetNumPlayingTeams() const;
    TeamStats GetTeamStatsByIndex(unsigned short index);
};

class StatsTracker;

extern "C" void GetSortedStats__12StatsTrackerFP11PlayerStatsiPii12ePlayerStats10eSortOrder(
    void*, PlayerStats*, int, int*, int, int, int);

/**
 * Offset/Address/Size: 0x3DC | 0x800F23A4 | size: 0x654
 * TODO: 92.74% match - 20 register-only diffs (r25-r31 allocation)
 */
void CupTickerManager::BuildGoalTotalTickerMessage(
    BasicString<unsigned short, Detail::TempStringAllocator>& result, bool bIsHuman)
{
    int numValid = 0;
    GameInfoManager* gameInfo = nlSingleton<GameInfoManager>::s_pInstance;

    int numTeams;
    if (bIsHuman)
    {
        numTeams = gameInfo->GetNumHumanTeams();
    }
    else
    {
        numTeams = (unsigned short)gameInfo->GetNumPlayingTeams();
    }

    PlayerStats playerStats[8];

    for (int i = 0; i < (int)gameInfo->GetNumPlayingTeams(); i++)
    {
        TeamStats teamStats = gameInfo->GetTeamStatsByIndex((unsigned short)i);

        if ((unsigned char)bIsHuman)
        {
            unsigned short humanTeams = *(unsigned short*)((char*)*(void**)((char*)gameInfo + 0x4960) + 0xC);
            if (humanTeams & (1 << (int)teamStats.mTeamIndex))
            {
                playerStats[numValid++] = teamStats.mPlayerTotalStats;
            }
        }
        else
        {
            playerStats[numValid++] = teamStats.mPlayerTotalStats;
        }
    }

    int sortedIndices[8];
    GetSortedStats__12StatsTrackerFP11PlayerStatsiPii12ePlayerStats10eSortOrder(
        nlSingleton<StatsTracker>::s_pInstance, playerStats, numTeams, sortedIndices, numTeams, 1, 1);

    int* pSorted = sortedIndices;
    PlayerStats* pStats = playerStats;

    for (int j = 0; j < numTeams; j++)
    {
        unsigned long teamNameHash = GetLOCTeamName__F7eTeamID(pStats[pSorted[0]].mRecordType.mTeamID);

        unsigned long formatHash;
        if (j == 0)
        {
            formatHash = 0xD517194DUL;
        }
        else
        {
            formatHash = 0x1DB17A6DUL;
        }

        int goals = (int)pStats[pSorted[0]].mNumGoalsFor;
        NLString goalsStr = LexicalCast<NLString, int>(goals);

        unsigned short wideGoals[16];
        nlStrToWcs__FPCcPUsUl(goalsStr.c_str(), wideGoals, 16);

        unsigned short* fmtLocStr;
        LOC_LOOKUP(formatHash, fmtLocStr);
        WideBasicString fmtWBS(fmtLocStr);

        unsigned short* teamNameLocStr;
        LOC_LOOKUP(teamNameHash, teamNameLocStr);

        WideBasicString formatted = Format<WideBasicString, const unsigned short*, unsigned short[16]>(
            fmtWBS, teamNameLocStr, wideGoals);
        result.AppendInPlace(formatted);

        pSorted++;
    }
}
