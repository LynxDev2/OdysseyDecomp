#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;

class LightningController : public LiveActor {
public:
    LightningController(const char* name);

private:
    u8 filler[0x148 - sizeof(LiveActor)];
};

static_assert(sizeof(LightningController) == 0x148);
}  // namespace al
