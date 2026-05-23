#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class BossRaidNpc : public al::LiveActor {
public:
    BossRaidNpc(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool isEnableReaction() const;
    void exeEvent();
    void exeReaction();

private:
    u8 filler[0x120 - sizeof(al::LiveActor)];
};

static_assert(sizeof(BossRaidNpc) == 0x120);
