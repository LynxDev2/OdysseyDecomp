#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class SenobiMoveMapParts : public al::LiveActor {
public:
    SenobiMoveMapParts(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void control() override;
    void exeWait();
    void exeMove();
    void exeStop();
    void exeStopEnd();
    void exeBack();

private:
    u8 filler[0x140 - sizeof(al::LiveActor)];
};

static_assert(sizeof(SenobiMoveMapParts) == 0x140);
