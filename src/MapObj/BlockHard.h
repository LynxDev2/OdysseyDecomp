#pragma once

#include <basis/seadTypes.h>

#include "Library/MapObj/BreakMapPartsBase.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class BlockHard : public al::BreakMapPartsBase {
public:
    BlockHard(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void kill() override;
    void movement() override;
    void calcAnim() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void startBreak(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self);
    al::JudgeFuncPtr getJudgeFunction(const char* name) const override;
    bool validateIncludeShineChip();

private:
    u8 filler[0x158 - sizeof(al::BreakMapPartsBase)];
};

static_assert(sizeof(BlockHard) == 0x158);
