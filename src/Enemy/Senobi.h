#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class Senobi : public al::LiveActor {
public:
    Senobi(const char* name);
    s64 getStretchJointName();
    s32 getStretchSensorNum();
    s64 getStretchJointLocalOffset();
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void makeActorDead() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void control() override;
    void movement() override;
    void calcAnim() override;
    void updateCollider() override;
    f32 getStretchRate() const;
    s64 rebirth(const sead::Vector3f& startPos, const sead::Vector3f& endPos);
    void resetCounter();
    void exeEnemy();
    void exeReset();
    void exeHack();

private:
    u8 filler[0x148 - sizeof(al::LiveActor)];
};

static_assert(sizeof(Senobi) == 0x148);
