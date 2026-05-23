#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"
#include "Library/Scene/ISceneObj.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class RaceStageInfo;
class RacePlayer;
class PlayerActorBase;

class RaceWatcher : public al::LiveActor, public al::ISceneObj {
public:
    RaceWatcher(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    s64 registerPlayer(PlayerActorBase* playerActorBase);
    s64 registerNpcPlayer(al::LiveActor* actor);
    s32 calcRaceProgress(const al::LiveActor* actor);
    s32 calcRaceProgressPlayer();
    RacePlayer* getPlayerRacer() const;
    const RaceStageInfo* getWinStageInfo() const;
    const RaceStageInfo* getLoseStageInfo() const;
    void resetRank();
    void startRace();
    void endRace();
    bool isCourseOutPlayer() const;
    void exeWait();
    void exeRace();
    void exeFinish();

private:
    u8 filler[0x158 - sizeof(al::LiveActor) - sizeof(al::ISceneObj)];
};

static_assert(sizeof(RaceWatcher) == 0x158);

class SnowManRaceFunction {
public:
    s64 registerNpcToRaceWatcher(al::LiveActor* actor);
    s32 calcRaceProgress(const al::LiveActor* actor);
    s32 calcRaceProgressPlayer(const al::LiveActor* actor);
    s32 getLapNum(const al::LiveActor* actor);
    s64 getLapMax(const al::LiveActor* actor);
    bool isWinGoal(const al::LiveActor* actor);
    s32 getRaceLoseCount(const al::LiveActor* actor);
};
