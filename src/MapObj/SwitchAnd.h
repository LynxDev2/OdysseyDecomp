#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class SwitchAnd : public al::LiveActor {
public:
    SwitchAnd(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void notifyInputSwitchOn();
    void notifyInputSwitchOff();

private:
    u8 filler[0x110 - sizeof(al::LiveActor)];
};

static_assert(sizeof(SwitchAnd) == 0x110);
