#pragma once

#include <basis/seadTypes.h>

#include "Library/MapObj/FixMapParts.h"

namespace al {
class SensorMsg;
class HitSensor;
}  // namespace al

class FixMapPartsForceSafetyPoint : public al::FixMapParts {
public:
    FixMapPartsForceSafetyPoint(const char* name);
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;

private:
    u8 filler[0x110 - sizeof(al::FixMapParts)];
};

static_assert(sizeof(FixMapPartsForceSafetyPoint) == 0x110);
