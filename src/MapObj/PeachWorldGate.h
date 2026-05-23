#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class PeachWorldGate : public al::LiveActor {
public:
    PeachWorldGate(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void start();
    void exeCloseWait();
    void exeOpen();
    void exeOpenWait();

private:
    u8 filler[0x118 - sizeof(al::LiveActor)];
};

static_assert(sizeof(PeachWorldGate) == 0x118);
