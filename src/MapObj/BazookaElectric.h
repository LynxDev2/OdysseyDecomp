#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class BazookaElectric : public al::LiveActor {
public:
    BazookaElectric(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void appear() override;
    void control() override;
    void exeWait();
    void exeNoReaction();
    void exeWaitPossession();
    void exeStartPossession();
    void exeWaitCharge();
    void exeStartChargePossession();
    void exeBeforeLaunch();
    void changeLaunchNerve();
    void exeLaunchPossession();
    void exeLaunchPossessionDownRise();
    void exeLaunchPossessionDownDown();
    void exeLaunchPossessionDownParabolic();
    void exeAppearDemo();
    void exeAppearDemoPlayerGround();
    void exeAppearDemoLand();
    void exeAppearDemoDown();
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    s64 cancelHack();

private:
    u8 filler[0x1D8 - sizeof(al::LiveActor)];
};

static_assert(sizeof(BazookaElectric) == 0x1D8);
