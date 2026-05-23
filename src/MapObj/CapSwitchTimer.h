#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class CapSwitchTimer : public al::LiveActor {
public:
    CapSwitchTimer(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void initAfterPlacement() override;
    void control() override;
    void exeOffWait();
    void exeOffWaitCapHold();
    void exeHitReaction();
    void exeOnWait();
    void exeReturnOff();
    void exeFreeze();

private:
    u8 filler[0x140 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CapSwitchTimer) == 0x140);
