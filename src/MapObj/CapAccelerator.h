#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class CapAccelerator : public al::LiveActor {
public:
    CapAccelerator(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void control() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    void exeWait();
    void exeReaction();
    void exeTrample();
    void exeHit();

private:
    u8 filler[0x120 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CapAccelerator) == 0x120);
