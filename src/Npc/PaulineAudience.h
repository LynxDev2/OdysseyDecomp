#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class PaulineAudience : public al::LiveActor {
public:
    PaulineAudience(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void control() override;
    void forceControlForDance();
    void controlForDance();
    void endClipped() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeDance();
    void exeSabi();
    void exeReaction();

private:
    u8 filler[0x130 - sizeof(al::LiveActor)];
};

static_assert(sizeof(PaulineAudience) == 0x130);
