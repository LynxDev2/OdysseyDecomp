#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class BendLeafTree : public al::LiveActor {
public:
    BendLeafTree(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initBendInfo();
    void initAfterPlacement() override;
    void exeWait();
    void movement() override;
    void control() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;

private:
    u8 filler[0x158 - sizeof(al::LiveActor)];
};

static_assert(sizeof(BendLeafTree) == 0x158);
