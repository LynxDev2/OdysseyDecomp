#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class RailDrawer : public al::LiveActor {
public:
    RailDrawer(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void makeActorAlive() override;
    void makeActorDead() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();

private:
    u8 filler[0x118 - sizeof(al::LiveActor)];
};

static_assert(sizeof(RailDrawer) == 0x118);
