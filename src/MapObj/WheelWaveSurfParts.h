#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class WheelWaveSurfParts : public al::LiveActor {
public:
    WheelWaveSurfParts(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void control() override;
    void updateFinder();
    const sead::Vector3f& getBaseTrans(sead::Vector3f* trans) const;
    bool isExistSurface() const;
    void approachSurface();
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void appearAndSetStart();
    void exeWait();
    void exeMove();

private:
    u8 filler[0x1C0 - sizeof(al::LiveActor)];
};

static_assert(sizeof(WheelWaveSurfParts) == 0x1C0);
