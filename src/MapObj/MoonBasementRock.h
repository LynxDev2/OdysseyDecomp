#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class MoonBasementRock : public al::LiveActor {
public:
    MoonBasementRock(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void kill() override;
    void updateCollider() override;
    bool isFalling() const;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void exeBreak();
    void exeFall();
    void exeLand();

private:
    u8 filler[0x118 - sizeof(al::LiveActor)];
};

static_assert(sizeof(MoonBasementRock) == 0x118);
