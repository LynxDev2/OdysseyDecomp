#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class HomeInside : public al::LiveActor {
public:
    HomeInside(const char* name);
    void init(const al::ActorInitInfo& info) override;

private:
    u8 filler[0x108 - sizeof(al::LiveActor)];
};

static_assert(sizeof(HomeInside) == 0x108);

class HomeShip : public al::LiveActor {
public:
    HomeShip(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();

private:
    u8 filler[0x108 - sizeof(al::LiveActor)];
};
