#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class KoopaLv1 : public al::LiveActor {
public:
    KoopaLv1(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void kill() override;
    void movement() override;
    void calcAnim() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeDemoStart();
    void exeJump1();
    void exeThrowCap();
    void exeJump2();
    void exeHipDrop();
    void exeThrowBall();
    void exeHitPunch();
    void exeAttackTail();
    void exeRecover();
    void exeFireBeam();
    void exeDeadAndDemoEnd();
    void exeDemoClashBasement();

private:
    u8 filler[0x1D8 - sizeof(al::LiveActor)];
};

static_assert(sizeof(KoopaLv1) == 0x1D8);
