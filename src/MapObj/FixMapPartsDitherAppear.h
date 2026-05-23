#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class FixMapPartsDitherAppear : public al::LiveActor {
public:
    FixMapPartsDitherAppear(const char* name);
    void init(const al::ActorInitInfo& info) override;
    s64 ditherAppear();
    s64 waitAppear();
    void calcAnim() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeAppear();
    void exeWait();

private:
    u8 filler[0x110 - sizeof(al::LiveActor)];
};

static_assert(sizeof(FixMapPartsDitherAppear) == 0x110);
