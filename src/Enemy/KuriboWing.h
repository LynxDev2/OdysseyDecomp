#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class KuriboWing : public al::LiveActor {
public:
    KuriboWing(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void control() override;
    void updateCollider() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    void setNerveTrample(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self);
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void endCapture();
    void exeFly();
    void exeDamageCap();
    void exeAttackHit();
    void exeSwoon();
    void exeAppearStart();
    void exeWait();
    void exeCaptureStart();
    void exeCaptureStartEnd();
    void exeCaptureEnd();
    void exeCaptureFly();
    void exeDie();
    void exeBlowDown();
    void exeTurnEdge();
    void exeTurnCorner();
    void exeTrample();
    void exeReset();
    void exeRevive();

private:
    u8 filler[0x1A8 - sizeof(al::LiveActor)];
};

static_assert(sizeof(KuriboWing) == 0x1A8);
