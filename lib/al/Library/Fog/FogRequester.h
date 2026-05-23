#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;

class FogRequester : public LiveActor {
public:
    FogRequester(const char*);

private:
    u8 filler[0x138 - sizeof(LiveActor)];
};

static_assert(sizeof(FogRequester) == 0x138);
}  // namespace al
