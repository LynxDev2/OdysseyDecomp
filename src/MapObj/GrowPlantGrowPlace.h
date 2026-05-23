#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class GrowPlantGrowPlace : public al::LiveActor {
public:
    GrowPlantGrowPlace(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool isPlantEnd() const;
    bool isEqualPlacementId(const al::PlacementId& placementId) const;
    bool isClimb() const;

private:
    u8 filler[0x128 - sizeof(al::LiveActor)];
};

static_assert(sizeof(GrowPlantGrowPlace) == 0x128);
