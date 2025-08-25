#include "Game/BaseGameSceneManager.h"

#include "Game/FE/FESceneManager.h"

#include "NL/nlConfig.h"

// /**
//  * Offset/Address/Size: 0x64 | 0x80096B94 | size: 0x4
//  */
// void IntroMovieScene::PlayScreenBackSFX()
// {
// }

// /**
//  * Offset/Address/Size: 0x60 | 0x80096B90 | size: 0x4
//  */
// void IntroMovieScene::PlayScreenForwardSFX()
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x80096B30 | size: 0x60
//  */
// IntroMovieScene::~IntroMovieScene()
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x80096AF8 | size: 0x38
//  */
// void SlideMenuList::SetSlide()
// {
// }

/**
 * Offset/Address/Size: 0x54 | 0x80096AF0 | size: 0x8
 */
// void BaseSceneHandler::SetPresentation(FEPresentation*)
// {
// }

/**
 * Offset/Address/Size: 0x50 | 0x80096AEC | size: 0x4
 */
// void BaseSceneHandler::InitializeSubHandlers()
// {
// }

/**
 * Offset/Address/Size: 0x8 | 0x80096AA4 | size: 0x48
 */
// BaseSceneHandler::~BaseSceneHandler()
// {
// }

/**
 * Offset/Address/Size: 0x0 | 0x80096A9C | size: 0x8
 */
// void BaseSceneHandler::SetVisible(bool)
// {
// }

/**
 * Offset/Address/Size: 0x142C | 0x800969E8 | size: 0xB4
 */
BaseGameSceneManager::BaseGameSceneManager()
{
    m_count = 0;
    for (int i = 0; i < MAX_SCENE_COUNT; ++i)
    {
        m_types[i] = SceneList_None;
        m_handlers[i] = 0;
    }
}

/**
 * Offset/Address/Size: 0x13B0 | 0x8009696C | size: 0x7C
 */
BaseGameSceneManager::~BaseGameSceneManager()
{
    while (m_count != 0)
    {
        this->Pop();
    }
}

/**
 * Offset/Address/Size: 0x324 | 0x800958E0 | size: 0x108C
 */
