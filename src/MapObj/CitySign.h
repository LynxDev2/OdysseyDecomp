#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class CitySign : public al::LiveActor {
public:
    CitySign(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void exeLightOff();

private:
    u8 filler[0x108 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CitySign) == 0x108);
