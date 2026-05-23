#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

#include "Util/IUseDimension.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class ActorDimensionKeeper;

class HammerBros2D : public al::LiveActor, public IUseDimension {
public:
    HammerBros2D(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void control() override;
    void kill() override;
    void exeWalk();
    void exeJump();
    void exeDown();
    ActorDimensionKeeper* getActorDimensionKeeper() const override;

private:
    u8 filler[0x160 - sizeof(al::LiveActor) - sizeof(IUseDimension)];
};

static_assert(sizeof(HammerBros2D) == 0x160);
