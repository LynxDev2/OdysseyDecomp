#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class CollapseSandHill : public al::LiveActor {
public:
    CollapseSandHill(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    void exeWait();
    void exeDying();

private:
    u8 filler[0x110 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CollapseSandHill) == 0x110);
