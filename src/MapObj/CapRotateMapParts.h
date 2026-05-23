#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class CapRotateMapParts : public al::LiveActor {
public:
    CapRotateMapParts(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    s32 getRotateCount() const;
    void deactivate();
    void exeWait();

private:
    u8 filler[0x110 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CapRotateMapParts) == 0x110);
