#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class KinokoUfo : public al::LiveActor {
public:
    KinokoUfo(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void listenClose();
    void listenOpen();
    void initAfterPlacement() override;

private:
    u8 filler[0x110 - sizeof(al::LiveActor)];
};

static_assert(sizeof(KinokoUfo) == 0x110);
