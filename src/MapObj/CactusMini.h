#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class CactusMini : public al::LiveActor {
public:
    CactusMini(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void exeReaction();
    void exeBlowDown();
    void exeBreak();

private:
    u8 filler[0x138 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CactusMini) == 0x138);
