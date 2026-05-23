#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class StatueParam {
public:
    StatueParam(al::LiveActor* actor);
};

class Statue : public al::LiveActor {
public:
    Statue(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void control() override;
    void updateCollider() override;
    void startHack(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self);
    void updateGround();
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void exeFall();
    void exeTrampled();
    void exeHackStart();
    void exeHack();
    void exeHackEndGround();
    void exeHackEndAir();
    void exeHackEndLand();
    void exeRevive();
    void exeTrampleReflect();

private:
    u8 filler[0x148 - sizeof(al::LiveActor)];
};

static_assert(sizeof(Statue) == 0x148);
