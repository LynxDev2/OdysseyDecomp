#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class EchoBlockMapParts : public al::LiveActor {
public:
    EchoBlockMapParts(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void begin();
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;

private:
    u8 filler[0x108 - sizeof(al::LiveActor)];
};

static_assert(sizeof(EchoBlockMapParts) == 0x108);
