#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class HomeChair : public al::LiveActor {
public:
    HomeChair(const char* name, HomeChair* homeChair = nullptr);
    void init(const al::ActorInitInfo& info) override;
    const sead::Vector3f& getCapMovePoint() const;
    void control() override;
    s64 getCapActor() const;
    s64 getEyeController() const;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void capOnPuppetPlayer();
    void exeWait();
    void exeBindSitDownStart();
    void exeBindSitDown();
    void exeBindCapAppear();
    void exeBindLookCap();
    void exeBindLookDefault();
    void exeBindWait();
    void exeBindSleepStart();
    void exeBindSleep();
    void exeBindWakeUp();
    void exeBindStandUp();
    void exeBindJump();
    void exeWaitNoSitDown();

private:
    u8 filler[0x160 - sizeof(al::LiveActor)];
};

static_assert(sizeof(HomeChair) == 0x160);
