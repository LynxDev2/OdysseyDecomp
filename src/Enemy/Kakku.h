#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

#include "Player/IUsePlayerCollision.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class PlayerCollider;

class Kakku : public al::LiveActor, public IUsePlayerCollision {
public:
    Kakku(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void startActionCapOff();
    void initAfterPlacement() override;
    void control() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void updateCollider() override;
    void exeAppearStart();
    void exeWait();
    bool trySlide();
    void endWait();
    void exeFall();
    void endFall();
    void exeSlide();
    void exeJumpEnd();
    void exeReaction();
    void exeReactionTrample();
    void exeReviveInsideScreen();
    void exeWaitHack();
    void exeWaitHackFall();
    void exeHackStart();
    void exeHackWalk();
    bool trySlideHack();
    bool tryJumpByFloorCode();
    void exeHackJump();
    void exeHackFall();
    void resetUpVec(f32 upVec);
    void exeHackLand();
    void exeHackGlide();
    void endHackGlide();
    void exeHackSlide();
    void exeSandGeyser();
    void exeHackBlowStartByJoku();
    void updateBlow();
    void exeHackBlowLoopByJoku();
    PlayerCollider* getPlayerCollider() const override;

private:
    u8 filler[0x258 - sizeof(al::LiveActor) - sizeof(IUsePlayerCollision)];
};

static_assert(sizeof(Kakku) == 0x258);
