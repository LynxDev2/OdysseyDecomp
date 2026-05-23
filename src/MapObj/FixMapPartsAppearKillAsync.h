#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class FixMapPartsAppearKillAsync : public al::LiveActor {
public:
    FixMapPartsAppearKillAsync(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void appear() override;
    void kill() override;
    void movement() override;
    void calcAnim() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;

private:
    u8 filler[0x110 - sizeof(al::LiveActor)];
};

static_assert(sizeof(FixMapPartsAppearKillAsync) == 0x110);
