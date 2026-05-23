#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}

class StageEventDemoBase : public al::LiveActor {
public:
    StageEventDemoBase(const char* name);

    void init(const al::ActorInitInfo& info) override;

private:
    s8 filler[0x108 - sizeof(al::LiveActor)];
};

static_assert(sizeof(StageEventDemoBase) == 0x108);
