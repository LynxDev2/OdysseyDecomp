#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class GrowPlantStartStage : public al::LiveActor {
public:
    GrowPlantStartStage(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void kill() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void exeSet();
    void exeJumpPlayer();
    void exeDown();

private:
    u8 filler[0x148 - sizeof(al::LiveActor)];
};

static_assert(sizeof(GrowPlantStartStage) == 0x148);
