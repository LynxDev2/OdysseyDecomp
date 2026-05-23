#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;

class SePlayObj : public LiveActor {
public:
    SePlayObj(const char* name);

private:
    u8 filler[0x1A0 - sizeof(LiveActor)];
};

static_assert(sizeof(SePlayObj) == 0x1A0);
}  // namespace al
