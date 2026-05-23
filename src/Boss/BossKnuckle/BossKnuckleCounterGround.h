#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class BossKnuckleCounterGround : public al::LiveActor {
public:
    BossKnuckleCounterGround(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    s64 doBreak();
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    s64 doFall(const sead::Vector3f& pos);
    s64 doFallStartDemo();
    void setBeforeStart();
    s64 doWaitOnGround();
    bool isBreak() const;
    bool isBeforeStart() const;
    void killAll();
    void exeWaitOnGround();
    void exeFall();
    void exeSink();
    void exeBreak();
    void exeBeforeStart();

private:
    u8 filler[0x130 - sizeof(al::LiveActor)];
};

static_assert(sizeof(BossKnuckleCounterGround) == 0x130);
