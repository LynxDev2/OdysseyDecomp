#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class CapCatapult : public al::LiveActor {
public:
    CapCatapult(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool isReactionable() const;
    bool isActive() const;
    void resetAll();
    bool isEnableBind() const;
    void exeWait();
    void exeReaction();
    void exeLockedOn();
    void exePull();
    void exeBack();
    void exeShoot();
    void exeShootEnd();
    void control() override;

private:
    u8 filler[0x160 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CapCatapult) == 0x160);
