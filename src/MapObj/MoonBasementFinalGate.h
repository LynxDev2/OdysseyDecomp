#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class MoonBasementFinalGate : public al::LiveActor {
public:
    MoonBasementFinalGate(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void kill() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void startBreakPillar(s32 breakPillar);
    void exeWait();
    void exeBreakPillar();
    void exeBreak();
    void exeBreakLast();
    void exeBreakLastAfter();

private:
    u8 filler[0x130 - sizeof(al::LiveActor)];
};

static_assert(sizeof(MoonBasementFinalGate) == 0x130);
