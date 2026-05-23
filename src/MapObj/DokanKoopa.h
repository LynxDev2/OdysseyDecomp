#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class HitSensor;
}  // namespace al

class DokanKoopa : public al::LiveActor {
public:
    DokanKoopa(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void control() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    void exeWait();
    void exeInStart();
    const sead::Vector3f& exeIn();
    void exeInWait();
    void exeOutSign();
    void exeOut();

private:
    u8 filler[0x148 - sizeof(al::LiveActor)];
};

static_assert(sizeof(DokanKoopa) == 0x148);
