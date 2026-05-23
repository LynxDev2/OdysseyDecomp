#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

#include "Util/IUseDimension.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class ActorDimensionKeeper;

class BarrelGenerator2D : public al::LiveActor, public IUseDimension {
public:
    BarrelGenerator2D(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void exeDelay();
    void exeWait();
    void exeMove();
    ActorDimensionKeeper* getActorDimensionKeeper() const override;

private:
    u8 filler[0x138 - sizeof(al::LiveActor) - sizeof(IUseDimension)];
};

static_assert(sizeof(BarrelGenerator2D) == 0x138);
