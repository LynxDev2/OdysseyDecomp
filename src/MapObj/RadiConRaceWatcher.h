#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"
#include "Library/Scene/ISceneObj.h"

namespace al {
struct ActorInitInfo;
class RaceCheckPoint;
}  // namespace al

class RadiconCar;
class RadiconNpc;

class RadiConRaceWatcher : public al::LiveActor, public al::ISceneObj {
public:
    RadiConRaceWatcher(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void setCheckPoint(al::RaceCheckPoint* raceCheckPoint);
    const sead::Vector3f& registerRadiconCar(RadiconCar* radiconCar);
    const sead::Vector3f& registerRadiconNpc(RadiconNpc* radiconNpc);
    bool isStateCountDown() const;
    bool isStateResult() const;
    void resetRadiConCarPosition();
    s64 doFinish();
    bool tryAppearShine();
    void exeWait();
    void exeCountDown();
    void exeRace();
    void exeFinish();
    void exeResult();
    void exeResultEnd();
    void exeAppearShine();

private:
    u8 filler[0x168 - sizeof(al::LiveActor) - sizeof(al::ISceneObj)];
};

static_assert(sizeof(RadiConRaceWatcher) == 0x168);

namespace rs {
bool isExistRadiConRaceWatcher(const al::IUseSceneObjHolder* iUseSceneObjHolder);
void getRadiConRaceWatcher(const al::IUseSceneObjHolder* iUseSceneObjHolder);
void tryRegisterRadiConNpcToRadiConRaceWatcher(RadiconNpc* radiconNpc);
}  // namespace rs
