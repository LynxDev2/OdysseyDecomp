#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

#include "Demo/IUseDemoSkip.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class IUseDemoSkip;

class Mofumofu : public al::LiveActor, public IUseDemoSkip {
public:
    Mofumofu(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void switchFunctionStartDemo();
    void makeActorAlive() override;
    void makeActorDead() override;
    void kill() override;
    void movement() override;
    void updateCollider() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool isFirstDemo() const;
    bool isEnableSkipDemo() const;
    void skipDemo() override;
    f32 getAttackSensorRadius() const;
    f32 getBodySensorRadius() const;
    void exeDemoPrepare();
    void exeDemoOpeningBefore();
    void exeDemoOpening1();
    void exeDemoOpening2();
    void exeWallMoveStart();
    void exeWallMove();
    void exeWallBrake();
    void exeWallStop();
    void exeWallShootSign();
    void exeWallSinkStart();
    void exeWallSink();
    void exeWallSinkWarpIn();
    void exeWallSinkWaitBullet();
    void exeWallSinkCloseWarpHole();
    void exeWallOutOpenWarpHole();
    void exeWallOutShoot();
    void exeWallOutWarpOut();
    void exePanicStopSlow();
    void exePanicStopStart();
    void exePanicStop();
    void exePanicWalk();
    void exePanicWalkEnd();
    void exePanicDamage();
    void exePanic();
    void exeDamageDelay();
    void exeDamage();
    void exeDamageAfter();
    void exeDashFallWarpHole();
    void exeDashOpenWarpHole();
    void exeDashSign();
    void exeDash();
    void exeDashCloseWarpHole();
    void exeDashMoveWarpHole();
    void exeWallSinkRise();
    void exeWallSinkMove();
    void exeDemoBattleEndBefore();
    void exeDemoBattleEnd();
    void exeDemoBattleEndDieSign();
    void exeDemoBattleEndDie();
    void exeDemoBattleEndDieAfter();
    void afterDemoPrepare();

private:
    u8 filler[0x360 - sizeof(al::LiveActor) - sizeof(IUseDemoSkip)];
};

static_assert(sizeof(Mofumofu) == 0x360);
