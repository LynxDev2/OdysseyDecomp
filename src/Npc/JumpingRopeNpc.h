#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class JumpingRopeNpc : public al::LiveActor {
public:
    JumpingRopeNpc(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void tryMiss();
    void movement() override;
    void exeStart();
    void updateAnim(bool anim);
    void updateRot(bool rot);
    void updateRope();
    bool checkRopeCollision() const;
    void miss();
    bool isActionEnd() const;
    void exeWait();
    f32 restoreInterval();
    bool isEnableDisplayBalloon() const;
    s64 interrupt();
    void exeJump();
    u64 searchNearestNode();
    void endJump();
    void exeMiss();
    void startResultAction();
    void startResultMessage();
    bool tryStartResultLoopAction();
    bool isPlayerOff() const;
    void exeInterrupt();
    void exeTryAgain();
    void startReactionPartner();
    void control() override;
    f32 calcRopePos(sead::Vector3f* outPos, s32 ropeIndex, f32 heightRate) const;
    s64 getBest() const;
    void setBest(s32 best);
    void setBestToday(s32 bestToday);
    s64 getBestToday() const;
    bool isNerveJump() const;
    bool isNerveMiss() const;

private:
    u8 filler[0x228 - sizeof(al::LiveActor)];
};

static_assert(sizeof(JumpingRopeNpc) == 0x228);
