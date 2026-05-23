#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class IndicatorDirector : public al::LiveActor {
public:
    IndicatorDirector(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void control() override;
    void exeWaitSync();
    bool tryChangeState();
    void exeLight();
    void exeTurnOff();

private:
    u8 filler[0x120 - sizeof(al::LiveActor)];
};

static_assert(sizeof(IndicatorDirector) == 0x120);
