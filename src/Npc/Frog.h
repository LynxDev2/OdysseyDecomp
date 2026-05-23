#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class FrogParam {
public:
    FrogParam(al::LiveActor* actor);
};

class Frog : public al::LiveActor {
public:
    Frog(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void control() override;
    s64 die();
    void updateWaterSurface();
    bool isOnWaterSurface() const;
    void updateCollider() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    void startHack(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self);
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void onDynamics();
    void offDynamics();
    f32 updateVelocity();
    f32 updateSurfaceTransform();
    void surfaceJump();
    void exeAppear();
    void exeWait();
    void exeWander();
    void exeDamageCap();
    void exeTrampled();
    f32 exeWaitHackStart();
    f32 exeWaitHackStartSwoon();
    void exeDemoHackFirst();
    void exeHackStart();
    f32 exeSwoon();
    f32 exeHack();
    void endHack();
    void exeRevive();
    void exeReviveAppear();
    void exeReset();
    void exeDie();

private:
    u8 filler[0x1E0 - sizeof(al::LiveActor)];
};

static_assert(sizeof(Frog) == 0x1E0);
