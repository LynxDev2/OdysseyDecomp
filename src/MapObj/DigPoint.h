#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class DigPoint : public al::LiveActor {
public:
    DigPoint(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void appear() override;
    void kill() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool tryUpdateHintTrans(const sead::Vector3f& trans);
    void emitGlowEffect();
    void exeWait();
    void exeItemDelay();

private:
    u8 filler[0x150 - sizeof(al::LiveActor)];
};

static_assert(sizeof(DigPoint) == 0x150);
