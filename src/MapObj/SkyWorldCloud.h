#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class SkyWorldCloud : public al::LiveActor {
public:
    SkyWorldCloud(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void exeWait();

private:
    u8 filler[0x120 - sizeof(al::LiveActor)];
};

static_assert(sizeof(SkyWorldCloud) == 0x120);
