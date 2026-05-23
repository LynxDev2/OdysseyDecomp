#pragma once

#include <basis/seadTypes.h>

#include "Library/Demo/DemoActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class DemoActorShineTower : public al::DemoActor {
public:
    DemoActorShineTower(const char* name);
    void makeActorAlive() override;
    void makeActorDead() override;
    void control() override;
    void init(const al::ActorInitInfo& info) override;

private:
    u8 filler[0x1A8 - sizeof(al::DemoActor)];
};

static_assert(sizeof(DemoActorShineTower) == 0x1A8);
