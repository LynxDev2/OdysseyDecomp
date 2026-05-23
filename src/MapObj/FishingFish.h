#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class FishingFish : public al::LiveActor {
public:
    FishingFish(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void movement() override;
    void updateCollider() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    const sead::Vector3f& startFishingUp(const sead::Vector3f& startPos,
                                         const sead::Vector3f& targetPos, const char* actionName);
    f32 calcFishingPullRate() const;
    bool isEnableFishingUp() const;
    bool isFailureFishingUp() const;
    bool isValidAfterAppearDemoEvent() const;
    bool tryStartFishingUpWithEventDemo(const sead::Vector3f& startPos,
                                        const sead::Vector3f& targetPos, const char* demoName);
    s64 cancelFishing();
    bool checkNeedMoveToBack() const;
    void exeWait();
    void exeMove();
    void exeBrake();
    void exeChase();
    void exeTouch();
    void exeTouchDummy();
    void exeTouchAfter();
    void exeFishingUpImmediatelyPrepare();
    void exeRunaway();
    void exeHitPullStart();
    void exeHitPull();
    void endHitPull();
    void exeHitPullEnd();
    void exeReset();
    void exeResetAfterFishing();
    void exeRevival();

private:
    u8 filler[0x198 - sizeof(al::LiveActor)];
};

static_assert(sizeof(FishingFish) == 0x198);
