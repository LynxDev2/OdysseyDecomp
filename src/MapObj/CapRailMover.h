#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class CapRailMover : public al::LiveActor {
public:
    CapRailMover(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void exeWait();
    void exeLockOn();
    void moveRailLockOn();
    void exeGoal();
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void startClipped() override;
    void endClipped() override;

private:
    u8 filler[0x138 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CapRailMover) == 0x138);
