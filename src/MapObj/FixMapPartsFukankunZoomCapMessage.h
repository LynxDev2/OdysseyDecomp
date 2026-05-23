#pragma once

#include <basis/seadTypes.h>

#include "Library/MapObj/FixMapParts.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class FixMapPartsFukankunZoomCapMessage : public al::FixMapParts {
public:
    FixMapPartsFukankunZoomCapMessage(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void appear() override;
    void movement() override;
    void calcAnim() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void control() override;

private:
    u8 filler[0x118 - sizeof(al::FixMapParts)];
};

static_assert(sizeof(FixMapPartsFukankunZoomCapMessage) == 0x118);
