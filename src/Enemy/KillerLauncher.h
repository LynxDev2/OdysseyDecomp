#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class KillerLauncher : public al::LiveActor {
public:
    KillerLauncher(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void startLaunch();
    void endLaunch();
    void killAll();
    void killAllAndThis();
    void control() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeStop();
    void exeDelay();
    void exeWait();
    void exeStandBy();
    void exeLaunch();

private:
    u8 filler[0x130 - sizeof(al::LiveActor)];
};

static_assert(sizeof(KillerLauncher) == 0x130);
