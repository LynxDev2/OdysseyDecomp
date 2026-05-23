#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;

class SeBarrierObj : public LiveActor {
public:
    SeBarrierObj(const char* name);

private:
    u8 filler[0x160 - sizeof(LiveActor)];
};

static_assert(sizeof(SeBarrierObj) == 0x160);
}  // namespace al
