#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

#include "Util/IUseDimension.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class ActorDimensionKeeper;

class KillerLauncherDot : public al::LiveActor, public IUseDimension {
public:
    KillerLauncherDot(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void startLaunch();
    void endLaunch();
    void initAfterPlacement() override;
    void appear() override;
    void kill() override;
    void control() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void exeLaunch();
    void exeSleep();
    void exeDelay();
    ActorDimensionKeeper* getActorDimensionKeeper() const override;

private:
    u8 filler[0x148 - sizeof(al::LiveActor) - sizeof(IUseDimension)];
};

static_assert(sizeof(KillerLauncherDot) == 0x148);
