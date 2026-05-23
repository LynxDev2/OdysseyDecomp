#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/Event/IEventFlowEventReceiver.h"
#include "Library/LiveActor/LiveActor.h"
#include "Library/Scene/ISceneObj.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class RaceManRace : public al::LiveActor, public al::IEventFlowEventReceiver, public al::ISceneObj {
public:
    RaceManRace(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool startCountDown();
    void startRace();
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool receiveEvent(const al::EventFlowEventData* eventData);
    bool trySetRaceManStep(s32 raceManStep);
    void checkGoalRaceMan();
    void control() override;
    void exeStartWait();
    s32 calcRank() const;
    s32 getAttachedGoalActorNum() const;
    s32 getPlayerRankResult() const;
    bool isGoalPlayer() const;
    bool isGoalNpc(sead::Vector3f* pos) const;
    void onGoalPlayer(bool isPlayerGoal);
    void onGoalNpc(const sead::Vector3f& pos);
    void exeRace();
    void exeGoalNpcLoseWait();
    void exeGoalNpcWin();
    void exeGoalNpcWinPlayerGoal();
    void startRetry();
    void exeStartRetry();
    void exeEventRetry();
    void exeWaitReEnterStage();
    bool isWaitReEnterStage() const;
    void exeWaitEndStage();
    bool isWaitEndStage() const;
    void attachDemoPlayerToGoal();
    void exeAttachJumpPlayer();
    void exeAttachJumpPlayerEnd();
    void exeResultTurn();
    void exeResult();
    s32 calcRaceTimeCsec(s32 raceTimeCsec) const;
    const char* getSceneObjName() const override;
    ~RaceManRace();

private:
    u8 filler[0x1B0 - sizeof(al::LiveActor) - sizeof(al::IEventFlowEventReceiver) -
              sizeof(al::ISceneObj)];
};

static_assert(sizeof(RaceManRace) == 0x1B0);
