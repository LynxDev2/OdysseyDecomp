#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class SequentialSwitch : public al::LiveActor {
public:
    SequentialSwitch(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool notifyInputSwitchOn();

private:
    u8 filler[0x110 - sizeof(al::LiveActor)];
};

static_assert(sizeof(SequentialSwitch) == 0x110);
