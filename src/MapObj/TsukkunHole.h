#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class TsukkunHole : public al::LiveActor {
public:
    TsukkunHole(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void exeKill();

private:
    u8 filler[0x110 - sizeof(al::LiveActor)];
};

static_assert(sizeof(TsukkunHole) == 0x110);
