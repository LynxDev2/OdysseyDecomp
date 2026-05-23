#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class PeachWorldMoatWater : public al::LiveActor {
public:
    PeachWorldMoatWater(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void control() override;
    void exeWait();
    void exeCameraDelay();
    void exeFallDelay();
    void exeFall();
    void exeFallEnd();
    void exeFallWait();

private:
    u8 filler[0x1A8 - sizeof(al::LiveActor)];
};

static_assert(sizeof(PeachWorldMoatWater) == 0x1A8);
