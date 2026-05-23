#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"
#include "Library/MapObj/BreakMapPartsBase.h"

namespace al {
class HitSensor;
class SensorMsg;
struct ActorInitInfo;
}  // namespace al

class PoleClimbParts : public al::LiveActor {
public:
    PoleClimbParts(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void movement() override;
    void calcAnim() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void exeBreak();
    void exeReaction();

private:
    al::JudgeFuncPtr mBreakJudgeFunction = nullptr;
    bool mIsBreak = false;
    u8 filler[0x118 - sizeof(al::LiveActor) - sizeof(bool) - sizeof(al::JudgeFuncPtr)];
};

static_assert(sizeof(PoleClimbParts) == 0x118);
