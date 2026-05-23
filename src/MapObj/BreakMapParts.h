#pragma once

#include <basis/seadTypes.h>

#include "Library/MapObj/BreakMapPartsBase.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class BreakMapParts : public al::BreakMapPartsBase {
public:
    BreakMapParts(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void kill() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    al::JudgeFuncPtr getJudgeFunction(const char* name) const override;

private:
    u8 filler[0x148 - sizeof(al::BreakMapPartsBase)];
};

static_assert(sizeof(BreakMapParts) == 0x148);
