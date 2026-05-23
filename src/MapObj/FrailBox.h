#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class FrailBox : public al::LiveActor {
public:
    FrailBox(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    bool checkBelow();
    void movement() override;
    void calcAnim() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void control() override;
    void exeWait();
    void exeFall();
    void exeLand();
    void exeDamage();
    void exeItemDelay();
    void exeLinkPlayerStart();
    bool checkBelowBrokenBox();

private:
    u8 filler[0x148 - sizeof(al::LiveActor)];
};

static_assert(sizeof(FrailBox) == 0x148);
