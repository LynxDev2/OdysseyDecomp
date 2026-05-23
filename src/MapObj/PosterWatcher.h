#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class PosterWatcher : public al::LiveActor {
public:
    PosterWatcher(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void control() override;

private:
    u8 filler[0x120 - sizeof(al::LiveActor)];
};

static_assert(sizeof(PosterWatcher) == 0x120);
