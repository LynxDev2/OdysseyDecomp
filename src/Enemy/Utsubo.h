#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class Utsubo : public al::LiveActor {
public:
    Utsubo(const char* name, bool utsubo = false);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool isAttack() const;
    void control() override;
    void exeWait();
    void exeWaitForWatcher();
    void exeMove();
    void exeFollow();
    void exeRiseSign();
    void exeRise();
    void exeAttackSign();
    void exeAttack();
    void exeSink();
    void exeWaitForce();
    bool isRiseReady() const;
    void setNerveRiseSign();

private:
    u8 filler[0x198 - sizeof(al::LiveActor)];
};

static_assert(sizeof(Utsubo) == 0x198);
