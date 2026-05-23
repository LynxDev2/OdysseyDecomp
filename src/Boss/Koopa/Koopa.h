#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

#include "Util/IUseDimension.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class ActorDimensionKeeper;

class Koopa : public al::LiveActor, public IUseDimension {
public:
    Koopa(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool tryStartHackActionIfNotPlaying(const char* actionName, bool isImmediate);
    void initAfterPlacement() override;
    void appear() override;
    void makeActorDead() override;
    void kill() override;
    void movement() override;
    void control() override;
    void calcAnim() override;
    void updateCollider() override;
    void startHackAction(const char* actionName, bool isImmediate);
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeSwoon();
    const sead::Vector3f& exeSwoonReaction();
    void exeDemoHackFirst();
    void exeStart();
    void exeWait();
    void endWait();
    void exeTurnPoint();
    void exeMove();
    void exeMoveBrake();
    void exeMoveBrakeTurn();
    void exeJumpStart();
    void exeJump();
    void exeJumpEnd();
    void exeFall();
    void exe2D();
    void end2D();
    void exeBind();
    void exeBindHackStart();
    void exeStop();
    const sead::Vector3f& exeDead();
    f32 exeDeadFall();
    void startBind();
    void endBind();
    void endBindAndPopUp(const sead::Vector3f& pos);
    void hideBindModel();
    void resetBindPosition(const sead::Vector3f& pos);
    const sead::Vector3f& calcPuppetMoveDir(sead::Vector3f* outDir,
                                            const sead::Vector3f& moveDir) const;
    bool isTriggerSwing() const;
    bool isBindWait() const;
    void changeHackTutorialElectricWire();
    void closeHackTutorial();
    void changeBind2D();
    void changeBindHackStart(const sead::Vector3f& bindStartPos,
                             const sead::Vector3f& bindTargetPos);
    f32 getBindHackStartActionFrame() const;
    f32 getBindHackStartActionFrameMax() const;
    ActorDimensionKeeper* getActorDimensionKeeper() const override;

private:
    u8 filler[0x220 - sizeof(al::LiveActor) - sizeof(IUseDimension)];
};

static_assert(sizeof(Koopa) == 0x220);
