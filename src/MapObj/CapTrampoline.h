#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class CapTrampoline : public al::LiveActor {
public:
    CapTrampoline(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void listenAppear();
    void initAfterPlacement() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void control() override;
    void exeWait();
    void exeOpenStart();
    void exeOpen();
    void exeReOpen();
    void exeJump();
    void exePressReaction();
    void exeClose();

private:
    u8 filler[0x128 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CapTrampoline) == 0x128);