BaseSceneHandler* BaseGameSceneManager::Push(SceneList sceneType, ScreenMovement movement, bool shouldCallVirtual)
{
    // Call virtual method if requested
    if (shouldCallVirtual)
    {
        this->Push(SceneList_0, ScreenMovement_0, false);
    }

    // Special case: SceneList_30 (0x1E) becomes SceneList_1
    if (sceneType == SceneList_30)
    {
        sceneType = SceneList_1;
    }

    // Get global config and find TVP setting
    Config* config = Config::Global();
    SetTagValuePair* tvp = config->FindTvp("fev2");

    // Handle TVP value based on type
    if (tvp->m_unk_0x04 == 0)
    {
        config->Set("fev2", false);
    }
    else if (tvp->m_unk_0x04 == 1)
    {
        // LexicalCast<b,i>
    }
    else if (tvp->m_unk_0x04 == 2)
    {
        // LexicalCast<b,f>
    }
    else if (tvp->m_unk_0x04 == 3)
    {
        // LexicalCast<b,PCc>
    }

    // Special handling for SceneList_3
    if (sceneType == SceneList_3)
    {
        this->Push(SceneList_1, ScreenMovement_0, false);
    }

    // // Get scene entry from table
    // SceneEntryTable* entryTable = &SceneEntryTable[sceneType];
    // const char* sceneName = entryTable->name;

    // // Get config again for second TVP lookup
    // config = Config::Global();
    // tvp = config->FindTvp("fev2");

    // // Handle TVP value again (same logic as above)
    // if (tvp->value == 0)
    // {
    //     config->Set("fev2", false);
    // }
    // else if (tvp->value == 1)
    // {
    //     // LexicalCast<b,i>
    // }
    // else if (tvp->value == 2)
    // {
    //     // LexicalCast<b,f>
    // }
    // else if (tvp->value == 3)
    // {
    //     // LexicalCast<b,PCc>
    // }

    // // Special handling for SceneList_2 based on build flags
    // if (sceneType == SceneList_2)
    // {
    //     if (g_e3_Build || g_Europe)
    //     {
    //         sceneName = "art/fe/start_screen_v2_german.fen";
    //     }
    //     else if (g_Language == 5)
    //     {
    //         sceneName = "art/fe/start_screen_jpn.fen";
    //     }
    // }

    // // Special handling for SceneList_8 based on build flags
    // if (sceneType == SceneList_8 && g_e3_Build)
    // {
    //     sceneName = "art/fe/choose_captains_vLeeptsig.fen";
    // }

    // Create scene based on scene type using jump table
    BaseSceneHandler* scene = nullptr;

    // switch (sceneType)
    // {
    // case SceneList_0:
    // case SceneList_1:
    //     scene = new BackgroundScene();
    //     break;

    // case SceneList_2:
    //     scene = new TitleScene();
    //     break;

    // case SceneList_3:
    //     scene = new SHMainMenu();
    //     break;

    // case SceneList_4:
    // case SceneList_5:
    // case SceneList_6:
    // case SceneList_7:
    //     scene = new SHChooseSides2(static_cast<SHChooseSides2::eCSContext>(sceneType - SceneList_4));
    //     break;

    // case SceneList_8:
    //     scene = new ChooseCaptainsSceneV2(ChooseCaptainsSceneV2::SceneType_0);
    //     break;

    // case SceneList_9:
    //     scene = new StadiumSelectSceneV2();
    //     break;

    // case SceneList_10:
    //     scene = new CupCheaterScene();
    //     break;

    // case SceneList_11:
    // case SceneList_12:
    //     scene = new BackgroundScene();
    //     break;

    // case SceneList_13:
    // case SceneList_14:
    //     scene = new ChooseCupSceneV2(sceneType == SceneList_14);
    //     break;

    // case SceneList_15:
    // case SceneList_16:
    //     scene = new CupChooseCaptainSceneV2(sceneType == SceneList_16);
    //     break;

    // case SceneList_17:
    // case SceneList_18:
    // case SceneList_19:
    // case SceneList_20:
    // case SceneList_21:
    // case SceneList_22:
    // case SceneList_23:
    // case SceneList_24:
    //     scene = new CupHubScene(sceneType >= SceneList_19, sceneType >= SceneList_21);
    //     break;

    // case SceneList_25:
    //     scene = new SuperTeamScene();
    //     break;

    // case SceneList_26:
    //     scene = new FEPopupMenu();
    //     break;

    // case SceneList_27:
    //     scene = new SpoilsScene();
    //     break;

    // case SceneList_28:
    //     scene = new ScrollingTickerScene();
    //     break;

    // case SceneList_29:
    //     scene = new BackgroundScene();
    //     break;

    // case SceneList_30:
    //     scene = new SaveLoadScene(SaveLoadScene::eSaveLoadMode_0);
    //     break;

    // case SceneList_31:
    //     scene = new SaveLoadScene(SaveLoadScene::eSaveLoadMode_3);
    //     break;

    // case SceneList_32:
    //     scene = new SaveLoadScene(SaveLoadScene::eSaveLoadMode_2);
    //     break;

    // case SceneList_33:
    //     scene = new SaveLoadScene(SaveLoadScene::eSaveLoadMode_4);
    //     break;

    // case SceneList_34:
    //     scene = new SaveLoadScene(SaveLoadScene::eSaveLoadMode_0);
    //     break;

    // case SceneList_35:
    //     scene = new TournSetParamsScene();
    //     break;

    // case SceneList_36:
    //     scene = new TournTeamSetupSceneV2();
    //     break;

    // case SceneList_37:
    //     scene = new OptionsScene();
    //     break;

    // case SceneList_38:
    //     scene = new CrossFaderScene();
    //     break;

    // case SceneList_39:
    //     scene = new CupOptionsScene(SceneList_15, SceneList_13);
    //     break;

    // case SceneList_40:
    //     scene = new CupOptionsScene(SceneList_16, SceneList_14);
    //     break;

    // case SceneList_41:
    //     scene = new CupOptionsScene(SceneList_25, SceneList_24);
    //     break;

    // case SceneList_42:
    //     scene = new SuperLoadingScene();
    //     break;

    // case SceneList_43:
    //     scene = new CupTrophyScene();
    //     break;

    // case SceneList_44:
    //     scene = new MilestoneTrophyScene();
    //     break;

    // case SceneList_45:
    //     scene = new BraggingRightsScene();
    //     break;

    // case SceneList_46:
    //     scene = new BraggingRightsOverlay();
    //     break;

    // case SceneList_47:
    //     scene = new MoviePlayerScene();
    //     break;

    // case SceneList_48:
    //     scene = new QuickGameplayOptionsScene();
    //     break;

    // case SceneList_49:
    //     scene = new LoadingTransitionScene();
    //     break;

    // case SceneList_50:
    //     scene = new HealthWarningSceneV2();
    //     break;

    // case SceneList_51:
    //     // Special NLG logo movie scene
    //     scene = new NLGLogoMovieScene();
    //     // Set movie details based on build flags
    //     if (GameInfoManager::GetInstance()->GetSomeFlag())
    //     {
    //         scene->SetMovieDetails("movies/nlgintrowide.thp", true, false);
    //     }
    //     else
    //     {
    //         scene->SetMovieDetails("movies/nlgintrofull.thp", true, false);
    //     }
    //     break;

    // case SceneList_52:
    //     // Special intro movie scene
    //     scene = new IntroMovieScene();
    //     scene->SetMovieDetails("intromovie.thp", true, false);
    //     break;

    // case SceneList_53:
    //     scene = new CreditScene();
    //     break;

    // case SceneList_54:
    //     scene = new ProgressiveScanScene(false);
    //     break;

    // case SceneList_55:
    //     scene = new ProgressiveScanScene(true);
    //     break;

    // case SceneList_56:
    //     scene = new PauseMenuScene(PauseMenuScene::eScreenContext_0);
    //     break;

    // case SceneList_57:
    //     scene = new SHChooseSides2(SHChooseSides2::eCSContext_4);
    //     break;

    // case SceneList_58:
    //     scene = new PauseOptionsScene(PauseOptionsScene::Mode_0);
    //     break;

    // case SceneList_59:
    //     scene = new PauseOptionsScene(PauseOptionsScene::Mode_1);
    //     break;

    // case SceneList_60:
    //     scene = new PausePostGameScene();
    //     break;

    // case SceneList_61:
    //     scene = new PauseMenuScene(PauseMenuScene::eScreenContext_1);
    //     break;

    // case SceneList_62:
    //     scene = new LessonScene();
    //     break;

    // case SceneList_63:
    //     scene = new LessonSelectScene();
    //     break;

    // case SceneList_64:
    //     scene = new LessonMoviePlayerScene();
    //     break;

    // case SceneList_65:
    //     scene = new HUDOverlay();
    //     break;

    // case SceneList_66:
    //     scene = new InGameTextOverlay();
    //     break;

    // case SceneList_67:
    //     scene = new FEPopupMenu();
    //     break;

    // case SceneList_68:
    //     scene = new SummaryOverlay(SummaryOverlay::eSummaryContext_0);
    //     break;

    // case SceneList_69:
    //     scene = new SummaryOverlay(SummaryOverlay::eSummaryContext_1);
    //     break;

    // case SceneList_70:
    //     scene = new GoalOverlay();
    //     break;

    // case SceneList_71:
    //     scene = new BraggingRightsOverlay();
    //     break;

    // case SceneList_72:
    //     scene = new DemoOverlay();
    //     break;

    // case SceneList_73:
    //     scene = new WinnerOverlay();
    //     break;

    // case SceneList_74:
    //     scene = new NSNMessengerScene();
    //     break;

    // case SceneList_75:
    //     scene = new STSX2Overlay();
    //     break;

    // case SceneList_76:
    //     scene = new BaseSceneHandler();
    //     break;

    // default:
    //     break;
    // }

    // // Queue the scene push with FESceneManager
    // FESceneManager* feManager = FESceneManager::GetInstance();
    // feManager->QueueScenePush(scene, sceneName);

    // // Store scene type and handler in arrays
    // m_types[m_count] = sceneType;
    // m_handlers[m_count] = scene;
    // m_count++;

    // // Play audio based on movement type
    // if (movement == ScreenMovement_1)
    // {
    //     FEAudio::PlayAnimAudioEvent("sfx_screen_forward", false);
    // }
    // else if (movement == ScreenMovement_2)
    // {
    //     FEAudio::PlayAnimAudioEvent("sfx_screen_back", false);
    // }

    return scene;
}

