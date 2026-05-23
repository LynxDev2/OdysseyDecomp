#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class CardboardBox : public al::LiveActor {
public:
    CardboardBox(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    bool checkNeighbors();
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool isActive() const;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void propagateWaitForCollapsing();
    void dealWithHit(f32 hitPower, f32 hitRange, al::HitSensor* self, al::HitSensor* other);
    void exeWait();
    void exePressDown();
    void exeShake();
    void propagateUpShake() const;
    void exeHit();
    void exeFall();
    void exeBounce();
    void exeVanish();
    void propagateUpHit(const sead::Vector3f& hitPos, f32 upSpeed, f32 spreadSpeed) const;
    void setHitSpeed(f32 upSpeed, f32 sideSpeed);

private:
    u8 filler[0x188 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CardboardBox) == 0x188);
