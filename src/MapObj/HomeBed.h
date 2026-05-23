#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class HomeBed : public al::LiveActor {
public:
    HomeBed(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void exeSnoozeStart();
    void exeSnooze();
    void exeSleepStart();
    void exeSleep();
    void exeStandUp();
    void exeBindJump();
    void exeWaitNoSleep();
    bool tryEndBind();

private:
    u8 filler[0x128 - sizeof(al::LiveActor)];
};

static_assert(sizeof(HomeBed) == 0x128);
