#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class RadioCassette : public al::LiveActor {
public:
    RadioCassette(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void appear() override;
    void control() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void endWait();
    void exeReactionNoise();
    void exeReactionNoiseEnd();
    void exeReactionTuning();
    void exeStartSpecialCollectBgm();

private:
    u8 filler[0x168 - sizeof(al::LiveActor)];
};

static_assert(sizeof(RadioCassette) == 0x168);
