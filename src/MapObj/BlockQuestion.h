#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class BlockQuestion : public al::LiveActor {
public:
    BlockQuestion(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void listenApeear();
    void listenKill();
    void initAfterPlacement() override;
    void appear() override;
    void control() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    void exeSingleItem();
    void exeTenCoin();
    void exeDead();

private:
    u8 filler[0x148 - sizeof(al::LiveActor)];
};

static_assert(sizeof(BlockQuestion) == 0x148);
