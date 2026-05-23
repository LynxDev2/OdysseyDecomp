#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;

class Sky : public LiveActor {
public:
    Sky(const char* name);

private:
    u8 filler[0x120 - sizeof(LiveActor)];
};

static_assert(sizeof(Sky) == 0x120);
}  // namespace al
