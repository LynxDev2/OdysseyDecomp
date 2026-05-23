#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class CapFlower : public al::LiveActor {
public:
    CapFlower(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void appear() override;
    void control() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool isBloom() const;
    bool isGerm() const;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    void exeGerm();
    void exeReturnToGerm();
    void exeBloom();
    bool isBloomTrig() const;
    bool tryPlayReturnAnim();
    void changeFlowerColorWhite();
    void forceReturnToGerm();
    bool tryStopReturnAnim();

private:
    u8 filler[0x110 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CapFlower) == 0x110);
