#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;

class SwitchKeepOnWatcher : public LiveActor {
public:
    SwitchKeepOnWatcher(const char* name);

private:
    u8 filler[0x110 - sizeof(LiveActor)];
};

static_assert(sizeof(SwitchKeepOnWatcher) == 0x110);
}  // namespace al
