#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class HackCar : public al::LiveActor {
public:
    HackCar(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void calcAnim() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void forceEndCameraBeforeSetNerve();
    void forceCancelHack(const al::SensorMsg* message);
    void exeWait();
    void exeWaitHackion();
    void exeHackStart();
    void exeHackWaitInput();
    void exeHackChargeStart();
    void chargeCore();
    void exeHackCharge();
    void exeHackMoveSign();
    void exeHackMoveStart();
    f32 runCore();
    void exeHackMove();
    void exeHackEnd();
    void control() override;

private:
    u8 filler[0x180 - sizeof(al::LiveActor)];
};

static_assert(sizeof(HackCar) == 0x180);
