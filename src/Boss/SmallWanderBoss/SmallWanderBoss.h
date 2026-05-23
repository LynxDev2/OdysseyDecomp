#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class SmallWanderBoss : public al::LiveActor {
public:
    SmallWanderBoss(const char*);
    void init(const al::ActorInitInfo&) override;
    void initAfterPlacement() override;
    void kill() override;
    void attackSensor(al::HitSensor*self, al::HitSensor*other) override;
    bool receiveMsg(const al::SensorMsg*message, al::HitSensor*other, al::HitSensor*self) override;
    void control() override;
    void exeFly();
    void moveRailLocal();
    void turnToPlayer();
    void exeStop();
    void exeHipDropFall();
    void exeHipDropDown();
    void exeAttack();
    void exeAppearCoin();
private:
    u8 filler[0x188 - sizeof(al::LiveActor)];
};
static_assert(sizeof(SmallWanderBoss) == 0x188);
