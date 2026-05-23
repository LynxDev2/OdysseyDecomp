#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class KickStone : public al::LiveActor {
public:
    KickStone(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void movement() override;
    void control() override;
    void kill() override;
    void updateCollider() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void endWait();
    void exeFall();
    void exeRoll();
    void exeWater();
    void exeRestartPrepare();
    void exeEatPrepare();
    void exeEatBy();
    void exeHold();
    void endHold();

private:
    u8 filler[0x1E0 - sizeof(al::LiveActor)];
};

static_assert(sizeof(KickStone) == 0x1E0);
