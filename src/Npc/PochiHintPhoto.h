#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class PochiHintPhoto : public al::LiveActor {
public:
    PochiHintPhoto(const char* name);
    void setIsLinkChild();
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();

private:
    u8 filler[0x110 - sizeof(al::LiveActor)];
};

static_assert(sizeof(PochiHintPhoto) == 0x110);
