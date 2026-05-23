#pragma once

#include <basis/seadTypes.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>

#include "Library/Event/IEventFlowEventReceiver.h"
#include "Library/Joint/JointControllerBase.h"
#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class JugemFishingSurfaceCheckInfo;

class JugemFishing : public al::LiveActor, public al::IEventFlowEventReceiver {
public:
    JugemFishing(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void kill() override;
    void control() override;
    void updateCollider() override;
    void calcAnim() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool receiveEvent(const al::EventFlowEventData* eventData) override;
    void exeFreeze();
    void exeWait();
    const sead::Vector3f& exeFishingStart();
    void exeFishing();
    const sead::Vector3f& exeFishingEnd();
    const sead::Vector3f& exeReaction();
    void exeHackStart();
    f32 exeHackWait();
    void exeHackTurnPoint();
    void exeHackMove();
    const sead::Vector3f& exeHackFishingStart();
    void exeHackFishing();
    void exeHackFishingSign();
    void endHackFishingSign();
    void exeHackFishingEnd();
    void exeHackFishingPullInOut();
    void endHackFishingPullInOut();
    void exeHackFishingFailure();
    void exeHackFishingSuccessStart();
    void exeHackFishingSuccessStartImmediately();
    void exeHackFishingSuccess();
    const sead::Vector3f& exeHackFishingSuccessWithFishEventDemo();
    void exeHackFishingSuccessWithFishEventDemoAfter();
    const sead::Vector3f& exeHackEnd();
    const sead::Vector3f& exeHackEndAfter1();
    void exeHackEndAfter2();

private:
    u8 filler[0x1E0 - sizeof(al::LiveActor) - sizeof(al::IEventFlowEventReceiver)];
};

static_assert(sizeof(JugemFishing) == 0x1E0);

class JugemFishingFunction {
public:
    f32 getJugemFloatOffset();
    bool tryCheckSurface(JugemFishingSurfaceCheckInfo* jugemFishingSurfaceCheckInfo,
                         const al::LiveActor* actor, const sead::Vector3f& startPos,
                         const sead::Vector3f& endPos);
};

class JugemFishingFloatOffsetCtrl : public al::JointControllerBase, public al::IUseNerve {
public:
    JugemFishingFloatOffsetCtrl(al::LiveActor* actor, const char* jugemFishingFloatOffsetCtrlName);
    void calcJointCallback(s32 jointCallback, sead::Matrix34f* matrix) override;
    void endHack();
    void startFishing();
    void endFishing();
    void exeWait();
    void exeFishingStart();
    void exeFishingWait();
    void exeFishingEnd();
    s64 getMaterialCode() const;
    bool isHitTopWater() const;
    bool isHitTopCollision() const;
    const char* getCtrlTypeName() const override;
    al::NerveKeeper* getNerveKeeper() const override;

private:
    u8 filler[0x1E0 - sizeof(al::JointControllerBase) - sizeof(al::IUseNerve)];
};

class JugemFishingHookOffsetCtrl : public al::JointControllerBase, public al::IUseNerve {
public:
    JugemFishingHookOffsetCtrl(al::LiveActor*, const char*, const char*,
                               const JugemFishingSurfaceCheckInfo*);
    void calcJointCallback(s32 jointCallback, sead::Matrix34f* matrix) override;
    void endHack();
    void startFishing(s32 startStep, s32 endStep);
    void endFishing(s32 fishing);
    void exeWait();
    void exeFishingStartDelay();
    void exeFishingStart();
    void exeFishingWait();
    void exeFishingEnd();
    const char* getCtrlTypeName() const override;
    al::NerveKeeper* getNerveKeeper() const override;

private:
    u8 filler[0x1E0 - sizeof(al::JointControllerBase) - sizeof(al::IUseNerve)];
};

class JugemFishingSurfaceCheckInfo {
public:
    JugemFishingSurfaceCheckInfo();
    void reset();
    bool isHitCollisionMaterialCode(const char* name) const;
};
