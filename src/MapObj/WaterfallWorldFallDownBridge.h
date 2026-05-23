#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class WaterfallWorldFallDownBridge : public al::LiveActor {
public:
    WaterfallWorldFallDownBridge(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void startDemo();
    bool isEndDemo() const;
    s64 fallDown();
    void exeWait();
    void exeWaitCameraInterpolate();
    void exeDemo();
    void exeDemoAfter();
    void exeFallDown();

private:
    u8 filler[0x130 - sizeof(al::LiveActor)];
};

static_assert(sizeof(WaterfallWorldFallDownBridge) == 0x130);
