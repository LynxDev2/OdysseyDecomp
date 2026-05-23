#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class CapRack : public al::LiveActor {
public:
    CapRack(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void offCapWithStageSwitch();
    void initByDoorAreaChangeCap(const al::ActorInitInfo& info);
    void initAfterPlacement() override;
    void makeActorDead() override;
    bool isRack();
    void offCap();
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void control() override;
    void offCapByDoor();
    void exeOffWait();
    void exeRack();
    void exeRackWait();
    void exeOff();
    void exeFreeze();

private:
    u8 filler[0x148 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CapRack) == 0x148);
