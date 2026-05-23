#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class ShineFukankunWatchObj : public al::LiveActor {
public:
    ShineFukankunWatchObj(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void exeWait();

private:
    u8 filler[0x110 - sizeof(al::LiveActor)];
};

static_assert(sizeof(ShineFukankunWatchObj) == 0x110);
