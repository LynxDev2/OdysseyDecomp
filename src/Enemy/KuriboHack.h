#pragma once

#include <basis/seadTypes.h>
#include <container/seadOffsetList.h>
#include <math/seadMatrix.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
class JointSpringControllerHolder;
class WaterSurfaceFinder;
}  // namespace al

class ActorStateSandGeyser;
class CapTargetInfo;
class CollisionMultiShape;
class CollisionPartsFilterBase;
class CollisionShapeKeeper;
class DisregardReceiver;
class EnemyCap;
class EnemyStateBlowDown;
class EnemyStateReset;
class EnemyStateSwoon;
class EnemyStateWander;
class KuriboStateHack;
class PlayerCeilingCheck;
class PlayerPushReceiver;

class KuriboHack : public al::LiveActor {
public:
    KuriboHack(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void appear() override;
    void makeActorAlive() override;
    void kill() override;
    void makeActorDead() override;
    void movement() override;
    void calcAnim() override;
    void startClipped() override;
    void endClipped() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void control() override;
    void updateCollider() override;
    bool tryCreateEnemyCap(const al::ActorInitInfo& info);
    void setNerveRideOnCommon();
    void resetRideOnPosBottomWithDefaultParam();
    void onSnapShotMode();
    void offSnapShotMode();
    void onDynamics();
    void detach(KuriboHack* kuriboHack);
    bool checkSandSinkPrecisely() const;
    s64 solveCollisionInHacking(const sead::Vector3f& moveDir);
    s64 pushFrom(KuriboHack* kuriboHack, const sead::Vector3f& pushDir);
    const sead::Vector4f& updateCapLockOnMtx();
    void forceStartClipped();
    void appearFall();
    s64 noRevive();
    void exeWait();
    void setShiftTypeOnGround(s32 shiftType);
    void offDynamics();
    void syncRideOnPosBottomWithDefaultParam();
    void exeWander();
    bool tryShiftDrown();
    void exeTurn();
    f32 exeFind();
    f32 exeChase();
    f32 exeStop();
    f32 exeAttack();
    void exePressDown();
    void exeBlowDown();
    void exeDamageCap();
    void exeFall();
    void exeLand();
    bool tryShiftChaseOrWander();
    void exeSink();
    void updateSink();
    void exeSlide();
    void exeReset();
    void exeSandGeyser();
    void clearSink();
    void exeWaitHack();
    void exeTowerHackEnd();
    void exeHack();
    void invalidateHackDamage();
    s64 shiftWaitHack();
    void endHack();
    void exeRideOn();
    void endRideOn();
    void exeDrown();
    void exeEatBind();
    s64 prepareKillByShineGet();
    bool tryReceiveMsgHack(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self);
    bool tryReceiveMsgWaitHack(const al::SensorMsg* message, al::HitSensor* other,
                               al::HitSensor* self);
    bool tryReceiveMsgRideOn(const al::SensorMsg* message, al::HitSensor* other,
                             al::HitSensor* self);
    bool tryReceiveMsgEatBind(const al::SensorMsg* message, al::HitSensor* other,
                              al::HitSensor* self);
    bool tryReceiveMsgNormal(const al::SensorMsg* message, al::HitSensor* other,
                             al::HitSensor* self);
    s64 transferGroup(sead::OffsetList<KuriboHack>* kuriboTowerList);
    s64 eraseFromHost();
    void notifyJumpSink(f32 sinkAmount);
    bool isSinking() const;
    void syncRideOnPosBottom(f32 rideOnRadius, f32 bottomOffset);
    void resetRideOnPosBottom(f32 bottomOffset);
    bool validateSpecialPush(u32 frameMax);
    void startRideOnRotation();
    s64 applyRideOnQuat(const sead::Quatf& quat);
    bool isInvalidHackDamage() const;
    bool validateHipDropProbe(al::HitSensor* sensor);
    s64 indexInHostList() const;
    f32 getRideOnRowSize();
    bool isCapWorn() const;
    bool isEnableHack() const;
    bool trySetHipDropActor(const al::SensorMsg* message, al::HitSensor* sensor);
    void addCapToHackDemo();
    bool tryReceiveMsgPush(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self);
    bool tryRideOnHack(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self);
    void notifyKillByShineGetToGroup(const al::SensorMsg* message, al::HitSensor* other,
                                     al::HitSensor* self);

private:
    CapTargetInfo* mCapTargetInfo;
    EnemyStateSwoon* mStateSwoon;
    EnemyStateReset* mStateReset;
    EnemyStateWander* mStateWander;
    ActorStateSandGeyser* mStateSandGeyser;
    KuriboStateHack* mStateHack;
    EnemyStateBlowDown* mStateBlowDown;
    al::JointSpringControllerHolder* mJointSpringControllerHolder;
    bool mIsKuriboActive;  // really abstract name... only false when kuribo is swooning, chase end,
                           // and right after damage taken
    EnemyCap* mEnemyCap;
    bool mIsEyebrowOff;
    KuriboHack* mKuriboTowerBottom;
    bool mIsGold;
    s32 mChaseEndTimer;  // name unsure
    CollisionPartsFilterBase* mCollisionPartsFilterBase;
    sead::Vector3f mNextKuriboTrans;  // position of the goomba directly above in a tower
    f32 mClippingRadius;
    PlayerPushReceiver* mPlayerPushReceiver;
    CollisionMultiShape* mCollisionMultiShape;
    CollisionShapeKeeper* mCollisionShapeKeeper;
    f32 mSandSinkJumpHeight;
    s32 mKuriboTowerIdx;  // name unsure
    s32 mStartRideTimer;
    s32 _1ac;
    u32 mHackEndTimer;
    s32 mShiftType;
    s32 mCapCancelLockOnTimer;
    f32 mLastHackEndPosY;
    PlayerCeilingCheck* mPlayerCeilingCheck;
    bool mIsHackJustEnded;
    sead::Vector3f mHackEndPos;
    s32 mHipDropTimer;
    const char* mJointName;
    sead::Matrix34f mCapLockOnMtx;
    sead::Matrix34f mInitMtx;
    al::LiveActor* mSensorHost;
    sead::Vector3f mHostDistance;
    al::HitSensor* mHipDropProbe;
    sead::Vector3f mHipDropProbeTrans;
    al::WaterSurfaceFinder* mWaterSurfaceFinder;
    sead::Matrix34f mWaterSurfaceEffectMtx;
    sead::Matrix34f mSandSurfaceEffectMtx;
    bool _2e0;  // set true in ctor, only ever checked if false
    sead::OffsetList<KuriboHack> mKuriboTowerOffsetList;
    sead::ListNode mKuriboTowerList;
    DisregardReceiver* mDisregardReceiver;
    u32 field_318;
};

static_assert(sizeof(KuriboHack) == 0x320);
