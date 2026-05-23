#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class SkyWorldKoopaFire : public al::LiveActor {
public:
    SkyWorldKoopaFire(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void listenAppear();
    void listenKill();
    void exeWait();
    void exeHighTension();
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;

private:
    u8 filler[0x140 - sizeof(al::LiveActor)];
};

static_assert(sizeof(SkyWorldKoopaFire) == 0x140);

class SkyWorldKoopaFrame : public al::LiveActor {
public:
    SkyWorldKoopaFrame(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void exeReaction();
    void exeFall();
    void exeFallNoCollider();
    const sead::Vector3f& exeFallEndWait();

private:
    u8 filler[0x140 - sizeof(al::LiveActor)];
};
