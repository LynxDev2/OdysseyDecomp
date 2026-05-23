#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class FireBlower : public al::LiveActor {
public:
    FireBlower(const char*);
    void init(const al::ActorInitInfo&) override;
    void startBattleStartDemo();
    void exeBeforeDemoStart();
    bool isValidCamera() const;
    void initAfterPlacement() override;
    void control() override;
    void attackSensor(al::HitSensor*self, al::HitSensor*other) override;
    bool receiveMsg(const al::SensorMsg*message, al::HitSensor*other, al::HitSensor*self) override;
    void hideFireBlowerFireVisAll();
    void damageOrDie();
    void exeBattleStartDemo();
    void exeStandBy();
    void exeResetAttackStart();
    void exeResetAttackEnd();
    void lotMiss();
    bool trySetNerveBlowSignOrBlowMissSign();
    bool trySetNerveWaitAttackSignOrWaitAttackMissSign();
    bool trySetNerveWait();
    void exeWaitAttackMiss();
    void exeWait();
    void exeWaitAttackMissSign();
    void exeWaitAttackSign();
    void showFireBlowerFireVisAll();
    bool tryChangeFireBlowerFireVisibility();
    void exeWaitAttack();
    void exeRunAttack();
    void exeWaitAttackEnd();
    void exeRunAttackEnd();
    void exeTurn();
    void exeChase();
    bool tryReflect();
    void exeAttackMoveReset();
    void exeAttackMoveResetEnd();
    void exeAttackMoveLineAttackSign();
    void exeAttackMoveLineAttack();
    void exeAttackMoveLineAttackTrampleReaction();
    void exeAttackMoveLineAttackEnd();
    void exeBlowSign();
    void exeBlow();
    void exeBlowEnd();
    void exeBlowMissSign();
    void exeBlowMiss();
    void exeReactionCap();
    void exeTrampleCap();
    void exeDamage();
    void exeResetFireFirstSignBeforeWait();
    void exeResetFireSign();
    void exeResetFire();
    void exeResetFireEnd();
    void exeFace();
    void exeBattleEndDemo();
private:
    u8 filler[0x210 - sizeof(al::LiveActor)];
};
static_assert(sizeof(FireBlower) == 0x210);
