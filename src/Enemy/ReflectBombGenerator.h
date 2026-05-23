#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class ReflectBombGenerator : public al::LiveActor {
public:
    ReflectBombGenerator(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void startLaunch();
    void endLaunch();
    void control() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeStop();
    void exeDelay();
    void exeWait();
    s64 findReflectBomb() const;
    void exeStandBy();
    const sead::Vector3f& exeLaunch();

private:
    u8 filler[0x140 - sizeof(al::LiveActor)];
};

static_assert(sizeof(ReflectBombGenerator) == 0x140);
