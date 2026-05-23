#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class GrowFlowerWatcher : public al::LiveActor {
public:
    GrowFlowerWatcher(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;

private:
    u8 filler[0x130 - sizeof(al::LiveActor)];
};

static_assert(sizeof(GrowFlowerWatcher) == 0x130);
