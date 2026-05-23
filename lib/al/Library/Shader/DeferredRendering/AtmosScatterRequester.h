#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;

class AtmosScatterRequester : public LiveActor {
public:
    AtmosScatterRequester(const char*);

private:
    u8 filler[0x128 - sizeof(LiveActor)];
};

static_assert(sizeof(AtmosScatterRequester) == 0x128);
}  // namespace al
