#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class CityStreetlight : public al::LiveActor {
public:
    CityStreetlight(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void calcAnim() override;
    void exeWaitOn();
    void exeWaitOff();

private:
    u8 filler[0x108 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CityStreetlight) == 0x108);
