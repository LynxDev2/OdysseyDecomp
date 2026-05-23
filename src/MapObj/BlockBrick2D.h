#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

#include "Util/IUseDimension.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class ActorDimensionKeeper;

class BlockBrick2D : public al::LiveActor, public IUseDimension {
public:
    BlockBrick2D(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void control() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    void exeSingleItem();
    void exeTenCoin();
    void exeItemEmpty();
    void exeBreak();
    ActorDimensionKeeper* getActorDimensionKeeper() const override;

private:
    u8 filler[0x148 - sizeof(al::LiveActor) - sizeof(IUseDimension)];
};

static_assert(sizeof(BlockBrick2D) == 0x148);
