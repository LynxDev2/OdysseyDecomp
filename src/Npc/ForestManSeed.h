#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class ForestManSeed : public al::LiveActor {
public:
    ForestManSeed(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool isEnableSeedReset() const;
    bool isSetSeed() const;
    bool isEnableReaction() const;
    void control() override;
    void exeWait();
    void tryUpdateSeedPosAndPose();
    bool tryEndGiveSeed();
    void exeSwitchOn();
    void exeOnWait();
    void exeSwitchOff();
    void updateSeedPosAndPose();
    void exeScare();
    void exeReaction();
    bool isPlantPlaceEmptyAny() const;

private:
    u8 filler[0x160 - sizeof(al::LiveActor)];
};

static_assert(sizeof(ForestManSeed) == 0x160);
