#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class MoonBasementPillar : public al::LiveActor {
public:
    MoonBasementPillar(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void kill() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool isBreakLastHit() const;
    void exeWait();
    void exeBreak();
    const sead::Vector3f& exeBridgeStart();
    void exeBridgeStartHit();
    void exeBridgeStartHitAfter();
    void exeBridge();
    const sead::Vector3f& exeBreakLast();
    void exeBreakLastHit();

private:
    u8 filler[0x150 - sizeof(al::LiveActor)];
};

static_assert(sizeof(MoonBasementPillar) == 0x150);