/**
 * Offset/Address/Size: 0x2D8 | 0x80095894 | size: 0x4C
 */
BaseSceneHandler* BaseGameSceneManager::GetScene(SceneList scene)
{
    BaseSceneHandler* handler = NULL;

    for (u32 i = 0; i < m_count; ++i)
    {
        if (m_types[i] == scene)
        {
            handler = m_handlers[i];
            break;
        }
    }

    return handler;
}

/**
 * Offset/Address/Size: 0x288 | 0x80095844 | size: 0x50
 */
void BaseGameSceneManager::Pop()
{
    FESceneManager* sceneManager = FESceneManager::s_pInstance->s_pInstance;
    sceneManager->QueueScenePop();

    m_handlers[m_count] = 0;
    m_count = (m_count - 1);
}

/**
 * Offset/Address/Size: 0x23C | 0x800957F8 | size: 0x4C
 */
void BaseGameSceneManager::PopEntireStack()
{
    while (m_count != 0)
    {
        this->Pop();
    }
}

/**
 * Offset/Address/Size: 0x1F4 | 0x800957B0 | size: 0x48
 */
int BaseGameSceneManager::GetSceneType(BaseSceneHandler* handler)
{
    // Iterate rows; when mHandlers[i] == handler, return mTypes[i], else -2. :contentReference[oaicite:10]{index=10}
    for (u32 i = 0; i < m_count; ++i)
    {
        if (m_handlers[i] == handler)
        {
            return m_types[i];
        }
    }
    return -2;
}

/**
 * Offset/Address/Size: 0x1C0 | 0x8009577C | size: 0x34
 */
bool BaseGameSceneManager::IsOnStack(SceneList scene)
{
    for (u32 i = 0; i < m_count; ++i)
    {
        // if (m_types[i].m_type == scene.m_type)
        // if (*(int*)&m_types[i] == *(int*)&scene)
        if (m_types[i] == scene)
            return true;
    }
    return false;
}

/**
 * Offset/Address/Size: 0x68 | 0x80095624 | size: 0x158
 */
void BaseGameSceneManager::GetFileName(SceneList)
{
}

/**
 * Offset/Address/Size: 0x0 | 0x800955BC | size: 0x68
 */
void BaseGameSceneManager::PushLoadingScene(bool clearStack)
{
    if (clearStack)
    {
        this->Pop();
    }

    BaseSceneHandler* handler = Push((SceneList)0x2B, ScreenMovement_1, false);
    handler->m_unk_0x1C = 0;
    // this->unk0->unkC(this, 0x2B, 1, 0)->unk1C = 0;
    // handler->SetVisible(false);
}
