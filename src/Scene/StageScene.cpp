#include "StageScene.h"
#include <prim/seadRuntimeTypeInfo.h>
#include <heap/seadHeapMgr.h>
#include <prim/seadSafeString.h>

#include "Library/Audio/IUseAudioKeeper.h"
#include "Library/Audio/SimpleAudioUser.h"
#include "Library/Camera/CameraPoserFactory.h"
#include "Library/Demo/DemoDirector.h"
#include "Library/Demo/DemoSyncedEventKeeper.h"
#include "Library/Graphics/GraphicsInitArg.h"
#include "Library/Layout/LayoutInitInfo.h"
#include "Library/LiveActor/ActorInitInfo.h"
#include "Library/Placement/PlacementFunction.h"
#include "Library/Placement/PlacementInfo.h"
#include "Library/Resource/ResourceHolder.h"
#include "Library/Scene/ItemDirectorBase.h"
#include "Library/Scene/Scene.h"
#include "Library/Scene/SceneObjHolder.h"
#include "Library/Scene/SceneUtil.h"
#include "Library/Framework/GameFrameworkNx.h"
#include "Library/LiveActor/LiveActorKit.h"
#include "Library/Effect/EffectKeeper.h"
#include "Library/Stage/StageInfo.h"
#include "Library/Thread/FunctorV0M.h"
#include "Npc/NpcEventDirector.h"
#include "Project/Scene/SceneInitInfo.h"
#include "Quest/QuestInfoHolder.h"
#include "Scene/EventFlowSceneExecuteCtrl.h"
#include "Scene/ProjectActorFactory.h"
#include "Scene/ProjectCameraPoserFactory.h"
#include "Scene/ProjectSeNamedList.h"
#include "Scene/SceneAudioSystemPauseController.h"
#include "Scene/SceneObjFactory.h"
#include "System/Application.h"
#include "Scene/StageSceneStateWorldMap.h"
#include "Scene/StageSceneStateMiniGameRanking.h"
#include "Scene/ProjectItemDirector.h"
#include "Library/Draw/ChromakeyDrawer.h"
#include "Library/Layout/LayoutTextureRenderer.h"
#include "Library/Math/MathRandomUtil.h"
#include "Library/Network/NetworkSystem.h"
#include "System/GameDataFunction.h"
#include "System/GameDataHolder.h"
#include "Library/System/GameSystemInfo.h"
#include "Library/Data/DataStoreDirector.h"
#include "Library/Ranking/RankingDirector.h"
#include "Scene/ProjectDemoDirector.h"
#include "Library/Audio/AudioDirectorInitInfo.h"
#include "Library/Draw/GraphicsSystemInfo.h"
#include "Scene/DemoSoundSynchronizer.h"
#include "Library/Audio/AudioDirector.h"
#include "Library/Se/SeDirector.h"
#include "Scene/BgmAnimeSyncDirector.h"
#include "Scene/CollectBgmPlayer.h"
#include "Library/Path/ParabolicPath.h"
#include "Npc/NpcEventCtrlInfo.h"
#include "Event/EventDemoCtrl.h"

typedef void (StageScene::*StageSceneThreadFunc)(void);

StageScene::StageScene() : al::Scene("StageScene") {}
StageScene::~StageScene(){
    if(mDemoSyncedEventKeeper)
        mDemoSyncedEventKeeper->finalize();
    al::stopPadRumble(this);
    auto* gameFrameworkNx = sead::DynamicCast<al::GameFrameworkNx>(Application::instance()->getGameFramework());
    gameFrameworkNx->mHasNoScene = true;
    if(mChromakeyDrawer)
        mChromakeyDrawer->finalize();
    al::tryDeleteSceneObj(this, SceneObjID_PaintObjHolder);
    al::tryDeleteSceneObj(this, SceneObjID_alFriendsProfileDownloader);
    rs::getQuestInfoHolder(this)->finalizeForScene();
    alEffectEnvUtil::resetNatureDirector(this->mLiveActorKit->getEffectSystem());
    al::tryDeleteSceneObj(this, SceneObjID_PlayerHackStartTexKeeper);
    al::tryDeleteSceneObj(this, SceneObjID_TimeBalloonDirector);
    if(mStateMiniGameRanking){
        delete mStateMiniGameRanking;
        mStateMiniGameRanking = nullptr;
    }
    if(mLayoutTextureRenderer){
        delete mLayoutTextureRenderer;
        mLayoutTextureRenderer = nullptr;
    }
    if(mStateWorldMap){
        delete mStateWorldMap;
        mStateWorldMap = nullptr;
    }
}

