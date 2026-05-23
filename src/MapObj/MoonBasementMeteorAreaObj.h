#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class MoonBasementMeteorAreaObj : public al::LiveActor {
public:
    MoonBasementMeteorAreaObj(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void control() override;

private:
    u8 filler[0x128 - sizeof(al::LiveActor)];
};

static_assert(sizeof(MoonBasementMeteorAreaObj) == 0x128);
