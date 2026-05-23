#pragma once

#include <basis/seadTypes.h>

#include "Library/Demo/DemoActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class DemoActorKoopaShip : public al::DemoActor {
public:
    DemoActorKoopaShip(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void calcAnim() override;
    void startAction(s32 action);

private:
    u8 filler[0x188 - sizeof(al::DemoActor)];
};

static_assert(sizeof(DemoActorKoopaShip) == 0x188);
