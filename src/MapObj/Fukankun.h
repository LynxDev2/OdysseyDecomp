#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class Fukankun : public al::LiveActor {
public:
    Fukankun(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void switchStart();
    void switchAppear();
    void control() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    s64 cleanupCaptureView();
    void turnHeadToDir(const sead::Vector3f& dir, f32 turnRate);
    void endCaptureAndNextNerve();
    void exeStandby();
    void exeRecoverWait();
    void exeWait();
    void exeCaptureWait();
    void exeCaptureStart();
    void exeCaptureDemo();
    f32 calcTargetYUp();
    f32 updateCamera(const sead::Vector3f& targetPos, f32 cameraDist, f32 interpoleRate);
    void exeCaptureStartEnd();
    void exeCaptureViewWait();
    void setupBalloon();
    void exeCaptureView();
    void exeCaptureEnd();
    void exeJoin();
    void exeReaction();

private:
    u8 filler[0x248 - sizeof(al::LiveActor)];
};

static_assert(sizeof(Fukankun) == 0x248);
