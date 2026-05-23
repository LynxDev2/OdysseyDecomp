#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class CapBeamer : public al::LiveActor {
public:
    CapBeamer(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void control() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void exeAttackSign();
    void exeAttackStart();
    void exeAttackLoop();
    void exeAttackEnd();
    void exeReaction();

private:
    u8 filler[0x120 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CapBeamer) == 0x120);
