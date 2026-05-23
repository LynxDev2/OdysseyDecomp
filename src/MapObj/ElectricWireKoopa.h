#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class ElectricWireKoopa : public al::LiveActor {
public:
    ElectricWireKoopa(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void start();
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeDemoAppearPrepare();
    void exeDemoAppear();
    void exeWait();
    void exeInDiveIn();
    void exeInStart();
    void exeInWait();
    void exeInCharge();
    const sead::Vector3f& exeInMoveStart();
    void exeInMove();

private:
    u8 filler[0x140 - sizeof(al::LiveActor)];
};

static_assert(sizeof(ElectricWireKoopa) == 0x140);
