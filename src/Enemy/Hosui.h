#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class Hosui : public al::LiveActor {
public:
    Hosui(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool isEmpty() const;
    bool isHack() const;
    bool tryTrample(al::HitSensor* self, al::HitSensor* other);
    bool isEnablePunch(al::HitSensor* self, al::HitSensor* other) const;
    void reactionBody();
    bool isSwoon() const;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool isEnableDamage() const;
    void incAmount();
    bool isOnGround() const;
    void startHackLocal(al::HitSensor* self, al::HitSensor* other);
    void endHackLocal(bool hackLocal);
    void forceKillAllWaterBall();
    bool tryReceiveMsgHackCommon(const al::SensorMsg* message, al::HitSensor* other,
                                 al::HitSensor* self);
    bool tryReceiveKick(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self);
    bool tryReceiveHosuiAttack(const al::SensorMsg* message, al::HitSensor* other,
                               al::HitSensor* self);
    bool tryBlowDown(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self);
    bool tryReceiveKillBySomething(const al::SensorMsg* message);
    bool tryReceivePush(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self);
    bool tryReceiveTrample(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self);
    void exeWait();
    void startActionForce(const char* actionName);
    f32 updateGravity();
    f32 scaleVelocityCommon();
    bool tryShiftTurnOrFind();
    void endWait();
    void exeWaitFar();
    void exeJump();
    void updateWaterBall(const sead::Vector3f& shotVelocity, u32 ballCount, bool isFollowFront);
    f32 exeJumpFar();
    void exeFall();
    void exeLand();
    void exeTurn();
    void exeFind();
    void exeAttackSign();
    void exeAttack();
    void exeSwoonStart();
    void exeSwoonAir();
    void exeSwoonLand();
    void exeSwoonGround();
    void exeSwoonEnd();
    void exeRecover();
    void exeTrampled();
    void exeHackStart();
    void endHackStart();
    void exeHackWait();
    void startActionWeak(const char* actionName);
    const sead::Vector3f& recordHoverStartPos();
    bool trySpin();
    bool isEnableHover() const;
    bool tryShiftHackNoWaterReaction();
    void exeHackWalk();
    void exeHackHover();
    s32 decAmount(f32 amount);
    void controlSlopeHover(const sead::Vector3f& moveDir);
    void controlVerticalHover(const sead::Vector3f& moveDir);
    f32 controlHorizontalHover(const sead::Vector3f& moveDir);
    bool tryEmpty();
    void startAttackWide();
    void endHackHover();
    void exeHackEmpty();
    void controlFall(bool isLimitRise);
    void exeHackFall();
    bool tryShiftNextNerveWhileHackFalling();
    void exeHackTrample();
    void exeHackSpin();
    void shootHorizontal(u32 ballCount);
    void endHackSpin();
    void exeHackNoWaterReaction();
    void exeHit();
    void exeOversupply();
    void exeDamage();
    void exeBlowDown();
    void exeKickDamage();
    void exePressDown();
    void exeReset();
    void endReset();
    void exeAppear();
    void control() override;
    void controlWaterSurfaceContact();
    void controlWaterSupply();
    void controlHosuiAttackHit();
    void controlBodyAnim();
    void controlBodySize();
    void controlReactionAnimEnd();
    void controlEnvironmentDamage();
    void controlCollisionJump();
    void controlMaterialCode();
    void controlSilhouette();
    f32 controlCameraOffset();
    void updateCollider() override;
    bool tryGetWaterBall();
    bool isAttackTarget(const al::HitSensor* sensor) const;
    bool isRecordableNormal() const;
    bool isWaterSnapNerve() const;
    f32 calcPushVelocity(al::HitSensor* self, al::HitSensor* other);
    f32 calcPushVelocity(al::HitSensor* sensor, const sead::Vector3f& velocity, f32 pushVelocity);
    bool isEnableWaterSupply() const;

private:
    u8 filler[0x278 - sizeof(al::LiveActor)];
};

static_assert(sizeof(Hosui) == 0x278);
