#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class PeachCastleCap : public al::LiveActor {
public:
    PeachCastleCap(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void appear() override;
    void kill() override;
    void control() override;
    void startClipped() override;
    void exeWait();
    void exeDemoStart();
    void exeDemo();
    void exeDemoAfter();

private:
    u8 filler[0x150 - sizeof(al::LiveActor)];
};

static_assert(sizeof(PeachCastleCap) == 0x150);
