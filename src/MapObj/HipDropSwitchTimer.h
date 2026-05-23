#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class HipDropSwitchTimer : public al::LiveActor {
public:
    HipDropSwitchTimer(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void control() override;
    bool isOn() const;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void startClipped() override;
    void exeOff();
    void exeOffWait();
    void exeReactionLand();
    void exeOn();
    void exeOnWait();

private:
    u8 filler[0x130 - sizeof(al::LiveActor)];
};

static_assert(sizeof(HipDropSwitchTimer) == 0x130);
