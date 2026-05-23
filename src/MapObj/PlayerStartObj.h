#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class PlayerStartObj : public al::LiveActor {
public:
    PlayerStartObj(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool tryRequestStartDemo();
    s64 requestBind();
    void setStartId(const char* name);
    void initAfterPlacement() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeDemoWait();
    void exeBindWait();
    void exeWait();
    void exeMove();
    void exeBindEnd();

private:
    u8 filler[0x1B0 - sizeof(al::LiveActor)];
};

static_assert(sizeof(PlayerStartObj) == 0x1B0);
