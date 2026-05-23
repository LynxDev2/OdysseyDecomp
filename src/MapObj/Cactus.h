#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class Cactus : public al::LiveActor {
public:
    Cactus(const char* name);
    void init(const al::ActorInitInfo& info) override;
    f32 calcColliderTrans(sead::Vector3f* trans);
    void initAfterPlacement() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void calcAnim() override;
    void exeWait();
    void exeReaction();
    void exeBlowDown();
    void setRevival();
    void exeBreak();
    void exeRevival();

private:
    u8 filler[0x1D8 - sizeof(al::LiveActor)];
};

static_assert(sizeof(Cactus) == 0x1D8);
