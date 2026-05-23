#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class RadiconNpc : public al::LiveActor {
public:
    RadiconNpc(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void kill() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void endHack();
    void control() override;
    bool exeWait();
    void exeWaitHack();
    void exeStartHack();
    void exeHackWait();
    void exeHackShake();
    void exeEndHack();
    void exeReaction();

private:
    u8 filler[0x180 - sizeof(al::LiveActor)];
};

static_assert(sizeof(RadiconNpc) == 0x180);
