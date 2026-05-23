#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;

class RippleGeneratePoint : public LiveActor {
public:
    RippleGeneratePoint(const char* name);

private:
    u8 filler[0x148 - sizeof(LiveActor)];
};

static_assert(sizeof(RippleGeneratePoint) == 0x148);
}  // namespace al
