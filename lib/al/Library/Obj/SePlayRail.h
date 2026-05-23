#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;

class SePlayRail : public LiveActor {
public:
    SePlayRail(const char* name);

private:
    u8 filler[0x120 - sizeof(LiveActor)];
};

static_assert(sizeof(SePlayRail) == 0x120);
}  // namespace al
