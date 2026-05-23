#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class MultiGateKeeperBonfire : public al::LiveActor {
public:
    MultiGateKeeperBonfire(const char*);
    void init(const al::ActorInitInfo&) override;
    void deadGK();
private:
    u8 filler[0x118 - sizeof(al::LiveActor)];
};
static_assert(sizeof(MultiGateKeeperBonfire) == 0x118);
