#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class HackMapParts : public al::LiveActor {
public:
    HackMapParts(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool isHack() const;
    void exeWait();
    void exeWaitHack();
    void exeHackStart();
    void exeHackMove();
    void exeHackEnd();
    void exeReaction();
    void control() override;

private:
    u8 filler[0x160 - sizeof(al::LiveActor)];
};

static_assert(sizeof(HackMapParts) == 0x160);
