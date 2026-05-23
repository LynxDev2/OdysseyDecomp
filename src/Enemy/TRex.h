#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

#include "Player/IUsePlayerCollision.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
class IUseNerve;
class LiveActorGroup;
class Nerve;
}  // namespace al

class PlayerCollider;
class TRexCollisionAnalyzer;
class TRexFootIK;
class TRexPatrolRouteRider;

class TRexHackTurnInfo {
public:
    TRexHackTurnInfo();
    void resetSpeed();
    void updateWithInput();
    void updateNoInput();
    void setReverseInput();
    bool isExistPreInput() const;
    bool isInvalidUpdateTurnSpeed() const;
    f32 calcInputScale() const;
};

class TRex : public al::LiveActor, public IUsePlayerCollision {
public:
    TRex(const char* name);
    void init(const al::ActorInitInfo& info) override;
    TRexFootIK* getLeftFootIK() const;
    TRexFootIK* getRightFootIK() const;
    void initAfterPlacement() override;
    void appear() override;
    void kill() override;
    void movement() override;
    void control() override;
    void updateCollider() override;
    void calcAnim() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeSleep();
    void endSleep();
    void exeSwoonStart();
    void exeSwoonStartLand();
    void exeSwoon();
    void exeFall();
    const sead::Vector3f& exeLand();
    void exeHackStart();
    void exeHackWait();
    void exeHackAttackWait();
    void endHackAttackWait();
    void exeHackMove();
    void exeHackMoveAfter();
    void exeHackMoveGround();
    void exeHackMoveJump();
    const sead::Vector3f& exeHackMoveEnd();
    void exeHackHoldJump();
    void exeHackFall();
    const sead::Vector3f& exeHackJumpStart();
    void exeHackJump();
    void exeHackTurn();
    const sead::Vector3f& exeHackTurnEnd();
    void exeHackLand();
    void endHackLand();
    void exeReset();
    void resetAllJointController();
    void exePatrolWalkStart();
    void exePatrolWalk();
    void exePatrolWalkAfter();
    void exePatrolWalkGround();
    const sead::Vector3f& exePatrolWalkEndL();
    const sead::Vector3f& exePatrolWaitSniff();
    void exePatrolNoticeSniff();
    void exePatrolTurnMario();
    void exePatrolTurnBack();
    void exePatrolDash();
    void exePatrolHoldJump();
    void exePatrolFall();
    const sead::Vector3f& exePatrolLand();
    const sead::Vector3f& exePatrolSwoonStartDashClash();
    const sead::Vector3f& exePatrolSwoonStart();
    void exePatrolSwoon();
    void exePatrolSwoonEnd();
    void exePatrolReset();
    bool isEnableBreakPartsForceScroll() const;
    f32 getMaxSinkGroundHeight();
    f32 getHoldJumpStartUpSpeed();
    f32 getHoldJumpMoveAccel();
    f32 getPatrolGravityAccel();
    f32 getPatrolGroundFriction();
    f32 getMaxPatrolFallSpeedOnGround();
    const char* getHeadColliderShapeName();
    void exeForceScrollStartFall();
    const sead::Vector3f& exeForceScrollStartLand();
    const sead::Vector3f& exeForceScrollRunStart();
    void exeForceScrollRun();
    void exeForceScrollAttackSign();
    const sead::Vector3f& exeForceScrollAttackStart();
    void exeForceScrollAttack();
    void endForceScrollAttack();
    const sead::Vector3f& exeForceScrollAttackEnd();
    const sead::Vector3f& exeForceScrollEndFallStart();
    void exeForceScrollEndFall();
    PlayerCollider* getPlayerCollider() const override;

private:
    u8 filler[0x360 - sizeof(al::LiveActor) - sizeof(IUsePlayerCollision)];
};

static_assert(sizeof(TRex) == 0x360);

class TRexFunction {
public:
    void sendMsgTRexAttackToAllCollidedCollision(const TRex* tRex);
    void updateMaterialCodeByFootCollide(TRex* tRex, const TRexFootIK* tRexFootIK);
    void appearFootPrint(al::LiveActorGroup* liveActorGroup, const TRex* tRex, bool footPrint);
    void updatePatrolRouteRider(TRexPatrolRouteRider* tRexPatrolRouteRider, const TRex* tRex);
    void calcBlendAnimFrameRateByIndex(const TRex* tRex, s32 index);
    bool tryStartPatrolTurnPoint(al::IUseNerve* iUseNerve, const TRex* tRex, const al::Nerve* nerve,
                                 sead::Vector3f* outTurnPoint, sead::Vector3f* outTurnDir,
                                 const sead::Vector3f& targetPoint, f32 turnRate);
    void executePatrolTurn(al::IUseNerve* iUseNerve, TRex* tRex, sead::Vector3f* turnPoint,
                           sead::Vector3f* turnDir);
    void updatePatrolRunSpeed(TRex* tRex, sead::Vector3f* pos);
    void updatePatrolDashSpeed(TRex* tRex, sead::Vector3f* pos, f32 patrolDashSpeed);
    void updatePatrolFindTurn(TRexHackTurnInfo* tRexHackTurnInfo, TRex* tRex,
                              const sead::Vector3f& pos, f32 patrolFindTurn,
                              const TRexCollisionAnalyzer* tRexCollisionAnalyzer);
    void updateFallPoseAndVelocity(TRex* tRex, f32 fallPoseAndVelocity);
};
