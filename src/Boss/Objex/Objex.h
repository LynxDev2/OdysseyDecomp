#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class Objex : public al::LiveActor {
public:
    Objex(const char*);
    void init(const al::ActorInitInfo&) override;
    bool receiveMsg(const al::SensorMsg*message, al::HitSensor*other, al::HitSensor*self) override;
    void exeWait();
    void exeAttackSlide();
    void exeDamage();
    const sead::Vector3f& exeAppearCrystal();
    void exeWaitCrystal();
private:
    u8 filler[0x138 - sizeof(al::LiveActor)];
};
static_assert(sizeof(Objex) == 0x138);
