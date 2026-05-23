#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class YoshiFruit : public al::LiveActor {
public:
    YoshiFruit(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void killWaterSurfaceShadow();
    void initAfterPlacement() override;
    void control() override;
    f32 exeWait();
    void exeReaction();
    void exeReactionCap();
    void exeReactionMotorcycle();
    void exeBind();
    void exeRestart();
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void eatAndKill();

private:
    u8 filler[0x160 - sizeof(al::LiveActor)];
};

static_assert(sizeof(YoshiFruit) == 0x160);
