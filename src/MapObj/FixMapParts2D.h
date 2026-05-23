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

class FixMapParts2D : public al::LiveActor, public IUseDimension {
public:
    FixMapParts2D(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    ActorDimensionKeeper* getActorDimensionKeeper() const override;

private:
    u8 filler[0x118 - sizeof(al::LiveActor) - sizeof(IUseDimension)];
};

static_assert(sizeof(FixMapParts2D) == 0x118);
