#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class BlockEmpty : public al::LiveActor {
public:
    BlockEmpty(const char* name, const char* blockEmptyName = nullptr);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void control() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void setShadowDropLength(f32 shadowDropLength);
    void startReaction();
    void startReactionTransparent();
    void exeWait();
    void exeReaction();
    void exeReactionTransparent();

private:
    u8 filler[0x130 - sizeof(al::LiveActor)];
};

static_assert(sizeof(BlockEmpty) == 0x130);
