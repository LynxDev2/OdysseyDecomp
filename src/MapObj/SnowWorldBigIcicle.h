#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class SnowWorldBigIcicle : public al::LiveActor {
public:
    SnowWorldBigIcicle(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void exeWait();
    void exeCameraDelay();
    void exeFallDelay();
    void exeFall();
    void exeFallEnd();
    void exeFallWait();

private:
    u8 filler[0x140 - sizeof(al::LiveActor)];
};

static_assert(sizeof(SnowWorldBigIcicle) == 0x140);
