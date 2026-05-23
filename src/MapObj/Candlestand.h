#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class Candlestand : public al::LiveActor {
public:
    Candlestand(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void burnUp();
    void initAfterPlacement() override;
    void appear() override;
    void appearBurning();
    void control() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool tryBurn(f32 burnAmount);
    void startRhythmSync();
    void stopRhythmSync();
    void exeBurnUp();
    void exeBurnDown();
    void exeBurnOut();
    bool isBurnUp() const;
    bool isBurning() const;

private:
    u8 filler[0x1A0 - sizeof(al::LiveActor)];
};

static_assert(sizeof(Candlestand) == 0x1A0);

class BurningLevelCalcurator {
public:
    BurningLevelCalcurator(f32 currentLevel, f32 targetLevel);
    void changeAttackTime(f32 attackTime);
    void changeReleaseTime(f32 releaseTime);
    void changeTarget(f32 targetLevel, bool isImmediate);
    void update();
};
