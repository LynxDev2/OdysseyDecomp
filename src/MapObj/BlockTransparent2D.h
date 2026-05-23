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

class BlockTransparent2D : public al::LiveActor, public IUseDimension {
public:
    BlockTransparent2D(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void control() override;
    ActorDimensionKeeper* getActorDimensionKeeper() const override;

private:
    u8 filler[0x138 - sizeof(al::LiveActor) - sizeof(IUseDimension)];
};

static_assert(sizeof(BlockTransparent2D) == 0x138);