namespace rs {
    bool isModeE3MovieRom();
    bool isModeMovieRom();
    bool isModeJungleGymRom();
    bool isModeDiverRom();

    void tryStartRaceStage(al::Scene*, GameDataHolder*);

    bool isKidsMode(const al::Scene*);
}

namespace CapManHeroDemoUtil {
    void initCapManHeroDemoDirector(const al::Scene*, const al::ActorInitInfo&);
}

namespace alGraphicsFunction {
    void invalidateCameraBlurSystem(al::Scene*);
}

namespace alAudioSystemFunction {
    void enableAudioMaximizer(const al::GameSystemInfo*);
}

namespace alDemoSyncedEventFunction {
    void tryCreateAndSetSeKeeper(al::DemoSyncedEventKeeper*, al::AudioDirector*, const char*);
}

namespace alEffectEnvUtil {
    void setNatureDirector(al::EffectSystem*, al::NatureDirector*);
}

namespace alCameraFunction {
    void validateCameraAreaKids(al::IUseCamera*);
}

namespace al {

    class StageInfo;
    class CameraPoserFactory;

    agl::DrawContext* getSceneDrawContext(const Scene*);
    sead::FrameBuffer* getSceneFrameBufferConsole(const Scene*);

    void tryGetPlacementInfoAndCount(PlacementInfo*, s32*, const StageInfo*, const char*);
    void getPlacementInfoByIndex(PlacementInfo*, const al::PlacementInfo&, s32);
    StageInfo* getStageInfoMap(const Scene*);
    void initGraphicsSystemInfo(Scene*, const char*, s32);
    void initItemDirector(Scene*, ItemDirectorBase*);
    void initDemoDirector(Scene*, al::DemoDirector*);
    void initAudioDirector3D(Scene*, const SceneInitInfo*, const AudioDirectorInitInfo*);
    void initSceneAudioKeeper(Scene*, const SceneInitInfo&, const char*);
    void setTriggerEventForStopAllBgm(const IUseAudioKeeper*, const FunctorBase&);
    void deactivateAudioEventController(const IUseAudioKeeper*);
    void initPadRumble(const Scene*, const SceneInitInfo&);
    void initNatureDirector(Scene*);
    void initLayoutInitInfo(LayoutInitInfo*, const al::Scene*, al::SceneInitInfo const&);
    void initActorInitInfo(ActorInitInfo*, const al::Scene*, const al::PlacementInfo*, const al::LayoutInitInfo*, const al::ActorFactory*, al::SceneMsgCtrl*, GameDataHolderBase*);
    void initCameraDirector(Scene*, const char*, s32, const CameraPoserFactory*);
    void initSceneCameraFovyDegree(Scene*, f32);
    void setNearClipDistance(const IUseCamera*, f32, s32);
    void setFarClipDistance(const IUseCamera*, f32, s32);
    float getSceneFrameBufferMainAspect(const Scene*);
    void setCameraAspect(Scene*, f32, f32);
    void initSnapShotCameraAudioKeeper(Scene*, IUseAudioKeeper*);

}

