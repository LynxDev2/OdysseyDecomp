#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;

class WaterAreaMoveModel : public LiveActor {
public:
    WaterAreaMoveModel(const char* name);

private:
    u8 filler[0x140 - sizeof(LiveActor)];
};

static_assert(sizeof(WaterAreaMoveModel) == 0x140);
}  // namespace al
