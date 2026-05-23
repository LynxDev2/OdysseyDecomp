#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

#include "Util/IUseDimension.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class ActorDimensionKeeper;

class KuriboGenerator2D : public al::LiveActor, public IUseDimension {
public:
    KuriboGenerator2D(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void exeWait();
    void exeMove();
    ActorDimensionKeeper* getActorDimensionKeeper() const override;

private:
    u8 filler[0x130 - sizeof(al::LiveActor) - sizeof(IUseDimension)];
};

static_assert(sizeof(KuriboGenerator2D) == 0x130);
