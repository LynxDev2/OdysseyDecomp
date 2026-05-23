#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class SandGeyser : public al::LiveActor {
public:
    SandGeyser(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void control() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void startPlaceTypeAction(const char* actionName);
    void exeUpStart();
    void exeUpLoop();
    void exeUpWait();
    void exeUpEnd();
    void exeUpEndWait();

private:
    u8 filler[0x178 - sizeof(al::LiveActor)];
};

static_assert(sizeof(SandGeyser) == 0x178);
