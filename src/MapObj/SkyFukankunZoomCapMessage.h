#pragma once

#include <basis/seadTypes.h>

#include "Library/Obj/Sky.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class SkyFukankunZoomCapMessage : public al::Sky {
public:
    SkyFukankunZoomCapMessage(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void control() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;

private:
    u8 filler[0x128 - sizeof(al::Sky)];
};

static_assert(sizeof(SkyFukankunZoomCapMessage) == 0x128);
