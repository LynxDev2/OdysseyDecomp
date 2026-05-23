#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class Pyramid : public al::LiveActor {
public:
    Pyramid(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void resetAtCloseAndGround();
    void resetFlyKeyPose(f32 flyKeyPose);
    void resetAtOpenAndGround();
    void resetAtCloseAndFly();
    void resetAtOpenAndFly();
    bool tryStartOpenDemo();
    bool tryStartRiseDemo();
    bool tryStartRiseDemo(bool isStageDemo);
    bool isDemoPlaying();
    void exeWait();
    void exeMove();
    void exeStopBefore();
    void exeStop();
    void exeDemoDoorOpen();

private:
    u8 filler[0x170 - sizeof(al::LiveActor)];
};

static_assert(sizeof(Pyramid) == 0x170);
