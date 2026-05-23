#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class CloudStep : public al::LiveActor {
public:
    CloudStep(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void control() override;
    void exeWait();
    void exeWaitOnPlayer();
    void exeAppear();
    void endAppear();
    void exeDisappear();
    void endDisappear();
    void exeThrough();
    void exeLand();

private:
    u8 filler[0x138 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CloudStep) == 0x138);
