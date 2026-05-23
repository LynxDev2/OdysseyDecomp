#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class Chair : public al::LiveActor {
public:
    Chair(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void exeBindSitDownStart();
    void exeBindSitDown();
    void exeBindStandUp();
    void exeBindJump();
    void exeWaitNoSitDown();
    void exeWaitLeave();
    void exeReaction();

private:
    u8 filler[0x138 - sizeof(al::LiveActor)];
};

static_assert(sizeof(Chair) == 0x138);
