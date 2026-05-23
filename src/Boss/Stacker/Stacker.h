#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class MultiGateKeeperWatcher;

class Stacker : public al::LiveActor {
public:
    Stacker(const char*, MultiGateKeeperWatcher* = nullptr);
    void init(const al::ActorInitInfo&) override;
    void startBattleStartDemo();
    void attackSensor(al::HitSensor*self, al::HitSensor*other) override;
    bool receiveMsg(const al::SensorMsg*message, al::HitSensor*other, al::HitSensor*self) override;
    void blowCapOnHead(const sead::Vector3f&, const sead::Vector3f&);
    void control() override;
    void kill() override;
    void calcAnim() override;
    bool isAlreadyDead() const;
    void attackStartCap();
    void attackEndCap();
    void updateAnimFrameCapOnHead();
    void restStartCap();
    void restEndCap();
    void updateCapOnHead();
    void blowAllCapOnHead();
    void exeBeforeStartDemo();
    void exeDemoBattleStart();
    void resetCapOnHead();
    void exeNormalAttack();
    void exePanic();
    void exeDamage();
    void exeInvincibleAttack();
    void exeReset();
    void exeDemoBattleEnd();
private:
    u8 filler[0x1B0 - sizeof(al::LiveActor)];
};
static_assert(sizeof(Stacker) == 0x1B0);
