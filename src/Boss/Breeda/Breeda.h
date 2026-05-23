#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class Breeda : public al::LiveActor {
public:
    Breeda(const char*);
    void init(const al::ActorInitInfo&) override;
    s32 calcCapCount() const;
    const sead::Vector3f& calcHandPos();
    void startBattleDemo();
    void calcAnim() override;
    void control() override;
    void attackSensor(al::HitSensor*self, al::HitSensor*other) override;
    bool isEnableAttackSuccess() const;
    bool receiveMsg(const al::SensorMsg*message, al::HitSensor*other, al::HitSensor*self) override;
    bool isEnableDamage() const;
    void exePreDemoBattleStart();
    void exeDemoBattleStart();
    void setUpDemo();
    void setUpBattle();
    void exePreDemoBattleEnd();
    void exeDemoBattleEnd();
    void updateDemoBattleEndCameraShine();
    void updateDemoBattleEndCamera();
    void exeDemoBattleEndCamera();
    void updateWaitWalkAnim(bool, const char*, const char*, f32, f32, bool);
    void exeBattleStartWait();
    void exeWait();
    void updateAimHead();
    f32 updateVelocityToWanwan();
    bool updateTurnToWanwan(f32);
    f32 updateVelocityGround();
    bool isLast() const;
    void exeForgive();
    void exeAttackSuccess();
    void exePanicStart();
    bool isPanic() const;
    void exePanic();
    void exePull();
    void exePullEnd();
    void exeSlapSign();
    void exeSlap();
    f32 exeMoveToWanwan();
    void exeSlapSignWanwan();
    void exeSlapWanwan();
    void exeTired();
    void exeTiredEnd();
    f32 exePreDamage();
    void exeDamage();
    void exeDamageLast();
    void endBattleDemo();
    void exeThrowWanwanSign();
    void exeThrowWanwan();
    void exeThrowWanwanEnd();
private:
    u8 filler[0x228 - sizeof(al::LiveActor)];
};
static_assert(sizeof(Breeda) == 0x228);
