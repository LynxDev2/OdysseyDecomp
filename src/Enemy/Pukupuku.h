#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class Pukupuku : public al::LiveActor {
public:
    Pukupuku(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    bool isNerveInWater() const;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void endCapture();
    void revive(s32 reviveDelay);
    void startCapture();
    void updateEffectWaterSurface();
    void updateWaterCondition();
    void control() override;
    void updateInputRolling();
    void updateInputKiss();
    void updateInputUpDown();
    bool isSwimTypeA() const;
    void updateVelocity();
    void exeReaction();
    void exeWaitRollingRail();
    void exeWait();
    bool checkCollidedFloorDamageAndNextNerve();
    void exeWaitTurnToRailDir();
    void exeSwoon();
    void exeCaptureStart();
    void exeCaptureStartEnd();
    f32 getAccel(IUsePlayerHack* iUsePlayerHack) const;
    void exeCaptureSwimStart();
    void onWaterOut();
    bool tryAddVelocityWaterSurfaceJumpOut();
    s64 approachSurface();
    void updatePoseSwim();
    bool isTriggerSwimDash() const;
    void onWaterIn();
    void exeCaptureSwim();
    void exeCaptureReactionWall();
    bool checkJumpOutCondition() const;
    bool updateCameraCaptureWait();
    void exeCaptureWait();
    void exeCaptureAttack();
    void exeCaptureRolling();
    bool updateGroundTimeLimit();
    void exeCaptureWaitGround();
    void exeCaptureJumpGround();
    void exeCaptureLandGround();
    void exeBlowDown();
    void exeTrample();
    void exeRevive();
    void exeDemoWaitToRevive();

private:
    u8 filler[0x308 - sizeof(al::LiveActor)];
};

static_assert(sizeof(Pukupuku) == 0x308);
