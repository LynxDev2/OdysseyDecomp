#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class SphinxTaxiWatcher : public al::LiveActor {
public:
    SphinxTaxiWatcher(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void exeWait();
    void exePlayerBind();

private:
    u8 filler[0x120 - sizeof(al::LiveActor)];
};

static_assert(sizeof(SphinxTaxiWatcher) == 0x120);
