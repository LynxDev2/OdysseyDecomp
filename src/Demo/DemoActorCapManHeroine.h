#pragma once

#include <basis/seadTypes.h>

#include "Library/Demo/DemoActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class DemoActorCapManHeroine : public al::DemoActor {
public:
    DemoActorCapManHeroine(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void makeActorAlive() override;

private:
    u8 filler[0x170 - sizeof(al::DemoActor)];
};

static_assert(sizeof(DemoActorCapManHeroine) == 0x170);
