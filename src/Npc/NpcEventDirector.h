#pragma once

#include "Library/Collision/IUseCollision.h"
#include "Library/Camera/IUseCamera.h"
#include "Library/Execute/IUseExecutor.h"
#include "Library/Message/IUseMessageSystem.h"
#include "Library/Nerve/NerveExecutor.h"
#include "Library/Scene/IUseSceneObjHolder.h"

namespace al{
class PlayerHolder;
class ActorInitInfo;
}

class EventFlowSceneExecuteCtrl;
class NpcEventCtrlInfo;
class EventDemoCtrl;

class NpcEventDirector : public al::NerveExecutor, public al::IUseCamera, public al::IUseCollision, public al::IUseExecutor, public al::IUseMessageSystem, public al::IUseSceneObjHolder{
public:
    NpcEventDirector(const al::PlayerHolder*, al::CameraDirector*, al::CollisionDirector*, const al::MessageSystem*, EventFlowSceneExecuteCtrl*);
    ~NpcEventDirector() override;

    al::NerveKeeper * getNerveKeeper() const override;
    virtual void init(const al::ActorInitInfo&);
    void execute() override;
    al::CameraDirector * getCameraDirector() const override;
    al::CollisionDirector * getCollisionDirector() const override;
    al::SceneObjHolder * getSceneObjHolder() const override;
    const al::MessageSystem * getMessageSystem() const override;

    NpcEventCtrlInfo* getNpcEventCtrlInfo(){ return mNpcEventCtrlInfo; }
    EventDemoCtrl* getEventDemoCtrl(){ return mEventDemoCtrl; }
private:
    void* gap1;
    NpcEventCtrlInfo* mNpcEventCtrlInfo;
    void* gap2[2];
    EventDemoCtrl* mEventDemoCtrl;
    void* filler[10];
};

static_assert(sizeof(NpcEventDirector) == 0xB0, "NpcEventDirector size");
