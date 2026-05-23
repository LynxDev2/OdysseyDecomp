#pragma once

#include <basis/seadTypes.h>

#include "Library/Demo/DemoActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class DemoActorHack : public al::DemoActor {
public:
    DemoActorHack(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void control() override;
    void makeActorAlive() override;
    void makeActorDead() override;

private:
    u8 filler[0x1C0 - sizeof(al::DemoActor)];
};

static_assert(sizeof(DemoActorHack) == 0x1C0);
