#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class CapThrower : public al::LiveActor {
public:
    CapThrower(const char*);
    void init(const al::ActorInitInfo&) override;
    void startBattleStartDemo();
    void attackSensor(al::HitSensor*self, al::HitSensor*other) override;
    bool receiveMsg(const al::SensorMsg*message, al::HitSensor*other, al::HitSensor*self) override;
    void appear() override;
    void control() override;
    void kill() override;
    bool isValidCamera() const;
    void exeBeforeStartDemo();
    void exeBattleStartDemo();
    void exeWalk();
    void turnHeadToPlayer();
    void exeCapThrow();
    void exeDamage();
    void exeInvincibleAttack();
    void resetHead();
    void exeBattleEndDemo();
    bool isNeedStartTowerCamera();
private:
    u8 filler[0x168 - sizeof(al::LiveActor)];
};
static_assert(sizeof(CapThrower) == 0x168);
