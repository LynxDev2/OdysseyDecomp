#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class WaterfallWorldBigBreakableWall : public al::LiveActor {
public:
    WaterfallWorldBigBreakableWall(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void kill() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void exeBeforeDemo();
    void exeDemo();

private:
    u8 filler[0x140 - sizeof(al::LiveActor)];
};

static_assert(sizeof(WaterfallWorldBigBreakableWall) == 0x140);
