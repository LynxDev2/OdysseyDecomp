#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class KoopaCapPlayer : public al::LiveActor {
public:
    KoopaCapPlayer(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void startHideChase();
    void appear() override;
    void kill() override;
    void control() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void endEquipAndKill();
    bool isPlayingCatchDemo() const;
    bool isPlayerBinding() const;
    void onFinish();
    void offFinish();
    void endEquipAndBlowDown();
    void endEquipAndBlowDownWithoutHitReaction();
    void exeHideChase();
    void exeCatchPrepare();
    const sead::Vector3f& exeCatch();
    void exeStart();
    void exeWait();
    void exeWaitBubble();
    void exePunchStart();
    void exePunchWait();
    void exePunch();
    const sead::Vector3f& endPunch();
    const sead::Vector3f& exePunchEnd();
    void exePunchFinishStart();
    void exePunchFinish();
    void exePunchFinishWait();
    void exePunchFinishEnd();
    const sead::Vector3f& exeDamage();
    f32 exeBlowDown();
    void endBlowDown();

private:
    u8 filler[0x170 - sizeof(al::LiveActor)];
};

static_assert(sizeof(KoopaCapPlayer) == 0x170);
