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

class BombTail : public al::LiveActor {
public:
    BombTail(const char*, MultiGateKeeperWatcher* = nullptr);
    void init(const al::ActorInitInfo&) override;
    void startBattleStartDemo();
    void control() override;
    void kill() override;
    void killPartsAll();
    void attackSensor(al::HitSensor*self, al::HitSensor*other) override;
    bool receiveMsg(const al::SensorMsg*message, al::HitSensor*other, al::HitSensor*self) override;
    void damageAndSetNerve();
    bool isAlreadyDead() const;
    void exeBattleStartDemo();
    void offSkirtDynamics();
    void offAnimDynamics();
    void onCap();
    void changeToWalk();
    void onAnimDynamics();
    void onSkirtDynamics();
    void exeWait();
    void startActionWithTail(const char*);
    void exeAppearBombSign();
    void exeAppearBomb();
    void appearTailBomb();
    void exeWalkToSide();
    void exeWalk();
    bool isChanceAttack() const;
    void decideTailThrowTargetFromPlayer(const sead::Vector3f&, bool);
    void exeGuard();
    void exeAppearChanceBombSign();
    void exeAppearChanceBomb();
    void exeAttackStart();
    void exeAttackSpeedy();
    void exeAttackChance();
    void exeAttackChanceLandStart();
    void exeAttackChanceLand();
    bool tryStartBounce();
    const sead::Vector3f& exeAttackEnd();
    void changeToAttackPrepare();
    void exeBounceStart();
    void exeBounce();
    const sead::Vector3f& offCap();
    void exeBounceEnd();
    void exePanic();
    bool tryChangeToEndDamageChance();
    void exeRunStart();
    void exeRun();
    void exeCapHit();
    void exeRunCapHitWait();
    void exeEndDamageChance();
    void exeDamage();
    void exeResetAttack();
    void exeBattleEndDemo();
    void throwBomb(const sead::Vector3f&, const sead::Vector3f&);
    void throwBombRun();
    s64 popFromDamageArray();
    s32 decideTailThrowTarget(s32, const sead::Vector3f&);
private:
    u8 filler[0x220 - sizeof(al::LiveActor)];
};
static_assert(sizeof(BombTail) == 0x220);
