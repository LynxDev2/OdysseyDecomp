#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class SenobiGeneratePoint : public al::LiveActor {
public:
    SenobiGeneratePoint(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void forceKill();
    bool tryGenerate();
    void exeStandby();
    void exeWait();
    void exeEnd();
    void exeGenerate();

private:
    u8 filler[0x120 - sizeof(al::LiveActor)];
};

static_assert(sizeof(SenobiGeneratePoint) == 0x120);
