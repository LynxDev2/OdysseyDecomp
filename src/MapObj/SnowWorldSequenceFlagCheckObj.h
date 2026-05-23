#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class SnowWorldSequenceFlagCheckObj : public al::LiveActor {
public:
    SnowWorldSequenceFlagCheckObj(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void exeWait();

private:
    u8 filler[0x118 - sizeof(al::LiveActor)];
};

static_assert(sizeof(SnowWorldSequenceFlagCheckObj) == 0x118);
