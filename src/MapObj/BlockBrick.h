#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class BlockBrick : public al::LiveActor {
public:
    BlockBrick(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    void control() override;
    void exeSingleItem();
    void exeTenCoin();
    void exeItemEmpty();
    void exeDead();

private:
    u8 filler[0x138 - sizeof(al::LiveActor)];
};

static_assert(sizeof(BlockBrick) == 0x138);
