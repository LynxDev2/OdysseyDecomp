#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class PackunFire : public al::LiveActor {
public:
    PackunFire(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void killBySwitch();
    void switchAppear();
    void initAfterPlacement() override;
    void control() override;
    void kill() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void endCapture();
    void exeStandby();
    void exeWait();
    void exeSearch();
    void exeAttackSign();
    void exeAttack();
    void updateStickTurn();
    void exeAttackHit();
    void exeCapSearch();
    void onCapSearchEnd();
    void onChokeCapEnd();
    void exeChoke();
    void exeSwoon();
    void exeVomit();
    void exeSwallow();
    void exeCaptureStart();
    void exeCaptureHackStart();
    void exeCaptureWait();
    void exePressDown();
    void exeBlowDown();
    void exeReset();
    void exeYoshiTongueEatBind();

private:
    u8 filler[0x2E8 - sizeof(al::LiveActor)];
};

static_assert(sizeof(PackunFire) == 0x2E8);
