#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class FukankunZoomCapMessageSun : public al::LiveActor {
public:
    FukankunZoomCapMessageSun(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void control() override;
    void exeWait();

private:
    u8 filler[0x128 - sizeof(al::LiveActor)];
};

static_assert(sizeof(FukankunZoomCapMessageSun) == 0x128);
