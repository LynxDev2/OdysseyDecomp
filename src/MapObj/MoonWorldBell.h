#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class MoonWorldBell : public al::LiveActor {
public:
    MoonWorldBell(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void exeCapReaction();
    void exeHipDropReaction();

private:
    u8 filler[0x108 - sizeof(al::LiveActor)];
};

static_assert(sizeof(MoonWorldBell) == 0x108);
