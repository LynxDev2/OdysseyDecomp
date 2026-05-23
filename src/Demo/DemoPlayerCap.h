#pragma once

#include <basis/seadTypes.h>

#include "Library/Demo/DemoActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class DemoPlayerCap : public al::DemoActor {
public:
    DemoPlayerCap(const char* name);
    void forceSetCapType(const char* name);
    void init(const al::ActorInitInfo& info) override;

private:
    u8 filler[0x1E0 - sizeof(al::DemoActor)];
};

static_assert(sizeof(DemoPlayerCap) == 0x1E0);
