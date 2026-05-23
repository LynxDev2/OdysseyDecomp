#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class Wanwan : public al::LiveActor {
public:
    Wanwan(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void onDitherRadiusAdd();
    void offDitherRadiusAdd();
    void forceKill();
    void makeActorDead() override;
    void calcAnim() override;
    void control() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool validateImpactSensor();
    bool isEnableEnemyAttack() const;
    void sendMsgMyPush(al::HitSensor* self, al::HitSensor* other);
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool tryEndCamera();
    bool isEnableHack() const;
    bool isEnableTrampleAttack() const;
    bool isEnableCapAttack() const;
    void exeDeactive();
    void endDeactive();
    void exeWait();
    f32 updateVelocityPull(bool velocityPull);
    f32 updateVelocityGround(bool velocityGround);
    void exeTurn();
    void exeAttackSign();
    void exeAttackPull();
    void exeAttack();
    bool tryAttackToCollide();
    void exeAttackEnd();
    void setNerveReturn();
    void exeSwoon();
    void exeHack();
    bool tryStartCamera();
    void endHack();
    void exeReturn();
    void exeReturnEnd();
    void exeBackChain();
    void updateBack();
    void exeBack();
    void endBack();
    void exeBackEnd();
    void exeBackReturn();
    void exeBlockAttack();
    void exeHit();
    void exeHitEnd();
    void exeTrampled();
    void exeBlowDown();
    void exeReset();
    void exeHoleIn();

private:
    u8 filler[0x1D0 - sizeof(al::LiveActor)];
};

static_assert(sizeof(Wanwan) == 0x1D0);
