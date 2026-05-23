#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;

class RippleFixMapParts : public LiveActor {
public:
    RippleFixMapParts(const char* name);

private:
    u8 filler[0x130 - sizeof(LiveActor)];
};

static_assert(sizeof(RippleFixMapParts) == 0x130);
class SensorMsg;
class HitSensor;
}  // namespace al