void StageScene::init(const al::SceneInitInfo& initInfo){
    mStageName = initInfo.initStageName;
    initDrawSystemInfo(initInfo);
    al::initRandomSeedByString(mStageName.cstr());
    al::GameFrameworkNx* framework;
    u32 vBlankWaitInterval;
    if(rs::isModeE3MovieRom() || rs::isModeMovieRom()){
        framework = sead::DynamicCast<al::GameFrameworkNx>(Application::instance()->getGameFramework());
        vBlankWaitInterval = 2;
    }else{
        framework = sead::DynamicCast<al::GameFrameworkNx>(Application::instance()->getGameFramework());
        vBlankWaitInterval = 1;
    }
    framework->setVBlankWaitInterval(vBlankWaitInterval);
    initLayoutKit(initInfo);
    al::addResourceCategory(sead::SafeString("シーン"), 0x200, sead::HeapMgr::instance()->getCurrentHeap());
    al::SceneObjHolder* sceneObjHolder = SceneObjFactory::createSceneObjHolder();
    initSceneObjHolder(sceneObjHolder);
    al::createSceneObj(this, SceneObjID_KidsModeLayoutAccessor);
    al::createSceneObj(this, SceneObjID_GuidePosInfoHolder);
    al::createSceneObj(this, SceneObjID_RouteGuideDirector);
    initAndLoadStageResource(mStageName.cstr(), initInfo.scenarioNo);
    GameDataHolder* dataHolder = (GameDataHolder*) initInfo.gameDataHolder;
    mGameDataHolder = dataHolder;
    mTimeBalloonSequenceInfo = dataHolder->getTimeBalloonSequenceInfo();
    dataHolder->getQuestInfoHolder()->initSceneObjHolder(getSceneObjHolder());
    rs::tryStartRaceStage(this, mGameDataHolder);
    mGameDataHolder->startStage(mStageName.cstr(), initInfo.scenarioNo);
    mGameDataHolder->setIsWaitingForStageStart(false);
    al::setSceneObj(this, mGameDataHolder, SceneObjID_GameDataHolder);
    al::setSceneObj(this, mGameDataHolder->getQuestInfoHolder(), SceneObjID_QuestInfoHolder);
    al::createSceneObj(this, SceneObjID_PaintObjHolder);
    al::createSceneObj(this, SceneObjID_FukankunZoomObjHolder);
    al::createSceneObj(this, SceneObjID_SphinxQuizRouteKillExecutor);
    al::createSceneObj(this, SceneObjID_GrowPlantDirector);
    al::createSceneObj(this, SceneObjID_CapManHeroDemoDirector);
    initScreenCoverCtrl();
    initSceneStopCtrl();
    al::GraphicsInitArg graphicsInitArg(al::getSceneDrawContext(this), al::getSceneFrameBufferConsole(this));
    al::PlacementInfo placementInfos;
    s32 placementInfoCount;
    al::tryGetPlacementInfoAndCount(&placementInfos, &placementInfoCount, al::getStageInfoMap(this), "ObjectList");
    bool foundMirror = false;
    //Is this if compiler generated for while loops too?
    if(placementInfoCount >= 1){
        //Set to false twice, might be compiler generated
        foundMirror = false;
        s32 i = 0;
        do {
            al::PlacementInfo placementInfo;
            al::getPlacementInfoByIndex(&placementInfo, placementInfos, i);
            foundMirror |= al::isObjectName(placementInfo, "Mirror");
            i++;
        } while(i < placementInfoCount && !foundMirror);
    }
    initLiveActorKitWithGraphics(graphicsInitArg, initInfo, 5120, 4, 2);
    al::initGraphicsSystemInfo(this, mStageName.cstr(), mScenarioNo);
    if(rs::isModeJungleGymRom() || rs::isModeDiverRom() || rs::isModeE3MovieRom(), rs::isModeMovieRom() || GameDataFunction::isHomeShipStage(mGameDataHolder))
        alGraphicsFunction::invalidateCameraBlurSystem(this);
    al::NetworkSystem* networkSystem = initInfo.gameSysInfo->networkSystem;
    al::DataStoreDirector* dataStoreDir = networkSystem->getDataStoreDirector();
    if(dataStoreDir)
        al::setSceneObj(this, dataStoreDir, SceneObjID_alDataStoreDirector);
    al::RankingDirector* rankingDir = networkSystem->getRankingDirector();
    if(rankingDir)
        al::setSceneObj(this, rankingDir, SceneObjID_alRankingDirector);
    ProjectItemDirector* itemDir = new ProjectItemDirector();
    al::initItemDirector(this, itemDir);
    mProjectItemDirector = itemDir;
    ProjectDemoDirector* demoDir = new ProjectDemoDirector(al::getScenePlayerHolder(this), mLiveActorKit->getGraphicsSystemInfo());
    al::initDemoDirector(this, demoDir);
    al::AudioDirectorInitInfo audioDirInitInfo = al::createAudioDirectorInitInfoForStageScene();
    al::GraphicsSystemInfo* graphicsSysInfo = mLiveActorKit->getGraphicsSystemInfo();
    if(graphicsSysInfo)
        audioDirInitInfo.seDirectorInitInfo.occlusionCullingJudge = graphicsSysInfo->getOcclusionCullingJudge();
    al::initAudioDirector3D(this, &initInfo, &audioDirInitInfo);
    alAudioSystemFunction::enableAudioMaximizer(initInfo.gameSysInfo);
    mAudioSystemPauseController = new SceneAudioSystemPauseController(mAudioDirector);
    mSoundSynchronizer = new DemoSoundSynchronizer(initInfo.gameSysInfo->applicationMessageReciever, mAudioDirector);
    mStageStartAtmoSe = new al::SimpleAudioUser("StageStartAtmosSe", mAudioDirector);
    mSePlayerArea = new al::SimpleAudioUser("SePlayArea", mAudioDirector);
    mSnapShotCameraCtrl = new al::SimpleAudioUser("SnapShotCameraCtrl", mAudioDirector);
    mSeNamedList = new ProjectSeNamedList();
    al::initSceneAudioKeeper(this, initInfo, "StageSceneDefault");
    mAudioDirector->setPlayerHolder(al::getScenePlayerHolder(this));
    al::setTriggerEventForStopAllBgm(this, al::FunctorV0M<StageScene*, StageSceneThreadFunc>(this, &StageScene::stopCollectBgm));
    if(rs::isModeE3MovieRom()){
        al::SeDirector* seDir = mAudioDirector->getSeDirector();
        seDir->setMuteSeInPVList(mSeNamedList->getMuteSeInPVList());
        seDir->setMuteSeInPVListSize(mSeNamedList->getMuteSeInPVListSize());
    }
    if(rs::isModeMovieRom()){
        al::SeDirector* seDir = mAudioDirector->getSeDirector();
        seDir->setMuteSeInPVList(mSeNamedList->getMuteSeInPVList());
        seDir->setMuteSeInPVListSize(mSeNamedList->getMuteSeInPVListSize());
    }
    al::deactivateAudioEventController(this);
    BgmAnimeSyncDirector* bgmAnimeSyncDir = new BgmAnimeSyncDirector();
    mBgmAnimeSyncDirector = bgmAnimeSyncDir;
    al::setSceneObj(this, bgmAnimeSyncDir, SceneObjID_BgmAnimeSyncDirector);
    al::setSceneObj(this, mCollectBgmPlayer, SceneObjID_CollectBgmPlayer);
    if(mLiveActorKit->getDemoDirector()){
        al::DemoSyncedEventKeeper* demoSyncedEventKeeper = new al::DemoSyncedEventKeeper(mAudioDirector);
        mDemoSyncedEventKeeper = demoSyncedEventKeeper;
        alDemoSyncedEventFunction::tryCreateAndSetSeKeeper(demoSyncedEventKeeper, mAudioDirector, "StageScene");
    }
    al::initPadRumble(this, initInfo);
    al::initNatureDirector(this);
    alEffectEnvUtil::setNatureDirector(mLiveActorKit->getEffectSystem(), mLiveActorKit->getNatureDirector());
    ProjectActorFactory actorFactory;
    al::LayoutInitInfo layoutInitInfo;
    al::initLayoutInitInfo(&layoutInitInfo, this, initInfo);
    al::PlacementInfo placementInfo;
    al::ActorInitInfo actorInitInfo;
    al::initActorInitInfo(&actorInitInfo, this, &placementInfo, &layoutInitInfo, &actorFactory, nullptr, mGameDataHolder);
    CapManHeroDemoUtil::initCapManHeroDemoDirector(this, actorInitInfo);
    al::LiveActor* checkpointWarpCapActor = new al::LiveActor("チェックポイントワープ用帽子");
    mCheckpointWarpCapActor = checkpointWarpCapActor;
    al::initActorWithArchiveName(checkpointWarpCapActor, actorInitInfo, "MarioCap", "CheckpointFlagWarp");
    mCheckpointWarpCapActor->makeActorDead();
    mCheckpointWarpParabolicPath = new al::ParabolicPath(); 
    mDemoShine = new al::LiveActor("デモ用シャイン");
    al::LiveActor* demoPowerStarActor = new al::LiveActor("デモ用パワースター");
    al::initChildActorWithArchiveNameNoPlacementInfo(demoPowerStarActor, actorInitInfo, "PowerStar", "Demo");
    al::initChildActorWithArchiveNameNoPlacementInfo(mDemoShine, actorInitInfo, "PowerStar", "Demo");
    mDemoDotShine = new al::LiveActor("デモ用ドットシャイン");
    al::initChildActorWithArchiveNameNoPlacementInfo(mDemoDotShine, actorInitInfo, "ShineDot", "Demo");
    mDemoDotShine->kill();
    mProjectItemDirector->initPlayerDeadCoin(mGameDataHolder, actorInitInfo);
    mGameDataHolder->setUnkNumber(0);
    mLayoutTextureRenderer = new al::LayoutTextureRenderer();
    al::setSceneObj(this, mLayoutTextureRenderer, SceneObjID_alLayoutTextureRenderer);
    al::createSceneObj(this, SceneObjID_NpcEventCtrlInfo);
    mHtmlViewer = initInfo.gameSysInfo->htmlViewer;
    al::initCameraDirector(this, mStageName.cstr(), initInfo.scenarioNo, new ProjectCameraPoserFactory());
    if(rs::isKidsMode(this))
        alCameraFunction::validateCameraAreaKids(this);
    al::initSceneCameraFovyDegree(this, 40.0f);
    al::setNearClipDistance(this, 25.0f, 0);
    al::setFarClipDistance(this, 500000.0f, 0);
    al::setCameraAspect(this, al::getSceneFrameBufferMainAspect(this), al::getSceneFrameBufferMainAspect(this));
    al::initSnapShotCameraAudioKeeper(this, mSnapShotCameraCtrl);
    EventFlowSceneExecuteCtrl* eventFlowExecCtrl = new EventFlowSceneExecuteCtrl();
    mNpcEventDirector = new NpcEventDirector(al::getScenePlayerHolder(this), mLiveActorKit->getCameraDirector(), mLiveActorKit->getCollisionDirector(), initInfo.gameSysInfo->messageSystem, eventFlowExecCtrl);
    mNpcEventDirector->init(actorInitInfo);
    al::setSceneObj(this, mNpcEventDirector->getNpcEventCtrlInfo(), SceneObjID_NpcEventCtrlInfo);
    al::setSceneObj(this, mNpcEventDirector->getEventDemoCtrl(), SceneObjID_EventDemoCtrl);
    al::createSceneObj(this, SceneObjID_TalkNpcParamHolder);
    al::createSceneObj(this, SceneObjID_TalkNpcSceneEventSwitcher);
}
