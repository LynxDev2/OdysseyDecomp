#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class Stake : public al::LiveActor {
public:
    Stake(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void listenStageSwitchWaterAreaDisappear();
    void initAfterPlacement() override;
    void kill() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeOffWait();
    void exeOn();
    void exeOnWait();
    void exePull();
    void exePullOut();

private:
    u8 filler[0x140 - sizeof(al::LiveActor)];
};

static_assert(sizeof(Stake) == 0x140);
