#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class ProjectRaceCheckPoint : public al::LiveActor {
public:
    ProjectRaceCheckPoint(const char* name);
    void init(const al::ActorInitInfo& info) override;

private:
    u8 filler[0x108 - sizeof(al::LiveActor)];
};

static_assert(sizeof(ProjectRaceCheckPoint) == 0x108);
