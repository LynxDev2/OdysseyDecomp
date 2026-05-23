#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class AirCurrent : public al::LiveActor {
public:
    AirCurrent(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void start();
    void stop();
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    f32 calcBlowPowerRate() const;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void control() override;
    void endClipped() override;
    void exeStop();
    void exeSleep();
    bool isBlowContinuous() const;
    void exeWait();
    bool isMoveAtWait() const;
    void updateKeyMove();
    void exeBlowSign();
    void exeBlowStart();
    void exeBlow();
    bool isMoveAtBlow() const;
    void sendBlowMsgToCollision();
    void exeBlowEnd();

private:
    u8 filler[0x188 - sizeof(al::LiveActor)];
};

static_assert(sizeof(AirCurrent) == 0x188);
