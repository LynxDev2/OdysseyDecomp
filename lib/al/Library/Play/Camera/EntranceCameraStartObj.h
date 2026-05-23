#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;

class EntranceCameraStartObj : public LiveActor {
public:
    EntranceCameraStartObj(const char* name);

private:
    u8 filler[0x110 - sizeof(LiveActor)];
};

static_assert(sizeof(EntranceCameraStartObj) == 0x110);
}  // namespace al
