#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class SneakingMan : public al::LiveActor {
public:
    SneakingMan(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    void control() override;
    const sead::Vector3f& adjustPosInMoveRange();
    void exeWait();
    u64 setDispScale(f32 dispScale);
    u64 updateDispScaleWaitAnim(s32 waitStep, f32 scaleRate);
    void updatePadRumble();
    void exeWander();
    s64 generateRipple();
    void exeFind();
    f32 updateTargetAngleDistByPos();
    void exeRunOuter();
    f32 calcPlayerAngle() const;
    void exeRunInner();
    void exeRunWait();
    void exeSwoonStart();
    void exeSwoon();
    void exeSwoonEnd();
    u64 exeHideStart();
    void exeHide();
    void stopPadRumble();
    void exeHideEnd();
    void exePressDown();
    void exeDie();
    void addSinPosToSide(f32 amplitude, f32 phase);
    void adjustPosByCollision();

private:
    u8 filler[0x1F0 - sizeof(al::LiveActor)];
};

static_assert(sizeof(SneakingMan) == 0x1F0);
