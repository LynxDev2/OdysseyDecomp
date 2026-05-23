#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class AirBubbleGenerator : public al::LiveActor {
public:
    AirBubbleGenerator(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void exeWait();
    void exeCreate();
    bool tryCreateBubble();
    void exeStop();

private:
    u8 filler[0x110 - sizeof(al::LiveActor)];
};

static_assert(sizeof(AirBubbleGenerator) == 0x110);
