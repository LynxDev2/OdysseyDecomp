#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class Tank : public al::LiveActor {
public:
    Tank(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void appear() override;
    bool isExistAndNearRail();
    void kill() override;
    void control() override;
    s64 die();
    void calcAnim() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool isMyBullet(al::HitSensor* sensor);
    void shootByPlayer(const sead::Vector3f& shotPos, f32 shotSpeed, s32 shotType);
    bool isSwoon() const;
    void appearCtrl();
    void preInitHandleByMofumofu();
    void appearAndDemoWait();
    void endDemoWait();
    void startShootByMofumofu();
    void startBlowDownByMofumofu(al::HitSensor* sensor);
    void startRevive();
    void startRevivePrepare();
    void forceEndHackByMofumofu();
    void setSubjectiveCameraLimitDegree(f32 horizontalDegree, f32 verticalDegree);
    void setSubjectiveCameraAimFollorRateV(f32 subjectiveCameraAimFollorRateV);
    bool isHacking() const;
    bool isRevivePrepare() const;
    bool isEnableStartAttack() const;
    void exeWait();
    void turn();
    void exeAppear();
    void exeMove();
    void exeAttackSign();
    void exeShoot();
    bool isEnableShoot();
    void exeReset();
    void exeReviveInsideScreenNoAutoRevive();
    void exeReviveInsideScreen();
    void exePressReaction();
    void exePressDown();
    void exeBlowDown();
    void exeDamageCap();
    void exeAttackHit();
    void exeSwoon();
    void exeHack();
    void exeDemoWait();
    s32 countAliveBullet() const;
    void enableShoot();   // Function should be implemented in header
    void disableShoot();  // Function should be implemented in header
private:
    u8 filler[0x1B0 - sizeof(al::LiveActor)];
};

static_assert(sizeof(Tank) == 0x1B0);
