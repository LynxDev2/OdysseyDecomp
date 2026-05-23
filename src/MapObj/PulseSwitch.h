#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class PulseSwitch : public al::LiveActor {
public:
    PulseSwitch(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void on();
    void exeStandby();
    void exeOn();
    void exeOff();

private:
    u8 filler[0x108 - sizeof(al::LiveActor)];
};

static_assert(sizeof(PulseSwitch) == 0x108);
