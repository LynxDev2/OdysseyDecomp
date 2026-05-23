#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;

class OccludedEffectRequester : public LiveActor {
public:
    OccludedEffectRequester(const char* name);

private:
    u8 filler[0x140 - sizeof(LiveActor)];
};

static_assert(sizeof(OccludedEffectRequester) == 0x140);
}  // namespace al
