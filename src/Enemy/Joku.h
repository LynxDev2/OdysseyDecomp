#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class IUsePlayerPuppet;

class Joku : public al::LiveActor {
public:
    Joku(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void setPuppetJumpBack(IUsePlayerPuppet* iUsePlayerPuppet, const al::LiveActor* actor);
    void control() override;
    void exeWait();
    void exeAppearArm();
    void resetArm(s32 arm);
    void exeWaitBeforeAttack();
    void exeAttackSign();
    void exeAttack();
    void exeWaitBeforeTurn();
    void exeTurn();
    void exeWaitBeforeMove();
    void exeMove();
    void exeDamage();
    void disappearArm();
    bool isArmAllDead();
    void exeStandby();
    void exeReturn();
    void exeDisappearStart();
    void exeDisappear();
    void exeDelay();
    void exeItemAppearDemo();
    void exeRotateAttackStart();
    void exeRotateAttack();
    void exeRotateAttackEnd();

private:
    u8 filler[0x220 - sizeof(al::LiveActor)];
};

static_assert(sizeof(Joku) == 0x220);
