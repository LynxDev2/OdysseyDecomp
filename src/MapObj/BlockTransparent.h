#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class BlockTransparent : public al::LiveActor {
public:
    BlockTransparent(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void setReaction(al::HitSensor* sensor);
    void exeWait();
    void exeReaction();
    void exeVisible();

private:
    u8 filler[0x138 - sizeof(al::LiveActor)];
};

static_assert(sizeof(BlockTransparent) == 0x138);
