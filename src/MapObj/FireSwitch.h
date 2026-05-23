#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class FireSwitch : public al::LiveActor {
public:
    FireSwitch(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void appear() override;
    void control() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWaitNoBurn();
    void exeReaction();
    void exeBurnStart();
    void exeBurnLoop();
    void exeBurnEnd();

private:
    u8 filler[0x120 - sizeof(al::LiveActor)];
};

static_assert(sizeof(FireSwitch) == 0x120);
